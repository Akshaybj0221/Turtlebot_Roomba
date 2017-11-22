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
 *   @file	  turtlebot_roomba.h
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
#include "std_msgs/String.h"
#include "sensor_msgs/LaserScan.h"
#include "geometry_msgs/Twist.h"

class Walker {
 public:
  // Constructor used
  Walker(ros::NodeHandle& nh);
  // Callback function called
  void callback(const sensor_msgs::LaserScan::ConstPtr& insensor);
  // Destructor called in the end
  ~Walker();
 private:
  // Distance from the obstacle
  double dist;
  // Subscriber object
  ros::Subscriber sub;
  // Publisher object
  ros::Publisher pub;
  // Geometry message object
  geometry_msgs::Twist msg;
};//Class ended
