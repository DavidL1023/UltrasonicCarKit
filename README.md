# Arduino Kit
I created a remote control / automatic car with arduino

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

https://github.com/DavidL1023/UltrasonicCarKit/assets/80372643/b4a6ad22-e755-45e3-bc25-b4828a27fcea

https://github.com/DavidL1023/UltrasonicCarKit/assets/80372643/04c87b62-c399-467d-9369-148e3fbd9a5c
