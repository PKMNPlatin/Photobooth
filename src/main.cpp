#include <gphoto2/gphoto2.h>
#include <iostream>
#include "GPIO.h"

static void onGPhotoError(GPLogLevel level, const char *domain, const char *str, void* data) {
    fprintf(stdout, "%s\n", str);
}

int main(int argc, char* argv[]) {
    int retVal;
    Camera *pCamera;
    GPContext *pGpContext = gp_context_new();

    gp_camera_new(&pCamera);
    printf("Camera initializing...\n");

    retVal = gp_camera_init(pCamera, pGpContext);
    if(retVal != GP_OK) {
        std::cout << "Error while initializing the camera. Exiting..." << std::endl;
        exit(1);
    }

    std::cout << "Successfully initialized a camera!" << std::endl;


    photobooth::GPIO GPIO;
    GPIO.registerGPIOPins();
    while(true) {
        GPIO.checkPinState();
    }
    gp_camera_exit(pCamera, pGpContext);
    return 0;
}

//cameraFile.save("my-gphoto2pp-test.jpg");
