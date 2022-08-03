//
// Created by jona on 7/15/22.
//

#ifndef PHOTOBOOTH_UTILS_H
#define PHOTOBOOTH_UTILS_H

#include "iostream"
#include "chrono"

using sysclock_t = std::chrono::system_clock;

inline std::string getDateString()
{
    std::time_t now = sysclock_t::to_time_t(sysclock_t::now());

    char buf[32] = { 0 };
    std::strftime(buf, sizeof(buf), "%Y-%m-%d_%H-%M-%S", std::localtime(&now));

    return std::string(buf);
}

#endif //PHOTOBOOTH_UTILS_H
