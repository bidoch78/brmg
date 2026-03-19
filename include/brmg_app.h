#pragma once

#include <app.h>

using namespace beaf::Core;

const uint32_t SENSOR_WATERTEMP = 1;
const uint32_t SENSOR_TRANNY_OILTEMP = 2;

class brmgApp: public App {
    
    public:
        brmgApp();
        ~brmgApp();

};