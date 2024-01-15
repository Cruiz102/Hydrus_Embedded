# The following Dockerfile is from this Repository:
# https://github.com/frankjoshua/rosserial_arduino_lib/blob/master/Dockerfile

# Change the noetic for the melodic becuase all the software is in this distro
FROM ros:melodic-ros-base



RUN apt-get update &&\
  apt-get install -y ros-$ROS_DISTRO-rosserial-arduino ros-$ROS_DISTRO-rosserial git &&\
  apt-get -y clean &&\
  apt-get -y purge &&\
  rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

# Create a Catkin Workspace
SHELL ["/bin/bash", "-c"]
ENV CATKIN_WS /catkin_ws
RUN source /opt/ros/$ROS_DISTRO/setup.bash &&\
  mkdir -p $CATKIN_WS/src &&\
  cd $CATKIN_WS/ &&\
  catkin_make

# Build ROS Serial
RUN source /opt/ros/$ROS_DISTRO/setup.bash &&\
  cd $CATKIN_WS/src &&\
  git clone https://github.com/ros-drivers/rosserial.git &&\
  cd $CATKIN_WS &&\
  catkin_make &&\
  catkin_make install

# Create ROS Serial Arduino builder
RUN source /opt/ros/$ROS_DISTRO/setup.bash &&\
  cd /tmp &&\
  rosrun rosserial_arduino make_libraries.py .


# custom installation for RPI Grove dependencies defined in requirements.txt
RUN apt-get update 
RUN apt-get install -y gcc
RUN apt-get install -y curl
# Install the latest version of arduino-cli
WORKDIR /usr/local/
RUN curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh |  sh  &&\
    # mv arduino-cli /usr/local/bin/arduino-cli &&\
    arduino-cli core update-index &&\
    arduino-cli core install arduino:avr


# Check the extension because in the example of the rosserial_arduino_lib
#  They used a pde extension instead of a .ino extension. I tried to compiled
#  the example but it didn't work in my avr:uno board.
# CMD [ "arduino-cli compile --fqbn arduino:samd:mkr1000 MyFirstSketch.ino" ]
