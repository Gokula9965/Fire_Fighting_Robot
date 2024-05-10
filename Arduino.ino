#include <Servo.h>

Servo myservo;  
int pos = 0;  //servo motor
// Motor A
int in1 = 2;
int in2 = 3;

// Motor B
int in3 = 4;
int in4 = 5;

// Motor C
int in5 = 6;
int in6 = 7;

// Motor D
int in7 = 8;
int in8 = 9;

int in10=10;// pump Motor
// Flame sensors
int flameSensor1 = A0; // Analog pin for Flame Sensor 1
int flameSensor2 = A1; // Analog pin for Flame Sensor 2
int flameSensor3 = A2; // Analog pin for Flame Sensor 3

void setup() {
  // Set all the motor control pins to outputs for Motors A, B, C, and D
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(in5, OUTPUT);
  pinMode(in6, OUTPUT);
  pinMode(in7, OUTPUT);
  pinMode(in8, OUTPUT);
  pinMode(in10, OUTPUT);

  // Set all the flame sensor pins to inputs
  pinMode(flameSensor1, INPUT);
  pinMode(flameSensor2, INPUT);
  pinMode(flameSensor3, INPUT);

 myservo.attach(13);
  Serial.begin(9600); // Initialize serial communication
}

void runServoMotor()
{
  digitalWrite(in10, LOW);
     for (pos = 45; pos <= 185; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 185; pos >= 45; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  delay(300);
  digitalWrite(in10, HIGH);
}
void put_off_fire()
{
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    digitalWrite(in5, LOW);
    digitalWrite(in6, LOW);
    digitalWrite(in7, LOW);
    digitalWrite(in8, LOW);
    runServoMotor();
    delay(2000);
    return;
}
void loop() {
  // Read flame sensor values
  int flameValue1 = analogRead(flameSensor1);
  int flameValue2 = analogRead(flameSensor2);
  int flameValue3 = analogRead(flameSensor3);

  // Print flame sensor values to Serial Monitor
  Serial.print("Flame Sensor 1: ");
  Serial.print(flameValue1);
  Serial.print(" | Flame Sensor 2: ");
  Serial.print(flameValue2);
  Serial.print(" | Flame Sensor 3: ");
  Serial.println(flameValue3);

if (flameValue1<700) { //1 
    // Move towards the right
    // Serial.println("Flame 1 is making it turn right");
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    digitalWrite(in5, LOW);
    digitalWrite(in6, HIGH);
    digitalWrite(in7, LOW);
    digitalWrite(in8, HIGH);
    digitalWrite(in10, HIGH);
        delay(300);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    digitalWrite(in5, LOW);
    digitalWrite(in6, LOW);
    digitalWrite(in7, LOW);
    digitalWrite(in8, LOW);
    digitalWrite(in10, HIGH);
  // } else if (flameValue2 < flameValue1 && flameValue2<flameValue3 && flameValue2<800) { //working
    } else if (flameValue2<700) { //working
    // Move towards the left
    // Serial.println("Flame 2 is making it turn left");
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    digitalWrite(in5, LOW);
    digitalWrite(in6, HIGH);
    digitalWrite(in7, LOW);
    digitalWrite(in8, LOW);
    digitalWrite(in10, HIGH);
    delay(300);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    digitalWrite(in5, LOW);
    digitalWrite(in6, LOW);
    digitalWrite(in7, LOW);
    digitalWrite(in8, LOW);
    digitalWrite(in10, HIGH);

      } else if (flameValue3<700) {
    // Move forward (or perform an appropriate action based on your setup)
    // Adjust this part based on your specific requirements
    // Serial.println("Flame 3 is making it go straight");
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    digitalWrite(in5, LOW);
    digitalWrite(in6, HIGH);
    digitalWrite(in7, LOW);
    digitalWrite(in8, HIGH);
    digitalWrite(in10, HIGH);
    delay(300);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    digitalWrite(in5, LOW);
    digitalWrite(in6, LOW);
    digitalWrite(in7, LOW);
    digitalWrite(in8, LOW);
    digitalWrite(in10, HIGH);
  } else {
    // Serial.println("No flame detected");
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    digitalWrite(in5, LOW);
    digitalWrite(in6, LOW);
    digitalWrite(in7, LOW);
    digitalWrite(in8, LOW);
    digitalWrite(in10, HIGH);
    delay(300);
  }
  if((500<flameValue1<600  ||  500<flameValue2<600  || 500<flameValue3<600) && flameValue1!=1023 && flameValue2!=1023 && flameValue3!=1023) //stop it and start the motor
  {
      put_off_fire();
  }
  delay(300);
}
