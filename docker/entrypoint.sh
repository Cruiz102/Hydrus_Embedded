#!/bin/bash
set -e

# Start roscore in the background
roscore &
sleep 2

# Navigate to your project directory
cd /root/Arduino/libraries/sensor_actuator_pkg/Hydrus

# Compile the Arduino project
arduino-cli compile --fqbn $ARDUINO_BOARD Hydrus.ino

arduino-cli upload -p /dev/ttyACM0 --fqbn $ARDUINO_BOARD Hydrus.ino

# Keep the container running
exec "$@"
