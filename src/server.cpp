#include "ros/ros.h"
#include "ros_service_assignment/RectangleAreaService.h"
 
bool findArea(ros_service_assignment::RectangleAreaService::Request  &req,
         ros_service_assignment::RectangleAreaService::Response &res)
{
  res.area = req.width * req.height;
  //ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
  //ROS_INFO("sending back response: [%ld]", (long int)res.sum);
  return true;
}

int main(int argc, char **argv){
  ros::init(argc, argv, "find_area_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("find_area_service", findArea);
  ROS_INFO("Ready to find area.");
  ros::spin();

  return 0;
}
