#pragma once

#include <string>
#include <unordered_map>

#include "depthai/depthai.hpp"
#include "depthai_ros_driver/param_handlers/base_param_handler.hpp"

namespace depthai_ros_driver {
namespace param_handlers {
namespace camera {
enum class NNType { None, Default, Spatial };
}
class CameraParamHandler : public BaseParamHandler {
   public:
    explicit CameraParamHandler(const std::string& name);
    ~CameraParamHandler();
    void declareParams(rclcpp::Node* node);
    dai::CameraControl setRuntimeParams(rclcpp::Node* node, const std::vector<rclcpp::Parameter>& params) override;
    camera::NNType getNNType(rclcpp::Node* node);
    dai::UsbSpeed getUSBSpeed(rclcpp::Node* node);

   private:
    std::unordered_map<std::string, dai::UsbSpeed> usbSpeedMap;
    std::unordered_map<std::string, camera::NNType> nnTypeMap;
};
}  // namespace param_handlers
}  // namespace depthai_ros_driver