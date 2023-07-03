#include <LiquidCrystal.h> // Library for LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int triggerPin = 10; // Setting the uses for these 3 pins on the microcontroller
const int echoPin = 9; // Pin 9 and 10 for motion sensor
const int buzzer = 8; // Pin for piezo
long motionSensor(int triggerPin, int echoPin) // Function for motion sensor functionality
{
pinMode(triggerPin, OUTPUT);
digitalWrite(triggerPin, LOW);
delayMicroseconds(2);
digitalWrite(triggerPin, HIGH);
delayMicroseconds(10);
digitalWrite(triggerPin, LOW);
pinMode(echoPin, INPUT);
return pulseIn(echoPin, HIGH);
}
// Function with instructions for what sound to play for each second out of 20 seconds
void notesPerSec(int i){
if(i == 20 || i == 10){
// output to piezo, (pin#, sound frequency, duration * 0.9 of note in ms), format
tone(buzzer, 659, 225);
delay(500); // Delay after each note in song
tone(buzzer, 587, 225);
delay(500);
noTone(buzzer); // Resets piezo for notes in the next second
}
else if(i == 19 || i == 9){
tone(buzzer, 523, 225);
delay(500);
tone(buzzer, 494, 225);
delay(500);
noTone(buzzer);
}
else if(i == 18 || i == 8){
tone(buzzer, 440, 225);
delay(250);
tone(buzzer, 440, 225);
delay(250);
tone(buzzer, 440, 225);
delay(250);
tone(buzzer, 494, 113);
delay(250);
noTone(buzzer);
}
else if(i == 17 || i == 7){
tone(buzzer, 0, 225);
delay(250);
tone(buzzer, 392, 113);
delay(125);
tone(buzzer, 392, 113);
delay(125);
tone(buzzer, 392, 113);
delay(125);
tone(buzzer, 392, 113);
delay(125);
tone(buzzer,392 , 225);
delay(250);
noTone(buzzer);
}
else if(i == 16 || i == 6){
tone(buzzer, 392, 225);
delay(250);
tone(buzzer, 392, 125);
delay(125);
tone(buzzer, 330, 113);
delay(125);
tone(buzzer, 392, 125);
delay(125);
tone(buzzer, 330, 113);
delay(125);
tone(buzzer, 392, 250);
delay(250);
noTone(buzzer);
}
else if(i == 15 || i == 5){
tone(buzzer, 0, 113);
delay(125);
tone(buzzer, 330, 125);
delay(125);
tone(buzzer, 392, 113);
delay(125);
tone(buzzer, 392, 113);
delay(125);
tone(buzzer, 392, 113);
delay(125);
tone(buzzer, 392, 113);
delay(125);
tone(buzzer, 392, 225);
delay(250);
noTone(buzzer);
}
else if(i == 14 || i == 4){
tone(buzzer, 392, 125);
delay(125);
tone(buzzer, 330, 113);
delay(125);
tone(buzzer, 392, 125);
delay(125);
tone(buzzer, 330, 113);
delay(125);
tone(buzzer, 392, 125);
delay(125);
tone(buzzer, 330, 113);
delay(125);
tone(buzzer, 392, 250);
delay(250);
noTone(buzzer);
}
else if(i == 13 || i == 3){
tone(buzzer, 0, 113);
delay(125);
tone(buzzer, 392, 113);
delay(125);
tone(buzzer, 392, 113);
delay(125);
tone(buzzer, 392, 113);
delay(125);
tone(buzzer, 392, 113);
delay(125);
tone(buzzer, 392, 113);
delay(125);
tone(buzzer, 392, 113);
delay(125);
tone(buzzer, 392, 113);
delay(125);
noTone(buzzer);
}
else if(i == 12 || i == 2){
tone(buzzer, 392, 113);
delay(125);
tone(buzzer, 392, 113);
delay(125);
tone(buzzer, 392, 125);
delay(125);
tone(buzzer, 330, 113);
delay(125);
tone(buzzer, 330, 225);
delay(250);
tone(buzzer, 392, 113);
delay(125);
tone(buzzer, 392, 113);
delay(125);
noTone(buzzer);
}
else if(i == 11 || i == 1){
tone(buzzer, 392, 113);
delay(125);
tone(buzzer, 392, 113);
delay(125);
tone(buzzer, 392, 225);
delay(250);
tone(buzzer, 330, 225);
delay(250);
tone(buzzer, 494, 113);
delay(125);
tone(buzzer, 0, 113);
delay(125);
noTone(buzzer);
}
else{
tone(buzzer, 0, 900);
delay(1000);
noTone(buzzer);
}
}
void setup() {
lcd.begin(16, 2); // Sets the LCD’s dimensions
}
void loop() {
// if motion sensor activates, formula is to set distances where sensor can be activated
if(0.01723 * motionSensor(triggerPin,echoPin) >= 3 && 0.01723 *
motionSensor(triggerPin,echoPin)<= 7){
for(int i = 20; i >= 0; i--){ // Loop for the countdown from 20 to 0
if(i >= 10){
lcd.setCursor(5,0);
lcd.print("Start: "); // Displays text at setCursor position on the LCD
lcd.setCursor(7,1);
lcd.print(i,1); // Displays current number at setCursor position on the LCD
notesPerSec(i); // Calls function to play the notes of the song for that given second
}
else{
if(i == 9){
lcd.clear(); // Resets LCD for single digits numbers instead of double digit numbers
lcd.setCursor(5,0);
lcd.print("Start: ");
}
if(i == 0){
lcd.setCursor(4,0);
lcd.print("Finish: "); // Changes “Start: “ to “Finish: “
}
lcd.setCursor(7,1);
lcd.print(i,1);
notesPerSec(i);
}
}
lcd.clear(); // Resets screen
delay(3000); // 3 second delay before song and countdown can occur again
}
}
