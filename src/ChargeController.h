#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include "Battery.h"

enum ChargerState
{
    IDLE,
    BATTERY_LOADING_IN,
    BATTERY_LOADED_IN,
    CHARGING,
    BATTERY_CHARGED,
    FAULT,
    CHECKING_BATTERY,
};

class ChargeController
{
private:
    ChargerState currentState;
    Battery &battery;
    DisplayController &displayController;
    void finishLoding();
    void doChecks();
    void loadNewBattery();
    void ejectBatteryToReadyBin();
    void ejectBatteryToTrashBin();
    void checkBatteryLoadStatus();

public:
    ChargeController(Battery &batteryInstance, DisplayController &displayController);
    void doLoop();
    void startCharging();
    ChargerState getState() const;
};

#endif // STATEMANAGER_H