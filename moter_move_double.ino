#define R_DIN0 53 //R 黄黒
#define R_DIN1 52 //R オレンジ白
#define R_DIN2 51 //R 赤白
#define R_VMana 8 //R 紫

#define L_DIN0 43　//L 黄黒
#define L_DIN1 42　//L オレンジ白
#define L_DIN2 41　//L 赤白
#define L_VMana 10　//L 紫

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

