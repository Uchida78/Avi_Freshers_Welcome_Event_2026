#include <Arduino.h>

#define LED_R 11
#define LED_G 12
#define LED_B 13
#define Sensor 15
#define Button 16

int Mode = 0;
int Mode_Prev = 0;
int Brightness = 0;
int Color = 0;

bool Push = false;
bool Push_Prev = false;

void setup() {
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(Sensor, INPUT);
  pinMode(Button, INPUT_PULLDOWN);
  Serial.begin(115200);
}

void loop() {
  Mode_Prev = Mode;
  if (Serial.available()) {
    char cmd = Serial.read();
    switch (cmd) {
    case 'a':
      Mode = 1;
      break;
    case 's':
      Mode = 2;
      break;
    case 'l':
      Serial.println(analogRead(Sensor));
      break;
    case 'r':
      digitalWrite(LED_R, HIGH);
      Mode = 0;
      break;
    case 'R':
      digitalWrite(LED_R, LOW);
      Mode = 0;
      break;
    case 'g':
      digitalWrite(LED_G, HIGH);
      Mode = 0;
      break;
    case 'G':
      digitalWrite(LED_G, LOW);
      Mode = 0;
      break;
    case 'b':
      digitalWrite(LED_B, HIGH);
      Mode = 0;
      break;
    case 'B':
      digitalWrite(LED_B, LOW);
      Mode = 0;
      break;
    }
    Serial.println(cmd);
  }
  if ((Mode == 0) && !(Mode_Prev == 0)) {
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_G, LOW);
    digitalWrite(LED_B, LOW);
  }
  if (Mode == 1) {
    Brightness = analogRead(Sensor);
    if (Brightness >= 4000) {
      digitalWrite(LED_R, LOW);
      digitalWrite(LED_G, LOW);
      digitalWrite(LED_B, HIGH);
    }
    else if (Brightness >= 3000) {
      digitalWrite(LED_R, LOW);
      digitalWrite(LED_G, HIGH);
      digitalWrite(LED_B, LOW);
    }
    else if (Brightness >= 2000) {
      digitalWrite(LED_R, HIGH);
      digitalWrite(LED_G, LOW);
      digitalWrite(LED_B, LOW);
    }
    else{
      digitalWrite(LED_R, LOW);
      digitalWrite(LED_G, LOW);
      digitalWrite(LED_B, LOW);
    }
  }
  if (Mode == 2) {
    Push_Prev = Push;
    Push = digitalRead(Button);
    if (Push and !Push_Prev) {
      Color = ++Color%4;
    }
    switch (Color) {
    case 0:
      digitalWrite(LED_R, LOW);
      digitalWrite(LED_G, LOW);
      digitalWrite(LED_B, LOW);
      break;
    case 1:
      digitalWrite(LED_R, HIGH);
      digitalWrite(LED_G, LOW);
      digitalWrite(LED_B, LOW);
      break;
    case 2:
      digitalWrite(LED_R, LOW);
      digitalWrite(LED_G, HIGH);
      digitalWrite(LED_B, LOW);
      break;
    case 3:
      digitalWrite(LED_R, LOW);
      digitalWrite(LED_G, LOW);
      digitalWrite(LED_B, HIGH);
      break;
    }
  }
}