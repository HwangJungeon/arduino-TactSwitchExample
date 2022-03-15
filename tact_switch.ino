const int sw = D7;
const int led = D6;
 
int led_state = LOW;
int current_state;
int previous_state = LOW;
 
long timer = 0;
long debounce = 100;

void setup() {
  pinMode(sw, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}
 
void loop() {
  current_state = digitalRead(sw);
 
  if (current_state == HIGH && previous_state == LOW && millis() - timer > debounce) {
    if (led_state == HIGH)
      led_state = LOW;
    else
      led_state = HIGH;
 
    timer = millis();
  }
 
  digitalWrite(led, led_state);
  previous_state = current_state;
}
