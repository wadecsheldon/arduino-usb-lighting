#include <USBLighting.h>

/* Pro Micro Test Code
   by: Nathan Seidle
   modified by: Jim Lindblom
   SparkFun Electronics
   date: September 16, 2013
   license: Public Domain - please use this code however you'd like.
   It's provided as a learning tool.

   This code is provided to show how to control the SparkFun
   ProMicro's TX and RX LEDs within a sketch. It also serves
   to explain the difference between Serial.print() and
   Serial1.print().
*/

void setup()
{
  Serial.begin(57600);
  delay(5000);
}

void loop()
{
  LightingReport rep = USBLighting.getReport();
  Serial.print(rep.id);
  Serial.print(' ');
  Serial.println(rep.len);
}
