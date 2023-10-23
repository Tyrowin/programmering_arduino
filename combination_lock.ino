const int buttonPins[] = {5, 4, 3, 2}; // Button pins in order
const int greenLEDPin = 12;
const int redLEDPin = 11;
const int numOfButtons = 4;

int combination[] = {4, 2, 1, 4}; // Combination
int inputBuffer[] = {0, 0, 0, 0}; // To store button presses

unsigned long unlockedTime = 0;            // Time when the lock was unlocked
const unsigned long unlockDuration = 5000; // 5 seconds

void setup() {
    for (int i = 0; i < numOfButtons; i++) {
        pinMode(buttonPins[i], INPUT_PULLUP);
    }
    pinMode(greenLEDPin, OUTPUT);
    pinMode(redLEDPin, OUTPUT);

    lock(); // Lock at startup
}

void loop() {
    for (int i = 0; i < numOfButtons; i++) {
        if (digitalRead(buttonPins[i]) == LOW) {     // Since the button is connected to GND, it'll read LOW when pressed
            delay(50);                               // Debounce delay
            if (digitalRead(buttonPins[i]) == LOW) { // Check again after delay
                shiftInputBuffer(i + 1);
                if (checkCombination()) {
                    unlock();
                }
            }
        }
    }

    // Lock after 5 seconds
    if (unlockedTime && (millis() - unlockedTime >= unlockDuration)) {
        lock();
    }
}

void shiftInputBuffer(int buttonPressed) {
    for (int i = 0; i < numOfButtons - 1; i++) {
        inputBuffer[i] = inputBuffer[i + 1];
    }
    inputBuffer[numOfButtons - 1] = buttonPressed;
}

bool checkCombination() {
    for (int i = 0; i < numOfButtons; i++) {
        if (inputBuffer[i] != combination[i]) {
            return false;
        }
    }
    return true;
}

void unlock() {
    digitalWrite(greenLEDPin, HIGH);
    digitalWrite(redLEDPin, LOW);
    unlockedTime = millis();
}

void lock() {
    digitalWrite(greenLEDPin, LOW);
    digitalWrite(redLEDPin, HIGH);
    unlockedTime = 0;
}
