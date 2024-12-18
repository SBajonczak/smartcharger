#ifndef DISPLAYCONTROLLER_H
#define DISPLAYCONTROLLER_H
enum DisplayState
{
    IDLE,
    BATTERY_LOADING_IN,
    BATTERY_LOADED_IN,
    CHARGING,
    BATTERY_CHARGED,
    FAULT,
    CHECKING_BATTERY,
};

class DisplayController
{
private:
    DisplayState currentState;

public:
    DisplayController();
    void isLoading();
    void isCharging();
    void finished();
    DisplayState getState() const;
};

#endif // DISPLAYCONTROLLER_H