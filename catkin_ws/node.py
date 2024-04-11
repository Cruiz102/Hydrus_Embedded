#!/usr/bin/env python
import rospy
from std_msgs.msg import UInt8
import random
import time


#define GRIPPER_PIN 12  // Pin for the gripper (#TODO: Assign a pin for the gripper)
#define GRIPPER_OPEN 1899  // PWM value for the gripper to be almost opened
#define GRIPPER_CLOSED 1099  // PWM value for the gripper to be almost closed
#define GRIPPER_NEUTRAL 1500  // PWM value for the gripper to be neutral

OPEN = 1899
CLOSED = 1099
NEUTRAL = 1500

def publisher():
    # Initialize the ROS node
    rospy.init_node('gripper_mode_publisher', anonymous=True)

    # Create a publisher object for the topic 'gripper_mode'
    pub = rospy.Publisher('gripper_mode', UInt8, queue_size=10)

    # Set the loop rate (0.1 Hz for every 10 seconds)
    rate = rospy.Rate(0.1)

    while not rospy.is_shutdown():
        # Generate a random number between 0 and 255
        random_number = random.choice([OPEN, CLOSED, NEUTRAL])

        # Create a UInt8 message with the random number
        msg = UInt8()
        msg.data = random_number

        # Publish the message
        pub.publish(msg)
        rospy.loginfo("Published random UInt8: %d" % random_number)

        # Sleep to maintain the loop rate
        rate.sleep()

if __name__ == '__main__':
    try:
        publisher()
    except rospy.ROSInterruptException:
        pass
