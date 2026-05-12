#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <tf2/LinearMath/Quaternion.h>

#include <iostream>
#include <fstream>
#include <string>

class NeedleTipSim : public rclcpp::Node {

private:
  
  rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr sim_tip_publisher;
  
  std::ifstream file;
    
public:
  
  NeedleTipSim( const std::string& name);
  void publish( );
  
};
