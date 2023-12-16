#include <Arduino.h>
#include <OneButton.h>
#include <def.h>

// NOTES
// Attch the button pin to digital pin: 4
// Connect the other button pin to the 3V3 GND (not the 5V GND)

OneButton button(BUTTON, true);

// This function will be called when the button1 was pressed 1 time
void press()
{
    Serial.println("........... Single Press");
    sendAction(0);
}

// This function will be called when the button is pressed 2 times in a short timeframe.
void doublePress()
{
    Serial.println("........... Double Press");
    sendAction(1);
}

// This function will be called when the button is pressed 2 times in a short timeframe.
void multiPress()
{
    if (button.getNumberClicks() == 3)
    {
        Serial.println("........... Triple Press");
        sendAction(2);
    }
}

// This function will be called often, while the button is pressed for a long time.
void longPressStart()
{
    Serial.println("........... Long Press");
    sendAction(3);
}

void listenForButtonPress()
{
    button.tick();
}

void setupButton()
{
    button.attachClick(press);
    button.attachDoubleClick(doublePress);
    button.attachMultiClick(multiPress);
    button.attachLongPressStart(longPressStart);
}