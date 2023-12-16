#include <Arduino.h>
#include <BleKeyboard.h>
#include <def.h>

BleKeyboard bleKeyboard("ChangeBuddy", "Homie Studio", 75);

void setupBleKeyboard()
{
    bleKeyboard.begin();
}

void changeMode()
{
    mode = (mode == 0) ? 1 : 0;
    Serial.print("\nMode is now: ");
    Serial.println(mode);
}

// sends keyboard actions
void sendAction(int action)
{
    if (bleKeyboard.isConnected())
    {
        switch (action)
        {
        case 0: // single press
            (mode == 0) ? bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE) : bleKeyboard.write(KEY_DOWN_ARROW);
            break;
        case 1: // double press
            (mode == 0) ? bleKeyboard.write(KEY_MEDIA_NEXT_TRACK) : bleKeyboard.write(KEY_UP_ARROW);
            break;
        case 2: // triple press
            if (mode == 0)
            {
                bleKeyboard.write(KEY_MEDIA_PREVIOUS_TRACK);
            }
            break;
        case 3: // long press
            changeMode();
            break;

        default:
            break;
        }
    }
    else
    {
        Serial.print("\nCan't send Key! No client connected.");
    }
}
