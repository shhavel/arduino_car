#include <IRremote.h>
const int RECV_PIN = 9;
IRrecv irrecv(RECV_PIN);
decode_results results;

const int LEFT_MOTOR_PIN = 11;
const int RIGHT_MOTOR_PIN = 3;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(LEFT_MOTOR_PIN, OUTPUT);
  pinMode(RIGHT_MOTOR_PIN, OUTPUT);
  digitalWrite(LEFT_MOTOR_PIN, LOW);
  digitalWrite(RIGHT_MOTOR_PIN, LOW);
}

void loop() {
  if (irrecv.decode(&results)) {
    switch(results.value) {
      case 0x20DF00FF:
        Serial.println("MOVE FORWARD");
        digitalWrite(LEFT_MOTOR_PIN, HIGH);
        digitalWrite(RIGHT_MOTOR_PIN, HIGH);
      break;
      case 0x20DF22DD:
        Serial.println("STOP");
        digitalWrite(LEFT_MOTOR_PIN, LOW);
        digitalWrite(RIGHT_MOTOR_PIN, LOW);
      break;
      case 0x20DF807F:
        Serial.println("MOVE BACKWARD (STOP)");
        digitalWrite(LEFT_MOTOR_PIN, LOW);
        digitalWrite(RIGHT_MOTOR_PIN, LOW);
      break;
      case 0x20DF40BF:
        Serial.println("RIGHT");
        digitalWrite(LEFT_MOTOR_PIN, HIGH);
        digitalWrite(RIGHT_MOTOR_PIN, LOW);
      break;
      case 0x20DFC03F:
        Serial.println("LEFT");
        digitalWrite(LEFT_MOTOR_PIN, LOW);
        digitalWrite(RIGHT_MOTOR_PIN, HIGH);
      break;
      default:
        Serial.println(results.value, HEX);
    }
    irrecv.resume();
  }
  delay(100);
}
