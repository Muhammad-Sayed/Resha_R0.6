#define X_STEP  21
#define X_DIR   20
#define Y_STEP  0
#define Y_DIR   1
#define Z_STEP  3
#define Z_DIR   2
#define EN      19
#define EN_Z    4
#define X_STOP  12
#define Y_STOP  9
#define Z_STOP  8

void setup() 
{
  Serial1.begin(115200);

  pinMode(X_STEP, OUTPUT);
  pinMode(X_DIR, OUTPUT);
  pinMode(Y_STEP, OUTPUT);
  pinMode(Y_DIR, OUTPUT);
  pinMode(Z_STEP, OUTPUT);
  pinMode(Z_DIR, OUTPUT);
  pinMode(EN, OUTPUT);
  pinMode(EN_Z, OUTPUT);
  pinMode(X_STOP, INPUT_PULLUP);
  pinMode(Y_STOP, INPUT_PULLUP);
  pinMode(Z_STOP, INPUT_PULLUP);

  digitalWrite(EN, LOW);
  digitalWrite(EN_Z, LOW);
}

void loop() 
{
  digitalWrite(X_DIR, digitalRead(X_STOP));
  digitalWrite(X_STEP, !digitalRead(X_STEP));
  digitalWrite(Y_DIR, digitalRead(Y_STOP));
  digitalWrite(Y_STEP, !digitalRead(Y_STEP));
  digitalWrite(Z_DIR, digitalRead(Z_STOP));
  digitalWrite(Z_STEP, !digitalRead(Z_STEP));
  delay(1);
  
//  Serial1.println("Hello World!");
//  delay(1500);
//  if(Serial.available()) {
//    int inByte = Serial.read();
//    Serial1.print("I got ");
//    while(Serial.available()) {
//      Serial1.write(inByte);
//    }
//    Serial1.println(" ");
//    delay(1000);
//  }
}
