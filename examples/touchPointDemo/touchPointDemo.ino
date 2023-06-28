#include <XPT2046_Touchscreen.h>
#include <SPI.h>

#define CS_PIN  8
// MOSI=11, MISO=12, SCK=13

//XPT2046_Touchscreen ts(CS_PIN);
#define TIRQ_PIN  2
//XPT2046_Touchscreen ts(CS_PIN);  // Param 2 - NULL - No interrupts
//XPT2046_Touchscreen ts(CS_PIN, 255);  // Param 2 - 255 - No interrupts
XPT2046_Touchscreen ts(CS_PIN, TIRQ_PIN);  // Param 2 - Touch IRQ Pin - interrupt enabled polling

void setup() {
  Serial.begin(9600);
  ts.begin();
  ts.setRotation(2); // change rotation as per requirement to configure display touch
  while (!Serial && (millis() <= 1000));
  Serial.println("Touch screen initialized");
}
uint16_t x, y;
void loop() {
  if (ts.touched()) {
    TS_Point p = ts.getPoint();
    Serial.print("Pressure = ");
    Serial.print(p.z);
    Serial.print(", x = ");
    Serial.print(p.x);
    Serial.print(", y = ");
    Serial.print(p.y);
    Serial.println();

    // map pressure points for pixel 240x320, make sure to set proper rotation
    x = map(p.x, 200, 3900, 0, 240);
    y = map(p.y, 140, 3930, 0, 320);
    Serial.print("Pixel Mapped Location: \n");
    Serial.print(" x = ");
    Serial.print(x);
    Serial.print(", y = ");
    Serial.print(y);
    delay(50);
    Serial.println();
  }
}
