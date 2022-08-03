//
// Created by jona on 7/9/22.
//

#ifndef PHOTOBOOTH_TEXTURE_H
#define PHOTOBOOTH_TEXTURE_H

#include <string>
#include <gphoto2pp/camera_file_wrapper.hpp>

class Texture {

    void prepareTexture();

public:
    unsigned int m_RenderID;
    std::string m_FilePath;
    int m_Width, m_Height, m_BPP;

    Texture(const std::string &path);
    Texture(const gphoto2pp::CameraFileWrapper &cameraFileWrapper);
    ~Texture();

    void bind(int texId = 0);
    void unbind();

};


#endif //PHOTOBOOTH_TEXTURE_H
