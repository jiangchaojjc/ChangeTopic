#include "ros/ros.h"
#include <tf/transform_broadcaster.h>  
#include <nav_msgs/Odometry.h> 
#include <geometry_msgs/Vector3.h>
#include "geometry_msgs/Pose.h"
#include "sensor_msgs/PointCloud2.h"

#include "tf2/LinearMath/Matrix3x3.h"
#include "std_msgs/Float64.h"

#include <math.h>
#include <string.h>

#include <iostream>

class topic;

class topic
{
public:
    topic();
	void change_topic(const sensor_msgs::PointCloud2::ConstPtr& input);

private:
	ros::NodeHandle n;  
	ros::Publisher topic_pub;
	ros::Subscriber laserscan_sub;
};