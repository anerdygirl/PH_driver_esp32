# PH_driver_esp32
a pH module driver for esp32 and Arduino boards

## Variables:  
**int sensorValue = 0:** initalized sensor value.  
**unsigned long int avgValue = 0:** initialized average voltage value.  
**int buf[10]:** array to store 10 sensor readings at a time.  
**int temp:** temporary variable for the sorting.  
## Functions:  
**void readsample(int AnalogPin, int (&buf)[10]):** Reads 10 samples and stores them in _buf_ array.  
**void sortAscend(int (&buf)[10]):** Sorts the elements of _buf_ in ascending order.  
**float analogtovolt(unsigned long int avg):** Converts the analog reading to voltage.  
**float getpH(float volt):** find pH according to the sensor equation `y= -5.70 * x + 21.34`.  
