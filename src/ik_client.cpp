#include "ik_service/PoseIK.h"
#include "ros/ros.h"
//#include "beginner_tutorials/AddTwoInts.h"
#include <cstdlib>
    
int main(int argc, char **argv)
{
  ros::init(argc, argv, "pose_ik_client");
  /*if (argc != 3)
  {
     ROS_INFO("usage: pose_ik_client X Y");
     return 1;
  }*/
   
  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<ik_service::PoseIK>("pose_ik");
  
  ik_service::PoseIK ik_pose;
// Declare a Pose variable
  geometry_msgs::Pose part_pose;
// Set the variables
  part_pose.position.x = 0.5;
  ik_pose.request.part_pose = part_pose;
  if (client.call(ik_pose)){
    ROS_INFO("Call to ik_service returned [%i] solutions", ik_pose.response.num_sols);
    if(ik_pose.response.num_sols > 0 && ik_pose.response.num_sols <= 8){
      ROS_INFO("Ik_service solution lisr: angle1: %f,angle2: %f,angle3: %f,angle4: %f,angle5: %f,angle6: %f", ik_pose.response.joint_solutions[0].joint_angles[0],ik_pose.response.joint_solutions[0].joint_angles[1],ik_pose.response.joint_solutions[0].joint_angles[2],ik_pose.response.joint_solutions[0].joint_angles[3],ik_pose.response.joint_solutions[0].joint_angles[4],ik_pose.response.joint_solutions[0].joint_angles[5]);
    }
  }
  else{
    ROS_ERROR("Failed to call service ik_service");
    return 1;
  }
  //beginner_tutorials::AddTwoInts srv;
  //srv.request.a = atoll(argv[1]);
  //srv.request.b = atoll(argv[2]); 
  return 0;
}

