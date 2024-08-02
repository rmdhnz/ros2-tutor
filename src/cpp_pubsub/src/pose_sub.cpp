#include <bits/stdc++.h>
#include "rclcpp/rclcpp.hpp"
#include "turtlesim/msg/pose.hpp"
using std::placeholders::_1;


using namespace std::chrono_literals;

class PoseSubscriber: public rclcpp::Node{
    private: 
        rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr pose_sub;
        void pose_callback(const turtlesim::msg::Pose::SharedPtr pose){
            double x = pose->x,y = pose->y,yaw_angle=pose->theta;
            RCLCPP_INFO(this->get_logger(),"Position : [%f , %f]\nYaw angle : %f\n",x,y,yaw_angle);
        }
    public: 
        PoseSubscriber() : Node("pose_subscriber"){
            RCLCPP_INFO(this->get_logger(),"Pose subscriber has been started...");
            pose_sub = this->create_subscription<turtlesim::msg::Pose>("turtle1/pose", 10, std::bind(&PoseSubscriber::pose_callback, this, _1));
        }
};
int main(int argc, char const *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PoseSubscriber>());
    rclcpp::shutdown();
    return 0;
}
