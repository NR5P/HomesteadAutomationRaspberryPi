#pragma once

#include<vector>
#include<memory>
#include<string>
#include <ctime>


/*
base class for each automation timer(component)
 */
class Controller {
    private:
        static std::vector<std::unique_ptr<Controller>> controllers;
        int id; // database id of component
        std::string name;
        int pin; // raspberry pi gpio pin number
        static bool mainOn; // if all are on or off
        bool on; // this is for individual controllers on or off
        bool test; // for testing, if on the controller turns on
        bool currentStateOn; // the actual current state of the controller
        const time_t whenCreated;
        std::vector<std::string> notes;

    public:
        Controller(int id, const std::string &name, int pin, const std::vector<std::string> &notes, const time_t &whenCreated);

        // GETTERS
        std::string getName() const;
        int getPin() const;
        bool isTesting() const;
        bool getCurrentState() const;
        std::vector<std::string> getNotes() const;

        // OTHER METHODS

        /*
        Starts the looping through each component and calls run on each component
        */
        static void start();

        /* 
        if deleted in database this will be called and the controller will be deleted
        by id
        */
        static void deleteFromControllers(const int controllerId);

        /*
        this will be called on all controllers. It will initialize the checking of sensors 
        and timers in each controller
        */
        virtual void run()=0;

        /*
        checks to see if the entry is already a controller in the vector 
        */
        static bool isAlreadyIn(int id);
};