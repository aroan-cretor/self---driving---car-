#define echoPin 2// attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3//attach pin D3 Arduino to pin Trig of HC-SR04
#include<Servo.h>
Servo Myservo;
int pos;
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement


int leftf1=7;
int leftf2=6;
int rightf1=5;
int rightf2=4;
int distance1; 
int distance2;

void setup()
{

          pinMode(leftf1, OUTPUT);
          pinMode(leftf2, OUTPUT);
          pinMode(rightf1, OUTPUT);
          pinMode(rightf2, OUTPUT);
          
      
      
      
         
        pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
        pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
        Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
        Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
        Serial.println("with Arduino UNO R3");
          
          Serial.begin(9600);
          Myservo.attach(8);

}
void loop()
{

              
          
             
            pos  = 73;
            Myservo.write(pos);
            delay(100);
          
          
              sens();
              
          if(distance>10)
          {
            forward();
            Serial.println("go");
            Serial.println(distance);
            
            }
          
          
            
           else if (distance < 10)
          {
            
             off();
            Serial.println("off");
            delay(100);

            reverse();
             delay(400);
             off();
            Serial.println("off");
            delay(100);
            
            pos  = 100;
            Myservo.write(pos);
            sens1();
            delay(1000);
          
            pos  = -100;
            Myservo.write(pos);
            sens2();
            delay(1000);



            
           
            
          

            if(distance1 >  distance2)
            {
              
              
            
               anticlockwise();
               delay(1500);
                pos  = 73;
              Myservo.write(pos);
               delay(100);
                sens();
            forward();
                     




                    
              
              }
              
              else if(distance1 < distance2)
              {
                 clockwise();
                 delay(1500);
                     pos  = 73;
                  Myservo.write(pos);
                   delay(100);
                  sens();
                      forward();
               
               
                
                
                }




          }
            

  

}


void forward()
{
  Serial.println("forward");


   digitalWrite(leftf1, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(leftf2, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(rightf1, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(rightf2, HIGH);   // turn the LED on (HIGH is the voltage level)
   
  
  
  }
  void reverse()
  {
   
 digitalWrite(leftf1,LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(leftf2, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(rightf1, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(rightf2, LOW);   // turn the LED on (HIGH is the voltage level)    // wait for a second

    }
      void anticlockwise()
  {
   
  digitalWrite(leftf1, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(leftf2, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(rightf1, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(rightf2, LOW);   // turn the LED on (HIGH is the voltage level)

    }
      void clockwise()
  {
   
  digitalWrite(leftf1, LOW);   // turn the LED on (HIGH is the voltage level)
   digitalWrite (leftf2, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(rightf1, LOW);   // turn the LED on (HIGH is the voltage level)
 digitalWrite(rightf2, HIGH);   // turn the LED on (HIGH is the voltage level)

    }
       void off()
  {
   
  digitalWrite(leftf1, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(leftf2, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(rightf1, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(rightf2, LOW);   // turn the LED on (HIGH is the voltage level)

    }

          void sens()
    {

       digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
      }



       void sens1()
    {

       digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance1 = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance1);
  Serial.println(" cm");
      }


       void sens2()
    {
  
          digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance2 = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance2);
  Serial.println(" cm");
      }
