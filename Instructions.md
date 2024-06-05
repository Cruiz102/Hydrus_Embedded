
Tutorial for Enabling Thrusters Code for a Robotics Team


How to access the Jetson:

Currently The Jetson can only be used though the Terminal.

After turning on the Jetson you will have to log in to the main user. The credentials are the following.

USERNAME: hydrus
Password: rumarino

Next will be to connect the board to the jetson by usb. Make sure to not disconnect never the board with the Jetson, it could make a short circuit with the PCB. Also in order for the 

Running on the Jetson:

The main technology for starting the software is docker.
Docker should already been installed inside the machine but if not
you can download it by pasting the following commands.

 > Important: Be sure that the Jetson is connected to the internet. This is needed to install the necessary packages. If possible connect it to a Lan cable.

```bash
sudo apt update
sudo apt install -y docker.io
sudo systemctl start docker
sudo systemctl enable docker
```



Thrusters and Gripper code:

The next step is to download the following  github repository. To do that you will need to paste this command:

```bash
git clone https://github.com/Cruiz102/Hydrus_Embedded.git
```

Now its time for downloading the docker images and running the docker containers running.

```bash
cd Hydrus_Embedded/docker
docker compose  up
```

Now the Jetson is connected with the microcontroller that controls the Thrusters. Just remember that the jetson must be always connected to the microcontroller with the usb hub.


Now for downloading all the dependencies  and get all the modules running you will have to connect all them with this command.

The following will activate the following modules:

- Camera
- DVL
- IMU
- Task Module

```bash
git clone https://github.com/Rumarino-Team/Task_Module.git
cd Task_Module/docker/production
docker compose up
```


After downloading and installing all the codes into Jetson Tx2 the next step is to run a task mission. The following mission will try to execute the most easy task from all of them. It will perform different types of movement Forward , 180 rotation Forward again.

For that you will need to connect though  ssh

Step 1: Ensure SSH is installed
Make sure SSH is installed on both computers. On most Linux distributions, you can install SSH using the following commands:

On the computer you want to connect to (the server):
```bash
sudo apt update
sudo apt install openssh-server 
```

On the computer you're connecting from (the client):

```bash
sudo apt update
sudo apt install openssh-client
```


Step 2: Next is to get the IP from the Jetson. remember that first you will need to connect the jetson with the client computer via LAN. This must be run on the Jetson.

Copiar código
hostname -I
This will directly show the IP address.

Step 3: Connect via SSH
Once you have the IP address of the target computer, you can connect to it via SSH using the following command:

```bash
ssh username@target_ip_address
```
Replace username with the actual username of the account on the target computer, and target_ip_address with the IP address you found in Step 2.

For example, if the username is user and the IP address is 192.168.1.10, you would run:

```sh
ssh hydrus@192.168.1.10
```


Finally After connecting  remotely with the Jetson run the following command for activating the mission. Remember that this command must be ran with the client that is connected to the Jetson. This will activate the mission and the submarine will begin to move.

```bash
docker exec -it simulator_node /bin/bash
python catkin_ws/src/Task_Module/src/tasks/demo.py
```


