# Arduino Camera Dolly

## Introduction
A camera dolly is a commonly used piece of equipment for filmmaking and television production. When a camera is operated or carried by a person that is walking, the footage tends to be very shaky. The camera dolly was invented in 1907 to allow filmmakers to be able to capture smooth panoramic videos while the camera is moving locations and panning. There are many different iterations of this device, all of which have a camera mount or a built in camera, and wheels or tracks. The camera dolly solves a very important problem in the film and television industry, which is filming moving shots without shakiness. This report will be documenting the creation of a home-made camera dolly. This version of the camera dolly features an Arduino, two twelve-volt DC motors for the drive train, and a stepper motor for the panoramic camera control.

<img src="https://github.com/stiefwc/ECE387_Embedded_System/blob/main/wiki_images/Back_right.png" width="360" height="270"> <img src="https://github.com/stiefwc/ECE387_Embedded_System/blob/main/wiki_images/Bottom.png" width="360" height="270">
<img src="https://github.com/stiefwc/ECE387_Embedded_System/blob/main/wiki_images/Top_left.png" width="360" height="270"> <img src="https://github.com/stiefwc/ECE387_Embedded_System/blob/main/wiki_images/Top_right.png" width="360" height="270">

[Click here for a video demonstration of the camera dolly.](https://youtu.be/5dX1Bid8B60)



***


## Description
The camera dolly is controlled by two joysticks, one which controls the movement of the car, and one which controls the movement of the panoramic camera attachment. The camera portion features a stepper motor for clockwise and counterclockwise motion, paired with a driver which is controlled by a single axis of the first joystick. The car features an independent drivetrain through the use of two DC motors, which allows for skid-steering. The stepper motor and dual DC motors all feature variable speed through the use of PWM. 


### Components
* Arduino Uno
* (2) Analog Joystick
* (2) 12-volt DC Motor
* L298N Dual DC Motor Driver
* 28BYJ-48 Stepper Motor
* ULN2003 Stepper Motor Driver
* 9.6 volt Battery Pack
* Breadboard
***


## Design Diary
**Spiral Design Model**
1. Control stepper motor and DC motors with one one axis input and constant speed
2. Add dual axis functionality for DC motors to allow turning
3. Add variable speed functionality to the stepper motor and DC motors

The design of the Arduino camera dolly began with learning how to use the DC motors and stepper motor. This was as simple as wiring each DC motor to the L298N driver and wiring the driver to the output ports of the Arduino. This allowed me to test the equipment and also become familiar with the associated functions. Next I became familiar with the stepper motor and driver in a similar fashion. I wired stepper motor to the driver and wired the driver to the Arduino. Then I tested each joystick by wiring them to the Arduino and printing out the value which was being inputted. At this point I had tested all of the electronic the equipment I would need to build by camera dolly.

The beginning of the code is quite simple. To start off, I am including the stepper library and defining each output pin. Next I am creating integers for each motor output, and calling initializing the stepper motor. Lastly, I initialize pins 1 through 6 as output pins.

<img src="https://github.com/stiefwc/ECE387_Embedded_System/blob/main/wiki_images/Initialization_code.png" width="900" height="380">

At this point I began writing the Arduino code to control the camera and car with each joystick. I began with writing the code for controlling the stepper motor with a single axis of the first joystick. The main concept behind the code that controlled the stepper motor was reading if the joystick was pressed left or right through the use of an if statement. Then, depending on which direction the joystick was pressed, the value that from the joystick was mapped to a value the driver can process. The following code is placed inside of the main loop.

<img src="https://github.com/stiefwc/ECE387_Embedded_System/blob/main/wiki_images/Stepper_motor_code.png" width="884" height="350">

The main idea of controlling the car was very similar to controlling the stepper motor, but it was much more complex. This was due to the fact that the car is driven by dual motors and also operates on two axes as opposed to one. I decided to do this by breaking the code into two main sections, one to handle the Y-axis input, and one to handle the X-axis input. Here is the code that handles the Y-axis input from the joystick. 

<img src="https://github.com/stiefwc/ECE387_Embedded_System/blob/main/wiki_images/DC_motor_Y_axis.png" width="945" height="382">

And here is the code that handles the X-axis input from the joystick, and then sends the output to each motor. 

<img src="https://github.com/stiefwc/ECE387_Embedded_System/blob/main/wiki_images/DC_motor_X_axis.png" width="890" height="420">

***

## How to Use
To use this project in your own instance, you would first need to build the physical camera dolly. I had limited access to tools when making this project so I used the tools that I had access to. The body of the car is a flat rectangular piece of wood, which is taken from a clipboard that was no longer being used. The body of the car is what all of the other components were mounted on. From there, I attached both DC drive motors to the underside of the body using epoxy putty. I would have preferred to make metal brackets to mount the motors which would attach to the body with screws, but I did not have access to the correct tools. Next, I attached the DC motor driver to the bottom side of the body, and the Arduino, stepper motor and driver, and the battery pack to the top of the body. I attached all of these components using hot glue, which worked well because hot glue is an electrical insulator. Lastly, I attached a phone mount to the stepper motor by drilling a hole which fit perfectly on the shaft of the stepper motor. 

Once the physical camera dolly has been built, you will need to wire the components to the Arduino. Here is a wiring diagram of the circuit I have built.

![](https://github.com/stiefwc/ECE387_Embedded_System/blob/main/wiki_images/Wiring%20Diagram.png)

The wiring diagram seems complicated at first, but it is actually quite simple when analyzed piece by piece. First, each joystick is wired to three analog pins on the Arduino, as well as a +5 volt connection and ground.  Next, the positive lead from the battery pack is run to the Vin connection on the Arduino as well as the L298N driver board. The negative lead runs to the ground on the Arduino as well as the L298N Driver board. Then the L298N driver is wired to the Arduino through 6 output pins, I used pins 1 through 6. The ULN2003 driver is wired to the Arduino through four output pins, I used pins 8 though 11. Lastly, we need to wire the motors to their drivers; the stepper motor plugs directly into its driver board whereas each DC motor needs to have the positive and negative terminals wired together.

***

## Design analysis

One aspect of the project I would improve on next time is the build quality. Since I am located in Oxford, I do not have access to the same tools I have at home. I would have preferred to attach the motors to the body with metal brackets instead of epoxy putty. Something else I would like to improve is the top speed of the camera dolly, which could be achieved by using DC motors with a different gearbox ration. Lastly, the design would be much easier and more fun to use if the joysticks used bluetooth to control the car wirelessly.

Overall, I think the Arduino camera dolly turned out very well. Building and programming the camera dolly was very challenging, but the final product exceeded my expectations. I was able to build a robotic car with an independent drivetrain, which is controlled by a dual axis input from a joystick. I was also successful at mounting the panoramic camera attachment and controlling that with a single axis input from a joystick. The car functioned as I had planned which I believe is a success. Building the camera dolly helped me become much more familiar with Arduino components as well as the Arduino IDE, and I also learned how to use the spiral design model. Overall, I believe the final project for ECE387 was a great learning experience.






***


## Works Used

[https://create.arduino.cc/projecthub/ryanchan/how-to-use-the-l298n-motor-driver-b124c5](https://create.arduino.cc/projecthub/ryanchan/how-to-use-the-l298n-motor-driver-b124c5)

[https://how2electronics.com/controlling-stepper-motor-joystick-arduino/](https://how2electronics.com/controlling-stepper-motor-joystick-arduino/)

[https://howtomechatronics.com/tutorials/arduino/arduino-dc-motor-control-tutorial-l298n-pwm-h-bridge/](https://howtomechatronics.com/tutorials/arduino/arduino-dc-motor-control-tutorial-l298n-pwm-h-bridge/)

[http://www.goodliffe.org.uk/arduino/joystick.php](http://www.goodliffe.org.uk/arduino/joystick.php)

***





