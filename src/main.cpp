#include "ros/ros.h"
#include "turtlebot_walker.h"  // NOLINT
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"
#include "sensor_msgs/LaserScan.h"

int main(int argc, char **argv) {
  ros::init(argc, argv, "roomba");
  ros::NodeHandle nh;
  Walker walk(nh);
  return 0;
}
