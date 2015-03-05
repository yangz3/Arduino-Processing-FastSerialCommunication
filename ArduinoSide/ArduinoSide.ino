/*
 Serial Call and Response
 Language: Wiring/Arduino
 This program sends an ASCII A (byte of value 65) on startup
 and repeats that until it gets some data in.
 Then it waits for a byte in the serial port, and
 sends three sensor values whenever it gets a byte in.
 Thanks to Greg Shakar and Scott Fitzgerald for the improvements
 The circuit:
 * potentiometers attached to analog inputs 0 and 1
 * pushbutton attached to digital I/O 2
 Created 26 Sept. 2005
 by Tom Igoe
 modified 24 April 2012
 by Tom Igoe and Scott Fitzgerald
 This example code is in the public domain.
 http://www.arduino.cc/en/Tutorial/SerialCallResponse
*/
 
int firstSensor = 0; // first analog sensor
int secondSensor = 0; // second analog sensor
int thirdSensor = 0; // digital sensor
int inByte = 0;   // incoming serial byte
void setup()
{
 // start serial port at 9600 bps:
 Serial.begin(9600);
 establishContact(); // send a byte to establish contact until receiver responds
}
void loop()
{
 // if we get a valid byte, read analog ins:
 if (Serial.available() > 0) {
   
 // get incoming byte:
 inByte = Serial.read();
 
 // read first analog input, divide by 4 to make the range 0-255:
 firstSensor = 1;
 secondSensor = 2;
 thirdSensor = 3;
 
 // send sensor values:
 Serial.write(firstSensor);
 Serial.write(secondSensor);
 Serial.write(thirdSensor);
 }
}
void establishContact() {
 while (Serial.available() <= 0) {
     Serial.print('A'); // send a capital A
     delay(300);
 }
}
