#include "ros/ros.h"
#include "std_msgs/Float64.h"
 
#include <vector>

int main(int argc, char **argv)
{
    std::vector<std::vector<float>> joint_position{ {-0.40, 0.00, 0.00,-2.00, 0.00, 3.50, 0.00},  
                                                    {-0.40, 0.00, 0.00,-2.00, 0.00, 2.50, 0.00},
                                                    { 0.40, 0.00, 0.00,-2.00, 0.00, 2.50, 0.00},
                                                    { 0.40, 0.00, 0.00,-2.00, 0.00, 3.50, 0.00}};

    std::vector<std_msgs::Float64> msg(7);

    ros::init(argc, argv, "franka_panda_joint_publisher");
    ros::NodeHandle n;

    ros::Publisher joint1_position = n.advertise<std_msgs::Float64>("/panda/joint1_position_controller/command", 1000);
    ros::Publisher joint2_position = n.advertise<std_msgs::Float64>("/panda/joint2_position_controller/command", 1000);
    ros::Publisher joint3_position = n.advertise<std_msgs::Float64>("/panda/joint3_position_controller/command", 1000);
    ros::Publisher joint4_position = n.advertise<std_msgs::Float64>("/panda/joint4_position_controller/command", 1000);
    ros::Publisher joint5_position = n.advertise<std_msgs::Float64>("/panda/joint5_position_controller/command", 1000);
    ros::Publisher joint6_position = n.advertise<std_msgs::Float64>("/panda/joint6_position_controller/command", 1000);
    ros::Publisher joint7_position = n.advertise<std_msgs::Float64>("/panda/joint7_position_controller/command", 1000);
    ros::Rate loop_rate(1);
  
    int index = 0;
  
    while (ros::ok())
    {   
        index < joint_position.size()-1 ? index++ : index = 0;

        msg[0].data = joint_position[index][0];
        joint1_position.publish(msg[0]);
        msg[1].data = joint_position[index][1];
        joint2_position.publish(msg[1]);
        msg[2].data = joint_position[index][2];
        joint3_position.publish(msg[2]);
        msg[3].data = joint_position[index][3];
        joint4_position.publish(msg[3]);
        msg[4].data = joint_position[index][4];
        joint5_position.publish(msg[4]);
        msg[5].data = joint_position[index][5];
        joint6_position.publish(msg[5]);
        msg[6].data = joint_position[index][6];
        joint7_position.publish(msg[6]);
             
        ROS_INFO("Joint position: %f, %f, %f, %f, %f, %f, %f", msg[0].data, msg[1].data, msg[2].data, msg[3].data, msg[4].data, msg[5].data, msg[6].data);
 
        ros::spinOnce();
 
        loop_rate.sleep();
    }

    return 0;
}