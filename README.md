# MajorProject
An Arduino project for home security system with the help of IOT (Internet of things).

# Overview
 Incidents like thefts, fire, and LPG gas leakage are very common these days. What is uncommon, is people’s awareness about different systems like smoke detectors, gas leakage detectors, etc. Installing all these different detectors in order to keep the house secured is also something that is difficult to maintain. Here, we have designed an integrated home security system that would help people secure their houses from such incidents. IOT based Home security system using Arduino project is designed to help an individual secure his/her house from theft, fire, and LPG gas leakage – all in one.

 This project uses four different sensors, from which data is sent over a website through IOT. The Internet of Things (IoT) is basically, the network of ‘things’ by which physical things can exchange data with the help of sensors, electronics, software, and connectivity. These systems do not require any human interaction.
 
 # Detailed description
  IOT and Arduino Based Home Security System uses four Sensors, namely, Temperature, Smoke, LPG and IR sensors. Data from these sensors is then sent to the Arduino, which has an inbuilt signal converter. Arduino then sends data over to the Wi-Fi module – ESP8266. ESP8266 is a chip used for connecting micro-controllers to the Wi-Fi network and make TCP/IP connections and send data. Data, which is sensed by these sensors, is then sent to the IOT.
   
  
  
# Block Diagram of the Project
 
![Screenshot (35)](https://user-images.githubusercontent.com/87115795/204463625-4663837d-3490-4cdb-a63f-06719335728c.png)

# Technical Specification
  The components that are used in the IOT and Arduino based Home Security system are:
- [IR sensor](https://robocraze.com/blogs/post/ir-sensor-interfacing-with-arduino)
- [Piezo Sensor](https://en.wikipedia.org/wiki/Piezoelectric_sensor)
- [PIR Sensor](https://www.tutorialspoint.com/arduino/arduino_pir_sensor.htm)
- [Sound Sensor](https://circuitdigest.com/microcontroller-projects/interfacing-sound-sensor-with-arduino)
- [LPG Sensor](https://www.rhydolabz.com/wiki/?p=3381)
- [Arduino Uno](https://en.wikipedia.org/wiki/Arduino_Uno)
- [LCD Display](https://www.electronicwings.com/arduino/lcd-16x2-interfacing-with-arduino-uno#:~:text=LCD%2016x2%20is%20a%2016,be%20used%20for%20control%20purposes.)
- [ESP8266- WiFi Module ](https://en.wikipedia.org/wiki/ESP8266)
- [Buzzer](https://robocraze.com/blogs/post/how-to-use-buzzer-with-arduino)
- [Keypad](https://www.electronicwings.com/arduino/4x4-keypad-interfacing-with-arduino-uno)

# Applications, Advantages & Future Development
- This device can be accessed wirelessly and to monitor our home or office. So, it’s very reliable and compatibility faster and secured.
- Security being the main intent of the project, the most important application of this system is any domestic security. By using this project, a person will be intimidated about any incident likely to be caused by fire, theft, LPG gas – REMOTELY.
- This project can be used at Restaurants, Industries, Manufacturing units, Banks, etc.
- The main advantage of this system is that it is fully automated. Once installed, it does not require any kind of human interaction. Also, it is very cost-effective.
- IOT and Arduino based Home Security System can be enhanced to identify fingerprints as opposed to a password using a keypad.
- Additionally, we can have a voice announcement system. It would send out vocal instructions regarding any of the four hazardous conditions detected by Smoke,      Temperature, IR and LPG gas sensors.
