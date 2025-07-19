//Define pins for IR sensors
#define IR_1 A1  //l5
#define IR_2 A2  //l4
#define IR_3 A3  //l3
#define IR_5 A5  //l2
#define IR_6 A6  //l1
#define IR_7 A7  //left
#define IR_4 A4  //right

// Define pins for motor control
#define LEFT_MOTOR_FORWARD 9
#define LEFT_MOTOR_BACKWARD 10
#define RIGHT_MOTOR_FORWARD 11
#define RIGHT_MOTOR_BACKWARD 12
#define ENABLE_A 3 // PWM
#define ENABLE_B 6 


void setup() {
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(A6, INPUT);
  pinMode(A7, INPUT);

  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);

  pinMode(3, OUTPUT);
  pinMode(6, OUTPUT);

  digitalWrite(9, 0);
  digitalWrite(10, 1);
  digitalWrite(11, 0);
  digitalWrite(12, 1);

  analogWrite(3, 0);
  analogWrite(6, 0);

  Serial.begin(9600);
}

void loop() {

  int IR1 = analogRead(A6);
  int IR2 = analogRead(A5);
  int IR3 = analogRead(A3);
  int IR4 = analogRead(A2);
  int IR5 = analogRead(A1);
  int IR6 = analogRead(A7);
  int IR7 = analogRead(A4);


  Serial.print(IR1);
  Serial.print(":");
  Serial.print(IR2);
  Serial.print(":");
  Serial.print(IR3);
  Serial.print(":");
  Serial.print(IR4);
  Serial.print(":");
  Serial.print(IR5);
  Serial.print(":");
  Serial.print(IR6);
  Serial.print(":");
  Serial.println(IR7);

  //high than 200 is black
  //lower than 200 is white

  if (IR1 > 200 && IR2 > 200 && IR3 > 200 && IR4 > 200 && IR5 > 200) {  //forward  ok
    analogWrite(3, 255);
    analogWrite(6, 255);

  } else if (IR2 > 200 && IR3 > 200 && IR4 > 200) {  // ok
    delay(15);
    analogWrite(3, 100);
    analogWrite(6, 100);

  } else if (IR5 > 200) {  // ok
    delay(15);
    analogWrite(3, 200);
    analogWrite(6, 50);

  } else if (IR1 > 200) {  //OK
    delay(15);
    analogWrite(3, 50);
    analogWrite(6, 200);

  } else if (IR1 > 200 && IR2 > 200) {  //OK
    delay(15);
    analogWrite(3, 50);
    analogWrite(6, 0);

  } else if (IR4 > 200 && IR5 > 200) {  //OK
    delay(15);
    analogWrite(3, 0);
    analogWrite(6, 50);

  } else if (IR1 > 200 && IR2 > 200 && IR3 > 200) {  //OK
    delay(15);
    analogWrite(3, 50);
    analogWrite(6, 200);

  } else if (IR3 > 200 && IR4 > 200 && IR5 > 200) {  //OK
    delay(15);
    analogWrite(3, 200);
    analogWrite(6, 50);

  } else if (IR3 > 200) {  //OK
    delay(15);
    analogWrite(3, 255);
    analogWrite(6, 255);

  } else if (IR2 > 200) {  //OK
    delay(15);
    analogWrite(3, 200);
    analogWrite(6, 200);

  } else if (IR4 > 200) {  //OK
    delay(15);
    analogWrite(3, 200);
    analogWrite(6, 50);

  } else if (IR2 < 200 && IR3 < 200 && IR4 < 200) {

    if (IR6 > 200) {  //ok
      analogWrite(3, 0);
      analogWrite(6, 150);
    } else if (IR7 > 200) {  //ok
      analogWrite(3, 150);
      analogWrite(6, 0);
    }

  } else if (IR3 > 200 && IR4 > 200) {
    if (IR6 > 200) {
      delay(15);
      analogWrite(3, 0);
      analogWrite(6, 150);
    }

  } else if (IR1 > 200 && IR2 > 200 && IR3 > 200 && IR4 > 200 && IR5 > 200 && IR6 > 200 && IR7 > 200) {
    delay(15);
    analogWrite(3, 0);
    analogWrite(6, 0);

  } else if (IR1 < 200 && IR2 < 200 && IR3 < 200 && IR4 < 200 && IR5 < 200 && IR6 < 200 && IR7 < 200) {
    delay(15);
    analogWrite(3, 0);
    analogWrite(6, 0);

  } else if (IR6 > 200 && IR7 > 200) {
    delay(15);
    analogWrite(3, 0);
    analogWrite(6, 150);
  }
}