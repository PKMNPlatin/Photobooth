#include "Photobooth.h"

int main(int argc, char *argv[]) {
    Photobooth photobooth;
    photobooth.runLoop();
    return photobooth.getShutdownStatusCode();
}

//cameraFile.save("my-gphoto2pp-test.jpg");
