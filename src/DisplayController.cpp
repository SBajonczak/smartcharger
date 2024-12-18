#include "DisplayController.h"

DisplayController::DisplayController() : currentState(IDLE) {}

void DisplayController::isLoading() {
    if (currentState == IDLE) {
        currentState = BATTERY_LOADING_IN;
    }
}

void DisplayController::isCharging() {
    if (currentState == BATTERY_LOADED_IN) {
        currentState = CHARGING;
    }
}

void DisplayController::finished() {
    if (currentState == CHARGING) {
        currentState = BATTERY_CHARGED;
    }
}

DisplayState DisplayController::getState() const {
    return currentState;
}