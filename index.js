var nbind = require('nbind');
var binding = nbind.init();
var gslam = binding.lib;

console.log("GSLAM Version:",gslam.version())
gslam.setPara("SLAM.nFeature","1000");

console.log("SLAM.nFeature:",gslam.getInt("SLAM.nFeature",0))
gslam.call("echo hello world")
 
pt=new gslam.Point3d(2,3,4)
pt=pt.add(gslam.Point3d(3,3,3))

console.log("Dot is :",pt.dot(pt))
console.log("norm is :",pt.norm())
console.log("Cross is :",pt.cross(pt).toString())

camera=gslam.Camera(Array(640,480,400,400,320,240))

console.log("Camera:",camera.info())
pt=camera.Project(gslam.Point3d(1,1,1))

console.log("pt:",pt.x,",",pt.y)
pt.y=100
console.log("pt:",pt.x,",",pt.y)

console.log("camPara:",camera.getParameters())
newCamera=camera.estimatePinHoleCamera();
console.log("NewCamera:",camera.info())

sharedCamera=new gslam.SharedCamera(newCamera)
shared=sharedCamera.getShared()
console.log("SharedInfo:",shared.info())

frame=gslam.getTestFrame()

console.log("id:",frame.id(),",time",frame.timestamp(),",camNum",frame.cameraNum(),",cam",frame.getCamera(0).info())

pt=new gslam.Point3d(0,0,0)
if(gslam.testGrabRef(pt))
  console.log("grab pt:",pt.toString())

dataset=new gslam.Dataset()
dataPath="/mnt/server0/users/zhaoyong/Dataset/KITTI/odomentry/color/00/mono.kitti";

if(dataset.open(dataPath))
{
  frame=dataset.grabFrame();
  acc=new gslam.Point3d();
  frame.getAcceleration(acc,0);
  console.log("acc:",acc.toString())

  console.log("Frame",frame,"id:",frame.id(),",time",frame.timestamp(),",camNum",frame.cameraNum(),",cam",frame.getCamera(0).info())
  image=frame.getImage(0,0)
  console.log("image:",image,"total",image.total())
}
else 
  console.log("Failed to open dataset",dataPath)

function handleGObject(obj){
  console.log("received",obj,obj.type());
}

{
slam=gslam.SLAM.create("/data/zhaoyong/Program/Apps/RTMapper3InOne/GSLAM-DIYSLAM/build/libdiyslam.so")
gslam.call("SLAM.Verbose=3");
if(slam.valid()){
  console.log("SLAM",slam.type(),"created");
  callback=gslam.GObjectHandleJS(handleGObject);
  //slam.setCallback(callback.getPointer())
  for(i=0;i<10;i++)
  {
     slam.feed(dataset.grabFrame())// This have some bug, the shared_ptr are not able to use as input?
  }
  map=slam.getMap();
  console.log("map:",map.frameNum(),", pointNUm",map.pointNum())
  map.save("map.gmap")
  points=map.getPoints()
  console.log("points:",points.length)
  for(i in points){
     var pt=points[i];
     console.log("Pt",pt.id(),"obs",pt.getObservations().length,",",pt.getPose().toString(),",color",pt.color.x,pt.color.y,pt.color.z,pt.normal.toString())
     
  }
}
slam.finalize()
slam=null
}


