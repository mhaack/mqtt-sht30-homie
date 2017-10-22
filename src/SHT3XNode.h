/*
 * SHT3XNode.h
 * Homie Node for SHT3X sensors using Adafruit SHT31 library.
 *
 * Version: 1.0
 * Author: Markus Haack (http://github.com/mhaack)
 */

#ifndef SRC_SHT3XNODE_H_
#define SRC_SHT3XNODE_H_

#include <Adafruit_SHT31.h>
#include <Wire.h>

#include <HomieNode.hpp>

class SHT3XNode : public HomieNode {
  private:
    bool _sensorFound = false;
    unsigned long _measurementInterval = 300;
    unsigned long _lastMeasurement;
    float _temperatureOffset = 0.0f;

    Adafruit_SHT31 sht31 = Adafruit_SHT31();

  public:
    SHT3XNode(const char *name);
    void setupHandler();

    float getHumidity() const { return humidity; }
    float getTemperature() const { return temperature; }

  protected:
    virtual void setup() override;
    virtual void loop() override;

  private:
    float temperature = NAN;
    float humidity = NAN;
};

#endif
