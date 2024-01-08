cmake_minimum_required(VERSION 3.0.0)
project(sensor_actuator_pkg)

# Set the C++ standard for the project
set(CMAKE_CXX_STANDARD 11)

# Include the directories where the header files are located
include_directories(
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/lib/BlueRobotics_MS5837_Library/src
    ${CMAKE_SOURCE_DIR}/lib/Rosserial_Arduino_Library/src
    ${CMAKE_SOURCE_DIR}/lib/Servo/src
    # Add additional directories as needed
)

# Specify the executable target
add_executable(sensor_actuator_pkg src/main.cpp)

# Link against libraries in the lib directory
# You will need to specify the actual file names of the libraries
target_link_libraries(sensor_actuator_pkg
    ${CMAKE_SOURCE_DIR}/lib/BlueRobotics_MS5837_Library/libMS5837.a
    ${CMAKE_SOURCE_DIR}/lib/Rosserial_Arduino_Library/libRosserial_Arduino.a
    ${CMAKE_SOURCE_DIR}/lib/Servo/libServo.a
    # Add additional libraries as needed
)
