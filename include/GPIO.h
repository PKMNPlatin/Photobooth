//
// Created by jona on 7/5/22.
//

#ifndef PHOTOBOOTH_GPIO_H
#define PHOTOBOOTH_GPIO_H

#include "vector"
#include "iostream"
#include <wiringPi.h>

#define GPIO_PIN_PREV 2
#define GPIO_PIN_PRINT 3
#define GPIO_PIN_NEXT 4
#define GPIO_PIN_CAPTURE 5

namespace photobooth {

    class GPIOTaster {

        std::string buttonName;
        int buttonId;
        bool buttonState = false;
        bool prevButtonState = false;

    public:

        GPIOTaster(const std::string &buttonName, int buttonId);

        void updateButtonState();

        const std::string getName();
        const int getButtonId();

    };

    class GPIO {

        std::vector<GPIOTaster> taster;

    public:
        void registerGPIOPins();
        void checkPinState();

    };

} // photobo

#endif //PHOTOBOOTH_GPIO_H
