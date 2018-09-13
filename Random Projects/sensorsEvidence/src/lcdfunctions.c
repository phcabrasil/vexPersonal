#include "main.h"
#include "autofunctions.h"
#include "lcdfunctions.h"
#include "drive.h"

void disablelcd(void *ignore){

  int screen = 1;
  int screen_cap = 4;
  int btn_time = 100;
  myauto = 4; //was int
  lcdClear(uart1);

  while(true){
    delay(25);

    if(!isEnabled()){

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
        lcdPrint(uart1, 1, "Distance = %d", getDistance);
        lcdPrint(uart1, 2, "Position Arm = %d", getPosition);
          if(lcdReadButtons(uart1) == 2){
              lcdClear(uart1);
              lcdSetText(uart1, 1, "Please wait...");
              delay(btn_time);
              screen = screen + 1;}
          if(lcdReadButtons(uart1) == 1){/*ADD ACTION*/}
          if(lcdReadButtons(uart1) == 4){/*ADD ACTION*/}

        break;

        case 3:
        lcdPrint(uart1, 1, "Encoder R = %d", getTicksR);
        lcdPrint(uart1, 2, "Gyro = %d", getAngle);
          if(lcdReadButtons(uart1) == 2){
              lcdClear(uart1);
              lcdSetText(uart1, 1, "Please wait...");
              delay(btn_time);
              screen = screen + 1;}
          if(lcdReadButtons(uart1) == 1){/*ADD ACTION*/}
          if(lcdReadButtons(uart1) == 4){/*ADD ACTION*/}
        break;

        case 4:
        lcdPrint(uart1, 1, "Encoder L = %d", getTicksL);
        lcdPrint(uart1, 2, "MEMES");
          if(lcdReadButtons(uart1) == 2){
              lcdClear(uart1);
              lcdSetText(uart1, 1, "Please wait...");
              delay(btn_time);
              screen = screen + 1;}
          if(lcdReadButtons(uart1) == 1){/*ADD ACTION*/}
          if(lcdReadButtons(uart1) == 4){/*ADD ACTION*/}
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
            lcdSetText(uart1, 2, "Stationary RED");
          break;
          case 6:
            lcdSetText(uart1, 2, "Stationary BLUE");
          break;
          case 7:
            lcdSetText(uart1, 2, "Mobile 3 Right 10");
          break;
          case 8:
            lcdSetText(uart1, 2, "Mobile 3 Left 10");
          break;
          case 9:
            lcdSetText(uart1, 2, "Mobile 3 Right 5");
          break;
          case 10:
            lcdSetText(uart1, 2, "Mobile 3 Left 5");
          break;
          case 11:
            lcdSetText(uart1, 2, "Trick Right");
          break;
          case 12:
            lcdSetText(uart1, 2, "Trick Left");
          break;
          case 13:
            lcdSetText(uart1, 2, "Far Mogo Right");
          break;
          case 14:
            lcdSetText(uart1, 2, "Far Mogo Left");
          break;
          case 15:
            lcdSetText(uart1, 2, "Defence");
          break;
          case 16:
            lcdSetText(uart1, 2, "Test");
          break;
          }
        }
      delay(20);
  }
  else{delay(50);}
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
      lcdPrint(uart1, 1, "Gyro = %d", getAngle);
      lcdPrint(uart1, 2, "Encoder R = %d", getTicksR);
        if(lcdReadButtons(uart1) == 2){
          lcdClear(uart1);
          lcdSetText(uart1, 1, "Please wait...");
          delay(btn_time);
          screen = screen + 1;}
        if(lcdReadButtons(uart1) == 1){/*ADD ACTION*/}
        if(lcdReadButtons(uart1) == 4){/*ADD ACTION*/}
      break;

      case 2:
      lcdPrint(uart1, 1, "Position = %d", getPosition);
      lcdPrint(uart1, 2, "Distance = %d", getDistance);
        if(lcdReadButtons(uart1) == 2){
          lcdClear(uart1);
          lcdSetText(uart1, 1, "Please wait...");
          delay(btn_time);
          screen = screen + 1;
        }
        if(lcdReadButtons(uart1) == 1){/*ADD ACTION*/}
        if(lcdReadButtons(uart1) == 4){/*ADD ACTION*/}
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
      lcdPrint(uart1, 1, "Position = %d", getPosition);
      lcdPrint(uart1, 2, "Distance = %d", getDistance);
        if(lcdReadButtons(uart1) == 2){
          lcdClear(uart1);
          lcdSetText(uart1, 1, "Please wait...");
          delay(btn_time);
          screen = screen + 1;
        }
        if(lcdReadButtons(uart1) == 1){/*ADD ACTION*/}
        if(lcdReadButtons(uart1) == 4){/*ADD ACTION*/}
      break;

      case 2:
      lcdPrint(uart1, 1, "Position = %d", getPosition);
      lcdPrint(uart1, 2, "Distance = %d", getDistance);
        if(lcdReadButtons(uart1) == 2){
            lcdClear(uart1);
            lcdSetText(uart1, 1, "Please wait...");
            delay(btn_time);
            screen = screen + 1;}
        if(lcdReadButtons(uart1) == 1){/*ADD ACTION*/}
        if(lcdReadButtons(uart1) == 4){/*ADD ACTION*/}
      break;

      }
    if(screen > screen_cap){screen = 1;}
  }

  taskDelete(autolcd_task);
}
