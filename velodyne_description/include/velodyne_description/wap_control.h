#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Quaternion.h>
#include <tf/tf.h>

namespace Way_Control{

class Way_Control{
    public:
        Way_Control( ros::NodeHandle nh);

    private:
    ros::NodeHandle nh;
    geometry_msgs::Point waypoint;
    double yaw;

    ros::Publisher pub_cmd; // cmd_vel to turtlebot
    

};


Way_Control::Way_Control( ros::NodeHandle nh)
{
    pub_cmd = nh.advertise<geometry_msgs::Twist>("cmd_vel", 1);
    // ros::Publisher pub_cmd("cmd_vel", geometry_msgs::Twist, 5);
    
    
}
}