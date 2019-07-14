#include "controller.h"

//Definition
std::vector<std::unique_ptr<Controller>> Controller::controllers;
bool Controller::mainOn;

//CONSTRUCTOR
Controller::Controller(int id, const std::string &name, int pin, const std::vector<std::string> &notes, const time_t &whenCreated)
    : id(id), name(name), pin(pin), notes(notes), on(true), currentStateOn(false), test(false), whenCreated(whenCreated) {}

//GETTERS
std::string Controller::getName() const {
    return name;
}

int Controller::getPin() const {
    return pin;
}

bool Controller::isTesting() const {
    return test;
}

bool Controller::getCurrentState() const {
    return currentStateOn;
}

std::vector<std::string> Controller::getNotes() const{
    return notes;
}

// OTHER METHODS
void Controller::start() {
    while(mainOn) {
        for (auto &i : controllers) {
            i->run(); 
        }
    }
}

void Controller::deleteFromControllers(int controllerId) {
    std::vector<std::unique_ptr<Controller>>::iterator it = std::begin(controllers);
    while (it != std::end(controllers)) {
        if ((*it)->id == controllerId) {
            it = controllers.erase(it);
        } else {
            it++;
        }
    }
}

bool Controller::isAlreadyIn(int id) {
    for (auto &i : controllers) {
        if (i->id == id)
            return true;
        else 
            return false;
    }
}




