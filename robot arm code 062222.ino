#include <Servo.h>

const int servo1 = 3;       // first servo
const int servo2 = 10;       // second servo
const int joyH = 3;        // L/R Parallax Thumbstick
const int joyV = 4;        // U/D Parallax Thumbstick

const int servo3 = 5; 
const int servo4 = 6 ;
const int joyclawx = 2;
const int joyclawy = 1;

int servoVal;           // variable to read the value from the analog pin

Servo myservo1;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo
Servo myservo3;
Servo myservo4;


void setup() {

  // Servo  
  myservo1.attach(servo1);  // attaches the servo
  myservo2.attach(servo2);  // attaches the servo
  myservo3.attach(servo3);
  myservo4.attach(servo4);

  // Inizialize Serial
  Serial.begin(9600);
}

void loop(){

    // Display Joystick values using the serial monitor
    outputJoystick();

    // Read the horizontal joystick value  (value between 0 and 1023)
    servoVal = analogRead(joyH);          
    servoVal = map(servoVal, 0, 1023, 0, 180);     // scale it to use it with the servo (result  between 0 and 180)

    myservo2.write(servoVal);                         // sets the servo position according to the scaled value    

    // Read the horizontal joystick value  (value between 0 and 1023)
    servoVal = analogRead(joyV);           
    servoVal = map(servoVal, 0, 1023, 0, 75);     // scale it to use it with the servo (result between 70 and 180)

    myservo1.write(servoVal);                           // sets the servo position according to the scaled value

    //Read the claw joystick value
    servoVal=analogRead(joyclawx);
    servoVal=map(servoVal, 0, 1023, 0, 180);

    myservo3.write(servoVal);

    //Read the other claw joystick value
    servoVal=analogRead(joyclawy);
    servoVal=map(servoVal, 0, 1023, 0, 75);

    myservo4.write(servoVal);

    delay(15);                                       // waits for the servo to get there

}


/**
* Display joystick values
*/
void outputJoystick(){

    Serial.print(analogRead(joyH));
    Serial.print ("---"); 
    Serial.print(analogRead(joyV));
    Serial.println ("---");
    Serial.println(analogRead(joyclawx));
    Serial.println("---");
    Serial.println(analogRead(joyclawy));
}