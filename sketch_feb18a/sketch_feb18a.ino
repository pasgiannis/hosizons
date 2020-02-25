
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
//this delay is for waiting 15 seconds until the next measurement
  delay(10000);

  
  //this checks if the SD card is ready to use
 if (!SD.begin(10)) { //using pin 10 (SS)
  
         //if there is a mistake with the code it will print that the initialization failed
          Serial.println("Initialization failed!\n");
          sdInitSuccess = false; //failure
          
        }
        
        //if it does not fail it then opens/creates the file and named "GASGASGAS(Giannis Atulit Sydney).txt"
        myFile = SD.open("GASGASGAS(Giannis Atulit Sydney).txt", FILE_WRITE);

        //if the file is successfully created/opened then we do the following
        if (myFile) {
                     
          //print success message, print the value we are writing (for fast testing purposes),
          //write the value, close the file, print done and change line
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
