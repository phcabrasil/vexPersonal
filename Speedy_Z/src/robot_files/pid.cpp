#include "main.h"
#include "robot_includes/robot_includes.hpp"

//PID Class Initialize Constants and Variables
PID::PID()
{
  kp = 0;
  ki = 0;
  kd = 0;

  target = 0;
  current = 0;

  data[ERROR] = 0;
  data[INTEGRAL] = 0;
  data[DERIVATIVE] = 0;
  data[PAST_ERROR] = 0;
  data[CONST_INTEGRAL] = false;
  data[INTEGRAL_LIMIT] = 0;
  data[CONST_INT_VAL] = 0;
}




//Set PID Constants/Variables
void PID::set_PID_vars(float p, float i, float d, int integral_limit)
{
  kp = p;
  ki = i;
  kd = d;
  data[INTEGRAL_LIMIT] = integral_limit;
}




//Set PID Constants/Variables
void PID::set_PID_vars(float p, int i_val, float d, int integral_limit, bool const_int)
{
  kp = p;
  kd = d;
  data[INTEGRAL_LIMIT] = integral_limit;
  data[CONST_INT_VAL] = i_val;
  data[CONST_INT_VAL] = const_int;
}




//Post PID Data Slots
void PID::post(int data_slot)
{
  std::cout << data[data_slot];
}




//PID Output Function
int PID::output(int max_power)
{
  //Create Output Variable
  int out;

  //Set Last Error
  data[PAST_ERROR] = data[ERROR];

  //Set Proportional Error
  data[ERROR] = target - current;

  //Set Derivative Error (Difference in Error / Time)
  data[DERIVATIVE] = data[ERROR] - data[PAST_ERROR];

  //Set Integral Error (Sum of Error / Time)
  data[INTEGRAL] = data[CONST_INTEGRAL] == true ? abs(data[INTEGRAL]) < data[INTEGRAL_LIMIT] ? (data[INTEGRAL] = data[INTEGRAL] + data[ERROR]) : (data[INTEGRAL] = 0) : (data[INTEGRAL] = data[CONST_INT_VAL]);

  //Set PID Output
  out = (data[ERROR] * kp) + (data[INTEGRAL] * ki) + (data[DERIVATIVE] * kd); // P + I + D

  //Limit PID Output
  out = out > max_power ? max_power : -out < -max_power ? -max_power : out;

  //Return PID Output
  return out;
}
