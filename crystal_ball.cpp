#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Set up a constant for the tilt switch pin
const int switchPin = 6;

// Variables to hold current and previous value of switch pin
int switchState = 0;
int prevSwitchState = 0;

// Variable to choose which reply from the crystal ball
int reply;

void setup(){
    // Setup number of columns and rows on the LCD
    lcd.begin(16, 2);
}

pinMode(switchPin, INPUT);

// Print message to the LCD
lcd.print("Ask the");
lcd.setCursor(0, 1);     // Sets the cursor to the second row
lcd.print("Crystal Ball!");

void loop(){
    switchState = digitalRead(switchPin);

    // compare the switchState to its previous state
    if (switchState != prevSwitchState){
        if (switchState == LOW){
            reply = random(8);    // Randomly chooses a reply
            lcd.clear();
            lcd.setCursor(0, 0);   // Cursor set to first line
            lcd.print("the ball says:")
            lcd.setCursor(0, 1);  // Cursor set to second line

            // Choose a saying to print based on the value in the reply
            switch(reply){
                case 0:
                    lcd.print("Yes");
                    break;
                case 1:
                    lcd.print("Most likely");
                    break;
                case 2:
                    lcd.print("Certainly");
                    break;
                case 3:
                    lcd.print("Outlook good");
                    break;
                case 4:
                    lcd.print("Unsure");
                    break;
                case 5:
                    lcd.print("Ask again");
                    break;
                case 6:
                    lcd.print("Doubtful");
                    break;
                case 7:
                    lcd.print("No");
                    break;
            }
        }
    }
    // Save the current switch state as the last state
    prevSwitchState = switchState;
}