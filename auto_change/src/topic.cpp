#include "auto_change/topic.h"
topic::topic(){

	ros::NodeHandle nh_private("~");
    laserscan_sub = n.subscribe("/velodyne_points", 10, &topic::change_topic, this);
    topic_pub = n.advertise<sensor_msgs::PointCloud2>("/points_raw", 10);    

}

void topic::change_topic(const sensor_msgs::PointCloud2::ConstPtr& input){

    sensor_msgs::PointCloud2 msg = *input;
    msg.header.stamp = ros::Time::now(); 
    msg.header.frame_id = "velodyne";
    topic_pub.publish(msg);

}
  


int main(int argc, char *argv[])
{
	ros::init(argc, argv, "topicc");
	ROS_INFO("Topic change node start! ");

	topic aa;

    ros::spin();
	
	return 0;
}
