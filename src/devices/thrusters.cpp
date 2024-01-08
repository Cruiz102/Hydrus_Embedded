

#include <Servo.h>
# include <string>
#include "devices.h"
#include <ros/ros.h>
#include <geometry_msgs/Vector3.h>
#include <vector>
#include <functional>
#include <unordered_map>


// Macro and enum declarations

#define MOTOR_NUM 8  // Total number of motors for the actuator
#define PWM_NEUTRAL 1500  // The thruster's output force is 0 lbf at this PWM value

enum MotorPins {MOTOR_1_PIN , MOTOR_2_PIN, MOTOR_3_PIN, MOTOR_4_PIN, MOTOR_5_PIN, MOTOR_6_PIN, MOTOR_7_PIN, MOTOR_8_PIN};


// Global variable declarations

static Servo motors[MOTOR_NUM]; 
static bool init_motors = false;
ros::Subscriber<geometry_msgs::Vector3> thrust_force_sub("thrust_force_values", setThrusterSpeeds);
static MotorPins motor_pins[] = {MOTOR_1_PIN, MOTOR_2_PIN, MOTOR_3_PIN, MOTOR_4_PIN, MOTOR_5_PIN, MOTOR_6_PIN, MOTOR_7_PIN, MOTOR_8_PIN};


// Function declarations



void initializeThrustersSubscribers(const std::string& model_name, int thruster_count) {
    ros::master::V_TopicInfo master_topics;
    ros::master::getTopics(master_topics);

    std::vector<std::string> required_topics;
    std::vector<std::string> found_topics;

    // Check each required topic
    for (const auto& required_topic : required_topics) {
        bool topic_found = false;
        for (const auto& topic_info : master_topics) {
            if (topic_info.name == required_topic) {
                topic_found = true;
                found_topics.push_back(topic_info.name);
                break;
            }
        }

        // If a required topic is not found, raise an error
        if (!topic_found) {
            throw std::runtime_error("Required topic not found: " + required_topic);
        }
    }

    // If all topics are found, subscribe to them
    std::vector<ros::Subscriber<geometry_msgs::Vector3>> subscribers;
    for (const auto& topic : found_topics) {
        subscribers.push_back(nh.subscribe<geometry_msgs::Vector3>(topic, 10, setThrusterSpeeds));
        ros::Subscriber<geometry_msgs::Vector3> thrust_force_sub("thrust_force_values", setThrusterSpeeds);
    }
    ros::Subscriber<geometry_msgs::Vector3> thruster1_sub = nh.subscribe<geometry_msgs::Vector3>(thruster_topics[0], 10, thruster1Callback);
    ros::Subscriber<geometry_msgs::Vector3> thruster2_sub = nh.subscribe<geometry_msgs::Vector3>(thruster_topics[1], 10, thruster2Callback);
}

enum class ThrusterID {
    Thruster1,
    Thruster2,
    Thruster3,
    Thruster4,
    Thruster5,
    Thruster6,
    Thruster7,
    Thruster8,
};


class ThrusterController {

private:
    ros::NodeHandle* nh;
    std::unordered_map<ThrusterID, ros::Subscriber> subscribers;
    std::string model_name;
    Servo motors[MOTOR_NUM]; 
    bool init_motors;
public:
    ThrusterController(const std::string& model_name const ros::NodeHandle* nh){
      this->nh = nh;
      this-> model_name;
      this->init_motors = false;
    }

    ~ThrusterController(){
      delete this->motors 
    }

    void initializeSubscribers() {
        for (int i = 0; i < static_cast<int>(ThrusterID::ThrusterCount); ++i) {
            std::string topic = "/" + model_name_ + "/thrusters/" + std::to_string(i + 1) + "/";
            ThrusterID thruster_id = static_cast<ThrusterID>(i);
            auto callback = std::bind(&ThrusterController::thrusterCallback, this, std::placeholders::_1, thruster_id);
            subscribers[thruster_id] = nh.subscribe<geometry_msgs::Vector3>(topic, 10, callback);
        }
    }

    void thrusterCallback(const geometry_msgs::Vector3::ConstPtr& msg, ThrusterID thruster_id) {
        // Process the message based on thruster_id
        ROS_INFO("Received data on Thruster %d: %f", static_cast<int>(thruster_id), msg->x);
        // Update the corresponding thruster's value or perform actions
    }

};



void initializeThrustersArduino(void)
{     
    init_motors = true;
    for (uint8_t i = 0; i < MOTOR_NUM; i++){
        motors[i].attach(motor_pins[i]);
        motors[i].writeMicroseconds(PWM_NEUTRAL);  // This sets the thrusters output force to 0 lbf
    }   
}

// Conversion from thrust force to PWM (example only, you need to define this)
int thrustToPWM(double thrust) {
  // Placeholder for conversion logic
  // You will need to replace this with your own conversion based on your thruster's characteristics
  int pwm_value = PWM_NEUTRAL + (thrust * conversion_factor);
  return pwm_value;
}


// Setter for the thruster motor PWM values
void setThrusterSpeeds(const MotorValues& motor_msg)
{ 
    if(init_motors)
        for (uint8_t i = 0; i < MOTOR_NUM; i++)
            motors[i].writeMicroseconds(motor_msg.motor_values[i]);
}


// Setter for the thruster motor PWM values based on thrust force
void setThrusterSpeeds(const geometry_msgs::Vector3& thrust_msg)
{
  if(init_motors) {
    // Assuming that thrust_msg.x is the desired thrust force for motor 1,
    // repeat for each motor as needed using thrust_msg.y, thrust_msg.z, etc.
    int pwm_value = thrustToPWM(thrust_msg.x); 
    motors[0].writeMicroseconds(pwm_value);
    // Repeat the above two lines for each thruster/motor, mapping the force to the correct motor
  }
}

