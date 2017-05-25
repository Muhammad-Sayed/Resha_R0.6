#include <Wire.h>

void setup() {
  Wire.begin();        // join i2c bus (address optional for master)
  Serial1.begin(115200);  // start serial for output
}

byte x = 0;

void loop() {
  if (Serial1.available())
  {
    x = Serial1.read();
    Wire.beginTransmission(8); // transmit to device #8
    Wire.write("x is ");        // sends five bytes
    Wire.write(x);              // sends one byte
    Wire.endTransmission();    // stop transmitting
  }

  delay(1000);
  
  Wire.requestFrom(8, 12);    // request 6 bytes from slave device #8
  while (Wire.available()) { // slave may send less than requested
    char c = Wire.read(); // receive a byte as character
    Serial1.print(c);         // print the character
  }
}
