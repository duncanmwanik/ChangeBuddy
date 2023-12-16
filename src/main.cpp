#include <Arduino.h>
#include <def.h>

void setup()
{
  Serial.begin(115200);
  Serial.println("\n............................... ChangeBuddy ...............................\n");
  setupBleKeyboard();
  setupButton();
}

void loop()
{
  listenForButtonPress();
}
