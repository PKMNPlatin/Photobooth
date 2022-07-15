//
// Created by jona on 7/15/22.
//

#ifndef PHOTOBOOTH_IMAGEVIEW_H
#define PHOTOBOOTH_IMAGEVIEW_H

#include "Window.h"
#include "Texture.h"

#include "gphoto2pp/camera_file_wrapper.hpp"

class ImageView {

    Window window;
    Texture* texture = nullptr;
    int windowSize[2]{0, 0};

public:

    explicit ImageView(const Window &window_);
    ~ImageView();

    void update(const int windowSize[2]);
    void render();
    void setImage(const std::string filePath);
    void setImage(const gphoto2pp::CameraFileWrapper &fileWrapper);

};


#endif //PHOTOBOOTH_IMAGEVIEW_H
