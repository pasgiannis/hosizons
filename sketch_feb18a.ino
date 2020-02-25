
#include <SPI.h>
#include <SD.h>
const int readLight=A1;
int sensorValue=0;
int outputValue=0;
byte inByte; //byte read from terminal
bool sdInitSuccess = false; //card init status
File myFile;
String readText; //text read from file
char readCharArray[128]; //buffer for reading from file
unsigned long fileSize; //size of opened file
unsigned long filePos = 0;
//---------------------------------------------------------------//
void setup() {
  Serial.begin(9600);
    pinMode(A1, INPUT);
  while (!Serial) {
    ; //wait for the serial port to connect.
  }
}
//---------------------------------------------------------------//
void loop() {

  delay(10000);
 if (!SD.begin(10)) { //using pin 10 (SS)
          Serial.println("Initialization failed!\n");
          sdInitSuccess = false; //failure
          
        }
        myFile = SD.open("TEST.txt", FILE_WRITE);
        if (myFile) {

//outputValue = map(sensorValue, 0, 1023, 0, 255);
           

          Serial.println("File opened successfully.");
          Serial.println("Writing to TEST.text /n  Writing value :");
          Serial.println(analogRead(readLight));
          myFile.println(analogRead(readLight));
          myFile.close(); //this writes to the card
          Serial.println("Done");
          Serial.println();
        }
        else { //else show error
          Serial.println("Error opeing file.\n");
        }
      }
