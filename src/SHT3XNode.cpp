/*
 * SHT3XNode.cpp
 * Homie Node for SHT3X sensors using Adafruit SHT31 library.
 *
 * Version: 1.0
 * Author: Markus Haack (http://github.com/mhaack)
 */

#include "SHT3XNode.h"
#include <Homie.hpp>

HomieSetting<long> sensorIntervalSetting("sensorInterval", "The sensor reading interval in seconds");
HomieSetting<double> temperatureOffsetSetting("temperatureOffset", "The temperature offset in degrees");

SHT3XNode::SHT3XNode(const char *name) : HomieNode(name, "SHT3XSensor"), _lastMeasurement(0) {}

void SHT3XNode::setup() {
    advertise("temperature");
    advertise("temperature/unit");
    advertise("humidity");
    advertise("humidity/unit");

    // sensorIntervalSetting.setDefaultValue(30).setValidator([](long candidate) { return candidate >= 0; });
    // temperatureOffsetSetting.setDefaultValue(0).setValidator(
    //     [](long candidate) { return (candidate >= -10) && (candidate <= 10); });

    _measurementInterval = sensorIntervalSetting.get();
    _temperatureOffset = temperatureOffsetSetting.get();

    if (sht31.begin(0x45)) {
        _sensorFound = true;
        Homie.getLogger() << "SHT3X sensor found" << endl
                          << "Reading interval: " << _measurementInterval << " s" << endl
                          << "Temperature offset: " << _temperatureOffset << " °C" << endl;
    } else {
        _sensorFound = false;
        Homie.getLogger() << "SHT3X sensor not found. Check wiring!" << endl;
    }
}

void SHT3XNode::setupHandler() {
    setProperty("temperature/unit").send("°C");
    setProperty("humidity/unit").send("%");
};

void SHT3XNode::loop() {
    if (_sensorFound) {
        if (millis() - _lastMeasurement >= _measurementInterval * 1000UL || _lastMeasurement == 0) {
            temperature = sht31.readTemperature();
            humidity = sht31.readHumidity();

            Homie.getLogger() << "Temperature: " << temperature << " °C" << endl;
            temperature += temperatureOffsetSetting.get();
            Homie.getLogger() << "Temperature (after offset): " << temperature << " °C" << endl;
            Homie.getLogger() << "Humidity: " << humidity << " %" << endl;

            setProperty("temperature").send(String(temperature));
            setProperty("humidity").send(String(humidity));

            _lastMeasurement = millis();
        }
    }
}
