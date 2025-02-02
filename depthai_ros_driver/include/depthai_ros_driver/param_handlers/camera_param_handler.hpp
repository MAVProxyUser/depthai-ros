#pragma once

#include <string>
#include <unordered_map>

#include "depthai_ros_driver/param_handlers/base_param_handler.hpp"

namespace dai {
enum class UsbSpeed;
}

namespace rclcpp {
class Node;
class Parameter;
}  // namespace rclcpp

namespace depthai_ros_driver {
namespace param_handlers {

class CameraParamHandler : public BaseParamHandler {
   public:
    explicit CameraParamHandler(const std::string& name);
    ~CameraParamHandler();
    void declareParams(rclcpp::Node* node);
    dai::CameraControl setRuntimeParams(rclcpp::Node* node, const std::vector<rclcpp::Parameter>& params) override;
    dai::UsbSpeed getUSBSpeed(rclcpp::Node* node);

   private:
    std::unordered_map<std::string, dai::UsbSpeed> usbSpeedMap;
};
}  // namespace param_handlers
}  // namespace depthai_ros_driver