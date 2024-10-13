#define DIN0 53
#define DIN1 52
#define DIN2 51
#define VMana 7

int pw = 255;//回転速度をPWMで設定する（0-255で設定）

void setup() {
  Serial.begin(9600);
  pinMode(DIN0, OUTPUT);
  pinMode(DIN1, OUTPUT);
  pinMode(DIN2, OUTPUT);
  digitalWrite(DIN0,HIGH);
  digitalWrite(DIN1,HIGH);
  digitalWrite(DIN2,HIGH);
}

void loop() {
  while(!Serial.available());//モータードライバの起動等が終わるまで、待機させるための処理（シリアルモニタのメッセージに何か入力すると回転し出す）
  digitalWrite(DIN0,LOW);
  digitalWrite(DIN1,LOW);
  analogWrite(VMana,pw);
  Serial.println("SPINNING!");
  while(1);
}
