#include <Arduino.h> //おまじない

#define LED_R 11 //LEDの赤色部分に繋がっているピンを11番と設定
#define LED_G 12 //LEDの緑色部分に繋がっているピンを12番と設定
#define LED_B 13 //LEDの青色部分に繋がっているピンを13番と設定
#define Button 16 //ボタンに繋がっているピンを16番として設定

void setup() { //この中のプログラムはマイコン起動時に一回だけ実行される
  pinMode(LED_R, OUTPUT); //LEDの赤色ピンのモードを出力に設定
  pinMode(LED_G, OUTPUT); //LEDの緑色ピンのモードを出力に設定
  pinMode(LED_B, OUTPUT); //LEDの青色ピンのモードを出力に設定
  pinMode(Button, INPUT_PULLDOWN); //ボタンのピンのモードをプルダウンしつつ入力に設定。これによってボタンを押していない間はピンに0Vが、押すと3.3Vが掛かるようになる
}

void loop() { //この中のプログラムはsetup実行後は繰り返し実行される
  if (digitalRead(Button)) { //ボタンのピンの電圧を読み、HIGH(3.3V)の時にこの中身が実行される
    digitalWrite(LED_R, LOW); //LEDの赤色ピンの電圧をLOW(0V)に設定
    digitalWrite(LED_G, LOW); //LEDの緑色ピンの電圧をLOW(0V)に設定
    digitalWrite(LED_B, LOW); //LEDの青色ピンの電圧をLOW(0V)に設定
  }
  else { //上の条件を満たさなかった時にこの中身が実行される
    digitalWrite(LED_R, HIGH); //LEDの赤色ピンの電圧をHIGH(3.3V)に設定
    digitalWrite(LED_G, HIGH); //LEDの緑色ピンの電圧をHIGH(3.3V)に設定
    digitalWrite(LED_B, HIGH); //LEDの青色ピンの電圧をHIGH(3.3V)に設定
  }
}