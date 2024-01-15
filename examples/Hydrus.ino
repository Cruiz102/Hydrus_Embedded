// This will be the main arduino sketch to put in the  Hydrus microcontroller.


#include <Arduino.h>

#include "ROS/ros_deps.h"
#include "devices/devices.h"
#include "<Hy"

void setup() 
{
  // initializeGripper();
  initROSDependencies();
  initializeThrusters();
  // initializeCameraServo();
  // initializePressureSensor();
}

void loop() 
{
  // publishCurrentDepth();
  runROSDependencies();
}
