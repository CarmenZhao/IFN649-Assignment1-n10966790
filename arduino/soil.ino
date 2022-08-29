const int ledPin = 11;
const int soilPin = 21;
// the setup() method runs once, when the sketch starts
void setup() {
// initialize the digital pin as an output.
pinMode(ledPin, OUTPUT);
Serial.begin(9600);
Serial1.begin(9600);
}
void loop() {
  if(Serial1.available() > 0){
    int val = analogRead(soilPin);
    Serial.print("Soil Moisture:");
    Serial.println(val);
    Serial1.print("Soil Moisture:");
    Serial1.println(val);

    digitalWrite(ledPin, HIGH); // set the LED on
    delay(1000); // wait for a second
    digitalWrite(ledPin, LOW); // set the LED off
    delay(1000); // wait for a second
  }
}