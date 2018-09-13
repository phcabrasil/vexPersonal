
#include "main.h"

void initializeIO() {
  //Pneumatics
  pinMode(solenoid, OUTPUT);
  digitalWrite(solenoid, LOW);
}

void initialize() {
  //Encoders
  encoderR = encoderInit(encoderLeft1, encoderLeft2, false); //Left Encoder initialize
  encoderL = encoderInit(encoderRight1, encoderRight2, false); //Right Encoder Initialize
  //Gyro
  gyro = gyroInit(gyroP, false); //Gyro initialize
  //Ultrasonic
  ultra = ultrasonicInit(ultra1, ultra2); //Ultrasonic Sensor initialize
  //Potentiometer
  analogCalibrate(catPot);
}
