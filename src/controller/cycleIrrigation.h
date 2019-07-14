#pragma once

#include <ctime>
#include <string>

#include "controller.h"

class CycleIrrigation : public Controller {
    private:
        time_t cycleOnTime; // amount of time on in hours : minutes : seconds
        time_t cycleOffTime; // amount of time off in hourse : minutes : seconds

        time_t blackoutStartTime; // blackout window for the timer to shut off. Usually
        time_t blackoutStopTime;  // used for turning off at night for plant propogation
    public:
        CycleIrrigation(int id, const std::string &name, int pin, const std::vector<std::string> &notes, 
        const time_t &whenCreated, time_t cycleOnTime, time_t cycleOffTime, time_t blackoutStartTime, 
        time_t blackoutStopTime);
};