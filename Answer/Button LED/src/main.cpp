#include <Arduino.h> //おまじない

#define LED_R 11 //LEDの赤色部分に繋がっているピンを11番と設定
#define LED_G 12 //LEDの緑色部分に繋がっているピンを12番と設定
#define LED_B 13 //LEDの青色部分に繋がっているピンを13番と設定
#define Button 16 //ボタンに繋がっているピンを16番として設定

int Color = 0; //"Color"を整数の変数として定義

bool Push = false; //"Push"を真偽の変数として定義
bool Push_Prev = false; //"Push_Prev"を真偽の変数として定義

void setup() { //この中のプログラムはマイコン起動時に一回だけ実行される
  pinMode(LED_R, OUTPUT); //LEDの赤色ピンのモードを出力に設定
  pinMode(LED_G, OUTPUT); //LEDの緑色ピンのモードを出力に設定
  pinMode(LED_B, OUTPUT); //LEDの青色ピンのモードを出力に設定
  pinMode(Button, INPUT_PULLDOWN); //ボタンのピンのモードをプルダウンしつつ入力に設定。これによってボタンを押していない間はピンに0Vが、押すと3.3Vが掛かるようになる
}

void loop() { //この中のプログラムはsetup実行後は繰り返し実行される
  Push_Prev = Push; //ボタンを押し続けても1回しか反応しなくするためのおまじない
  Push = digitalRead(Button); //ボタンのピンがHIGH(3.3V)かLOW(0V)かを読み、Pushに代入
  if (Push and !Push_Prev) { //ちょうどボタンが押され始めた時だけこの中身が実行される
    Color = ++Color%4; //押した回数をカウントして変数Colorを調整する処理
  }
  switch (Color) { //変数Colorの値に応じて分岐した処理がされる
  case 0: //変数Colorが0の時の処理が下4行に書かれている
    digitalWrite(LED_R, LOW); //LEDの赤色ピンの電圧をLOW(0V)に設定
    digitalWrite(LED_G, LOW); //LEDの緑色ピンの電圧をLOW(0V)に設定
    digitalWrite(LED_B, LOW); //LEDの青色ピンの電圧をLOW(0V)に設定
    break; //おまじない
  case 1: //変数Colorが1の時の処理が下4行に書かれている
    digitalWrite(LED_R, HIGH); //LEDの赤色ピンの電圧をHIGH(3.3V)に設定
    digitalWrite(LED_G, LOW); //LEDの緑色ピンの電圧をLOW(0V)に設定
    digitalWrite(LED_B, LOW); //LEDの青色ピンの電圧をLOW(0V)に設定
    break; //おまじない
  case 2: //変数Colorが2の時の処理が下4行に書かれている
    digitalWrite(LED_R, LOW); //LEDの赤色ピンの電圧をLOW(0V)に設定
    digitalWrite(LED_G, HIGH); //LEDの緑色ピンの電圧をHIGH(3.3V)に設定
    digitalWrite(LED_B, LOW); //LEDの青色ピンの電圧をLOW(0V)に設定
    break; //おまじない
  case 3: //変数Colorが3の時の処理が下4行に書かれている
    digitalWrite(LED_R, LOW); //LEDの赤色ピンの電圧をLOW(0V)に設定
    digitalWrite(LED_G, LOW); //LEDの緑色ピンの電圧をLOW(0V)に設定
    digitalWrite(LED_B, HIGH); //LEDの青色ピンの電圧をHIGH(3.3V)に設定
    break; //おまじない
  }
  delay(10); //ボタンの誤動作防止で10ミリ秒(0.01秒)待機
}