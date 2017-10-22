/*
 * mqtt-sht3x-sensor.cpp
 *
 * Version: 1.0.0
 * Author: Markus Haack (http://github.com/mhaack)
 */

#include <Homie.h>

#include "SHT3XNode.h"

// init Homie nodes
SHT3XNode sht3xNode("sensor");

void setupHandler() { sht3xNode.setupHandler(); }

void setup() {
    Serial.begin(115200);
    Serial << endl << endl;

    Homie_setFirmware("mqtt-sht3x-sensor", "1.0.0");
    Homie.disableResetTrigger();
    // Homie.disableLedFeedback();
    Homie.setLoggingPrinter(&Serial);
    Homie.setSetupFunction(setupHandler);
    Homie.setup();
}

void loop() { Homie.loop(); }
