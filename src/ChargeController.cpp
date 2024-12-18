#include "ChargeController.h"
#include "DisplayController.h"

ChargeController::ChargeController(Battery &batteryInstance, DisplayController &displayController) : battery(batteryInstance),
                                                                                                     currentState(ChargerState::IDLE),
                                                                                                     displayController(displayController)
{
    this->currentState = ChargerState::IDLE;
}

void ChargeController::loadNewBattery()
{
    // Todo: Doing loading into the charger
    this->currentState = ChargerState::BATTERY_LOADING_IN;
}

void ChargeController::checkBatteryLoadStatus()
{
    this->currentState = ChargerState::BATTERY_LOADING_IN;
}

void ChargeController::ejectBatteryToTrashBin()
{
    this->currentState = ChargerState::IDLE;
}

void ChargeController::ejectBatteryToReadyBin()
{
    this->currentState = ChargerState::IDLE;
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
        currentState = ChargerState::CHARGING;
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
        currentState = ChargerState::IDLE;
    }
}

void ChargeController::doChecks()
{
    // Add logic to perform checks and possibly change state to FAULT
    if (this->battery.isBatteryOk() == false)
    {
        currentState = ChargerState::FAULT;
    }
}