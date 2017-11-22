#include "ros/ros.h"

void Roomba::callback(const sensor_msgs::LaserScan::ConstPtr& readings) {
  double min = 0;
  for (int i = 0; i < readings->ranges.size(); i++) {
    if (readings->ranges[i] > min)
      min = readings->ranges[i];
}
  dist = min;
  ROS_INFO_STREAM("Distance between turtlebot and obstacles: " << dist);
}

