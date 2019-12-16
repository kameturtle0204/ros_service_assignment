#include "ros/ros.h"
#include "ros_service_assignment/RectangleAreaService.h"
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "find_area_client");
  if (argc != 3)
  {
    ROS_INFO("usage: find_area_client X Y");
    return 1;
  }

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<ros_service_assignment::RectangleAreaService>("find_area_service");
  ros_service_assignment::RectangleAreaService srv;
  srv.request.width = std::stof(argv[1]);
  srv.request.height = std::stof(argv[2]);
  if (client.call(srv))
  {
    ROS_INFO("Sum: %ld", (long int)srv.response.area);
  }
  else
  {
     ROS_ERROR("Failed to call service add_two_ints");
     return 1;
  }

  return 0;
}
