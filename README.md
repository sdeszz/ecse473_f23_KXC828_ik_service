

This ROS package, `ik_service`, is developed to perform Inverse Kinematics (IK) calculations for a robotic system. The package is structured as follows:

- **ik_service**
  - **launch**
    - `ik_service.launch`
  - **src**
    - `ik_service.cpp`
    - `ik_client.cpp`
  - **srv**
    - `PoseIK.srv`
  - **include**
    - `<any include files must be here>`
  - `CMakeLists.txt`
  - `package.xml`
  - `README.md`

## Package Functionality

### Inverse Kinematics Service

The primary functionality of this package is to provide an Inverse Kinematics service. The `ik_service` node calculates the IK solutions for a given pose and returns the number of solutions along with the corresponding joint angles.

### Service Launch

To launch the IK service, use the provided launch file:

```bash
roslaunch ik_service ik_service.launch
```

This will instantiate the `ik_service` node, and the output will be directed to the screen.

### ROS Output

The package generates ROS messages using `ROS_INFO`, `ROS_WARN`, `ROS_ERROR`, and other appropriate log levels to convey:

- The status of the service during instantiation.
- Notifications when service requests are received.
- The number of solutions generated for a given request.

## How to Launch

1. Clone the repository:

```bash
git clone https://github.com/your-username/ecse373_f23_kxc828_ik_service.git
```

2. Navigate to your ROS workspace:

```bash
cd ~/your-ros-workspace
```

3. Build the package:

```bash
catkin_make
```

4. Source your workspace:

```bash
source devel/setup.bash
```

5. Launch the IK service:

```bash
roslaunch ik_service ik_service.launch
```

## Verification

To verify that the `ik_service` node works as intended, run the provided `ik_client`:

```bash
rosrun ik_service ik_client
```

Check the terminal where the `ik_service` node is running. You should see output messages indicating the status of the service, reception of service requests, and the number of solutions generated for each request.
