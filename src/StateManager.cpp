#include "StateManager.h"

StateManager::StateManager(Battery &batteryInstance) : battery(batteryInstance), currentState(IDLE)
{
    this->currentState = IDLE;
}

void StateManager::startLoading()
{
    
    if (currentState == IDLE)
    {
        currentState = CHARGING;
    }
}

ChargerState StateManager::getState() const
{
    return currentState;
}

void StateManager::finishLoding()
{
    if (currentState == CHARGING)
    {
        currentState = IDLE;
    }
}

void StateManager::doChecks()
{
    // Add logic to perform checks and possibly change state to FAULT
    if (this->battery.isBatteryOk() == false)
    {
        currentState = FAULT;
    }
}