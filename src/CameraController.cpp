//
// Created by jona on 7/11/22.
//

#include <sstream>
#include "CameraController.h"

#include "iostream"

CameraController::CameraController() {
    std::cout << cameraWrapper.getModel() << std::endl;
}
CameraController::~CameraController() {}

void CameraController::InitializeWidgets() {
    gphoto2pp::WindowWidget config = cameraWrapper.getConfig();
    std::vector<std::string> allWidgets = gphoto2pp::helper::getAllWidgetsNames(config, false);
    {
//        for(size_t i = 0; i < allWidgets.size(); i++) {
//            const std::string widgetName = allWidgets[i];
//            std::cout << widgetName << std::endl;
//        }
//        std::vector<std::string> radioWidgets = gphoto2pp::helper::getAllWidgetsNamesOfType(config, gphoto2pp::CameraWidgetTypeWrapper::Radio, false);
//        for(size_t i = 0; i < radioWidgets.size(); i++) {
//            const std::string widgetName = radioWidgets[i];
//            const gphoto2pp::RadioWidget widget = config.getChildByName<gphoto2pp::RadioWidget>(widgetName);
//
//            std::stringstream ss;
//            for(size_t k = 0; k < widget.getChoices().size(); k++) {
//                ss << widget.getChoices()[i];
//                if(k != widget.getChoices().size() - 1) {
//                    ss << ", ";
//                }
//            }
//            std::cout << widget.getName() << " : " << widget.getValue() << " | " << ss.str() << std::endl;
//        }
//        std::vector<std::string> rangeWidgets = gphoto2pp::helper::getAllWidgetsNamesOfType(config, gphoto2pp::CameraWidgetTypeWrapper::Range, false);
//        for(size_t i = 0; i < rangeWidgets.size(); i++) {
//            const std::string widgetName = rangeWidgets[i];
//            const gphoto2pp::RangeWidget widget = config.getChildByName<gphoto2pp::RangeWidget>(widgetName);
//
//            const auto ranges = widget.getRange();
//            std::cout << widget.getName() << " : " << widget.getValue() << " | " << ranges.Min << " - " << ranges.Max << std::endl;
//        }
//        std::vector<std::string> toggleWidgets = gphoto2pp::helper::getAllWidgetsNamesOfType(config, gphoto2pp::CameraWidgetTypeWrapper::Toggle, false);
//        for(size_t i = 0; i < toggleWidgets.size(); i++) {
//            const std::string widgetName = toggleWidgets[i];
//            const gphoto2pp::ToggleWidget widget = config.getChildByName<gphoto2pp::ToggleWidget>(widgetName);
//            std::cout << widget.getName() << " : " << widget.getValue() << std::endl;
//        }
//        std::stringstream ss;
//
//        for(size_t k = 0; k < autoFocusDriveWidget.countChoices(); k++) {
//            ss <<         autoFocusDriveWidget.getChoices()[k];
//            if(k != autoFocusDriveWidget.countChoices() -1) {
//                ss << ", ";
//            }
//        }
//        viewFinder.setValue(1);
//        focusMode2.setValue("MF (selection)");
//        liveViewAFFocus.setValue("Single-servo AF");}
        this->UpdateWidgets();
    }
}

void CameraController::UpdateWidgets() {
//    static auto viewFinder =  config.getChildByName<gphoto2pp::ToggleWidget>("viewfinder");
//    static auto liveViewAFFocus = config.getChildByName<gphoto2pp::RadioWidget>("liveviewaffocus");
//    static auto focusMode2 = config.getChildByName<gphoto2pp::StringWidget>("focusmode2");
}

void CameraController::TakePicture(const std::string &fileName) {
    this->Focus();
    try {
        gphoto2pp::CameraFileWrapper fileWrapper;
        gphoto2pp::helper::capture(cameraWrapper, fileWrapper);
        fileWrapper.save(fileName);
    } catch(std::exception ex) {}
}

void CameraController::Focus() {
    try {
        auto config = cameraWrapper.getConfig();
        static auto autofocusdrive = config.getChildByName<gphoto2pp::ToggleWidget>("autofocusdrive");
        autofocusdrive.setValue(1);
        cameraWrapper.setConfig(config);
    } catch (std::exception ex) {}
}

gphoto2pp::CameraFileWrapper CameraController::getViewfinderPreviewStream() {
    return this->cameraWrapper.capturePreview();
}

template <typename T>
void CameraController::registerWidget(const std::string &name, T type) {
    if(this->widgetCache.find(name) == this->widgetCache.end()) {
        this->widgetCache[name] = &this->cameraWrapper.getConfig().getChildByName<type>(name);
    }
}

template <typename T>
void CameraController::getWidgetByName(const std::string &name, T &pWidgetWrapper) {
    pWidgetWrapper = *((T)this->widgetCache[name]);
}

bool CameraController::IsLiveViewAllowed() {
    auto config = cameraWrapper.getConfig();
    auto widget = config.getChildByName<gphoto2pp::TextWidget>("liveviewprohibit");
    const auto widgetValue = widget.getValue();
    return widgetValue.find(" not be ") != std::string::npos;
}
