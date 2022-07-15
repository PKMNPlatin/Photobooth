//
// Created by jona on 7/11/22.
//

#include <sstream>
#include "CameraController.h"

#include "iostream"

CameraController::CameraController() {
    std::cout << cameraWrapper.getModel() << std::endl;
}
CameraController::~CameraController() = default;

void CameraController::InitializeWidgets() {
    this->EnableAutoFocus();
}

void CameraController::TakePicture(const std::string &fileName) {
    this->EnableAutoFocus();
    try {
        gphoto2pp::CameraFileWrapper fileWrapper;
        gphoto2pp::helper::capture(cameraWrapper, fileWrapper);
        fileWrapper.save(fileName);
    } catch(std::exception ex) {}
}

void CameraController::EnableAutoFocus() {
    try {
        auto config = cameraWrapper.getConfig();
        auto autofocusdrive = config.getChildByName<gphoto2pp::ToggleWidget>("autofocusdrive");
        auto autofocus = config.getChildByName<gphoto2pp::ToggleWidget>("autofocus");
        autofocus.setValue(0);
        autofocusdrive.setValue(1);
        cameraWrapper.setConfig(config);
    } catch (std::exception ex) {}
}

gphoto2pp::CameraFileWrapper CameraController::getViewfinderPreviewStream() {
    return this->cameraWrapper.capturePreview();
}

bool CameraController::IsLiveViewAllowed() {
    auto config = cameraWrapper.getConfig();
    auto widget = config.getChildByName<gphoto2pp::TextWidget>("liveviewprohibit");
    const auto widgetValue = widget.getValue();
    return widgetValue.find(" not be ") != std::string::npos;
}
