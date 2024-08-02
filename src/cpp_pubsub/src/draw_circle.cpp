#include <bits/stdc++.h>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
using namespace std::chrono_literals;
class DrawCircleNode : public rclcpp::Node{
    public : 
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr vel_cmd_pub;
    rclcpp::TimerBase::SharedPtr timer;
    DrawCircleNode() : Node("draw_circle"){ 
        RCLCPP_INFO(this->get_logger(),"Draw circle node has been created and updated");
        vel_cmd_pub = this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel",10);
        timer = this->create_wall_timer(500ms,std::bind(&DrawCircleNode::send_velocity,this));
    }
    void send_velocity(){
        auto message = geometry_msgs::msg::Twist();
        message.linear.x = 1.0;
        message.angular.z = 0.7;
        vel_cmd_pub->publish(message);
    }
};
int main(int argc, char const *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<DrawCircleNode>());
    rclcpp::shutdown();
    return 0;
}
