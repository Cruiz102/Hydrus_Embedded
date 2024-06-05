#!/usr/bin/env python
import rospy
from std_msgs.msg import UInt16  # Assuming PWM commands require UInt16
import time

# Define PWM values for different thruster commands
PWM_ACTIVE = 1600
PWM_NEUTRAL = 1500

# Thruster topic names for all 8 thrusters
THRUSTER_TOPICS = [
    "hydrus/thrusters/1",
    "hydrus/thrusters/2",
    "hydrus/thrusters/3",
    "hydrus/thrusters/4",
    "hydrus/thrusters/5",
    "hydrus/thrusters/6",
    "hydrus/thrusters/7",
    "hydrus/thrusters/8"
]

def publisher():
    rospy.init_node('thruster_control_publisher', anonymous=True)

    # Create a list of publisher objects for each thruster topic
    publishers = [
        rospy.Publisher(topic, UInt16, queue_size=10) for topic in THRUSTER_TOPICS
    ]

    rate = rospy.Rate(1)  # 1 Hz for simplicity

    while not rospy.is_shutdown():
        # Sequence 1: Activate thrusters 1, 2, 3, 4 for 8 seconds
        for _ in range(8):
            for i in range(4):  # Only the first four thrusters
                publishers[i].publish(PWM_ACTIVE)
            for i in range(4, 8):  # Ensure thrusters 5-8 are neutral
                publishers[i].publish(PWM_NEUTRAL)
            rate.sleep()

        # Sequence 2: Activate thrusters 1, 3 for 4 seconds
        for _ in range(4):
            publishers[0].publish(PWM_ACTIVE)  # Thruster 1
            publishers[2].publish(PWM_ACTIVE)  # Thruster 3
            # Ensure thrusters 2, 4-8 are neutral
            publishers[1].publish(PWM_NEUTRAL)
            for i in range(3, 8):
                publishers[i].publish(PWM_NEUTRAL)
            rate.sleep()

        rospy.loginfo("Completed a cycle of thruster commands.")

if __name__ == '__main__':
    try:
        publisher()
    except rospy.ROSInterruptException:
        pass