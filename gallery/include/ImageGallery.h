//pmr
// Created by jona on 7/15/22.
//

#ifndef PHOTOBOOTH_IMAGEGALLERY_H
#define PHOTOBOOTH_IMAGEGALLERY_H

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <filesystem>

#include "Window.h"
#include "Texture.h"

class ImageView;

class ImageGallery {

    Window &window;
    std::string rootPath;
    ImageView* view;
    bool state = false;
    int offset = 0;
    std::vector<std::shared_ptr<Texture>> imageCache_;

    void _updateImage();

public:
    void _updateGalleryCache();

    ImageGallery(std::string rootPath_, Window &window_);
    ~ImageGallery();

    void initialize();
    void update(int windowSize[2]);
    void render();

    void nextImage();
    void previousImage();
    void close();
    void open();
    void addImageToGallery(const std::string & path);

    const std::string & getRootPath();

    inline bool isActive() {
        return this->state;
    }

};


#endif //PHOTOBOOTH_IMAGEGALLERY_H
