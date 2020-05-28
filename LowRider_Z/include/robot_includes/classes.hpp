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
    int gyroValue(); //Get Gyro Value
    void resetChassisSensors(bool); //Reset Drive Sensors (Encoders and **Optional** Gyro)

    //Motor Power
    void setLeft(int); //Set Left Drive
    void setRight(int); //Set Right Drive
    void stop(bool); //Stop Drive (**Optional** Reset Sensors)

    //Auto Functions
    void autoDrive(int, int, int); //Drive Function
    void autoTurn(int, int, int); //Turn Function
    void autoCurve(int, int, int, int); //Curve/Arc Function
    void autoPivot(int, int, int, int); //Pivot Function

  private:
    int left; //LEFT Power
    int right; //RIGHT Power
    int arcadeY; //Arcade Drive Power
    int arcadeX; //Arcade Turn Power
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

  private:
    int anglerJoystick; //Exponential Power on Joy
};


#endif
