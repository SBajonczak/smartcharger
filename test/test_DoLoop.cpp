#include "unity.h"
#include "ChargeController.h"
#include "Battery.h"

void setUp(void)
{
}

void tearDown(void)
{
    // Clean up after each test
}

void test_doLoop_idleState(void)
{
    Battery battery(22, 31);
    ChargeController chargeController(battery);

    chargeController.doLoop();
    TEST_ASSERT_EQUAL(IDLE, chargeController.getState());
}

// void test_doLoop_batteryLoadingInState(void)
// {
//     Battery battery(22, 31);
//     ChargeController chargeController(battery);

//     chargeController.loadNewBattery();
//     chargeController.doLoop();
//     TEST_ASSERT_EQUAL(BATTERY_LOADING_IN, chargeController.getState());
// }

// void test_doLoop_batteryLoadedInState(void)
// {
//     Battery battery(22, 31);
//     ChargeController chargeController(battery);
//     chargeController->loadNewBattery();
//     chargeController->checkBatteryLoadStatus();
//     chargeController->doLoop();
//     TEST_ASSERT_EQUAL(BATTERY_LOADED_IN, chargeController->getState());
// }

// void test_doLoop_chargingState(void)
// {
//     chargeController->startCharging();
//     chargeController->doLoop();
//     TEST_ASSERT_EQUAL(CHARGING, chargeController->getState());
// }

// void test_doLoop_batteryChargedState(void)
// {
//     chargeController->startCharging();
//     chargeController->finishLoding();
//     chargeController->doLoop();
//     TEST_ASSERT_EQUAL(IDLE, chargeController->getState());
// }

int runUnityTests(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_doLoop_idleState);
    // RUN_TEST(test_doLoop_batteryLoadingInState);
    // RUN_TEST(test_doLoop_batteryLoadedInState);
    // RUN_TEST(test_doLoop_chargingState);
    // RUN_TEST(test_doLoop_batteryChargedState);
    return UNITY_END();
}

void setup()
{
    // Wait ~2 seconds before the Unity test runner
    // establishes connection with a board Serial interface
    delay(2000);

    runUnityTests();
}

void loop()
{
}