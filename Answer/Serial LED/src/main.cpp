#include <Arduino.h> //おまじない

#define LED_R 11 //LEDの赤色部分に繋がっているピンを11番と設定
#define LED_G 12 //LEDの緑色部分に繋がっているピンを12番と設定
#define LED_B 13 //LEDの青色部分に繋がっているピンを13番と設定

void setup() { //この中のプログラムはマイコン起動時に一回だけ実行される
  pinMode(LED_R, OUTPUT); //LEDの赤色ピンのモードを出力に設定
  pinMode(LED_G, OUTPUT); //LEDの緑色ピンのモードを出力に設定
  pinMode(LED_B, OUTPUT); //LEDの青色ピンのモードを出力に設定
  Serial.begin(115200); //シリアル通信をボーレート115200で起動
}

void loop() { //この中のプログラムはsetup実行後は繰り返し実行される
  if (Serial.available()) { //パソコンからシリアルで何かが送られてきた時にこの中身が実行される
    char cmd = Serial.read(); //送られてきたもじれるを変数cmdに代入
    switch (cmd) { //変数cmdの中身に応じて分岐した処理がされる
    case 'r': //変数cmdがrの時の処理が下2行に書かれている
      digitalWrite(LED_R, HIGH); //LEDの赤色ピンの電圧をHIGH(3.3V)に設定
      break; //おまじない
    case 'R': //変数cmdがRの時の処理が下2行に書かれている
      digitalWrite(LED_R, LOW); //LEDの赤色ピンの電圧をLOW(0V)に設定
      break; //おまじない
    case 'g': //変数cmdがgの時の処理が下2行に書かれている
      digitalWrite(LED_G, HIGH); //LEDの緑色ピンの電圧をHIGH(3.3V)に設定
      break; //おまじない
    case 'G': //変数cmdがGの時の処理が下2行に書かれている
      digitalWrite(LED_G, LOW); //LEDの緑色ピンの電圧をLOW(0V)に設定
      break; //おまじない
    case 'b': //変数cmdがbの時の処理が下2行に書かれている
      digitalWrite(LED_B, HIGH); //LEDの青色ピンの電圧をHIGH(3.3V)に設定
      break; //おまじない
    case 'B': //変数cmdがBの時の処理が下2行に書かれている
      digitalWrite(LED_B, LOW); //LEDの青色ピンの電圧をLOW(0V)に設定
      break; //おまじない
    }
    Serial.println(cmd); //変数cmdをシリアルで表示
  }
}