#include <ros/ros.h>
#include <velodyne_description/wap_control.h>

namespace Way_Control{

class Way_Control{
    public:
        Way_Control( ros::NodeHandle nh);

    private:
    ros::NodeHandle nh;

    ros::Publisher pub_cmd; // cmd_vel to turtlebot


};


Way_Control::Way_Control( ros::NodeHandle nh)
{
    pub_cmd = nh.advertise<geometry_msgs::Twist>("cmd_vel", 1);
    // ros::Publisher pub_cmd("cmd_vel", geometry_msgs::Twist, 5);

    
}
}