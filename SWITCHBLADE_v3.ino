#include <AFMotor.h>
#include <Servo.h>

AF_DCMotor motor2(2,MOTOR12_64KHZ); // create motor #4, 64KHz pwm
AF_DCMotor motor1(1,MOTOR12_64KHZ);
AF_DCMotor rotorX(3,MOTOR12_64KHZ);
AF_DCMotor rotorY(4,MOTOR12_64KHZ); 
int state = 0;

int angle1 = 90;
int angle2 = 90;

 
Servo servo1;
Servo servo2;


void setup() 
{
  Serial.begin(115200);           // set up Serial library at 9600 bps
  Serial.println("          Welcome: Forward=1   Left=2   Right=3   Backwards=4   Stop=0   Up=5   Down=6   Clockwise=7   Anti-Clockwise=8   FIRE=9  ");
  motor2.setSpeed(200);     // set the speed to 200
  motor1.setSpeed(200);     // set the speed to 200
  rotorX.setSpeed(200);
  rotorY.setSpeed(200);
  servo1.attach(9);
  servo2.attach(10);
}


void loop() {
  //if some data is sent, read it and save it in the state variable
if(Serial.available() > 0)
  {
    state = Serial.read();
    Serial.print("I received: ");
    Serial.println(state);
    delay(10);

    if (state == '0') 
    {
      motor2.setSpeed(200);     // set the speed to 200/255
      motor1.setSpeed(200);     // set the speed to 200/255
      rotorX.setSpeed(200);
      rotorY.setSpeed(200);
      motor2.run(RELEASE);      // turn it on going forward
      motor1.run(RELEASE);      // turn it on going forward
      rotorX.run(RELEASE);
      rotorY.run(RELEASE);
      Serial.println("Stopped <<TANK DIS-ENGAGED>>");
      delay(100);
      state = 0; 
    }
    
    else if (state == '1')      // If 1 Forwards
    {
      motor2.run(RELEASE);      // turn it on going forward
      motor1.run(RELEASE);      // turn it on going forward
      motor2.setSpeed(500);     // set the speed to 200
      motor1.setSpeed(500);     // set the speed to 200
      motor2.run(FORWARD);      // turn it on going forward
      motor1.run(FORWARD);      // turn it on going forward
      Serial.println("Forward:- ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ ");
      delay(100);
      state = 0; 
    }
    
    else if (state == '2')      // If 2 Turn Left
    { 
      motor2.run(RELEASE);      // turn it on going forward
      motor1.run(RELEASE);      // turn it on going forward  
      motor1.setSpeed(500);     // set the speed to 200/255
      motor2.setSpeed(500);
      motor1.run(FORWARD);
      motor2.run(BACKWARD);      
      Serial.println("Left:-    <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< "); 
      delay(100);
      state = 0;     
    }
    else if (state == '3') {    // If 3 Turn Right
      motor2.run(RELEASE);      // turn it on going forward
      motor1.run(RELEASE);      // turn it on going forward
      motor2.setSpeed(500);     // set the speed to 255
      motor1.setSpeed(500);
      motor2.run(FORWARD);      
      motor1.run(BACKWARD);    
      Serial.println("Right:-   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> ");
      delay(100);
      state = 0;  
    }
    
    else if (state == '4')       // If 4 Backwards
    {
      motor2.run(RELEASE);      // turn it on going forward
      motor1.run(RELEASE);      // turn it on going forward
      motor2.setSpeed(450);      // set the speed to 200
      motor1.setSpeed(450);      // set the speed to 200
      motor2.run(BACKWARD);      // Motor 2 backwards
      motor1.run(BACKWARD);      // Motor 1 backwards
      Serial.println("Backward:- vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvz ");
      delay(100);
      state = 0;   
    }
    
     else if(state == '5')
    {
      while(state == '5')
      {
        angle1 = angle1 + 30;
        if(angle1>180)
        {
          servo1.write(180);
        }
        else if(angle1<0)
        {
          servo1.write(0);
        }
        delay(50);
        servo1.write(angle1);
        Serial.println("UP:-   AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA ");    
        if(state == '5')
        break;
      }
    }
    else if(state == '6')
    {
      while(state == '6'){
        angle1 = angle1 - 30;
        if(angle1>180)
        {
          servo1.write(180);
          }
          if(angle1<0)
        {
          servo1.write(0);
          }
        delay(50);
              
       servo1.write(angle1);
       Serial.println("DOWN:-  VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV ");
       if(state == '6')
       break;
      }
    }

    if(state == '7')
    {
   
     while(state == '7')
     {
       
        angle2 = angle2 + 30;
        if(angle2>180)
        {
          servo2.write(180);
          }
          if(angle2<0)
        {
          servo2.write(0);
          }
        delay(50);
              
     servo2.write(angle2);
     Serial.println("clockwise:-]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]] ");
     if(state == '7')
       break;
       }
     }
     if(state == '8') 
     {
       
       while(state == '8') 
       {
         
        angle2 = angle2 - 30;
        if(angle2>180)
        {
          servo2.write(180);
          }
          if(angle2<0)
        {
          servo2.write(0);
          }
        delay(50);
              
       servo2.write(angle2);
       Serial.println("anti-clockwise:-[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[ ");
       if(state == '8')
       break;
       
       }
     }
     else if (state == '9')
     {
      rotorX.run(RELEASE);
      rotorY.run(RELEASE);
      rotorX.setSpeed(255);
      rotorY.setSpeed(500);
      rotorX.run(FORWARD);
      delay(250);
      rotorY.run(FORWARD);
      Serial.println("CANNON ARMED");
      delay(2000);
      Serial.println("FIRE:-       <+>  <+>");
      delay(7000);
      rotorX.run(BACKWARD);
      rotorY.run(BACKWARD);
      Serial.println("RELOAD:-     <->  <->");
      delay(5000);
      rotorX.run(RELEASE);
      rotorY.run(RELEASE);
      Serial.println("CANNON DIS-ENGAGED");
      state = 0;
     }


    
    else if (state > '9')
    {
      Serial.println("Invalid");
      delay(100);
      state = 0; 
    }
  }
}
