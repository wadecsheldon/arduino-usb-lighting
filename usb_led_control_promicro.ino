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


#include "USBLighting.h"
#include "Keyboard.h"

void setup()
{
  
}

void loop()
{
  uint8_t id = USBLighting.getReportID();
  uint8_t len = USBLighting.getReportLength();
  if (id) {
    Serial.print(id);
    Serial.print(' ');
    Serial.println(len);
  }
  delay(1);
}
