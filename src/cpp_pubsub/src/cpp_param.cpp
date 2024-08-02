#include <bits/stdc++.h>
#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;

class MinimalParam: public rclcpp::Node{
    rclcpp::TimerBase::SharedPtr timer;
    public:
        MinimalParam(): Node("cpp_param"){ 
            RCLCPP_INFO(this->get_logger(),"Parameter Node has been started...");
        }
};

int main(int argc, char const *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MinimalParam>());
    rclcpp::shutdown();
    return 0;
}
