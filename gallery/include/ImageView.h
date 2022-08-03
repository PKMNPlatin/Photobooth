//
// Created by jona on 7/15/22.
//

#ifndef PHOTOBOOTH_IMAGEVIEW_H
#define PHOTOBOOTH_IMAGEVIEW_H

#include "Window.h"
#include "Texture.h"

#include "gphoto2pp/camera_file_wrapper.hpp"

#include <memory>

class ImageView {

    Window window;
    int windowSize[2]{0, 0};

    int x, y = 0;

public:
    std::shared_ptr<Texture> texture = nullptr;

    ImageView(const Window &window_);

    void update(const int windowSize[2]);
    void render();
    void setImage(const std::string &filePath);
    void setImage(const gphoto2pp::CameraFileWrapper &fileWrapper);
    void setTexture(std::shared_ptr<Texture> _texture);

    void setX(int x);
    void setY(int y);
    int getX();
    int getY();

};


#endif //PHOTOBOOTH_IMAGEVIEW_H
