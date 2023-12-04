#include "ik_service/PoseIK.h"
#include "ros/ros.h"
#include "ur_kinematics/ur_kin.h"
//#include "beginner_tutorials/AddTwoInts.h"
 
// Declare a variable
//ik_service::PoseIK pose_ik;
// Declare a Pose variable
//geometry_msgs::Pose part_pose;
 
bool pose_ik(ik_service::PoseIK::Request &req, ik_service::PoseIK::Response &res)
{
  double q[] = {3.14, -1.13, 1.51, 3.77, -1.51, 0};
  double T[4][4] = {{0,-1,0,req.part_pose.position.x},{0,0,1,req.part_pose.position.y},{-1,0,0,req.part_pose.position.z},{0,0,0,1}};
  
  int num_sol;
// Allocate space for up to eight solutions of six joint angles
  double q_sols[8][6];
// Inverse kinematic solution(s)
  num_sol = ur_kinematics::inverse(&T[0][0], &q_sols[0][0], 0.0);
  res.num_sols = num_sol;
  for(int i = 0; i < num_sol; i++){
    for(int j = 0; j < 6; j++){
      res.joint_solutions[i].joint_angles[j] = q_sols[i][j];
    }
    
  }
  
  
  
  ROS_INFO("Pose Information...");
  return true;
}


// Set the variables
//part_pose.position.x = 0.5;
//pose_ik.request = part_pose;
/*if(client.call(pose_ik))
{
  ROS_INFO("Call to ik_service returned [%i] solutions", pose_ik.res.num_sols);
}
else
{
  ROS_ERROR("Failed to call service ik_service");
  return 1;
}*/

int main(int argc, char **argv)
{
   ros::init(argc, argv, "pose_ik_server");
   ros::NodeHandle n;
 
   ros::ServiceServer service = n.advertiseService("pose_ik", pose_ik);
   ROS_INFO("Ready to pose_ik.");
   ros::spin();
  
   return 0;
}
