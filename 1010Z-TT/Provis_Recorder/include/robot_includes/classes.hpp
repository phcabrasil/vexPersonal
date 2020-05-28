#ifndef _CLASSES_HPP_
#define _CLASSES_HPP_

//Autonomous Tasks
void liftAuto_fn(void*parameter);

// ==== CHASSIS ==== //
class Chassis
{
  public:
    //Initialize
    Chassis();

    //Operator Control Code
    void driveControl();

    //Sensors
    int leftPosition(); //Get Left Encoder
    int rightPosition(); //Get Right Encoder
    int leftBackPosition(); //Get Left Encoder
    int rightBackPosition(); //Get Right Encoder
    int getAngle(); //Get Gyro Value
    void resetChassisSensors(bool); //Reset Drive Sensors (Encoders and **Optional** Gyro)

    //Motor Power
    void setLeftFront(int); //Set Left Drive
    void setLeftBack(int); //Set Left Drive
    void setRightFront(int); //Set Right Drive
    void setRightBack(int); //Set Right Drive
    void stop(bool); //Stop Drive (**Optional** Reset Sensors)

    //Auto Functions
    void autoDrive(int, int, int, int); //Drive Function
    void autoTurn(int, int, int); //Turn Function
    void autoCurve(int, int, int, int); //Curve/Arc Function
    void autoPivot(int, int, int, int); //Pivot Function
    void autoFence(int, float, float, int);

  private:
    int leftFront; //LEFT Power
    int leftBack; //LEFT Power
    int rightFront; //RIGHT Power
    int rightBack; //RIGHT Power
    int arcadeY; //Arcade Drive Power
    int arcadeZ; //Aracde Turn Power
    double driveWidth; //Drive Width in Encoder Units
};

// ==== LIFT AND INTAKE ==== //
class Lift
{
  public:
    //Initialize
    Lift();

    //Operator Control Code
    void driveControl();

    //Motor Power
    void setIntakePower(int); //Set Intake Motor
    void setRampVel(int); //Set Ramp Motor
    void setLiftPower(int); //Set Arm Motor

    //Sensors
    int getRampPos();
    void resetRampPos();

  private:
    int anglerJoystick; //Exponential Power on Joy
};


#endif
