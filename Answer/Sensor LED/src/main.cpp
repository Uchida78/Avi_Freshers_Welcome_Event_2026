#include <Arduino.h> //おまじない

#define LED_R 11 //LEDの赤色部分に繋がっているピンを11番と設定
#define LED_G 12 //LEDの緑色部分に繋がっているピンを12番と設定
#define LED_B 13 //LEDの青色部分に繋がっているピンを13番と設定
#define Sensor 15 //光センサーに繋がっているピンを15番と設定

int Brightness = 0; //"Brightness"を整数の変数として定義

void setup() { //この中のプログラムはマイコン起動時に一回だけ実行される
  pinMode(LED_R, OUTPUT); //LEDの赤色ピンのモードを出力に設定
  pinMode(LED_G, OUTPUT); //LEDの緑色ピンのモードを出力に設定
  pinMode(LED_B, OUTPUT); //LEDの青色ピンのモードを出力に設定
  pinMode(Sensor, INPUT); //光センサーのピンのモードを入力に設定
}

void loop() { //この中のプログラムはsetup実行後は繰り返し実行される
  Brightness = analogRead(Sensor); //光センサーのピンの電圧を読み、それを変数Brightnessに代入
  if (Brightness >= 4000) { //Brightnessが4000以上の時にこの中身が実行される
    digitalWrite(LED_R, LOW); //LEDの赤色ピンの電圧をLOW(0V)に設定
    digitalWrite(LED_G, LOW); //LEDの緑色ピンの電圧をLOW(0V)に設定
    digitalWrite(LED_B, HIGH); //LEDの青色ピンの電圧をHIGH(3.3V)に設定
  }
  else if (Brightness >= 3000) { //今までの条件を満たさず、なおかつBrightnessが3000以上の時にこの中身が実行される
    digitalWrite(LED_R, LOW); //LEDの赤色ピンの電圧をLOW(0V)に設定
    digitalWrite(LED_G, HIGH); //LEDの緑色ピンの電圧をHIGH(3.3V)に設定
    digitalWrite(LED_B, LOW); //LEDの青色ピンの電圧をLOW(0V)に設定
  }
  else if (Brightness >= 2000) { //今までの条件を満たさず、なおかつBrightnessが2000以上の時にこの中身が実行される
    digitalWrite(LED_R, HIGH); //LEDの赤色ピンの電圧をHIGH(3.3V)に設定
    digitalWrite(LED_G, LOW); //LEDの緑色ピンの電圧をLOW(0V)に設定
    digitalWrite(LED_B, LOW); //LEDの青色ピンの電圧をLOW(0V)に設定
  }
  else{ //今までの条件をどれも満たさなかった時にこの中身が実行される
    digitalWrite(LED_R, LOW); //LEDの赤色ピンの電圧をLOW(0V)に設定
    digitalWrite(LED_G, LOW); //LEDの緑色ピンの電圧をLOW(0V)に設定
    digitalWrite(LED_B, LOW); //LEDの青色ピンの電圧をLOW(0V)に設定
  }
}