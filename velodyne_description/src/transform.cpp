#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <tf/transform_broadcaster.h>


void pointCallback(const sensor_msgs::PointCloud2& data){
    static tf::TransformBroadcaster br;

    br.sendTransform((x,y,z), tf::trans
}


int main(int argc, char** argv)
{
    ros::init(argc, argv, "tf_octomap");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("", 10, &pointCallback);

    ros::spin();
    return 0;
}