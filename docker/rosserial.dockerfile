# The following Dockerfile is from this Repository that isthe official repository
#  that the arduino community reference for downloading rosserial :
# https://github.com/frankjoshua/rosserial_arduino_lib/blob/master/Dockerfile
# The Official 
FROM ros:noetic-ros-base


# custom installation for RPI Grove dependencies defined in requirements.txt
RUN apt-get update 
RUN apt-get install -y gcc
RUN apt-get install -y curl
# Install the latest version of arduino-cli
WORKDIR /usr/local/
RUN curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh |  sh  &&\
    arduino-cli core update-index &&\
    arduino-cli core install arduino:avr

# Installing the latest version of the Rosserial Arduino Library 0.9.4 got me the following error:
#  Therefore I had to install the version 0.7.9 as mentioned in this post.
# https://answers.ros.org/question/361930/rosserial-arduino-compilation-error-no-cstring/
WORKDIR /catkin_ws
RUN arduino-cli lib install "Rosserial Arduino Library@0.7.9"






# Check the extension because in the example of the rosserial_arduino_lib
#  They used a pde extension instead of a .ino extension. I tried to compiled
#  the example but it didn't work in my avr:uno board.
# CMD [ "arduino-cli compile --fqbn arduino:samd:mkr1000 MyFirstSketch.ino" ]
