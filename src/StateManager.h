#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include "Battery.h"

enum ChargerState
{
    IDLE,
    CHARGING,
    FAULT,
    CHECKING_BATTERY,
};

class StateManager
{
private:
    ChargerState currentState;
    Battery &battery;
    void finishLoding();
    void doChecks();

public:
    StateManager(Battery &batteryInstance);
    void startLoading();
    ChargerState getState() const;
};

#endif // STATEMANAGER_H