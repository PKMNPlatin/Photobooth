//
// Created by jona on 7/15/22.
//

#include "ImageView.h"
#include "ImageGallery.h"

void ImageGallery::initialize() {
    this->_updateGalleryCache();
}

void ImageGallery::update(int windowSize[2]) {
    this->view->update(windowSize);
}

void ImageGallery::render() {
    if(this->isActive()) {
        this->view->render();
    }
}

void ImageGallery::nextImage() {
    this->offset++;
    const int maxLength = this->imageCache_.size() - 1;
    if(this->offset > maxLength) {
        this->offset = maxLength;
    }
    this->_updateImage();
}

void ImageGallery::previousImage() {
    this->offset--;
    if(this->offset < 0) {
        this->offset = 0;
        this->close();
    }
    this->_updateImage();
}

void ImageGallery::_updateImage() {
    const int localOffset = (this->imageCache_.size() - 1) - this->offset;
    this->view->setTexture(this->imageCache_[localOffset]);
}

void ImageGallery::close() {
    this->state = false;
}

void ImageGallery::open() {
    this->offset = 0;
    _updateImage();
    this->state = true;
}

void ImageGallery::_updateGalleryCache() {
    this->imageCache_.clear();
    for(auto const & dir_entry : std::filesystem::directory_iterator(this->rootPath)) {
        this->imageCache_.push_back(std::make_shared<Texture>(absolute(dir_entry.path())));
    }
}

const std::string &ImageGallery::getRootPath() {
    return this->rootPath;
}

ImageGallery::ImageGallery(std::string rootPath_, Window &window_) : rootPath(std::move(rootPath_)), window(window_) {
    this->view = new ImageView(window_);
}

ImageGallery::~ImageGallery() {
    delete this->view;
}

void ImageGallery::addImageToGallery(const std::string & path) {
    this->imageCache_.push_back(std::make_shared<Texture>(path));
}