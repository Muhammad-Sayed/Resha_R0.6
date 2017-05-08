void setup() {
  Serial1.begin(115200);
}

void loop() {
  Serial1.println("Hello World!");
  delay(1500);
  if(Serial.available()) {
    int inByte = Serial.read();
    Serial1.print("I got ");
    while(Serial.available()) {
      Serial1.write(inByte);
    }
    Serial1.println(" ");
    delay(1000);
  }
}
