# Arduino Kit
I created a remote control / automatic car out of an arduino car kit

NOTE: I used the Platform.io extension to create this project on VSCode, it's probably best to use that when running this.

[The Arduino kit I used](https://www.amazon.com/LAFVIN-Chassis-Ultrasonic-Compatible-Arduino/dp/B07YCHCQNK/ref=cm_cr_arp_d_pdt_img_top?ie=UTF8)

# Dependencies
[Arduino.h](https://www.arduino.cc/en/software) /
[Servo.h](https://github.com/arduino-libraries/Servo?utm_source=platformio&utm_medium=piohome) /
[Ultrasonic.h](https://github.com/ErickSimoes/Ultrasonic?utm_source=platformio&utm_medium=piohome) /
[IRremote.h](https://github.com/Arduino-IRremote/Arduino-IRremote?utm_source=platformio&utm_medium=piohome)

## How To Use
Once you turn on the battery pack, you use the IR controller to choose whether or not you want the remote or automatic mode enabled. **Asterick** key starts remote, **pound** key starts auto. Turn off Car and wait 2 seconds if you want to choose another mode.

### ---Remote mode---
Arrow buttons to choose direction, car continues to move on its own without having to hold the buttons, press ok to stop moving.
### ---Auto mode---
Car drives itself easy peasy. It has a radar attached to a servo so that if it gets close to a wall it will check its left and right and drive whichever direction has more distance from a wall.

# Video in Action
## [Arduino Car Kit](https://youtu.be/S2veobpOqNU)
