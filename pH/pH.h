// variables
int sensorValue = 0;  // init reading
unsigned long int avgValue = 0;
float b;
int buf[10], temp;

// get 10 readings
void readsample(int AnalogPin, int *buf, int size) {
  for (int i = 0; i < size; i++) {
    *buf[i] = analogRead(AnalogPin);
    delay(10);
  }
}

// Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
float analogtovolt(unsigned long int avg) {
  float pHVol = (float)avg * 5.0 / 1024 / 6;
  return pHVol;
}

// find pH according to the sensor equation: y= -5.70 * x + 21.34
float getpH(float volt) {
  float ph = -5.70 * volt + 21.34;
  return ph;
}
