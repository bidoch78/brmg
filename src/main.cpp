//#define ACTIVATE_MUTEX 1

#include <Arduino.h>
#include <brmg_app.h>
#include <navigation_joystick.h>
#include <sensor_pot.h>

using namespace beaf::Navigation;

brmgApp app = brmgApp();

void setup() {

    Serial.begin(115200);

    //Initialize app
    app.setNavigationController(new NavigationJoystick(7, 6, 5, 200));

    app.addSensor(new SensorPot(SENSOR_WATERTEMP, 4, new valueConverterInterval(120), new valueConverterVoltage(3.3), 100));

    app.initialize();

}

uint32_t currentMS = 0;

void loop() {

    app.acquire();
    app.draw();

    uint32_t cur = millis();
    if (cur-currentMS > 2000) {
        Serial.println(app.getSensorRate());
        currentMS = cur;
    }


    // joy.read();

}