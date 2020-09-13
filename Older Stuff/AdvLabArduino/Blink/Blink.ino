const int relayPin = 8;
void setup() 
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(relayPin, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH); 
  digitalWrite(relayPin, LOW);// turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(relayPin, HIGH);// turn the LED off by making the voltage LOW
  delay(500);    
// wait for a second
}
