
#include <Servo.h>
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;
int count=0;
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  myservo.attach(9);
  Serial.begin(9600);
}


void loop() {
  int value = analogRead(A0);

  if(value<40){
      count += 1;
      if(count==1){
        digitalWrite(LED_BUILTIN, HIGH);
        Serial.println(value);
        Serial.println("Analog value : ");
        for (pos = 135; pos <= 360; pos += 30) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the servo to reach the position
        }
        for (pos = 360; pos >= 90; pos -= 10) { // goes from 180 degrees to 0 degrees
          myservo.write(pos);              // tell servo to go to position in variable 'pos'
          delay(15);                       // waits 15ms for the servo to reach the position
        }
        if(count>3){
          count -=1;
        }    
      }
  }else{
    count=0;
    digitalWrite(LED_BUILTIN, LOW);
  }
 
  delay(1000);
}
