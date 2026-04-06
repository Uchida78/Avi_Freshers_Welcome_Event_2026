#include <Arduino.h> //おまじない

#define Sensor 15 //光センサーに繋がっているピンを15番と設定

void setup() { //この中のプログラムはマイコン起動時に一回だけ実行される
  pinMode(Sensor, INPUT); //光センサーのピンのモードを入力に設定
  Serial.begin(115200); //シリアル通信をボーレート115200で起動
}

void loop() { //この中のプログラムはsetup実行後は繰り返し実行される
  Serial.println(analogRead(Sensor)); //光センサーのピンの電圧を読み、それをシリアルで表示
  delay(1000); //1000ミリ秒(1秒)待機
}