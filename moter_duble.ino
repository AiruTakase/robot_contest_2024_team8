#define R_DIN0 53
#define R_DIN1 52
#define R_DIN2 51
#define R_VMana 7

#define L_DIN0 43
#define L_DIN1 42
#define L_DIN2 41
#define L_VMana 5

int pw = 255;//回転速度をPWMで設定する（0-255で設定）

void setup() {
  Serial.begin(9600);
  
  pinMode(R_DIN0, OUTPUT);
  pinMode(R_DIN1, OUTPUT);
  pinMode(R_DIN2, OUTPUT);
  digitalWrite(R_DIN0,HIGH);
  digitalWrite(R_DIN1,HIGH);
  digitalWrite(R_DIN2,HIGH);

  pinMode(L_DIN0, OUTPUT);
  pinMode(L_DIN1, OUTPUT);
  pinMode(L_DIN2, OUTPUT);
  digitalWrite(L_DIN0,HIGH);
  digitalWrite(L_DIN1,HIGH);
  digitalWrite(L_DIN2,HIGH);
}

void loop() {
  while(!Serial.available());//モータードライバの起動等が終わるまで、待機させるための処理（シリアルモニタのメッセージに何か入力すると回転し出す）
  digitalWrite(R_DIN0,LOW);
  digitalWrite(R_DIN1,LOW);
  analogWrite(R_VMana,pw);

  digitalWrite(L_DIN0,LOW);
  digitalWrite(L_DIN1,LOW);
  analogWrite(L_VMana,pw);
  
  Serial.println("SPINNING!");
  while(1);
}

