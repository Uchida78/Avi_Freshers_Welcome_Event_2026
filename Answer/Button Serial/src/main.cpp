#include <Arduino.h> //おまじない

#define Button 16 //ボタンに繋がっているピンを16番として設定

void setup() { //この中のプログラムはマイコン起動時に一回だけ実行される
  pinMode(Button, INPUT_PULLUP); //ボタンのピンのモードをプルアップしつつ入力に設定。これによってボタンを押していない間はピンに0Vが、押すと3.3Vが掛かるようになる
  Serial.begin(115200); //シリアル通信をボーレート115200で起動
}

void loop() { //この中のプログラムはsetup実行後は繰り返し実行される
  Serial.println(digitalRead(Button)); //ボタンのピンがHIGH(3.3V)かLOW(0V)かを読み、それをシリアルで表示
  delay(1000); //1000ミリ秒(1秒)待機
}