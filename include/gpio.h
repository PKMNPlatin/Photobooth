//
// Created by jona on 7/5/22.
//

#ifndef PHOTOBOOTH_GPIO_H
#define PHOTOBOOTH_GPIO_H

#include <wiringPi.h>

#define GPIO_PIN_PREV 2
#define GPIO_PIN_PRINT 3
#define GPIO_PIN_NEXT 4
#define GPIO_PIN_CAPTURE 5

namespace photobooth {

    class gpio {

    public:
        void setupGPIOPins();
        void readCurrentState();

    };

} // photobo

#endif //PHOTOBOOTH_GPIO_H
