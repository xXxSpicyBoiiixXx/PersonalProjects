
const int relayPin = 8;

void setup() 
{
  pinMode(relayPin, OUTPUT);

}

void loop() 
{
  digitalWrite(relayPin, LOW);
  delay(500);
  digitalWrite(relayPin, HIGH);
  delay(500);

}
