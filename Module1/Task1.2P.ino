const int led = 7;
const int button = 2;

//volatile int buttonState = 0;
volatile byte buttonState = LOW;

void setup()
{
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(2, INPUT);
  //attach interrupt
  attachInterrupt(digitalPinToInterrupt(2), high_low, FALLING);
  attachInterrupt(digitalPinToInterrupt(3), low_high, RISING);
}

void loop()
{
  delay(1000);
}

void low_high() {
  buttonState = digitalRead(button);
  digitalWrite(led, buttonState);
  Serial.println("LED ON");
}

void high_low() {
  buttonState = digitalRead(button);
  digitalWrite(led, buttonState);
  Serial.println("LED OFF");
}