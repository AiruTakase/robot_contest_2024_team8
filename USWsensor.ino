#２つの超音波センサーから距離をとるプログラムです

#define tri_1 22 //triの値を2と定義
#define echo_1 23 //echoの値を3と定義
#define tri_2 30
#define echo_2 31

int duration_1 = 0; //超音波を出してから、跳ね返ってくるまでの時間を格納する変数
double dist_1 = 0; //durationから求めた距離を格納する変数

int duration_2 = 0;
double dist_2 = 0;

double del_dist = dist_1 - dist_2;

void setup() {
  pinMode(tri_1, OUTPUT); //tri（2番）ピンを出力用に設定する。triピンで超音波の出す、出さないを制御する。
  digitalWrite(tri_1, LOW); //triピンに0Vを出力する。即ち超音波を出さない。
  pinMode(echo_1, INPUT); //echo（3番）ピンを入力用に設定する。echoピンで跳ね返ってくる超音波を検出する。

  pinMode(tri_2, OUTPUT); //tri（2番）ピンを出力用に設定する。triピンで超音波の出す、出さないを制御する。
  digitalWrite(tri_2, LOW); //triピンに0Vを出力する。即ち超音波を出さない。
  pinMode(echo_2, INPUT);

  Serial.begin(9600); //シリアル通信を9600bpsで行うことを設定する。
}

void loop() {

  digitalWrite(tri_1, HIGH);
  digitalWrite(tri_2, HIGH); 
  //triピンに5Vを出力する。即ち超音波を出す。
  delayMicroseconds(10);
   //10マイクロ秒間プログラムを停止する。
  digitalWrite(tri_1, LOW);
  digitalWrite(tri_2, LOW); 
  //triピンに0Vを出力する。即ち超音波を出さない。
  duration_1 = pulseIn(echo_1, HIGH);
  duration_2 = pulseIn(echo_2, HIGH); //超音波が出力されてから、跳ね返ってくるまでの時間をマイクロ秒で計測し、durationに代入する。

  dist_1 = 0.5*340.0*(duration_1/1000000.0);
  dist_2 = 0.5*340.0*(duration_2/1000000.0); //音速と時間（duration）から距離をメートル単位で計算し、distに代入する。

  Serial.println(dist_2); //距離をシリアルモニタに表示し、改行する。
  
  delay(100); //100ミリ秒間プログラムを停止する。
}
