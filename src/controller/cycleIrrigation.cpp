#include "cycleIrrigation.h"

CycleIrrigation::CycleIrrigation(int id, const std::string &name, int pin, const std::vector<std::string> &notes, 
const time_t &whenCreated, time_t cycleOnTime, time_t cycleOffTime, time_t blackoutStartTime, 
        time_t blackoutStopTime) 
    : Controller(id, name, pin, notes, whenCreated), cycleOnTime(cycleOnTime), cycleOffTime(cycleOffTime),
    blackoutStartTime(blackoutStartTime), blackoutStopTime(blackoutStopTime)
{}