/*
 * This sketch is for example on how to control the Soft Latch circuit
 * INT_PIN is the arduino Digital Pin connected to the Soft Latch's "Off Pin"
 * */
#define INT_PIN     2


void setup() {
  //Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  delay(1000);
  setInterrupt();
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}

void setInterrupt(){
  //Here we are setting the INT_PIN as INPUT_PULLUP and set the Interrup to listen for Falling Edge
  //Whenever the power button at Soft Latch is pressed, it will pull this pin down, triggering the function attached
  pinMode(INT_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(INT_PIN), shuttingDown, FALLING);
}

void shuttingDown(){
  //Here is the shuttingDown routine.
  //We also could call this function without waiting for the interrupt triggered.
  detachInterrupt(digitalPinToInterrupt(INT_PIN));
  pinMode(INT_PIN, OUTPUT);
  digitalWrite(INT_PIN, LOW);
}
