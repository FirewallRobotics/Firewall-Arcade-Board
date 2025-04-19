// Team Firewall Arduino Micro based arcade board controller code

#include <Joystick.h> 

void setup() {
  // Initialize Button Pins
  // Barge Left Red = pin 0
  pinMode(0, INPUT_PULLUP);
  // Barge Right Red = pin 1
  pinMode(1, INPUT_PULLUP);
  // Barge Left White = pin 3
  pinMode(3, INPUT_PULLUP);
  // Barge Left Blue = pin 4
  pinMode(4, INPUT_PULLUP);
  // Barge Right Blue = pin 5
  pinMode(5, INPUT_PULLUP);
  // Barge Right White = pin 6
  pinMode(6, INPUT_PULLUP);
  // Left L3 = pin 7
  pinMode(7, INPUT_PULLUP);
  // Left L2 = pin 8
  pinMode(8, INPUT_PULLUP);
  // Right L2 = pin 9
  pinMode(9, INPUT_PULLUP);
  // Left L4 = pin 10
  pinMode(10, INPUT_PULLUP);
  // Right L4 = pin 11
  pinMode(11, INPUT_PULLUP);
  // Right L3 = pin 12
  pinMode(12, INPUT_PULLUP);

  // Initialize Joystick Library
  Joystick.begin();
}

const int NUM_BUTTONS = 13;

// Last state of the button
int lastButtonState[NUM_BUTTONS] = {0,0,0,0,0,0,0,0,0,0,0,0,0};

void loop() {

  // Read pin values
  for (int index = 0; index < NUM_BUTTONS; index++)
  {
    int currentButtonState = !digitalRead(index);
    if (currentButtonState != lastButtonState[index])
    {
      Joystick.setButton(index, currentButtonState);
      lastButtonState[index] = currentButtonState;
    }
  }

  delay(50);
}

