int LIGHT_TIMER = 4000;

int red_H = 3;
int yellow_H = 5;
int green_H = 6;

int red_V = 9;
int yellow_V = 10;
int green_V = 11;

int button = 13;
int buttonState = 0;

uint8_t button_prev;

void setup() {
  pinMode(green_H, OUTPUT);
  pinMode(yellow_H, OUTPUT);
  pinMode(red_H, OUTPUT);

  pinMode(green_V, OUTPUT);
  pinMode(yellow_V, OUTPUT);
  pinMode(red_V, OUTPUT);

  pinMode(button, INPUT);
}

void loop() {
  lights(LIGHT_TIMER);

  delay(1000);

}

/* V - V
 * G - V
 * A - V
 * V - V
 * V - G
 * V - A
 * V - V
*/

void lights(int timer) {
  // inicio V - V
  digitalWrite(red_H, HIGH);
  digitalWrite(red_V, HIGH);
  delay(1000);

  // G - V
  digitalWrite(red_H, LOW);
  digitalWrite(green_H, HIGH);
  delay(LIGHT_TIMER - 1000);

  // A - V
  digitalWrite(green_H, LOW);
  digitalWrite(yellow_H, HIGH);
  delay(LIGHT_TIMER - 3000);

  // V - V
  digitalWrite(yellow_H, LOW);
  digitalWrite(red_H, HIGH);
  delay(1000);

  // V - G
  digitalWrite(red_V, LOW);
  digitalWrite(green_V, HIGH);
  delay(LIGHT_TIMER - 1000);

  // V - A
  digitalWrite(green_V, LOW);
  digitalWrite(yellow_V, HIGH);
  delay(LIGHT_TIMER - 3000);
  digitalWrite(yellow_V, LOW);

  // V - V
  changeRed();
  digitalWrite(red_H, LOW);
  digitalWrite(red_V, LOW);
}

void changeRed() {
  digitalWrite(green_H, LOW);
  digitalWrite(green_V, LOW);

  digitalWrite(yellow_H, LOW);
  digitalWrite(yellow_V, LOW);
  
  digitalWrite(red_H, HIGH);
  digitalWrite(red_V, HIGH);
}

void buttonRed() {
  changeRed();
  delay(5000);
  
}
