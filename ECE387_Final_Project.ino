
#include <Stepper.h> // Library of useful stepper motor functions

#define enableA 5 // Used to enable the motor
#define enableB 6 // Used to enable the motor
#define out1 1 // Output pin 1
#define out2 2 // Output pin 2
#define out3 3 // Output pin 3
#define out4 4 // Output pin 4

int outputA = 0; // Output which is sent to motor A
int outputB = 0; // Output which is sent to motor A

// initialize the stepper motor on pins 8 through 11, 32 full steps is one revolution:
Stepper myStepper(32, 9, 11, 8, 10);

void setup() {
  pinMode(out1,OUTPUT); // pin 1 as output
  pinMode(out2,OUTPUT); // pin 2 as output
  pinMode(out3,OUTPUT); // pin 3 as output
  pinMode(out4,OUTPUT); // pin 4 as output
  pinMode(enableA,OUTPUT); // pin 5 as output
  pinMode(enableB,OUTPUT); // pin 6 as output
}

void loop() {

//________________________________________________________________________________________________________________________________________
  
  // The following code is responsible for controlling the stepper motor (camera control)
  
  int xIn = analogRead(A0); // Reads X-axis input from joystick 1

  if (xIn < 480) { // if joystick is moved to the right (X value is less than 480), the following code is executed
    // map the joystick input to a speed between 0 and 800 rpm
    int speed_ = map(xIn, 480, 0, 0, 800);
    // set motor speed
    myStepper.setSpeed(speed_);
    // clockwise step
    myStepper.step(1); 
  }
  else if (xIn > 544) { // if joystick is moved to the left (X value is greater than 544), the following code is executed
    // map the joystick input to a speed between 0 and 800 rpm
    int speed_ = map(xIn, 544, 1023, 0, 800);
    // set motor speed
    myStepper.setSpeed(speed_);
    // step counterclockwise
    myStepper.step(-1);
  }

//________________________________________________________________________________________________________________________________________

  // The following code is responsible for controlling the Dual DC motors (car control)
  
  int xIn2 = analogRead(A3); // Reads X-axis input from joystick 2
  int yIn2 = analogRead(A4); // Reads y-axis input from joystick 2

  // Forward and reverse control from Y-axis
  
  if (yIn2 < 480) { // if joystick is moved up (Y value is less than 480), the following code is executed
    // Set motor A forward
    digitalWrite(out1, HIGH);
    digitalWrite(out2, LOW);
    // Set motor B forward
    digitalWrite(out3, HIGH);
    digitalWrite(out4, LOW);
    // Convert analog signal (0 to 480) to digital (0 to 255) for PWM
    outputA = map(yIn2, 480, 0, 0, 255);
    outputB = map(yIn2, 480, 0, 0, 255);
  }
  else if (yIn2 > 544) { // if joystick is moved down (Y value is greater than 544), the following code is executed
    // Motor A backwards
    digitalWrite(out1, LOW);
    digitalWrite(out2, HIGH);
    // Motor B backwards
    digitalWrite(out3, LOW);
    digitalWrite(out4, HIGH);
    // Convert analog signal (544 to 1023) to digital (0 to 255) for PWM
    outputA = map(yIn2, 544, 1023, 0, 255);
    outputB = map(yIn2, 544, 1023, 0, 255);
  }
  else { // Do nothing
    outputA = 0;
    outputB = 0;
  }

//________________________________________________________________________________________________________________________________________

  // Left and right control from X-axis
  
  if (xIn2 < 480) { // if joystick is moved to the right (Y value is less than 480), the following code is executed
    int xMap = map(xIn2, 480, 0, 0, 255);
    outputA = outputA - xMap; // the output to motor A is the Y value minus the X value; this allows the car to turn right
    outputB = outputB + xMap; // the output to motor B is the Y value plus the X value; this allows the car to turn right

    if (outputA < 0) { // do nothing
      outputA = 0;
    }
  }
  if (xIn2 > 544) { // if joystick is moved to the left (Y value is greater than 544), the following code is executed
    int xMap = map(xIn2, 544, 1023, 0, 255);
    outputA = outputA + xMap; // the output to motor A is the Y value plus the X value; this allows the car to turn left
    outputB = outputB - xMap; // the output to motor B is the Y value minus the X value; this allows the car to turn left
    
    if (outputA < 0) { // do nothing
      outputA = 0;
    }
  }
  
  analogWrite(enableA, outputA); // sends the PWM output to motor A
  analogWrite(enableB, outputB); // sends the PWM output to motor B

}
