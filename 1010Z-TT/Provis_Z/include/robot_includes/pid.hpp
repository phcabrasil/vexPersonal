#ifndef _PID_HPP_
#define _PID_HPP_

//Data Slots
#define ERROR 0
#define INTEGRAL 1
#define DERIVATIVE 2
#define PAST_ERROR 3
#define CONST_INTEGRAL 4
#define INTEGRAL_LIMIT 5
#define CONST_INT_VAL 6

//PID Class
class PID
{
  public:
    PID(); //PID Class
    int output(int max_power); //Set Max Output
    int current; //Set Sensor Input
    int target; //Set Sensor Target
    int data[7]; //Data Array
    void set_PID_vars(float p, float i, float d, int integral_limit); //Set PID Variables
    void set_PID_vars(float p, int i_val, float d, int integral_limit, bool const_int); //Set PID Variables
    void post(int post); //Post PID Data Slots
  private:
    float kp; //Proportional Constant
    float ki; //Integral Constant
    float kd; //Differential Constant
};

#endif
