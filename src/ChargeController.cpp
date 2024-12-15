#include "ChargeController.h"

ChargeController::ChargeController(Battery &batteryInstance) : battery(batteryInstance), currentState(IDLE)
{
    this->currentState = IDLE;
}

void ChargeController::loadNewBattery()
{
    // Todo: Doing loading into the charger
    this->currentState = BATTERY_LOADING_IN;
}

void ChargeController::checkBatteryLoadStatus()
{
    this->currentState = BATTERY_LOADING_IN;
}

void ChargeController::ejectBatteryToTrashBin()
{
    this->currentState = IDLE;
}

void ChargeController::ejectBatteryToReadyBin()
{
    this->currentState = IDLE;
}

void ChargeController::doLoop()
{
    switch (this->currentState)
    {
    case IDLE:
        this->loadNewBattery();
        break;
    case BATTERY_LOADING_IN:
        // Check against load status
        this->checkBatteryLoadStatus();
        break;
    case BATTERY_LOADED_IN:
        // When battery is loaded in then start the charging process
        this->startCharging();
        break;
    case BATTERY_CHARGED:
        // Eject battery to ready bin
        this->ejectBatteryToReadyBin();
        break;
    case CHARGING:
        // Check if Battery is fully charged
        break;
    case FAULT:
        this->ejectBatteryToTrashBin();
        // Eject battery
        break;
    default:
        break;
    }
}

void ChargeController::startCharging()
{

    if (currentState == IDLE)
    {
        currentState = CHARGING;
    }
}

ChargerState ChargeController::getState() const
{
    return currentState;
}

void ChargeController::finishLoding()
{
    if (currentState == CHARGING)
    {
        currentState = IDLE;
    }
}

void ChargeController::doChecks()
{
    // Add logic to perform checks and possibly change state to FAULT
    if (this->battery.isBatteryOk() == false)
    {
        currentState = FAULT;
    }
}