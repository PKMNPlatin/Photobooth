//
// Created by jona on 7/11/22.
//

#ifndef PHOTOBOOTH_CAMERACONTROLLER_H
#define PHOTOBOOTH_CAMERACONTROLLER_H

#include "gphoto2pp/helper_gphoto2.hpp"
#include "gphoto2pp/helper_camera_wrapper.hpp"
#include "gphoto2pp/helper_widgets.hpp"

#include "gphoto2pp/camera_wrapper.hpp"
#include "gphoto2pp/camera_file_wrapper.hpp"
#include "gphoto2pp/camera_capture_type_wrapper.hpp"

#include "gphoto2pp/window_widget.hpp"
#include "gphoto2pp/range_widget.hpp"
#include "gphoto2pp/text_widget.hpp"
#include "gphoto2pp/section_widget.hpp"
#include "gphoto2pp/choices_widget.hpp"
#include "gphoto2pp/menu_widget.hpp"
#include "gphoto2pp/toggle_widget.hpp"
#include "gphoto2pp/radio_widget.hpp"
#include "gphoto2pp/camera_widget_type_wrapper.hpp"

#include "gphoto2pp/range_widget_range.hpp"

class CameraController {

    std::map<std::string, gphoto2pp::CameraWidgetWrapper*> widgetCache;
    gphoto2pp::CameraWrapper cameraWrapper;

public:

    CameraController();
    ~CameraController();

    void InitializeWidgets();
    void UpdateWidgets();

    void TakePicture(const std::string &fileName);
    void EnableAutoFocus();
    bool IsLiveViewAllowed();
    gphoto2pp::CameraFileWrapper getViewfinderPreviewStream();


    template <typename T>
    void registerWidget(const std::string &name, T type);

    template <typename T>
    void getWidgetByName(const std::string &name, T &pWidgetWrapper);

};


#endif //PHOTOBOOTH_CAMERACONTROLLER_H
