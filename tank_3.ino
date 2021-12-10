#include <Servo.h>
#define ENA_m1 5        // Enable/speed motor Right 
#define ENB_m1 6        // Enable/speed motor Left
#define ENA_m2 10       // Enable/speed motor Reload
#define ENB_m2 11       // Enable/speed motor Fire

#define IN_11a  2        // L298N #1 in 1 motor Right
#define IN_12a  3        // L298N #1 in 2 motor Right
#define IN_13b  4        // L298N #1 in 3 motor Left
#define IN_14b  7        // L298N #1 in 4 motor Left

#define IN_21a  8        // L298N #2 in 1 motor Reload
#define IN_22a  9        // L298N #2 in 2 motor Arm
#define IN_23b  12       // L298N #2 in 3 motor Disengage
#define IN_24b  13       // L298N #2 in 4 motor Fire

int command;             //Int to store app command state.
int speedCar = 255;     // 50 - 255.
int angleX=90;
int angleY=90;
Servo x;
Servo y;
int led=19;
int brightness=0;

void setup() {
    pinMode(ENA_m1, OUTPUT);
    pinMode(ENB_m1, OUTPUT);  // L298N #1
    pinMode(ENA_m2, OUTPUT);
    pinMode(ENB_m2, OUTPUT);  // L298N #2
  
    pinMode(IN_11a, OUTPUT);
    pinMode(IN_12a, OUTPUT);
    pinMode(IN_13b, OUTPUT);
    pinMode(IN_14b, OUTPUT);  // L298N #1
    
    pinMode(IN_21a, OUTPUT);
    pinMode(IN_22a, OUTPUT);
    pinMode(IN_23b, OUTPUT);
    pinMode(IN_24b, OUTPUT);  // L298N #2
    pinMode(14, OUTPUT);
    pinMode(15, OUTPUT);
    pinMode(led, OUTPUT);
    x.attach(14);
    y.attach(15);
   
        
Serial.begin(115200);
Serial.println("F-forward , B-backward , L-turn left , R-turn right , u-canon up , d-canon down , l-canon left , r-canon right , K-canon reload , C-canon fire , S-stop");

}

void goAhead(){
      digitalWrite(IN_11a, HIGH);
      digitalWrite(IN_12a, LOW);
      analogWrite(ENA_m1, speedCar);

      digitalWrite(IN_13b, HIGH);
      digitalWrite(IN_14b, LOW);
      analogWrite(ENB_m1, speedCar);
      Serial.println("FORWAR4D");
      brightness=155;
      digitalWrite(led, HIGH);
      analogWrite(led, brightness);
}


void goBack(){
      digitalWrite(IN_11a, LOW);
      digitalWrite(IN_12a, HIGH);
      analogWrite(ENA_m1, speedCar);


      digitalWrite(IN_13b, LOW);
      digitalWrite(IN_14b, HIGH);
      analogWrite(ENB_m1, speedCar);
      Serial.println("BACKWARD");
      brightness=155;
      digitalWrite(led, HIGH);
      analogWrite(led, brightness);
}


void goRight(){
      digitalWrite(IN_11a, LOW);
      digitalWrite(IN_12a, HIGH);
      analogWrite(ENA_m1, speedCar);


      digitalWrite(IN_13b, HIGH);
      digitalWrite(IN_14b, LOW);
      analogWrite(ENB_m1, speedCar);
      Serial.println("RIGHT");
}


void goLeft(){
      digitalWrite(IN_11a, HIGH);
      digitalWrite(IN_12a, LOW);
      analogWrite(ENA_m1, speedCar);


      digitalWrite(IN_13b, LOW);
      digitalWrite(IN_14b, HIGH);
      analogWrite(ENB_m1, speedCar);
      Serial.println("LEFT");
}


int xRight(int angle){
      int ang=angle;
      int i=0;
      while(ang>=0)
      {
        x.write(ang);
        i++;ang++;
        delay(50);
        if(i==20)
        break;
        if(ang>=180)
        ang=180;
      }
      Serial.println("CANON FACE RIGHT");
      return ang;
  
}


int xLeft(int angle){
      int ang=angle;
      int i=0;
      while(ang<=180)
     {
       x.write(ang);
       i++;ang--;
       delay(50);
       if(i==20)
       break;
       if(ang<=0)
       ang=0;
     }
     Serial.println("CANON FACE LEFT");
     return ang;
  
}


int yDown(int *angle){
      int ang=angle;
      int i=0;
      while(ang>=0)
      {
        y.write(ang);
        i++;ang++;
        delay(50);
        if(i==20)
        break;
        if(ang>=180)
        ang=180;
      }
      Serial.println("CANON FACE DOWN");
      return ang;
}


int yUp(int angle){
      int ang=angle;
      int i=0;
      while(ang<=180)
     {
       y.write(ang);
       i++;ang--;
       delay(50);
       if(i==20)
       break;
       if(ang<=0)
       ang=0;
     }
     Serial.println("CANON FACE UP");
     return ang;
    
}


void reload(){
      Serial.println("DROPPING CARTRIDGE");
      digitalWrite(IN_21a, HIGH);
      digitalWrite(IN_22a, LOW);
      analogWrite(ENA_m2, speedCar);

      digitalWrite(IN_23b, HIGH);
      digitalWrite(IN_24b, LOW);
      analogWrite(ENB_m2, 150);
      Serial.println("Dis-Engaging CANON PLEASE RELOAD");

      delay(1500);
      
      digitalWrite(IN_21a, LOW);
      digitalWrite(IN_22a, LOW);
      analogWrite(ENA_m2, speedCar);

      digitalWrite(IN_23b, LOW);
      digitalWrite(IN_24b, LOW);
      analogWrite(ENB_m2, 150);
      
}


void fire(){
      
      Serial.println("CANON ARMED");
      brightness=255;
      digitalWrite(led, HIGH);
      analogWrite(led, brightness);
      delay(300);
      brightness=0;
      digitalWrite(led, HIGH);
      analogWrite(led, brightness);
      delay(300);
      brightness=255;
      digitalWrite(led, HIGH);
      analogWrite(led, brightness);
      delay(300);
      brightness=0;
      digitalWrite(led, HIGH);
      analogWrite(led, brightness);
      delay(300);
      brightness=255;
      digitalWrite(led, HIGH);
      analogWrite(led, brightness);
      delay(300);
      brightness=0;
      digitalWrite(led, HIGH);
      analogWrite(led, brightness);
      
      
      digitalWrite(IN_21a, LOW);
      digitalWrite(IN_22a, HIGH);
      analogWrite(ENA_m2, speedCar);

      digitalWrite(IN_23b, LOW);
      digitalWrite(IN_24b, HIGH);
      analogWrite(ENB_m2, 150);
      Serial.println("FIRING");
      
      brightness=0;
      digitalWrite(led, HIGH);
      analogWrite(led, brightness);
      delay(1000);
      brightness=255;
      digitalWrite(led, HIGH);
      analogWrite(led, brightness);
      delay(2000);
      brightness=0;
      digitalWrite(led, HIGH);
      analogWrite(led, brightness);
      
      
      digitalWrite(IN_21a, LOW);
      digitalWrite(IN_22a, LOW);
      analogWrite(ENA_m2, speedCar);
      digitalWrite(IN_23b, LOW);
      digitalWrite(IN_24b, LOW);
      analogWrite(ENB_m2, 150);
      Serial.println("FIRED");
      
}


void stopRobot(){  
       
      brightness=55;
      digitalWrite(led, HIGH);
      analogWrite(led, brightness);
      
      digitalWrite(IN_11a, LOW);
      digitalWrite(IN_12a, LOW);
      analogWrite(ENA_m1, speedCar);


      digitalWrite(IN_13b, LOW);
      digitalWrite(IN_14b, LOW);
      analogWrite(ENB_m1, speedCar);

  
      digitalWrite(IN_21a, LOW);
      digitalWrite(IN_22a, LOW);
      analogWrite(ENA_m2, speedCar);

      
      digitalWrite(IN_23b, LOW);
      digitalWrite(IN_24b, LOW);
      analogWrite(ENB_m2, speedCar);

      Serial.println("STOPPED");
  
  }



void loop(){
  if (Serial.available() > 0) {
  command = Serial.read();
  int angle1;
  int angle2; 
  switch (command){
   case 'F':goAhead();break;
   case 'B':goBack();break;
   case 'L':goLeft();break;
   case 'R':goRight();break;
   case 'K':reload();break;
   case 'C':fire();break;
   case 'S':stopRobot();break;
  }
  
  if(command=='l')
  {
     int i;
     if(angleX<=180 && angleX!=0)
     {
     for(i=0;i<15;i++)
     {
      x.write(angleX--);
      delay(50);
      if(angleX<=0)
      angleX=0;
     }
     }
     else if(angleX==0)
     Serial.println("ANTI-CLOCKWISE ANGLE LIMIT REACHED");
     Serial.println("CANON FACE LEFT");
     Serial.println(angleX);
  }

  if(command=='r')
  {
     int j;
     if(angleX>=0 && angleX!=180)
     {
     for(j=0;j<15;j++)
     {
      x.write(angleX++);
      delay(50);
      if(angleX>=180)
      angleX=180;
     }
     }
     else if(angleX==180)
     Serial.println("CLOCKWISE ANGLE LIMIT REACHED");
     Serial.println("CANON FACE RIGHT");
     Serial.println(angleX);
  }
  
  if(command=='d')
  {
     int a;
     if(angleY>=0 && angleY!=180)
     {
     for(a=0;a<15;a++)
     {
      y.write(angleY++);
      delay(50);
      if(angleY>=180)
      angleY=180;
     }
     }
     else if(angleY==180)
     Serial.println("DOWN FACE ANGLE LIMIT REACHED");
     Serial.println("CANON FACE DOWNWARDS");
     Serial.println(angleY);
  }

  if(command=='u')
  {
     int b;
     if(angleY<=180 && angleY!=0)
     {
     for(b=0;b<15;b++)
     {
      y.write(angleY--);
      delay(50);
      if(angleY<=0)
      angleY=0;
     }
     }
     else if(angleY==0)
     Serial.println("UP FACE ANGLE LIMIT REACHED");
     Serial.println("CANON FACE UPWARDS");
     Serial.println(angleY);
  }
 }
}
  
