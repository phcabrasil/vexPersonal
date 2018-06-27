#include "main.h"

void openLock(){
  digitalWrite(4, LOW); // write LOW to port 1 (solenoid may be extended or not, depending on wiring)
}

void lock(){
  digitalWrite(4, HIGH); // write LOW to port 1 (solenoid may be extended or not, depending on wiring)
}
