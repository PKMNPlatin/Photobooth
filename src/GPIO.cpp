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
        this->prevButtonState = this->buttonState;
        this->buttonState = currentDigitalState;
        if(this->buttonState != this->prevButtonState) {
            this->prevButtonState = this->buttonState;
            if(this->buttonState) {
                std::cout << "Pressed " << this->getName() << "!" << std::endl;
            } else {
                std::cout << "Released " << this->getName() << "!" << std::endl;
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
        this->taster.emplace_back(GPIOTaster("TEst", 4));
        std::cout <<         this->getTasterByPin(4)->getName() << std::endl;
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