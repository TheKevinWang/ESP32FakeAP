# ESP32FakeAP
Fake Wifi AP using ESP32 and ESPAsyncWebServer for static payload hosting. 

#Arduino IDE installation

Download and unzip the following into your arduino libraries directory (~/Documents/Arduino/libraries by default on windows; mkdir if not exit):

https://github.com/me-no-dev/ESPAsyncWebServer

https://github.com/me-no-dev/AsyncTCP

Then install this:

https://github.com/me-no-dev/arduino-esp32fs-plugin

Make sure to hit Tools->ESP32 Sketch Data Upload after uploading firmware to upload the static web files.

![phishing example](https://github.com/TheKevinWang/ESP32FakeAP/raw/main/FakeAP/FakeAPExample.png)

The example phishing payload is for a Broadcom firmware update based on (wifiphisher)[https://github.com/wifiphisher/wifiphisher]'s fake router configuration page. Replace the "hello world" data/broadcom-wifi-3.0.12.i586.exe with your payload.


