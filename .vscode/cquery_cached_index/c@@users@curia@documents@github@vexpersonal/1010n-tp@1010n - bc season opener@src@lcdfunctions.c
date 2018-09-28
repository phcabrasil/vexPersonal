#include "C:\Users\Curia\Documents\GitHub\vexPersonal\1010N-TP\1010N - BC Season Opener\include\main.h"
#include "C:\Users\Curia\Documents\GitHub\vexPersonal\1010N-TP\1010N - BC Season Opener\include\autofunctions.h"
#include "C:\Users\Curia\Documents\GitHub\vexPersonal\1010N-TP\1010N - BC Season Opener\include\lcdfunctions.h"
#include "C:\Users\Curia\Documents\GitHub\vexPersonal\1010N-TP\1010N - BC Season Opener\include\drive.h"
#include "C:\Users\Curia\Documents\GitHub\vexPersonal\1010N-TP\1010N - BC Season Opener\include\flywheel.h"
#include "C:\Users\Curia\Documents\GitHub\vexPersonal\1010N-TP\1010N - BC Season Opener\include\lift.h"

void disablelcd(void *ignore){

  int screen = 1;
  int screen_cap = 5;
  int btn_time = 100;
  myauto = 1; //was int
  lcdClear(uart1);

  while(true){

    delay(25);

      switch(screen){

        case 1:
        lcdPrint(uart1, 1, "%d, Auto  %d ", screen, myauto);
          if(lcdReadButtons(uart1) == 2){
              lcdClear(uart1);
              lcdSetText(uart1, 1, "Please wait...");
              delay(btn_time);
              screen = screen + 1;}
          if(lcdReadButtons(uart1) == 1){
              lcdClear(uart1);
              lcdSetText(uart1, 1, "Please wait...");
              delay(btn_time);
              myauto = myauto-1;}
          if(lcdReadButtons(uart1) == 4){
              lcdClear(uart1);
              lcdSetText(uart1, 1, "Please wait...");
              delay(btn_time);
              myauto = myauto+1;}
        break;

        case 2:
        lcdPrint(uart1, 1, "Encoder L: %d", encoderGet(encoderL));
        lcdPrint(uart1, 2, "Encoder R: %d", encoderGet(encoderR));
          if(lcdReadButtons(uart1) == 2){
              lcdClear(uart1);
              lcdSetText(uart1, 1, "Please wait...");
              delay(btn_time);
              screen = screen + 1;}
          if(lcdReadButtons(uart1) == 1){/*Action*/}
          if(lcdReadButtons(uart1) == 4){/*Action*/}
        break;

        case 3:
        lcdPrint(uart1, 1, "Relative Gyro: %d", gyroGet(relativeGyro));
        lcdPrint(uart1, 2, "Absolute Gyro: %d", gyroGet(absoluteGyro));
          if(lcdReadButtons(uart1) == 2){
              lcdClear(uart1);
              lcdSetText(uart1, 1, "Please wait...");
              delay(btn_time);
              screen = screen + 1;}
          if(lcdReadButtons(uart1) == 1){/*Action*/}
          if(lcdReadButtons(uart1) == 4){/*Action*/}
        break;

        case 4:
        lcdPrint(uart1, 1, "Encoder Arm: %d", encoderGet(encoderA));
        lcdPrint(uart1, 2, "Cap Intake: %d", analogRead(CAPPOT));
          if(lcdReadButtons(uart1) == 2){
              lcdClear(uart1);
              lcdSetText(uart1, 1, "Please wait...");
              delay(btn_time);
              screen = screen + 1;}
          if(lcdReadButtons(uart1) == 1){/*Action*/}
          if(lcdReadButtons(uart1) == 4){/*Action*/}
        break;

        case 5:
        lcdPrint(uart1, 1, "Encoder F: %d", encoderGet(encoderF));
        lcdPrint(uart1, 2, "Action");
          if(lcdReadButtons(uart1) == 2){
              lcdClear(uart1);
              lcdSetText(uart1, 1, "Please wait...");
              delay(btn_time);
              screen = screen + 1;}
          if(lcdReadButtons(uart1) == 1){/*Action*/}
          if(lcdReadButtons(uart1) == 4){/*Action*/}
        break;

        default:
          lcdClear(uart1);
          lcdSetText(uart1, 1, "DEFAULT");
          delay(50);
          screen = 1;
        break;
        }

      //screen cap reset
      if(screen > screen_cap){screen = 1;}

      //auto line dispalby
      if(screen == 1){
        switch(myauto){
          case -1:
            lcdSetText(uart1, 2, "NoAuto");
          break;
          case 0:
            lcdSetText(uart1, 2, "Skills");
          break;
          case 1:
            lcdSetText(uart1, 2, "Mobile 3 Right 20");
          break;
          case 2:
            lcdSetText(uart1, 2, "Mobile 3 Left 20");
          break;
          case 3:
            lcdSetText(uart1, 2, "Mobile 2 Right 20");
          break;
          case 4:
            lcdSetText(uart1, 2, "Mobile 2 Left 20");
          break;
          case 5:
            lcdSetText(uart1, 2, "Test");
          break;
          }
        }
    delay(50);
  }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

void opcontrollcd(void *ignore){
  int screen = 1;
  int screen_cap = 2;
  int btn_time = 50;
  lcdClear(uart1);

  while(isEnabled()){

    switch(screen){

      case 1:
      lcdPrint(uart1, 1, "Action");
      lcdPrint(uart1, 2, "Action");
        if(lcdReadButtons(uart1) == 2){
            lcdClear(uart1);
            lcdSetText(uart1, 1, "Please wait...");
            delay(btn_time);
            screen = screen + 1;}
        if(lcdReadButtons(uart1) == 1){/*Action*/}
        if(lcdReadButtons(uart1) == 4){/*Action*/}
      break;

      case 2:
      lcdPrint(uart1, 1, "Action");
      lcdPrint(uart1, 2, "Action");
        if(lcdReadButtons(uart1) == 2){
            lcdClear(uart1);
            lcdSetText(uart1, 1, "Please wait...");
            delay(btn_time);
            screen = screen + 1;}
        if(lcdReadButtons(uart1) == 1){/*Action*/}
        if(lcdReadButtons(uart1) == 4){/*Action*/}
      break;

      default:
      lcdClear(uart1);
      lcdSetText(uart1, 1, "DEFAULT");
      delay(50);
      screen = 1;
      break;
      }
    if(screen > screen_cap){screen = 1;}
  }
  taskDelete(opcontrollcd_task);
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

void autolcd(void *ignore){
  int screen = 1;
  int screen_cap = 2;
  int btn_time = 100;
  lcdClear(uart1);

  while(isAutonomous()){

    switch(screen){

      case 1:
      lcdPrint(uart1, 1, "Action");
      lcdPrint(uart1, 2, "Action");
        if(lcdReadButtons(uart1) == 2){
            lcdClear(uart1);
            lcdSetText(uart1, 1, "Please wait...");
            delay(btn_time);
            screen = screen + 1;}
        if(lcdReadButtons(uart1) == 1){/*Action*/}
        if(lcdReadButtons(uart1) == 4){/*Action*/}
      break;

      case 2:
      lcdPrint(uart1, 1, "Action");
      lcdPrint(uart1, 2, "Action");
        if(lcdReadButtons(uart1) == 2){
            lcdClear(uart1);
            lcdSetText(uart1, 1, "Please wait...");
            delay(btn_time);
            screen = screen + 1;}
        if(lcdReadButtons(uart1) == 1){/*Action*/}
        if(lcdReadButtons(uart1) == 4){/*Action*/}
      break;

      }
    if(screen > screen_cap){screen = 1;}
  }

  taskDelete(autolcd_task);
}
