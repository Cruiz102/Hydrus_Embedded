
#include "ros_embedded_node.h"
#include "devices/devices.h"

// Global declarations

ros::NodeHandle nh;

void initRosNode(void)
{
    nh.initNode();  // Initialize ROS node

    // Declare publishers
    // nh.advertise(current_depth_pub);
    
    // Declare subscribers
    nh.subscribe(thruster_sub_1);
    nh.subscribe(thruster_sub_2);
    nh.subscribe(thruster_sub_3);
    nh.subscribe(thruster_sub_4);
    nh.subscribe(thruster_sub_5);
    nh.subscribe(thruster_sub_6);
    nh.subscribe(thruster_sub_7);
    nh.subscribe(thruster_sub_8);
    nh.subscribe(camera_angle_sub);
    nh.subscribe(gripper_mode_sub);
}


void runRosNode(void)
{
    nh.spinOnce();
}

