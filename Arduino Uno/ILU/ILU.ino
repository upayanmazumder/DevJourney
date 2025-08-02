// Segment pins: a–g
const int segPins[7] = {2, 3, 4, 5, 6, 7, 8};

// Digit control pins
const int digitPins[3] = {9, 10, 11};

// Segment patterns for I, L, U (gfedcba)
const byte letters[3] = {
  B0110000, // I
  B1110000, // L
  B1111010  // U
};

void setup() {
  for (int i = 0; i < 7; i++) pinMode(segPins[i], OUTPUT);
  for (int i = 0; i < 3; i++) pinMode(digitPins[i], OUTPUT);
}

void loop() {
  for (int d = 0; d < 3; d++) {
    showLetter(d, letters[d]);
    delay(2); // Small delay to let the digit show up
  }
}

void showLetter(int digitIndex, byte segments) {
  // Turn off all digits first
  for (int i = 0; i < 3; i++) digitalWrite(digitPins[i], HIGH);

  // Set segments
  for (int i = 0; i < 7; i++) {
    digitalWrite(segPins[i], (segments >> i) & 1);
  }

  // Enable current digit (active LOW)
  digitalWrite(digitPins[digitIndex], LOW);
}
