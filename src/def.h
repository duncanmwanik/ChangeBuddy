#ifndef DEF_H
#define DEF_H
#include <Arduino.h>

#define BUTTON 4

extern int mode;

// ble-keyboard
void setupBleKeyboard();
void sendAction(int action);

// button
void setupButton();
void listenForButtonPress();

// power

#endif
