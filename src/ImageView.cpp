//
// Created by jona on 7/15/22.
//

#include "ImageView.h"

ImageView::ImageView(const Window &window_) : window(window_) {

}

ImageView::~ImageView() {
    delete this->texture;
}

void ImageView::update(const int windowSize_[2]) {
    for(short i = 0; i < 2; i++) {
        this->windowSize[i] = windowSize_[i];
    }
}

void ImageView::render() {
    if(this->texture) {
        this->texture->bind();
        glBegin(GL_QUADS);
        glTexCoord2d(0, 0);
        glVertex2d(0, 0);
        glTexCoord2d(0, 1);
        glVertex2d(0, windowSize[1]);
        glTexCoord2d(1, 1);
        glVertex2d(windowSize[0], windowSize[1]);
        glTexCoord2d(1, 0);
        glVertex2d(windowSize[0], 0);
        glEnd();
        this->texture->unbind();
    }
}

void ImageView::setImage(const std::string filePath) {
    delete this->texture;
    this->texture = new Texture(filePath);
}

void ImageView::setImage(const gphoto2pp::CameraFileWrapper &fileWrapper) {
    delete this->texture;
    this->texture = new Texture(fileWrapper);
}


