// This will be the main arduino sketch to put in the  Hydrus microcontroller.

# pragma once
#include <Arduino.h>

# include <rosserial_hydrus_node.h>

void setup() 
{
  runROSDependencies();
  // initializeGripper();
  // initializeCameraServo();
  // initializePressureSensor();
}

void loop() 
{
  // publishCurrentDepth();
  runROSDependencies();
}
