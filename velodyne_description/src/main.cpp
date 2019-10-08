#include <ros/ros.h>
#include <velodyne_description/wap_control.h>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "wap_control");
    ros::NodeHandle nh;

    Way_Control::Way_Control(nh);

    ros::spin();
    return 0;
}