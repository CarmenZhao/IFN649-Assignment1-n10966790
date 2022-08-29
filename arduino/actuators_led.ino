#define LEDPIN 5
#define LEDPIN_TWO 10


void setup() { 
// Setup serial for monitor and Setup Serial1 for BlueTooth
Serial.begin(9600); 
Serial1.begin(9600); 
pinMode(LEDPIN, OUTPUT);
pinMode(LEDPIN_TWO, OUTPUT);
}

void loop() {
// Process commands from bluetooth first.
if(Serial1.available() > 0){
String str = Serial1.readString().substring(0); 
Serial.println(str); 
if(str.indexOf("LED_ON") != -1 ){
digitalWrite(LEDPIN, HIGH);
} else if(str.indexOf("LED_OFF") != -1){
digitalWrite(LEDPIN, LOW);
}
if(str.indexOf("LED2_ON") != -1){
digitalWrite(LEDPIN_TWO, HIGH);
}
else if(str.indexOf("LED2_OFF") != -1){
digitalWrite(LEDPIN_TWO, LOW); 
  } 
 }
}