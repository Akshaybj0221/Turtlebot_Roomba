/**********************************************************************************
 *                                                          			  *
 * Copyright (C) 2017 by Akshay Bajaj                       			  *
 *										  *
 * Permission is hereby granted, free of charge, to any person obtaining a copy   *
 * of this software and associated documentation files (the "Software"), to deal  *
 * in the Software without restriction, including without limitation the rights   *
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell	  *
 * copies of the Software, and to permit persons to whom the Software is	  *
 * furnished to do so, subject to the following conditions:			  *
 *										  *
 * The above copyright notice and this permission notice shall be included in	  *
 * all copies or substantial portions of the Software.				  *
 *										  *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR	  *
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,	  *
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE	  *
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER	  *
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  *
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  *
 * SOFTWARE.                                                         		  *
 *********************************************************************************/

/**
 *   @file	  turtlebot_roomba.cpp
 *   @author	  Akshay Bajaj
 *   @copyright   MIT License
 *
 *   @brief  	  Demo for ROS talker node   
 *   @date	  11/20/2017
 *   @section	  DESCRIPTION
 *
 *   This program contains the function definitions of all the functions initialized in turtlebot_roomba.h header file"
 */

#include "ros/ros.h"
#include "turtlebot_roomba.h" // NOLINT

/**
 * @brief       Callback function for the subscriber
 *
 * @param       insensor  
 *
 * @Description This is used to receive message over the topic
 */

void Roomba::callback(const sensor_msgs::LaserScan::ConstPtr& insensor) {
  double min = 0;
  for (int i = 0; i < insensor->ranges.size(); i++) {
    if (insensor->ranges[i] > min)
      min = readings->ranges[i];
}
  dist = min;
  ROS_INFO_STREAM("Distance between turtlebot and obstacles: " << dist);
}

/**
 * @brief      Makes object and velocitiy commands (Constructor)
 * @param      nh     Nodehandle
 */

Walker::Walker(ros::NodeHandle& nh) {
  sub = nh.subscribe("/scan", 1000, &Walker::callback, this);
  pub = nh.advertise < geometry_msgs::Twist
      > ("/mobile_base/commands/velocity", 1);
  ros::Rate loop_rate(2);
  while (nh.ok()) {
  // Twist message is initiated
    msg.linear.x = 0.0;
    msg.angular.z = 0.0;
  // Checks if object is in the range or not
    if (dist > 0.8) {
  // Moves forward
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

/**
 * @brief      Destructor (Used to stop the turtlebot in the end)
 *             
 */

Walker::~Walker() {
  msg.linear.x = 0.0;
  msg.angular.z = 0.0;
  pub.publish(msg);
}
