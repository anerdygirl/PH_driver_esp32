#include "pH.h"

const int analogInPin = A0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  // get readings
  readsample(A0, buf);
  float pHVol = analogtovolt(avgValue);
  float pHValue = getpH(pHVol);

  Serial.print("sensor = ");
  Serial.println(pHValue);

  delay(20);
}