#include <GSLAM/core/GSLAM.h>
#include <GSLAM/core/Dataset.h>
#include <GSLAM/core/VideoFrame.h>
#include <sstream>
#include "nbind/api.h"

//namespace nbind
//{

//template <typename KeyType, typename VarType>
//struct BindingType<std::map<KeyType, VarType> > {

//    typedef std::map<KeyType, VarType> Type;

//    static inline bool checkType(WireType arg) {
//        if(!arg->IsMap()) return(false);

////        v8::Local<v8::Map> arr = arg.template As<v8::Map>();

//        return true;
//    }

//    static inline Type fromWireType(WireType arg) {
//        // TODO: Don't convert sparse arrays.

//        v8::Local<v8::Map> map = arg.template As<v8::Map>();
//        v8::Local<v8::Array> arr=map->AsArray();

//        uint32_t count = arr->Length();

//        Type val;

//        // Length of arr is checked in checkType().
//        for(int num = 0; num < count; num+=2) {
//            v8::Local<v8::Value> key;
//            v8::Local<v8::Value> var;

//            if(
//                Nan::Get(arr, num).ToLocal(&key) &&
//                    Nan::Get(arr, num+1).ToLocal(&var)
//            ) {
//                val[convertFromWire<KeyType>(key)]=convertFromWire<VarType>(var);
//            } else {
//                throw(std::runtime_error("Error converting map element"));
//            }
//        }

//        return(val);
//    }

//    static inline WireType toWireType(Type &&arg) {
//        v8::Local<v8::Map> mp = Nan::New<v8::Map>();

//        for(auto it: arg) {
//            mp->Set(convertToWire(std::forward<KeyType>(it.first)),
//                    convertToWire(std::forward<VarType>(it.second)));
//        }

//        return(mp);
//    }

//};

//}

using namespace std;

//If using C++11 instead of C++14, uncomment this:
namespace std {
 template<typename T, typename... Args>
 std::unique_ptr<T> make_unique(Args&&... args) {
   return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
 }
}

namespace Wrapper{

std::string version(){return GSLAM_VERSION;}

void setPara(std::string name,std::string value){
    svar.insert(name,value);
}

std::string getString(std::string name,std::string def){
    return svar.GetString(name,def);
}

int getInt(std::string name,int def){
    return svar.GetInt(name,def);
}

double getDouble(std::string name,double def){
    return svar.GetDouble(name,def);
}

bool call(std::string cmd){
    return svar.ParseLine(cmd);
}

GSLAM::FramePtr getTestFrame(){
    return GSLAM::FramePtr(new GSLAM::FrameMono(2,3,
     GSLAM::GImage(3,4,GSLAM::GImageType<uchar,3>::Type),GSLAM::Camera({10,10})));
}


class Point2 : public GSLAM::Point2d
{
public:
    Point2(){}
    Point2(const GSLAM::Point2d& pt):GSLAM::Point2d(pt){}
    Point2(double X,double Y):GSLAM::Point2d(X,Y){}
    double getX(){return x;}
    double getY(){return y;}
    void setX(double X){x=X;}
    void setY(double Y){y=Y;}
    double dot(const Point2& a)const{return x*a.x+y*a.y;}
    double norm()const
    {
        return sqrt(x*x+y*y);
    }
    std::string toString()const{std::stringstream sst;sst<<*this;return sst.str();}

};

class Point3 : public GSLAM::Point3d
{
public:
    Point3(){}
    Point3(const GSLAM::Point3d& pt):GSLAM::Point3d(pt){}
    Point3(double X,double Y,double Z):GSLAM::Point3d(X,Y,Z){}
    double getX(){return x;}
    double getY(){return y;}
    double getZ(){return z;}
    void setX(double X){x=X;}
    void setY(double Y){y=Y;}
    void setZ(double Z){z=Z;}
    double dot(const Point3& a)const{return x*a.x+y*a.y+z*a.z;}
    double norm()const
    {
        return sqrt(x*x+y*y+z*z);
    }
    Point3 cross(const Point3& a)const
    {
        return GSLAM::Point3d::cross(a);
    }
    std::string toString()const{std::stringstream sst;sst<<*this;return sst.str();}
};


class SharedCamera: public GSLAM::Camera{
public:
    SharedCamera(GSLAM::Camera camera):GSLAM::Camera(camera){}
    SPtr<GSLAM::Camera> getShared(){return SPtr<GSLAM::Camera>(new GSLAM::Camera(getParameters()));}
};

bool testGrabRef(GSLAM::Point3d& pt){
    pt=GSLAM::Point3d(1,2,3);
    return true;
}

class GObjectHandleJS : public GSLAM::GObjectHandle
{
public:
    GObjectHandleJS(nbind::cbFunction cb)
    {
        fn = std::make_unique<nbind::cbFunction>(cb);
        (*fn).call<void>(GSLAM::GObjectPtr(new GSLAM::Map()));
    }
    GSLAM::GObjectHandle* getPointer(){return this;}
    virtual void handle(const SPtr<GSLAM::GObject>& obj){
        LOG(INFO)<<"Passing "<<obj->type();
        GSLAM::GObjectPtr tmpObj(new GSLAM::Map());
        (*fn).call<void>(tmpObj);
//        cbk.call<void>(obj);
    }
    std::unique_ptr<nbind::cbFunction> fn;
};

}

#include "nbind/nbind.h"
#ifdef NBIND_CLASS

namespace GSLAM {

NBIND_CLASS(Point2d){
    construct<>();
    construct<double,double>();
    method(dot);
    method(norm);
    method(at);
    method(toString);
    method(add);
    method(plus);
    method(minus);
    method(time);
    method(divide);
    getset(getX,setX);
    getset(getY,setY);
}

NBIND_CLASS(Point3d){
    construct<>();
    construct<double,double,double>();
    method(dot);
    method(cross);
    method(norm);
    method(at);
    method(toString);
    method(add);
    method(plus);
    method(minus);
    method(time);
    method(divide);
    getset(getX,setX);
    getset(getY,setY);
    getset(getZ,setZ);
}

NBIND_CLASS(Point3ub){
    construct<>();
    construct<double,double,double>();
    method(dot);
    method(cross);
    method(norm);
    method(at);
    method(toString);
    method(add);
    method(plus);
    method(minus);
    method(time);
    method(divide);
    getset(getX,setX);
    getset(getY,setY);
    getset(getZ,setZ);
}

NBIND_CLASS(Camera) {
    construct<>();
    construct<std::vector<double> >();
    method(CameraType);
    method(info);
    method(isValid);
    method(width);
    method(height);
    method(getParameters);
    method(estimatePinHoleCamera);
    multimethod(Project,args(const Point3d&));
    multimethod(UnProject,args(const Point2d&));
}

NBIND_CLASS(SO3) {
    construct<>();
    construct<double,double,double,double>();
    method(log);
    method(normalise);
    method(plus);
    method(trans);
    method(toString);
    getset(getX,setX);
    getset(getY,setY);
    getset(getZ,setZ);
    getset(getW,setW);
//    method(exp);
}

NBIND_CLASS(SE3) {
    construct<>();
    construct<const SO3&,const Point3d&>();
    method(log);
    method(plus);
    method(trans);
    method(toString);
    getset(getTranslation,setTranslation);
    getset(getRotation,setRotation);
//    method(exp);
}

NBIND_CLASS(SIM3) {
    construct<>();
//    multimethod(get_translation,args());
//    method(get_rotation);
//    method(get_scale);
}

NBIND_CLASS(GImage){
    construct<>();
//    construct<int,int,int,uchar*,bool>();
    method(empty);
    method(elemSize);
    method(elemSize1);
    method(channels);
    method(type);
    method(total);
    method(clone);
    method(row);
    method(getWidth);
    method(getHeight);
    getter(getWidth);
    getter(getHeight);
}

NBIND_CLASS(GObject){
    construct<>();
    method(type);
    method(call);
    method(draw);
}

NBIND_CLASS(GObjectHandle){
    construct<>();
    multimethod(handle,args(const SPtr<GObject>&));
}

NBIND_CLASS(MapPoint){
    inherit(GObject);
    construct<const PointID&,const Point3d&>();
    method(id);
    method(getPose);
    method(setPose);
    method(getNormal);
    method(setNormal);
    method(getColor);
    method(setColor);
    method(getDescriptor);
    method(setDescriptor);
    method(isPoseRelative);
    method(refKeyframeID);
    method(refKeyframe);
    method(observationNum);
    multimethod(getObservations,args());
    method(addObservation);
    method(eraseObservation);
    method(clearObservation);
    getset(getPose,setPose);
    getset(getNormal,setNormal);
    getset(getColor,setColor);
    getset(getDescriptor,setDescriptor);
}

NBIND_CLASS(FrameConnection){
    inherit(GObject);
    construct<>();
    method(matchesNum);
    multimethod(getMatches,args());
    method(getInformation);
    method(setMatches);
    method(setInformation);
}

NBIND_CLASS(MapFrame){
    inherit(GObject);
    construct<const FrameID&,const double&>();
    method(id);
    method(timestamp);
    multimethod(setPose,args(const SE3&));
    multimethod(setPose,args(const SIM3&),"getPoseSim3");
    multimethod(getPose,args());
    method(getPoseScale);
    method(cameraNum);
    method(getCameraPose);
    method(imageChannels);
    method(getCamera);
    method(getImage);
    method(setImage);
    method(setCamera);
    method(getIMUNum);
    method(getIMUPose);
    method(getAcceleration);
    method(getAngularVelocity);
    method(getMagnetic);
    method(getAccelerationNoise);
    method(getAngularVNoise);
    method(getPitchYawRoll);
    method(getPYRSigma);
    method(getGPSNum);
    method(getGPSPose);
    method(getGPSLLA);
    method(getGPSLLASigma);
    method(getGPSECEF);
    method(getHeight2Ground);
    method(getGPSECEF);
    method(keyPointNum);
    method(setKeyPoints);
    multimethod(getKeyPoints,args());
    method(getKeyPointColor);
    method(getKeyPointIDepthInfo);
    method(getKeyPointObserve);
    method(getDescriptor);
    multimethod(getBoWVector,args());
    multimethod(getFeatureVector,args());
    method(getFeaturesInArea);
    method(observationNum);
    multimethod(getObservations,args());
    method(addObservation);
    method(eraseObservation);
    method(clearObservations);
    method(getParent);
    method(getChild);
    multimethod(getParents,args());
    multimethod(getChildren,args());
    method(addParent);
    method(addChildren);
    method(eraseParent);
    method(eraseChild);
    method(clearParents);
    method(clearChildren);
    method(getMedianDepth);
    method(channelTypeString);
    method(channelString);
}

NBIND_CLASS(FrameMono){
    inherit(MapFrame);
    construct<FrameID,double,const GImage&,const Camera&,int,const Camera&>();
    method(imageChannels);
    method(cameraNum);
    method(getImage);
    method(getCamera);
}

NBIND_CLASS(Dataset){
    inherit(GObject);
    construct<>();
    method(name);
    method(type);
    method(isOpened);
    method(grabFrame);
    method(open);
}

NBIND_CLASS(Map){
    inherit(GObject);
    method(insertMapPoint);
    method(insertMapFrame);
    method(eraseMapPoint);
    method(eraseMapFrame);
    method(clear);
    method(frameNum);
    method(pointNum);
    method(getFrame);
    method(getPoint);
    multimethod(getFrames,args());
    multimethod(getPoints,args());
    method(setLoopDetector);
    method(getLoopDetector);
    multimethod(obtainCandidates,args(const FramePtr&));
    method(save);
    method(load);
    method(getPid);
    method(getFid);
}

NBIND_CLASS(SLAM){
    inherit(GObject);
    method(valid);
    method(isDrawable);
    method(setMap);
    method(getMap);
    method(setSvar);
    method(setCallback);
    method(track);
    method(feed);
    method(finalize);
    method(create);
}

}

namespace Wrapper{

NBIND_GLOBAL() {
    function(version);
    function(setPara);
    function(getString);
    function(getInt);
    function(getDouble);
    function(call);
    function(getTestFrame);
    function(testGrabRef);
}

NBIND_CLASS(SharedCamera){
    inherit(GSLAM::Camera);
    construct<GSLAM::Camera>();
    method(getShared);

}

NBIND_CLASS(GObjectHandleJS){
    inherit(GSLAM::GObjectHandle);
    construct<nbind::cbFunction>();
    method(getPointer);
}

}



#endif

