//
// Created by jona on 7/15/22.
//


#include "ImageView.h"

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
        glVertex2d(this->x, this->y);
        glTexCoord2d(0, 1);
        glVertex2d(this->x, this->y + windowSize[1]);
        glTexCoord2d(1, 1);
        glVertex2d(this->x + windowSize[0], this->y + windowSize[1]);
        glTexCoord2d(1, 0);
        glVertex2d(this->x + windowSize[0], this->y);
        glEnd();
        this->texture->unbind();
    }
}

void ImageView::setImage(const std::string &filePath) {
    this->texture = std::make_shared<Texture>(filePath);
}

void ImageView::setImage(const gphoto2pp::CameraFileWrapper &fileWrapper) {
    this->texture = std::make_shared<Texture>(fileWrapper);
}

void ImageView::setTexture(std::shared_ptr<Texture> _texture) {
    this->texture = _texture;
}

ImageView::ImageView(const Window &window_) : window(window_) {}

void ImageView::setX(int x) {
    this->x = x;
}

void ImageView::setY(int y) {
    this->y = y;
}

int ImageView::getX() {
    return this->x;
}

int ImageView::getY() {
    return this->y;
}

