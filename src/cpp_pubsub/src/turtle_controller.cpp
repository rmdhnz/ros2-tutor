#include <bits/stdc++.h>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "turtlesim/msg/pose.hpp"
using std::placeholders::_1;
using namespace std::chrono_literals;

class TurtleController : public rclcpp::Node{
    private:
        rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr turtle_pub;
        rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr turtle_sub;
    public:
        TurtleController(): Node("turtle_controller") { 
            RCLCPP_INFO(this->get_logger(),"Turtle Controller has been created...");
            turtle_pub = this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel",10);
            turtle_sub = this->create_subscription<turtlesim::msg::Pose>("/turtle1/pose",10,std::bind(&TurtleController::pose_callback,this,_1));
        }
        void pose_callback(const turtlesim::msg::Pose::SharedPtr pose){
            auto cmd = geometry_msgs::msg::Twist();
            if(pose->x >9.0||pose->x <2||pose->y>9.0||pose->y<2){
                cmd.linear.x = 1.0;
                cmd.angular.z=0.9;
            }else{
                cmd.linear.x =5.0;
                cmd.angular.z = 0.0;
            }
            turtle_pub->publish(cmd);
        }
};

int main(int argc, char const *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TurtleController>());
    rclcpp::shutdown();
    return 0;
}
