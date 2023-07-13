#include <DS3231.h> 
#include <SPI.h> 
#include <SD.h> 

int temp_sensor = A2;
int ldr_sensor = A1;
int pot = A0;

File dataFile; 

float temperature;
int light_percentage;
int pot_percentage;

const int chipSelect = 10; //SD card CS pin connected to pin 10 of Arduino

// Init the DS3231 using the hardware interface
DS3231  rtc(SDA, SCL);

void setup()
{
    rtc.begin();
  
   Serial.begin(9600);

   
  // setup for the SD card
  Serial.print("Initializing SD card...");

  if(!SD.begin(chipSelect)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
    
  //open file
  dataFile = SD.open("LOGDATA.txt", FILE_WRITE);

  // if the file opened ok, write to it:
  if (dataFile) {
    Serial.println("File opened ok");
    // print the headings for our data
    dataFile.println("Date,Time,Temperature,Light Intensity%,POT%");
  }
 dataFile.close();

  Serial.println("CLEARDATA"); //clears up any data left from previous projects
  Serial.println("LABEL,Date,Logging Time,Time,Temperature,Light Intensity %, POT %"); //always write LABEL, to indicate it as first line
  Serial.println("RESETTIMER");
}

void loop()
{
    int temp_sensor_val = analogRead(temp_sensor);
    int ldr_sensor_val = analogRead(ldr_sensor);
    int pot_val = analogRead(pot);

    int light_percentage = map(ldr_sensor_val, 0, 1023, 0, 100);
    int pot_percentage = map(pot_val, 0,
1023, 0, 100);

    float millivolts = (temp_sensor_val / 1024.0) * 5000;
    float temperature = millivolts / 10;  // temperature in degrees celcius

    dataFile = SD.open("LOGDATA.txt", FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.print(rtc.getDateStr()); //Store date on SD card
    dataFile.print(","); //Move to next column using a ","

    dataFile.print(rtc.getTimeStr()); //Store date on SD card
    dataFile.print(","); //Move to next column using a ","

    dataFile.print(temperature);
//Store date on SD card
    dataFile.print(","); //Move to next column using a ","

    dataFile.print(light_percentage); //Store date on SD card
    dataFile.print(","); //Move to next column using a ","

    dataFile.print(pot_percentage); //Store date on SD card
    dataFile.print(","); //Move to next column using a ","

    dataFile.println(); //End of Row move to next row
    dataFile.close(); //Close the file
  }
  else
  Serial.println("OOPS!! SD card writing failed");
  
    //write to plx-dax
    
  Serial.print("DATA, DATE, TIMER, TIME,"); //always write "DATA" to Indicate the following as Data
    
    Serial.print(temperature); //Store date on Excel
    Serial.print(","); //Move to next column using a ","

    Serial.print(light_percentage); //Store date on Excel
    Serial.print(","); //Move to next column using a ","

    Serial.print(pot_percentage); //Store date on Excel
    Serial.print(","); //Move to next column using a ","

    Serial.println(); //End of Row move to next row
    
 delay(3000); //Wait for 3 seconds before writing the next data 
}