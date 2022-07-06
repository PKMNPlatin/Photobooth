//
// Created by jona on 7/5/22.
//

#include "iostream"

#include "GPIO.h"

namespace photobooth {

    //-------------------------------------------------------------------------------------
    // GPIO Taster
    //-------------------------------------------------------------------------------------

    GPIOTaster::GPIOTaster(const std::string &buttonName, int buttonId) {
        this->buttonName = buttonName;
        this->buttonId = buttonId;
    };

    void GPIOTaster::updateButtonState() {
        const bool currentDigitalState = digitalRead(this->getButtonId()) == 1;
        if (prevButtonState != currentDigitalState) {
            buttonState = currentDigitalState;
            if (prevButtonState != currentDigitalState) {
                prevButtonState = buttonState;
//                std::cout << "Pressed " << this->getName() << std::endl;
            }
        }
    }

    std::string GPIOTaster::getName() {
        return this->buttonName;
    }

    int GPIOTaster::getButtonId() {
        return this->buttonId;
    }


    bool GPIOTaster::getState() {
        return this->buttonState;
    }

    //-------------------------------------------------------------------------------------
    // GPIO
    //-------------------------------------------------------------------------------------

    void GPIO::registerGPIOPins() {
#ifdef ADD_GPIO_SUPPORT
        wiringPiSetup();
        this->taster.emplace_back(GPIOTaster("PREV", 2));
        this->taster.emplace_back( GPIOTaster("PRINT", 3));
        this->taster.emplace_back( GPIOTaster("NEXT", 4));
        this->taster.emplace_back( GPIOTaster("CAPTURE", 5));
        for(size_t i = 0; i < this->taster.size(); i++) {
            GPIOTaster taster = this->taster[i];
            pinMode(taster.getButtonId(), INPUT);
            std::cout << "Initalized Pin " << taster.getButtonId() << " as "<< taster.getName() << std::endl;
        }
#endif
    };

    void GPIO::checkPinState() {
        for (size_t i = 0; i < this->taster.size(); i++) {
            GPIOTaster taster = this->taster[i];
            taster.updateButtonState();
        }
    };

    GPIOTaster *GPIO::getTasterByName(const std::string &name) {
        for (size_t i = 0; i < this->taster.size(); i++) {
            GPIOTaster *taster = &this->taster[i];
            if (taster->getName() == name) {
                return taster;
            }
        }
        return nullptr;
    }

    GPIOTaster *GPIO::getTasterByPin(int pin) {
        for (size_t i = 0; i < this->taster.size(); i++) {
            GPIOTaster *taster = &this->taster[i];
            if (taster->getButtonId() == pin) {
                return taster;
            }
        }
        return nullptr;
    }

} // photobooth