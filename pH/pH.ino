#include "pH.h"

const int analogInPin = A0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  // get readings
  readsample(A0, buf);

  // sort readings in ascending order
  sortAscend(buf);

  // remove the smallest and the largest readings then calculate avg reading
  for (int i = 2; i < 8; i++)
    avgValue += buf[i];

  float pHVol = analogtovolt(avgValue);
  float pHValue = getpH(pHVol);

  Serial.print("sensor = ");
  Serial.println(pHValue);

  delay(20);
}