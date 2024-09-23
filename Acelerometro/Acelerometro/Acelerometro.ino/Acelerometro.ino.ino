#include<ADXL362.h>

ADXL362 xl;

int16_t temp;
int16_t XValue, YValue, ZValue, Temperature;

void setup(){
  
  Serial.begin(115200);
  xl.begin(7);                   // Setup SPI protocol, issue device soft reset
  xl.beginMeasure();              // Switch ADXL362 to measure mode  
	
  Serial.println("Start Demo: Simple Read");
}

void loop(){
    
  // read all three axis in burst to ensure all measurements correspond to same sample time
  xl.readXYZTData(XValue, YValue, ZValue, Temperature);  
  Serial.println("m/s^2 --> x: " + String(XValue) + "\t, y: "  + String(YValue) + "\t, z: " + String(ZValue) + "\t, t: " + String(Temperature) );
  
  delay(500);                // Arbitrary delay to make serial monitor easier to observe
}