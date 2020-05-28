#include "main.h"
#include "robot_includes/timing.hpp"

int start_times[20] =
{
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};



void startTimer(int slot)
{
  start_times[slot] = pros::millis();
}



int getTime(int slot)
{
  return (pros::millis() - start_times[slot]);
}
