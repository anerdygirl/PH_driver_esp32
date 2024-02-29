#include "pH.h"

const int analogInPin = A0;


void setup() {
  Serial.begin(9600);
}

void loop() {
  readsample(A0, &buf);

  // sort readings in ascending order
  for (int i = 0; i < 9; i++) {
    for (int j = i + 1; j < 10; j++) {
      if (buf[i] > buf[j]) {
        temp = buf[i];
        buf[i] = buf[j];
        buf[j] = temp;
      }
    }
  }
  // remove the smallest and the largest readings then calculate avg reading
  for (int i = 2; i < 8; i++)
    avgValue += buf[i];

  float pHVol = analogtovolt(avgValue);
  float pHValue = getpH(pHVol);

  Serial.print("sensor = ");
  Serial.println(phValue);

  delay(20);
}
