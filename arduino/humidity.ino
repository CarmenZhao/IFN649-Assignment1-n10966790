#include "DHT.h"

#define DHTPIN 21      // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11

#define LEDPIN 11

DHT dht(DHTPIN, DHTTYPE);

// Teensy 5V <--> HC-05 Vcc
// Teensy Ground <--> HC-05 GND
#define rxPin 7 // Teensy pin 7 <--> HC-05 Tx
#define txPin 8 // Teensy pin 8 <--> HC-05 Rx

void setup() {
  // Setup serial for monitor
  Serial.begin(9600); 

  // Setup DHT Sensor
  pinMode(DHTPIN, INPUT);
  dht.begin();

  // Setup Serial1 for BlueTooth
  Serial1.begin(9600); // Default communication rate of the Bluetooth module
}

void loop() {
  if(Serial1.available() > 0){ // Checks whether data is comming from the serial port
    
    float h = dht.readHumidity();
   
    Serial.print(F("Humidity:"));
    Serial.print(h);
    Serial.println(F("%"));

    Serial1.print(F("Humidity:"));
    Serial1.print(h);
    Serial1.println(F("%"));
    
    digitalWrite(LEDPIN, HIGH);
    delay(1000);
    digitalWrite(LEDPIN, LOW);
    delay(1000);
 }
}