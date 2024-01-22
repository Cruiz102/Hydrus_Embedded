

#include <Servo.h>
#include "devices.h"
#include "geometry_msgs/Vector3.h"


// Macro and enum declarations

#define MOTOR_NUM 8  // Total number of motors for the actuator
#define PWM_NEUTRAL 1500  // The thruster's output force is 0 lbf at this PWM value
#define model_name "rexrov2"  // The name of the model


char* concatenateTopic(char* prefix, char* name, char* postfix) {
    // Calculate the total length
    int totalLength = 0;
    for (char* p = prefix; *p; ++p) totalLength++;
    for (char* p = name; *p; ++p) totalLength++;
    for (char* p = postfix; *p; ++p) totalLength++;

    // Allocate memory for the concatenated string
    char* result = new char[totalLength + 1]; // +1 for the null terminator

    // Copy the strings
    char* current = result;
    for (char* p = prefix; *p; ++p) *current++ = *p;
    for (char* p = name; *p; ++p) *current++ = *p;
    for (char* p = postfix; *p; ++p) *current++ = *p;

    // Null-terminate the result
    *current = '\0';

    return result;
}


// Global variable declarations
//  We use the class of Servo becuase its abstraction
// can be used for thusters.
static Servo motors[MOTOR_NUM]; 
static char* thruster_topics[MOTOR_NUM];
static bool init_motors = false;

    // ros::master::V_TopicInfo master_topics;
    // ros::master::getTopics(master_topics);

//  We defined them like this to declare them explicetly
//  To not make the class f a Vector for memory efficiency.
char* thruster_topics_0 =  concatenateTopic("/", model_name, "/thrusters/1/");
char* thruster_topics_1 =  concatenateTopic("/", model_name, "/thrusters/1/");
char* thruster_topics_2 =  concatenateTopic("/", model_name, "/thrusters/1/");
char* thruster_topics_3 =  concatenateTopic("/", model_name, "/thrusters/1/");
char* thruster_topics_4 =  concatenateTopic("/", model_name, "/thrusters/1/");
char* thruster_topics_5 =  concatenateTopic("/", model_name, "/thrusters/1/");
char* thruster_topics_6 =  concatenateTopic("/", model_name, "/thrusters/1/");
char* thruster_topics_7 =  concatenateTopic("/", model_name, "/thrusters/1/");
// thruster_topics[1] =  concatenateTopic("/", model_name, "/thrusters/2/");
// thruster_topics[2] =  concatenateTopic("/", model_name, "/thrusters/3/");
// thruster_topics[3] =  concatenateTopic("/", model_name, "/thrusters/4/");
// thruster_topics[4] =  concatenateTopic("/", model_name, "/thrusters/5/");
// thruster_topics[5] =  concatenateTopic("/", model_name, "/thrusters/6/");
// thruster_topics[6] =  concatenateTopic("/", model_name, "/thrusters/7/");
// thruster_topics[7] =  concatenateTopic("/", model_name, "/thrusters/8/");


ros::Subscriber<geometry_msgs::Vector3> thruster_sub_1(thruster_topics_0, setThruster_1);
ros::Subscriber<geometry_msgs::Vector3> thruster_sub_2(thruster_topics_1, setThruster_2);
ros::Subscriber<geometry_msgs::Vector3> thruster_sub_3(thruster_topics_2, setThruster_3);
ros::Subscriber<geometry_msgs::Vector3> thruster_sub_4(thruster_topics_3, setThruster_4);
ros::Subscriber<geometry_msgs::Vector3> thruster_sub_5(thruster_topics_4, setThruster_5);
ros::Subscriber<geometry_msgs::Vector3> thruster_sub_6(thruster_topics_5, setThruster_6);
ros::Subscriber<geometry_msgs::Vector3> thruster_sub_7(thruster_topics_6, setThruster_7);
ros::Subscriber<geometry_msgs::Vector3> thruster_sub_8(thruster_topics_7, setThruster_8);


// TODO: Need a work around for implementing this raise Error for testing purposes.

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



