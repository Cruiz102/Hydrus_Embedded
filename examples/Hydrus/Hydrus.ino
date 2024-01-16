// This will be the main arduino sketch to put in the  Hydrus microcontroller.

# pragma once
#include <Arduino.h>

# include <hydrus_rosserial.h>

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
