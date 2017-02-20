#include <IRremote.h>
int RECV_PIN = 9;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    switch(results.value) {
      case 0x20DF00FF:
        Serial.println("MOVE FORWARD");
        break;
      case 0x20DF22DD:
        Serial.println("STOP");
        break;
      case 0x20DF807F:
        Serial.println("MOVE BACKWARD");
        break;
      case 0x20DF40BF:
        Serial.println("TURN RIGHT");
        break;
      case 0x20DFC03F:
        Serial.println("TURN LEFT");
        break;
      default:
        Serial.println(results.value, HEX);
    }
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}
