#include "ros/ros.h"
#include "turtlebot_roomba.h" // NOLINT

void Roomba::callback(const sensor_msgs::LaserScan::ConstPtr& insensor) {
  double min = 0;
  for (int i = 0; i < insensor->ranges.size(); i++) {
    if (insensor->ranges[i] > min)
      min = readings->ranges[i];
}
  dist = min;
  ROS_INFO_STREAM("Distance between turtlebot and obstacles: " << dist);
}

Walker::Walker(ros::NodeHandle& nh) {
  sub = nh.subscribe("/scan", 1000, &Walker::callback, this);
  pub = nh.advertise < geometry_msgs::Twist
      > ("/mobile_base/commands/velocity", 1);
  ros::Rate loop_rate(2);
  while (nh.ok()) {
    msg.linear.x = 0.0;
    msg.angular.z = 0.0;
    if (dist > 0.8) {
      msg.linear.x = 0.1;
      ROS_INFO_STREAM("Go!");
    } else {
      msg.angular.z = 1.5;
      ROS_WARN_STREAM("Obstacle detected, turn");
    }
    pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
  }
}

Walker::~Walker() {
  msg.linear.x = 0.0;
  msg.angular.z = 0.0;
  pub.publish(msg);
}
