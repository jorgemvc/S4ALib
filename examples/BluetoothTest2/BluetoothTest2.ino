/** @file    BluetoothTest2.h
 *  @author  Jorge Villalobos Carvajal (jorgemvc@gmail.com)
 *  @date    19.Mar.2019  
 *  @version 1.0 
 *  
 *  @brief   Simple example for S4ALib usage with Bluetooth
 *           controller (HC-06).
 *
 *  @licence  MIT License
 */
#include <S4ALib.h>
#include <SoftwareSerial.h>

enum eDirection {
  forward_dir,
  backward_dir,
  stopped
};

SoftwareSerial bt(1,0);
char   lectura;
String hilera = "";
eDirection direction;
int    i, v;

S4ALib Robot;
void setup() {
  Robot.begin();
  bt.begin(9600);
  v = 0;
  direction = stopped;
}  // setup

void loop() {
  if (bt.available()) {
    while (bt.available()) {
      lectura = (char)bt.read();
      hilera += lectura;
    }

    switch (hilera[0]) {
      case 'r':
        Robot.right(100);
        break;
        
      case 'l':
        Robot.left(100);
        break;  

      case 'u':
        direction = forward_dir;
        break;

      case 'd':
        direction = backward_dir;
        break;

      case 's':
        direction = stopped;
        break;

      default:
        setSpeed(hilera);
        break;
    }  // switch

    hilera = "";
  }  // bt is available  
}  // loop

void setSpeed(String str){
  if (isDigit(str[0])) {
    i = str.toInt();
    if (i == 0) i = 10;
    v = map(i, 1, 10, 0, 255);
    Robot.setSpeed(v, v);
  } else {
    moveRobot();
  }
}  // setSpeed

void moveRobot() {
  if (direction == stopped) {
    Robot.ledOn();
    Robot.stop();
    
  } else if (direction == forward_dir) {
    Robot.ledOff();
    Robot.forward();
    
  } else {
    Robot.ledOff();
    Robot.backward();
  }
}  // moveRobot
