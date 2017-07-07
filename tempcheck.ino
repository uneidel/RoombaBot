#include <Wire.h>
#include <Adafruit_BMP085.h>
Adafruit_BMP085 bmp;
void setupTemp() {
  Wire.begin(12,13);
  bmp.begin();  
}
  
