# Turtlebot_Roomba_Walker
[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://github.com/Akshaybj0221/Turtlebot_Roomba/blob/master/LICENSE)


ROS Turtlebot Random Walker
============================
- ROS package containing a node to make a Turtlebot wander around with obstacle
avoidance by simply moving forward and turning when an obstacle is detected


## Dependencies

- ROS Kinetic running
- Ubuntu 16.04. 
- Gazebo 
- Turtlebot Simulation stack

### Package Dependency
- roscpp
- rospy
- sensor_msgs
- geometry_msgs
- turtlebot_gazebo

## Build steps
- Open a terminal
```bash
mkdir -p catkin_ws/src
cd catkin_ws/src && catkin_init_workspace
git clone https://github.com/Akshaybj0221/Turtlebot_Roomba.git
cd ..
catkin_make
source ./devel/setup.bash
```

## Running the demo
- In your terminal

```bash
cd catkin_ws
source devel/setup.bash
roslaunch turtlebot_roomba roomba.launch
```

## Enable rosbag recording

```bash
cd ~/catkin_ws
source devel/setup.bash
roslaunch turtlebot_roomba roomba.launch record:=true
```
The bag file will be stored in the results sub-directory as record.bag


## Inspect rosbag 

```bash
cd ~/catkin_ws/
source devel/setup.bash
cd src/Turtlebot_Roomba/results
rosbag info record.bag
```
## Playback recording bag file 

```bash
cd ~/catkin_ws/
source devel/setup.bash
cd src/Turtlebot_Roomba/results
rosbag play record.bag
```

