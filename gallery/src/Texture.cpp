//
// Created by jona on 7/9/22.
//

#include "Texture.h"
#include "stb_image.h"
#include "Window.h"

Texture::~Texture() {
    glDeleteTextures(1, &m_RenderID);
}

void Texture::bind(int texId /* = 0 */) {
    glEnable(GL_TEXTURE_2D);
    glActiveTexture(GL_TEXTURE0 + texId);
    glBindTexture(GL_TEXTURE_2D, m_RenderID);
}

void Texture::unbind() {
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);
}

Texture::Texture(const std::string &filePath) : m_RenderID(0), m_FilePath(filePath), m_Width(0), m_Height(0), m_BPP(0) {
    stbi_set_flip_vertically_on_load(0);
    auto m_LocalBuffer = stbi_load(filePath.c_str(), &m_Width, &m_Height, &m_BPP, 4);

    glGenTextures(1, &m_RenderID);
    glBindTexture(GL_TEXTURE_2D, m_RenderID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_LocalBuffer);
    glBindTexture(GL_TEXTURE_2D, 0);

    if(m_LocalBuffer) {
        stbi_image_free(m_LocalBuffer);
    }
}

Texture::Texture(const gphoto2pp::CameraFileWrapper &cameraFileWrapper) : m_RenderID(0), m_FilePath(""), m_Width(0), m_Height(0), m_BPP(0) {
    stbi_set_flip_vertically_on_load(0);
    auto m_LocalBuffer = stbi_load_from_memory(reinterpret_cast<unsigned char*>(cameraFileWrapper.getDataAndSize().data()), cameraFileWrapper.getDataAndSize().size(), &m_Width, &m_Height, &m_BPP, 4);

    this->prepareTexture();

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_LocalBuffer);
    glBindTexture(GL_TEXTURE_2D, 0);

    if(m_LocalBuffer) {
        stbi_image_free(m_LocalBuffer);
    }
}

void Texture::prepareTexture() {
    glGenTextures(1, &m_RenderID);
    glBindTexture(GL_TEXTURE_2D, m_RenderID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
}
