//
// Created by jona on 7/5/22.
//

#ifndef PHOTOBOOTH_GPIO_H
#define PHOTOBOOTH_GPIO_H

#include "vector"
#include "iostream"
#include <wiringPi.h>
#include "Window.h"

#define GPIO_PIN_PREV 2
#define GPIO_PIN_PRINT 3
#define GPIO_PIN_NEXT 4
#define GPIO_PIN_CAPTURE 5

static bool GPIO_Enabled = false;

#ifdef ADD_GPIO_SUPPORT
    GPIO_Enabled = true;
#endif

namespace photobooth {

    class GPIOTaster {

        std::string buttonName;

        // GPIO Pin
        int pinId;

        // Corresponding KeyCode
        int keyCode;

        bool buttonState = false;
        bool waitForReset = false;

        bool getInternalState(Window &window);

    public:

        GPIOTaster(const std::string &buttonName, int pinId, int keyCode);

        void updateButtonState(Window &window);

        std::string getName();

        int getButtonId();
        int getKeyCode();
        int getPinId();

        bool getState();
        void disableUntilReactivation();

    };

    class GPIO {

        std::vector<GPIOTaster> taster;

    public:
        void registerGPIOPins();

        void checkPinState(Window &window);

        std::vector<GPIOTaster>* getRegisteredTaster();

        GPIOTaster *getTasterById(int id);

        GPIOTaster *getTasterByPin(int pin);

        GPIOTaster *getTasterByKeyCode(int keyCode);

        GPIOTaster *getTasterByButtonId(int buttonId);

        GPIOTaster *getTasterByName(const std::string &name);

    };

} // photobo

#endif //PHOTOBOOTH_GPIO_H
