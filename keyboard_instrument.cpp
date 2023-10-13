// Create an array of notes
// the numbers below corresponid to the frequencies of middle, C, D, E and F
int notes[] = {262, 294, 330, 349};

void setup(){
    // Start serial communication
    Serial.begin(9600);
}

void loop(){
    // Create a local variable to hold the input on pin A0
    int keyVal = analogRead(A0);
    // Send the value from A0 to the serial Monitor
    Serial.println(keyVal);

    // Play the note corresponding to each value on A0
    // Then play the first frequency in the array on pin 8
    if (keyVal == 1023){
        tone(8, notes[0]);
    }

    else if (keyVal >= 990 && keyVal <= 1010){
        tone(8, notes[1]);
    }

    else if (keyVal >= 505 && keyVal <= 515){
        tone(8, notes[2]);
    }

    else if (keyVal >= 5 && keyVal <= 10){
        tone(8, notes[3]);
    }

    else {
        // If the value is out of range, play no tone
        noTone(8);
    }
}