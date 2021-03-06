/**
  ORIGINAL: https://github.com/guillaume-rico/SharpIR/blob/master/examples/SharpSensorCm/SharpSensorCm.ino

  Connection instructions for Arduino UNO
  ---------------------------------------
  Connect RED wire to 5V
  Connect BLACK wiere to GND
  Connect YELLOW/WHITE to AO
*/

#include <SharpIR.h>

#define ir 0
#define model 20150         //Check your model: 1080 for GP2Y0A21Y, 20150 for GP2Y0A02Y
#define sampleSize 25
#define validityPercent 95

SharpIR sharp(ir, sampleSize, validityPercent,  model);

void setup(){
  Serial.begin(9600);
}

void loop(){
  delay(2000);   

  unsigned long pepe1 = millis();  // takes the time before the loop on the library begins

  int dis = sharp.distance();  // this returns the distance to the object you're measuring

  Serial.print("Mean distance: ");  // returns it to the serial monitor
  Serial.println(dis);
  
  unsigned long pepe2 = millis() - pepe1;  // the following gives you the time taken to get the measurement
  Serial.print("Time taken (ms): ");
  Serial.println(pepe2);  
}
