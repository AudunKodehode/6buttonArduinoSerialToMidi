const int button1 = 2;
const int button2 = 3;
const int button3 = 4;
const int button4 = 5;
const int extButton1 = 8;
const int extButton2 = 9;

const int debounce = 400;
const int midiChannel = 1; // MIDI channel to use

void setup() {
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  pinMode(extButton1, INPUT_PULLUP);
  pinMode(extButton2, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  int buttonState1 = digitalRead(button1);
  int buttonState2 = digitalRead(button2);
  int buttonState3 = digitalRead(button3);
  int buttonState4 = digitalRead(button4);
  int extButtonState1 = digitalRead(extButton1);
  int extButtonState2 = digitalRead(extButton2);

  if (buttonState1 == 0) {
    sendMidiNoteOn(60); // Send MIDI note on with note number 60 (middle C)
    delay(debounce);
  }
  if (buttonState2 == 0) {
    sendMidiNoteOn(62); // Send MIDI note on with note number 62 (D)
    delay(debounce);
  }
  if (buttonState3 == 0) {
    sendMidiNoteOn(64); // Send MIDI note on with note number 64 (E)
    delay(debounce);
  }
  if (buttonState4 == 0) {
    sendMidiNoteOn(65); // Send MIDI note on with note number 65 (F)
    delay(debounce);
  }
  if (extButtonState1 == 0) {
    sendMidiNoteOn(67); // Send MIDI note on with note number 67 (G)
    delay(debounce);
  }
  if (extButtonState2 == 0) {
    sendMidiNoteOn(69); // Send MIDI note on with note number 69 (A)
    delay(debounce);
  }
}

void sendMidiNoteOn(byte note) {
  Serial.write(0x90 | midiChannel); // Note on command on MIDI channel
  Serial.write(note); // Note number
  Serial.write(127); // Velocity
}