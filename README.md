# ~Anton Arduino Kits
I created a remote control / automatic car out of an arduino car kit Anton gave me. Working with robots was fun, and seeing it come to life is cool. Learned lots about C++, the language isn't very different from what I've worked with before. I also had an Arduino crane but it's construction was not perfect so the servos burned out, rip.

NOTE: I used the Platform.io extension to create this project on VSCode, it's probably best to use that when running this.

# Dependencies
[Arduino.h](https://www.arduino.cc/en/software) /
[Servo.h](https://github.com/arduino-libraries/Servo?utm_source=platformio&utm_medium=piohome) /
[Ultrasonic.h](https://github.com/ErickSimoes/Ultrasonic?utm_source=platformio&utm_medium=piohome) /
[IRremote.h](https://github.com/Arduino-IRremote/Arduino-IRremote?utm_source=platformio&utm_medium=piohome)

## How To Use
Once you turn on the battery pack, you may use the IR controller to choose whether or not you want the remote or automatic mode enabled. **Asterick** key stars remote, **pound** key starts auto. Turn off Car and wait 2 seconds if you want to choose another mode.

### ---Remote mode---
Arrow buttons to choose direction, car continues to move on its own without having to hold the buttons, press ok to stop moving.
### ---Auto mode---
Car drives itself easy peasy. It has a radar attached to a servo so that if it gets close to a wall it will check its left and right and drive whichever direction has more distance from a wall.

# Video in Action
## [Arduino Car Kit](https://youtu.be/S2veobpOqNU)
