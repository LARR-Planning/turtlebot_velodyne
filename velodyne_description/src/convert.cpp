#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Vector3.h>

#define MAX_VEL 0.26
#define MAX_ANG 1.81
namespace Converter{
class Converter{
    public:
    Converter(const ros::NodeHandle& nh);
    void cmd_Callback(const geometry_msgs::Twist&);

    private:
    ros::NodeHandle nh_;
    ros::Publisher pub_const;
    ros::Subscriber sub_unconst;
    geometry_msgs::Twist unc_twist;
    geometry_msgs::Twist cons_twist;

};
}

void Converter::Converter::cmd_Callback(const geometry_msgs::Twist& twist)
{
    unc_twist.linear = twist.linear;
    unc_twist.angular = twist.angular;
}

Converter::Converter::Converter(const ros::NodeHandle& nh) : nh_(nh)
{
    geometry_msgs::Vector3 zero;
    zero.x = 0.0; zero.y = 0.0; zero.z = 0.0;
    unc_twist.linear = zero;
    unc_twist.angular = zero;

    ros::Publisher pub_const = nh_.advertise<geometry_msgs::Twist>("cmd_vel", 1000);
    ros::Subscriber sub_unconst = nh_.subscribe("unc_cmd_vel", 10, &Converter::cmd_Callback);

    while(ros::ok())
    {
        cons_twist = unc_twist;
        if(unc_twist.linear.x > MAX_VEL)
            cons_twist.linear.x = MAX_VEL;
        if(unc_twist.linear.y > MAX_VEL)
            cons_twist.linear.y = MAX_VEL;
        if(unc_twist.linear.z > MAX_VEL)
            cons_twist.linear.z = MAX_VEL;
        if(unc_twist.angular.x > MAX_ANG)
            cons_twist.angular.x = MAX_ANG;
        if(unc_twist.angular.y > MAX_ANG)
            cons_twist.angular.y = MAX_ANG;  
        if(unc_twist.angular.z > MAX_ANG)
            cons_twist.angular.z = MAX_ANG;
        pub_const.publish(cons_twist);                  
    }
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "converter");

    ros::NodeHandle nh;
    Converter::Converter::Converter(nh);
    
    ros::spin();

    return 0;
}
