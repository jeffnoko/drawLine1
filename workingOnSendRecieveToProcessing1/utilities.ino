
unsigned int bitOut(void)
{
  static unsigned long firstTime=1, prev=0;
  unsigned long bit1=0, bit0=0, x=0, port=0, limit=99;
  if (firstTime)
  {
    firstTime=0;
    prev=analogRead(port);
  }
  while (limit--)
  {
    x=analogRead(port);
    bit1=(prev!=x?1:0);
    prev=x;
    x=analogRead(port);
    bit0=(prev!=x?1:0);
    prev=x;
    if (bit1!=bit0)
      break;
  }
  return bit1;
}
//------------------------------------------------------------------------------
unsigned long seedOut(unsigned int noOfBits)
{
  // return value with 'noOfBits' random bits set
  unsigned long seed=0;
  for (int i=0;i<noOfBits;++i)
    seed = (seed<<1) | bitOut();
  return seed;
}

void s1up(){
   stepper3.setMaxSpeed(500);
  stepper3.setAcceleration(500);
  stepper3.moveTo(100);
  stepper3.runToPosition();
  }
void s1down(){
   stepper3.setMaxSpeed(500);
  stepper3.setAcceleration(500);
   stepper3.moveTo(0);
  stepper3.runToPosition();
}
void s1upR(){
   stepper3.setMaxSpeed(500);
  stepper3.setAcceleration(500);
 // stepper3.moveTo(random(0,500));
   stepper3.moveTo(0);
  stepper3.runToPosition();
  }
  
  void zUpRandom(){
     stepper3.setMaxSpeed(500);
  stepper3.setAcceleration(500);
  stepper3.moveTo(random(0,500));
  //stepper3.runToPosition();
  }
  void zDown(){
     stepper3.setMaxSpeed(500);
  stepper3.setAcceleration(500);
   stepper3.moveTo(0);
 // stepper3.runToPosition();
  }
  /*
void sprayOn(){
  for(i= 160; i <= 180; i++)
  servo2.write(i);
  delay(200);
  
}
void sprayOff(){
  servo2.write(160);
}

*/

/*
void button(){
  
  
  button1Reading = digitalRead(A5);
  if (button1Reading == LOW && button1Previous == HIGH && millis() - time > debounce) {
    if (button1State == LOW){
      button1State = HIGH;
    }
    else
      button1State = LOW;
    time = millis();    
  }

  button1Previous = button1Reading;

  if (button1State == LOW ){      }
} 
*/
 /*
  button1Reading = digitalRead(A5);
  if (button1Reading == HIGH && button1Previous == LOW && millis() - time > debounce) {
    if (button1State == HIGH){
      button1State = LOW;
    }
    else
      button1State = HIGH;
    time = millis();    
  }

  button1Previous = button1Reading;

  if (button1State == HIGH ){      }
  
  */
  void spray1(){
     servo2.write(173);//trigger 171
 // delay(100); 
  //delay(random(500,1000));
   voltageV = analogRead(A10);voltageV = map(voltageV,0,1023, 0,500);
    voltageU = analogRead(A11); delay(20);
    paint = map(voltageU,0,1023,90,110);
   servo1.write(paint);//paint
   delay(voltageV);
    servo1.write(90);//paint
  delay(100); 
  servo2.write(167);delay(500);//trigger 165
  
  // servo3.write(120);//shield
  //  delay(500);
   // servo3.write(90);//shield
   //  delay(500);
    
  }
   void spray1copy(){
     servo2.write(180);//trigger 171
  delay(400); 
  //delay(random(500,1000));
   voltageV = analogRead(A10);voltageV = map(voltageV,0,1023, 0,500);
   
   servo1.write(paint);//paint
   delay(voltageV);
    servo1.write(90);//paint
  delay(100); 
  servo2.write(165);delay(500);//trigger 165
  
  // servo3.write(120);//shield
  //  delay(500);
   // servo3.write(90);//shield
   //  delay(500);
    
  }
  
   void spray2(){
     int q ;
     int w ;
     servo2.write(q);//trigger 160
  //delay(10); 
  //delay(random(500,1000));
  // servo1.write(w);//paint
  // delay(d);
 //   servo1.write(85);//paint
 // delay(10); 
  servo2.write(145);delay(20);//trigger 145
  
  // servo3.write(120);//shield
  //  delay(500);
   // servo3.write(90);//shield
   //  delay(500);
    
  }
  
  void sprayOn(int intensity){
     servo2.write(174);//trigger 160
  delay(400); 
   voltageV = analogRead(A10);voltageV = map(voltageV,0,1023, 0,500);
  //delay(random(500,1000));
  // servo1.write(voltageV);//paint
   paint = map(intensity,0,1023,90,100);//was 110
   servo1.write(paint);//paint
   delay(100);
  }
   void sprayOn1(){
     servo2.write(174);//trigger 160
 // delay(400); 
 //  voltageV = analogRead(A10);voltageV = map(voltageV,0,1023, 0,500);
  //delay(random(500,1000));
  // servo1.write(voltageV);//paint
 //  paint = map(intensity,0,1023,90,100);//was 110
    paint = 93;
    // paint = random(90,100);
   servo1.write(paint);//paint
  // delay(100);
  }
  
  void sprayOff(){
      servo1.write(90);//paint
  //delay(100); 
  servo2.write(167);//delay(100);//trigger 145
  }
  
   void sprayclean(){
     long positions[2];
      positions[0] =  -300;//(g2 - random(-100,100) );//stepper#1  horizontal
  positions[1] =  1000 ;//stepper#2 up down
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
  s1upR();
  spray1(); 
  //shieldClean2();
     
     
     
   }
   
   void shieldClean1(){
     
   servo3.write(120);//shield
    delay(500);
    servo3.write(90);//shield
     delay(500);
   }
   
    void shieldClean2(){
     
   servo3.write(120);//shield
    delay(500);
    servo3.write(90);//shield
     delay(500);
   }
   
   void motors(){
     long positions[2];
       positions[0] =  aSegment + abuffer;//(g2 - random(-100,100) );//stepper#1  horizontal
  positions[1] =  bStart + bbuffer;//stepper#2 up down
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
     
   }
   
   void homing(){
     long positions[2];
      sensorStateX1 = digitalRead(sensorX1);  //Serial.println(sensorStateX1);delay(200);
   stepper1.setMaxSpeed(1000);
  stepper2.setMaxSpeed(1000);
 // if(sensorStateX1 == 1){
  while( sensorStateX1 == 1){
    //stepper1.move(-10000);
    //stepper1.run();
    // stepper1.setCurrentPosition(0);
    //sensorStateX1 = digitalRead(sensorX1);
  //int numberOfLines = random(2,100);
  
   positions[0] =  -10;//(g2 - random(-100,100) );//stepper#1  horizontal
  positions[1] = 0;//stepper#2 up down
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
   sensorStateX1 = digitalRead(sensorX1);
   stepper1.setCurrentPosition(0);
   stepper2.setCurrentPosition(0);
   
  }
   //stepper1.run();
 // }
  sensorStateY1 = digitalRead(sensorY1);  Serial.println(sensorStateY1);delay(200);
  
   //if(sensorStateY1 == 1){
 
  while( sensorStateY1 == 1){
  
   // sensorStateY1 = digitalRead(sensorY1);
    
  //int numberOfLines = random(2,100);
   positions[0] =  0;//(g2 - random(-100,100) );//stepper#1  horizontal
  positions[1] = -10;//stepper#2 up down
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
   sensorStateY1 = digitalRead(sensorY1);
   stepper1.setCurrentPosition(0);
   stepper2.setCurrentPosition(0);
   //Serial.println(sensorStateY1);delay(200);
   
  }
  stepper1.setCurrentPosition(0);
   stepper2.setCurrentPosition(0);
   }
   
     void homingX(){
   
      sensorStateX1 = digitalRead(sensorX1);  //Serial.println("inside homingX loop");delay(200);
   stepper1.setMaxSpeed(1500);

  while(  sensorStateX1 == 1){
     sensorStateX1 = digitalRead(sensorX1);
      stepper1.moveTo(-100000);
      stepper1.run();
      // Serial.println("inside while loop");delay(20);
      // stepper1.setCurrentPosition(0);
  }
 // stepper1.setCurrentPosition(0);
 }
 
  void homingY(){
   
      sensorStateY1 = digitalRead(sensorY1);  //Serial.println(sensorStateX1);delay(200);
   stepper2.setMaxSpeed(1500);

  while(  sensorStateY1 == 1){
     sensorStateY1 = digitalRead(sensorY1);
      stepper2.moveTo(-100000);
      stepper2.run();
      // stepper1.setCurrentPosition(0);
  }

 }
 
 void homingXY(){
    stepper1.setMaxSpeed(1500);
     stepper2.setMaxSpeed(1500);
   //  Serial.print("start homingXY");
   homingX();
    homingY();
     stepper1.setCurrentPosition(0);
   stepper2.setCurrentPosition(0);
 }
  
   
    void homingTest(){
     long positions[2];
      sensorStateX1 = digitalRead(sensorX1);  //Serial.println(sensorStateX1);delay(200);
   stepper1.setMaxSpeed(1000);
  stepper2.setMaxSpeed(1000);
 // if(sensorStateX1 == 1){
  while( sensorStateX1 == 1){
    //stepper1.move(-10000);
    //stepper1.run();
    // stepper1.setCurrentPosition(0);
    //sensorStateX1 = digitalRead(sensorX1);
  //int numberOfLines = random(2,100);
  
   positions[0] =  positions[0] ;//(g2 - random(-100,100) );//stepper#1  horizontal
  positions[1] = -10;//stepper#2 up down
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
   sensorStateX1 = digitalRead(sensorX1);
   stepper1.setCurrentPosition(0);
   stepper2.setCurrentPosition(0);
   
  }
   //stepper1.run();
 // }
  sensorStateY1 = digitalRead(sensorY1);  Serial.println(sensorStateY1);delay(200);
  
   //if(sensorStateY1 == 1){
 
  while( sensorStateY1 == 1){
  
   // sensorStateY1 = digitalRead(sensorY1);
    
  //int numberOfLines = random(2,100);
   positions[0] =  -10;//(g2 - random(-100,100) );//stepper#1  horizontal
  positions[1] =  positions[1];//stepper#2 up down
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
   sensorStateY1 = digitalRead(sensorY1);
   stepper1.setCurrentPosition(0);
   stepper2.setCurrentPosition(0);
   //Serial.println(sensorStateY1);delay(200);
   
  }
  stepper1.setCurrentPosition(0);
   stepper2.setCurrentPosition(0);
   }
   
   
    void homing2(){
         long positions[2];
        sensorStateX1 = digitalRead(sensorX1); // Serial.println(sensorStateX1);delay(200);
         sensorStateY1 = digitalRead(sensorY1);
 //  stepper1.setMaxSpeed(1000);
 // stepper2.setMaxSpeed(1000);
      while( sensorStateX1 == 1 || sensorStateY1 ==1){
          positions[0] =  -10;//(g2 - random(-100,100) );//stepper#1  horizontal
  positions[1] = -10;//stepper#2 up down
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
  sensorStateX1 = digitalRead(sensorX1);
   sensorStateY1 = digitalRead(sensorY1);
   stepper1.setCurrentPosition(0);
   stepper2.setCurrentPosition(0);
        
      }
    }
    
     void homing3(){
       long positions[2];
       // sensorStateX1 = digitalRead(sensorX1);  Serial.println(sensorStateX1);delay(200);
  // stepper1.setMaxSpeed(1000);
  //stepper2.setMaxSpeed(1000);
     // while( sensorStateX1 == 1 || sensorStateY1 ==1){
          positions[0] =  0;//(g2 - random(-100,100) );//stepper#1  horizontal
  positions[1] = 0;//stepper#2 up down
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
 // sensorStateX1 = digitalRead(sensorX1);
  // sensorStateY1 = digitalRead(sensorY1);
  // stepper1.setCurrentPosition(0);
  // stepper2.setCurrentPosition(0);
        
     // }
    }
    
     void homing4(){
      // long positions[2];
        sensorStateX1 = digitalRead(sensorX1);  //Serial.println(sensorStateX1);delay(200);
  // st
  
  
  
  
  
  
  //stepper1.setMaxSpeed(1000);
  //stepper2.setMaxSpeed(1000);
      if( sensorStateX1 == 1 ){
        //  positions[0] =  0;//(g2 - random(-100,100) );//stepper#1  horizontal
 // positions[1] = 0;//stepper#2 up down
  stepper1.moveTo(-100);
   sensorStateX1 = digitalRead(sensorX1);
      }
  stepper1.run();
  // stepper2.moveTo(0);
 // stepper2.run();
 // sensorStateX1 = digitalRead(sensorX1);
  // sensorStateY1 = digitalRead(sensorY1);
   stepper1.setCurrentPosition(0);
  // stepper2.setCurrentPosition(0);
        
      }
   
