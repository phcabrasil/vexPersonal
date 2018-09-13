#include "main.h"
#include "lcdfunctions.h"

void disablelcd(void *ignore){

  int screen = 1;
  int screen_cap = 3;
  int btn_time = 100;
  myauto = 1; //was int
  lcdClear(uart1);

  while(true){
    delay(25);

    if(!isEnabled()){
      switch(screen){

        case 1:
        lcdPrint(uart1, 1, "%d, Auto  %d ", screen, myauto);
          if(lcdReadButtons(uart1) == 2){
              lcdClear(uart1);
              lcdSetText(uart1, 1, "wait");
              delay(btn_time);
              screen = screen + 1;}
          if(lcdReadButtons(uart1) == 1){
              lcdClear(uart1);
              lcdSetText(uart1, 1, "wait");
              delay(btn_time);
              myauto = myauto-1;}
          if(lcdReadButtons(uart1) == 4){
              lcdClear(uart1);
              lcdSetText(uart1, 1, "wait");
              delay(btn_time);
              myauto = myauto+1;}
        break;

        case 2:
        lcdPrint(uart1, 1, "Main: %dV",powerLevelMain()/1000);
        lcdPrint(uart1, 2, "Backup: %dV",powerLevelBackup()/1000);
          if(lcdReadButtons(uart1) == 2){
              lcdClear(uart1);
              lcdSetText(uart1, 1, "wait");
              delay(btn_time);
              screen = screen + 1;}
          if(lcdReadButtons(uart1) == 1){}
          if(lcdReadButtons(uart1) == 4){}

        break;

        case 3:
        lcdPrint(uart1, 1, "En1 = %d", encoderGet(encoderR));
        lcdPrint(uart1, 2, "gyro = %d", gyroGet(gyro));
          if(lcdReadButtons(uart1) == 2){
              lcdClear(uart1);
              lcdSetText(uart1, 1, "wait");
              delay(btn_time);
              screen = screen + 1;}
          if(lcdReadButtons(uart1) == 1){}
          if(lcdReadButtons(uart1) == 4){}
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
            lcdSetText(uart1, 2, "Mobile L Red");
          break;
          case 2:
            lcdSetText(uart1, 2, "Mobile R BLue");
          break;
          case 3:
            lcdSetText(uart1, 2, "Mobile R Red");
          break;
          case 4:
            lcdSetText(uart1, 2, "Mobile L Blue");
          break;
          case 5:
            lcdSetText(uart1, 2, "StationaryRED");
          break;
          case 6:
            lcdSetText(uart1, 2, "StationaryBLUE");
          break;
          case 7:
            lcdSetText(uart1, 2, "20 Red Point Zone");
          break;
          case 8:
            lcdSetText(uart1, 2, "20 Blue Point Zone");
          break;
          }}
          delay(20);
  }
  else{delay(50);}
  }
}

void opcontrollcd(void *ignore){
  int screen = 1;
  int screen_cap = 2;
  int btn_time = 100;
  lcdClear(uart1);

  while(isEnabled()){
    delay(25);
    switch(screen){

      case 1:
      lcdPrint(uart1, 1, "Gyro %d", gyroGet(gyro));
      lcdPrint(uart1, 2, "En1: %d", encoderGet(encoderR));
        if(lcdReadButtons(uart1) == 2){
            lcdClear(uart1);
            lcdSetText(uart1, 1, "wait");
            delay(btn_time);
            screen = screen + 1;}
        if(lcdReadButtons(uart1) == 1){
          encoderReset(encoderR);
          gyroReset(gyro);
          delay(50);
        }
        if(lcdReadButtons(uart1) == 4){
          analogCalibrate(1);
          encoderReset(encoderA);
          delay(50);
        }
      break;


      case 2:
      lcdPrint(uart1, 1, "P.C: %d", analogRead(1));
      lcdPrint(uart1, 2, "EnCB: %d", encoderGet(encoderA));
        if(lcdReadButtons(uart1) == 2){
            lcdClear(uart1);
            lcdSetText(uart1, 1, "wait");
            delay(btn_time);
            screen = screen + 1;}
        if(lcdReadButtons(uart1) == 1){
          encoderReset(encoderR);
          gyroReset(gyro);
          delay(50);
        }
        if(lcdReadButtons(uart1) == 4){
          analogCalibrate(1);
          encoderReset(encoderA);
          delay(50);
        }
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

void autolcd(void *ignore){
  int screen = 1;
  int screen_cap = 2;
  int btn_time = 100;
  lcdClear(uart1);

  while(isAutonomous()){
    delay(25);
    switch(screen){

      case 1:
      lcdPrint(uart1, 1, "Gyro %d", gyroGet(gyro));
      lcdPrint(uart1, 2, "En1: %d", encoderGet(encoderR));
        if(lcdReadButtons(uart1) == 2){
            lcdClear(uart1);
            lcdSetText(uart1, 1, "wait");
            delay(btn_time);
            screen = screen + 1;}
        if(lcdReadButtons(uart1) == 1){/*action*/}
        if(lcdReadButtons(uart1) == 4){/*action*/}
      break;

      case 2:
      lcdPrint(uart1, 1, "Gyro %d", gyroGet(gyro));
      lcdPrint(uart1, 2, "En1: %d", encoderGet(encoderR));
        if(lcdReadButtons(uart1) == 2){
            lcdClear(uart1);
            lcdSetText(uart1, 1, "wait");
            delay(btn_time);
            screen = screen + 1;}
        if(lcdReadButtons(uart1) == 1){
          encoderReset(encoderR);
          gyroReset(gyro);
          delay(50);
        }
        if(lcdReadButtons(uart1) == 4){
          analogCalibrate(1);
          encoderReset(encoderA);
          delay(50);
        }
      break;

      }
    if(screen > screen_cap){screen = 1;}
  }

  taskDelete(autolcd_task);
}
