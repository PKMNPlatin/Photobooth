//
// Created by jona on 7/5/22.
//

#include "iostream"

#include "GPIO.h"

//-------------------------------------------------------------------------------------
// GPIO Taster
//-------------------------------------------------------------------------------------

GPIOTaster::GPIOTaster(const std::string &buttonName, int pinId, int keyCode = -1) {
    this->buttonName = buttonName;
    this->pinId = pinId;
    this->keyCode = keyCode;
};

bool GPIOTaster::getInternalState(Window &window) {
    if(GPIO_Enabled) {
        return (digitalRead(this->getPinId()) == 1);
    } else {
        return glfwGetKey(window.getHandle(), this->getKeyCode()) == GLFW_TRUE;
    }
}

void GPIOTaster::updateButtonState(Window &window) {
    const bool internalState = getInternalState(window);
    if(internalState != this->buttonState && !waitForReset) {
        this->buttonState = internalState;
    }
    if(!internalState || waitForReset) {
        this->buttonState = false;
        this->waitForReset = internalState;
    }
}

std::string GPIOTaster::getName() {
    return this->buttonName;
}

int GPIOTaster::getButtonId() {
    if(GPIO_Enabled) {
        return this->getPinId();
    } else {
        return this->getKeyCode();
    }
}

int GPIOTaster::getPinId() {
    return this->pinId;
}

int GPIOTaster::getKeyCode() {
    return this->keyCode;
}

bool GPIOTaster::getState() {
    return this->buttonState;
}

void GPIOTaster::disableUntilReactivation() {
    this->waitForReset = true;
}

//-------------------------------------------------------------------------------------
// GPIO
//-------------------------------------------------------------------------------------

void GPIO::registerGPIOPins() {
    if(GPIO_Enabled) {
        wiringPiSetup();
    }
    this->taster.emplace_back( GPIOTaster("PREV", GPIO_PIN_PREV, GLFW_KEY_U));
    this->taster.emplace_back( GPIOTaster("PRINT", GPIO_PIN_PRINT, GLFW_KEY_I));
    this->taster.emplace_back( GPIOTaster("NEXT", GPIO_PIN_NEXT, GLFW_KEY_O));
    this->taster.emplace_back( GPIOTaster("CAPTURE", GPIO_PIN_CAPTURE, GLFW_KEY_P));
    for(size_t i = 0; i < this->taster.size(); i++) {
        GPIOTaster taster = this->taster[i];
        if(GPIO_Enabled) {
            pinMode(taster.getButtonId(), INPUT);
        }
        std::cout << "Initalized Pin " << taster.getButtonId() << " as "<< taster.getName() << std::endl;
    }
};

void GPIO::checkPinState(Window &window) {
    for (size_t i = 0; i < this->taster.size(); i++) {
        (&taster[i])->updateButtonState(window);
    }
};

std::vector<GPIOTaster>* GPIO::getRegisteredTaster() {
    return &this->taster;
}

GPIOTaster *GPIO::getTasterByName(const std::string &name) {
    for (size_t i = 0; i < this->taster.size(); i++) {
        GPIOTaster *pTaster = &this->taster[i];
        if (pTaster && pTaster->getName() == name) {
            return pTaster;
        }
    }
    return nullptr;
}

GPIOTaster *GPIO::getTasterByPin(int pin) {
    for (size_t i = 0; i < this->taster.size(); i++) {
        GPIOTaster *pTaster = &this->taster[i];
        if (pTaster && pTaster->getPinId() == pin) {
            return pTaster;
        }
    }
    return nullptr;
}

GPIOTaster *GPIO::getTasterByButtonId(int buttonId) {
    for (size_t i = 0; i < this->taster.size(); i++) {
        GPIOTaster *pTaster = &this->taster[i];
        if (pTaster && pTaster->getButtonId() == buttonId) {
            return pTaster;
        }
    }
    return nullptr;
}

GPIOTaster *GPIO::getTasterByKeyCode(int keyCode) {
    for (size_t i = 0; i < this->taster.size(); i++) {
        GPIOTaster *pTaster = &this->taster[i];
        if (pTaster && pTaster->getKeyCode() == keyCode) {
            return pTaster;
        }
    }
    return nullptr;
}