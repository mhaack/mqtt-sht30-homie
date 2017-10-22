# Homie Sensor project with SHT30  

[![Build Status](https://img.shields.io/travis/mhaack/mqtt-sht30-homie.svg?style=flat-square)](https://travis-ci.org/mhaack/mqtt-sht30-homie)
[![GitHub release](https://img.shields.io/github/release/mhaack/mqtt-sht30-homie.svg?style=flat-square)](https://github.com/mhaack/mqtt-sht30-homie/releases)

The mqtt-sht30-homie project is a simple and easy to integrate temperature and humidity sensor setup similar to my other project with [BME280 sensor](https://github.com/mhaack/mqtt-bme280-homie). I use this sensor in a hidden area, therefor it has no display. Sensor data is send via MQTT and processed by my OpenHab setup. The project is built with a cost-effective ESP8266 WiFi chip, Wemos D1 mine and sensor are available for a total price lower $10.

The software is based on [Homie](https://github.com/marvinroger/homie-esp8266) to enable an easy integration with home automation systems like [OpenHab](http://www.openhab.org).

## Hardware

- ESP8266 (Wemos D1 mini, Nodemcu)
- SHT30 sensor breakout
- USB power supply and cable
- Enclosure

I got the SHT30 breakout form [Wemos](https://wiki.wemos.cc/products:d1_mini_shields:sht30_shield) as part of a set form Aliexpress, others will do as well. This [enclosure](https://www.amazon.de/gp/product/B00PZYMLJ4) keeps everything together.

## Software

The following software libraries are used. If using PlatformIO all dependencies are resolved automatically.

- [Homie V2](https://github.com/marvinroger/homie-esp8266) (dev) including dependencies
- [Adafruit SHT31 Driver](https://github.com/adafruit/Adafruit_SHT31)
- Optionally PlatformIO environment for building the code

## Config

The following config parameters are available via MQTT message (see Homie documentation how to use):

Parameter           | Type        | Usage
------------------- | ----------- | -------
sensorInterval      | long        | temperature reading interval in seconds
temperatureOffset   | double      | temperature offset (-/+) to correct the sensor reading, for example if used in enclosure box
