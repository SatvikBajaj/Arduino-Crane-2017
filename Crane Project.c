
#include <Servo.h>                //include the servo thing
Servo servoHorizontal;            //naming each servo, this one is for horizontal rotation
Servo servoVertical;              //naming each servo, this one is for vertical rotation
int joyStickYAxis = A1;           //joystick y pins are connected to A1
int joyStickXAxis = A0;           //joystick x pins are connected to A0
int joyStickXPosition;            //variable for the position of the joystick on the X axis
int joyStickXPrevious;            //variable for the position of the joystick on the X axis previously
int joyStickXPresent;             //variable for the position of the joystick on the X axis currently
int joyStickYPosition;            //variable for the position of the joystick on the Y axis
int joyStickYPrevious;            //variable for the position of the joystick on the Y axis previously
int joyStickYPresent;             //variable for the position of the joystick on the Y axis currently
void setup() {                    //setup all the pins
  servoHorizontal.attach(7);      //servo that connects horizontal movement is asigned to
  servoVertical.attach(12);        //servo that connects vertical movement is asigned to
  pinMode(joyStickXAxis, INPUT);  //makes joysticks inputs
  pinMode(joyStickYAxis, INPUT);  //makes joysticks inputs
  servoHorizontal.write(0);      //make starting position the centre
  servoVertical.write(180);        //make starting position the centre
  Serial.begin(9600);             //begin writing to the serial monitor
}
void loop() {
  joyStickXPosition = analogRead(joyStickXAxis);                //reads value of joystickpin
  joyStickXPosition = map(joyStickXPosition, 0, 1023, 0, 180);  //scale joystick to servo values (0-1023 --> 0-180)
  joyStickXPresent = analogRead(joyStickXAxis);                 //reads value of joystickpin
  joyStickXPresent = map(joyStickXPresent, 0, 1023, 0, 180);    //scale joystick to servo values (0-1023 --> 0-180)

  if (joyStickXPosition < 83 && joyStickXPrevious < joyStickXPresent ) {  //if joystick is being let go, keep the position                                -
    servoHorizontal.write (joyStickXPrevious);                            //tell the horizontal servo to use the previous value                             -
    delay(15);                                                            //just a small delay for the servo to reach its position                           -
  }                                                                       //                                                                                  |
  if (joyStickXPosition > 93 && joyStickXPresent < joyStickXPrevious) {   //if joystick is being let go, keep the position                                    |
    servoHorizontal.write(joyStickXPrevious);                             //tell the horizontal servo to use the previous value                               |
    delay(15);                                                            //just another small delay for the servo                                            |
  }                                                                       //                                                                                  |
  if (joyStickXPosition > 93 && joyStickXPresent > joyStickXPrevious) {   //if joystick being pushed to the right, move the crane right                       |
    joyStickXPrevious = joyStickXPrevious + 1;                            //increase the previous increment because it is increasing as you push it           |
    servoHorizontal.write(joyStickXPrevious);                             //tell the horizontal servo to use the previous value                                -
    Serial.println(joyStickXPrevious);                                    //write the value to the serial monitor                                                -
    joyStickXPresent = joyStickXPrevious;                                 //makes them the same                                                                    - HORIZONTAL SECTION (ROTATION OF THE CRANE)
    delay(15);                                                            //delay for the servo to keep up                                                       -
  }                                                                       //                                                                                   -
  if (joyStickXPosition < 83 && joyStickXPrevious > joyStickXPresent) {   //if joystick is pushed to the left , move the crane left                           |
    joyStickXPrevious = joyStickXPrevious - 1;                            //decrease the previous increment because it is decreasing as you push it           |
    servoHorizontal.write (joyStickXPrevious);                            //tell the horizontal servo to use the previous value                               |
    Serial.println(joyStickXPrevious);                                    //write the value to the serial monitor                                             |
    joyStickXPresent = joyStickXPrevious;                                 //make them the same                                                                |
    delay(15);                                                            //delay for the servo to keep up                                                    |
  }                                                                       //                                                                                  |
  if (joyStickXPosition > 83 && joyStickXPosition < 93) {                 //if joystick is in the centre, dont move the crane                                -
    servoHorizontal.write(joyStickXPrevious);                             //make the servo use the previous value so it doesnt move                         -
    delay(15);                                                            //delay for the servo to keep up                                                -
  }
  joyStickYPosition = analogRead(joyStickYAxis);                //reads value of joystickpin
  joyStickYPosition = map(joyStickYPosition, 0, 1023, 0, 180);  //scale joystick to servo values (0-1023 --> 0-180)
  joyStickYPresent = analogRead(joyStickYAxis);                 //reads value of joystickpin
  joyStickYPresent = map(joyStickYPresent, 0, 1023, 0, 180);    //scale joystick to servo values (0-1023 --> 0-180)

  if (joyStickYPosition < 83 && joyStickYPrevious < joyStickYPresent ) {  //if joystick is being let go, keep the position                                -
    servoVertical.write (joyStickYPrevious);                              //tell the vertical servo to use the previous value                             -
    delay(15);                                                            //just a small delay for the servo to reach its position                           -
  }                                                                       //                                                                                  |
  if (joyStickYPosition > 93 && joyStickYPresent < joyStickYPrevious) {   //if joystick is being let go, keep the position                                    |
    servoVertical.write(joyStickYPrevious);                               //tell the vertical servo to use the previous value                                 |
    delay(15);                                                            //just another small delay for the servo                                            |
  }                                                                       //                                                                                  |
  if (joyStickYPosition > 93 && joyStickYPresent > joyStickYPrevious) {   //if joystick being pushed to the down, move the crane down                         |
    joyStickYPrevious = joyStickYPrevious + 5;                            //increase the previous increment because it is increasing as you push it           |
    servoVertical.write(joyStickYPrevious);                               //tell the vertical servo to use the previous value                                 -
    Serial.println(joyStickYPrevious);                                    //write the value to the serial monitor                                                -
    joyStickYPresent = joyStickYPrevious;                                 //makes them the same                                                                    - VERTICAL SECTION OF CODE (CRANE STRING UP AND DOWN)
    delay(15);                                                            //delay for the servo to keep up                                                       -
  }                                                                       //                                                                                   -
  if (joyStickYPosition < 83 && joyStickYPrevious > joyStickYPresent) {   //if joystick is pushed to the up , move the crane up                               |
    joyStickYPrevious = joyStickYPrevious - 5;                            //decrease the previous increment because it is decreasing as you push it           |
    servoVertical.write (joyStickYPrevious);                              //tell the vertical servo to use the previous value                                 |
    Serial.println(joyStickYPrevious);                                    //write the value to the serial monitor                                             |
    joyStickYPresent = joyStickYPrevious;                                 //make them the same                                                                |
    delay(15);                                                            //delay for the servo to keep up                                                    |
  }                                                                       //                                                                                  |
  if (joyStickYPosition > 83 && joyStickYPosition < 93) {                 //if joystick is in the centre, dont move the crane                                -
    servoVertical.write(joyStickYPrevious);                               //make the servo use the previous value so it doesnt move                         -
    delay(15);                                                            //delay for the servo to keep up   