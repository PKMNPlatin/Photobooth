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
        const int currentDigitalState = digitalRead(this->getButtonId()) == 1;
        if(currentDigitalState != this->buttonState) {
            this->buttonState = currentDigitalState;
            std::cout << "Pressed button " << this->buttonName << std::endl;
        }
    }

    const std::string GPIOTaster::getName() {
        return this->buttonName;
    }

    const int GPIOTaster::getButtonId() {
        return this->buttonId;
    }

    //-------------------------------------------------------------------------------------
    // GPIO
    //-------------------------------------------------------------------------------------

    void GPIO::registerGPIOPins() {
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
    };

    void GPIO::checkPinState() {
        for(size_t i = 0; i < this->taster.size(); i++) {
            GPIOTaster taster = this->taster[i];
            taster.updateButtonState();
        }
    };

} // photobooth