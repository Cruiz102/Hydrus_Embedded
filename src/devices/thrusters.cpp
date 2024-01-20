

#include <Servo.h>
// # include <string>
#include "devices.h"
#include "geometry_msgs/Vector3.h"
#include <cstring> // For strcpy and strcat


// #include <vector>


// Macro and enum declarations

#define MOTOR_NUM 8  // Total number of motors for the actuator
#define PWM_NEUTRAL 1500  // The thruster's output force is 0 lbf at this PWM value


// Global variable declarations
//  We use the class of Servo becuase its abstraction
// can be used for thusters.
static Servo motors[MOTOR_NUM]; 
static char* thruster_topics[MOTOR_NUM];
static bool init_motors = false;


// TODO: Implement concatanation for char pointers
void initializeThrustersSubscribers(const char* model_name) {
    // ros::master::V_TopicInfo master_topics;
    // ros::master::getTopics(master_topics);

//  We defined them like this to declare them explicetly
//  To not make the class f a Vector for memory efficiency.
    thruster_topics[0] =  "/" + model_name + "/thrusters/1/";
    thruster_topics[1] =  "/" + model_name + "/thrusters/2/";
    thruster_topics[2] =  "/" + model_name + "/thrusters/3/";
    thruster_topics[3] =  "/" + model_name + "/thrusters/4/";
    thruster_topics[4] =  "/" + model_name + "/thrusters/5/";
    thruster_topics[5] =  "/" + model_name + "/thrusters/6/";
    thruster_topics[6] =  "/" + model_name + "/thrusters/7/";
    thruster_topics[7] =  "/" + model_name + "/thrusters/8/";



// TODO: Need a work around for getting this raise Error for testing purposes.

    // if a thuster_topic is not found then we throw an error. 
    // for (const auto& required_topic : required_topics) {
    //     bool topic_found = false;
    //     for (const auto& topic_info : master_topics) {
    //         if (topic_info.name == required_topic) {
    //             topic_found = true;
    //             break;
    //         }
    //     }
    //     // If a required topic is not found, raise an error
    //     if (!topic_found) {
    //         throw std::runtime_error("Required topic not found: " + required_topic);
    //     }
    // }

    // We cant abstract the  the function calling making callbacks with std::bind because
    // The arduino dependencies do not support this function for this board. We must call
    // them individually or make a wrapper but I don't like the idea of making a wrapper.
    ros::Subscriber<geometry_msgs::Vector3> thruster_sub_1(thruters_topics[0], setThruster_1);
    ros::Subscriber<geometry_msgs::Vector3> thruster_sub_2(thruters_topics[1], setThruster_2);
    ros::Subscriber<geometry_msgs::Vector3> thruster_sub_3(thruters_topics[2], setThruster_3);
    ros::Subscriber<geometry_msgs::Vector3> thruster_sub_4(thruters_topics[3], setThruster_4);
    ros::Subscriber<geometry_msgs::Vector3> thruster_sub_5(thruters_topics[4], setThruster_5);
    ros::Subscriber<geometry_msgs::Vector3> thruster_sub_6(thruters_topics[5], setThruster_6);
    ros::Subscriber<geometry_msgs::Vector3> thruster_sub_7(thruters_topics[6], setThruster_7);
    ros::Subscriber<geometry_msgs::Vector3> thruster_sub_8(thruters_topics[7], setThruster_8);


}

//----------------------
//----------------------
//  Callbacks

// Setter for the thruster motor PWM values
void setThruster_1(const geometry_msgs::Vector3& thusterVector)
{ 
    // The Vector ffrom the parameter is tecnically a scalar inside 
    // a 3d vector. Don't ask me why it is like that. uuv_simulator
    // implement it like that The y and z parameter of the vector is 
    // always 0.
    if(init_motors){
    motors[0].writeMicroseconds(thusterVector.x);
    
}
void setThruster_2(const geometry_msgs::Vector3& thusterVector)
{ 
    if(init_motors){
    motors[1].writeMicroseconds(thusterVector.x);
    }
}

void setThruster_3(const geometry_msgs::Vector3& thusterVector)
{ 
    if(init_motors){
    motors[2].writeMicroseconds(thusterVector.x);
    }
}
void setThruster_4(const geometry_msgs::Vector3& thusterVector)
{ 
    if(init_motors){
    motors[3].writeMicroseconds(thusterVector.x);
    }
}
void setThruster_5(const geometry_msgs::Vector3& thusterVector)
{ 
    if(init_motors){
    motors[4].writeMicroseconds(thusterVector.x);
    }
}
void setThruster_6(const geometry_msgs::Vector3& thusterVector)
{ 
    if(init_motors){
    motors[5].writeMicroseconds(thusterVector.x);
    }
}
void setThruster_7(const geometry_msgs::Vector3& thusterVector)
{ 
    if(init_motors){
    motors[6].writeMicroseconds(thusterVector.x);
    }
}
void setThruster_8(const geometry_msgs::Vector3& thusterVector)
{ 
    if(init_motors){
    motors[7].writeMicroseconds(thusterVector.x);
    }
}



