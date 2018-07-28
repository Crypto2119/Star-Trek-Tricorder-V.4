
//=============================================================
//            SETUP:                                          |
//-------------------------------------------------------------
//*THIS PROGRAM WAS INTENDED FOR USE WITH THE ARDUINO UNO R3* |
//-------------------------------------------------------------
//GO TO SKETCH AND DOWNLOAD THE LIBRARIES BELOW:              |
//  1.DHT.H                                                   |
//  2.LIQUIDCRYSTAL.H                                         |
//IF IT DOES NOT WORK, THEN                                   |
//TRY DOWNLOADING ALL OF THE LIRARIES                         |
//CHECK THAT YOU DOWNLOADED THE CORRECT LIBRARY, SIMPLE DHT   |
//-------------------------------------------------------------
//=============================================================
//SETUP THE CORRECT TOOLS:                                    |
//- SET BOARD TO THE CORRECT BOARD                            |
//- SET THE CORRECT BOARD (IF POSSIBLE)                       |
//- SET THE UPLOAD SPEED TO 115200 OR YOUR OWN BOARD SPEED    |
//=============================================================
//============================================================= 
// DHT11 PINS:                                                |
//      (PIN 1)Data: D7                                       |
//      (PIN 2)VCC: 5V or 3V                                  |
//      (PIN 3)GND: GND                                       |
//=============================================================
//---------------------------------------------------------------
//CHECK THE SCHEMATIC FOR THE LCD DISPLAY IN THE ZIP FILE       |
//---------------------------------------------------------------
#include <LiquidCrystal.h>//LIBRARY FOR THE LCD DISPLAY
#include "DHT.h"//LIBRARY FOR THE DHT11 (NAME OF THE HUMIDITY SENSOR)
//#include <Esplora.h>//LIBRARY FOR THE BUTTON
#define DHTPIN 8//STATES POSITION OF THE DHT11 DATA PINS

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {

  // BEGINS THE SETUP OF THE PROGRAM:
  const int buttonPin = 2;//STATES THE POSITION OF THE BUTTON
  pinMode(buttonPin, INPUT); 
  lcd.begin(16, 2);//SETS THE LCD TO 16,2
  dht.begin();//STARTS LCD
  pinMode(LED_BUILTIN, OUTPUT);//defines the output
  lcd.print("TRICORDER SETUP");//setup
  delay((random(1000, 3000)));//WAITS 1000- 3000 MILLISECS (1-3 SECS)
  lcd.setCursor(7,1);//RESETS THE CURSOR TO THE SECOND ROW
  Serial.print("Setup.");
  lcd.print(".");
  delay((random(10, 30)));//WAITS 10-30 MILLISECS (0.01-0.03 SECS)
  Serial.print("Setup..");
  lcd.clear();//CLEARS LCD
  lcd.print("..");
  delay((random(10, 30)));//WAITS 10-30 MILLISECS (0.01-0.03 SECS)
  Serial.print("Setup...");//LOADING
  lcd.clear();//CLEAR LCD
  lcd.print("...");//LOADING
  delay((random(10, 30)));//WAITS 10-30 MILLISECS (0.01-0.03 SECS)
  Serial.print("Setup.");
  lcd.clear();//CLEAERS LCD
  lcd.setCursor(7,1);//RESETS THE CURSOR TO THE SECOND ROW
  lcd.print(".");
  delay((random(10, 30)));//WAITS 10-30 MILLISECS (0.01-0.03 SECS)
  Serial.print("Setup..");
  lcd.clear();//CLEARS LCD
  lcd.print("..");
  delay((random(10, 30)));//WAITS 10-30 MILLISECS (0.01-0.03 SECS)
  Serial.print("Setup...");
  lcd.clear();//CLEARS LCD
  lcd.print("...");
  delay((random(10, 30)));//WAITS 10-30 MILLISECS (0.01-0.03 SECS)
  Serial.print("Setup.");
  lcd.clear();//CLEARS LCD
  lcd.setCursor(7,1);//RESETS THE CURSOR TO THE SECOND ROW
  lcd.print(".");
  delay((random(10, 30)));//WAITS 10-30 MILLISECS (0.01-0.03 SECS)
  Serial.print("Setup..");
  lcd.clear();//CLEARS LCD
  lcd.print("..");
  delay((random(10, 30)));//WAITS 10-30 MILLISECS (0.01-0.03 SECS)
  Serial.print("Setup...");
  lcd.clear();//CLEARS LCD
  lcd.print("...");
  delay((random(10, 3000)));//WAITS 10-3000 MILLISECS (0.01-3 SECS)
  Serial.print("Setup.");
  lcd.clear();//CLEARS LCD
  pinMode(LED_BUILTIN, OUTPUT);//defines the output
  int buttonState = 0; 
 }
  int buttonState = 0; 
  const int buttonPin = 2;//STATES THE POSITION OF THE BUTTON
  void loop() {//BEGINS MAIN PART OF THE PROGRAM
  if (buttonState == HIGH) {
    int buttonState = 0; 
    const int buttonPin = 2;//STATES THE POSITION OF THE BUTTON
    pinMode(buttonPin, INPUT);
    // PRINT DATA TO THE LCD.
    lcd.print("Temp(F) |  Humidity|");
    delay((random(10, 30)));//waits 10-30 millisecs (0.01-0.03)
    Serial.print("Temp:");
    digitalWrite(LED_BUILTIN, HIGH);//turns on the led
    // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
    lcd.setCursor(0, 1); //RESETS CURSOR TO THE FIRST ROW 
    // read humidity
    float h = dht.readHumidity();//SETS UP THE DHT11 IN HUMIDITY
    //read temperature in Fahrenheit
    float f = dht.readTemperature(true);//SETS UP THE DHT11 IN TEMPERATURE (F)
    float c = 5*(f-32)/9;//SETS UP THE DHT11 IN TEMPERATURE (C)

    delay((random(10, 30)));//waits 10-30 millisecs (0.01-0.03)
    digitalWrite(LED_BUILTIN, LOW);//turns off the led
    if (isnan(h) || isnan(f)) {//if there is an error, the error message will show on screen
      lcd.print("|==| TRICORDER ERROR |==|");//error message
      Serial.print("TRICORDER ERROR");
      delay(1000);//WAIT 1000 MILLISECS (1 SECS)
      lcd.print("REALIGN DHT11 PINS");//TROUBLESHOOTING TIPS
      delay(1000);//WAIT 1000 MILLISECS (1 SECS)
      lcd.print("CHECK PINS");//TROUBLESHOOTING TIPS
      return;//RESETS THE CURSOR AND CLEARS THE LCD
    }
    lcd.print(f);//PRINTS THE TERMPERATURE IN F
    Serial.print(f);//PRINTS THE F IN SERIAL MONITER
    lcd.setCursor(7,1);//RESETS THE CURSOR TO THE SECOND ROW
    lcd.print(h); //PRINTS THE HUMIDITY
    Serial.print("HUMIDITY");//WRITES THE LABEL FOR THE HUMIDITY ON THE SERIAL MONITER
    Serial.print(h);//PRINTS THE HUMIDITY IN THE SERIAL MONITER
    if (h>40) {//WARNING FOR HIGH HUMIDITY
      Serial.print("||RED ALERT||");
      Serial.print("BIOCONTAMINATION");
      Serial.print("EVACUATE ZONE: HIGH HUMIDITY");
      lcd.print("||RED ALERT||");
      delay(500);
      Serial.print("BIOCONTAMINATION");
      delay(500);
      lcd.print("EVACUATE ZONE: HIGH HUMIDITY");
      }
    if (f>100) {//WARNING FOR TOO HOT 
      Serial.print("||RED ALERT||");
      Serial.print("TIME DISTORTIONS");
      Serial.print("EVACUATE ZONE: HIGH TEMPERATURE");
      lcd.print("||RED ALERT||");
      delay(500);
      Serial.print("TIME DISTORTIONS");
      delay(500);
      lcd.print("EVACUATE ZONE: HIGHT TEMPERATURE");
      }
    if (f<45) {//WARNING FOR TOO COLD
      Serial.print("||WARNING||");
      Serial.print("CHECK TEMPERATURE");
      Serial.print("EVACUATE ZONE: TOO COLD");
      lcd.print("||WARNING||");
      delay(500);
      Serial.print("CHECK TEMPERATURE");
      delay(500);
      lcd.print("EVACUATE ZONE: TOO COLD");
      }
    delay((random(900, 1000))); digitalWrite(LED_BUILTIN, HIGH);//WAITS 900-1000 MILLISECS(0.9-1 SECS)AND TURNS ON THE LED
    lcd.clear();//CLEARS LCD
    lcd.print("CELSIUS: ");//WRITES TEXT
    (7,1);//RESETS CURSOR TO THE SECOND ROW
    lcd.print(c);//CONVERTS TEMPERATURE F TO C WITH THE CONVERSION EQUATION (5/9*(F-32) USING ACII CHARS)
    delay((random(900, 1000))); digitalWrite(LED_BUILTIN, LOW);//WAITS 900-1000 MILLISECS(0.9-1 SECS)AND TURNS OFF THE LED
    lcd.clear();//CLEARS LCD  
  }
 else{
  lcd.clear();
  lcd.print("Press The Button To Initiate Scan");
  }
}
//---------------------------------------------------------------------------------------------
//OBJECTIVE:
//THE OBJECTIVE OF THIS PROJECT IS TO CREATE A STAR TREK TRICORDER AS REAL AS POSSIBLE.
//THIS ALSO MEANS THAT IT MUST SHOW REAL DATA IN THE SURROUNDINGS, OR IT WILL WORK AS A PROP.
//*USE A CASE THAT LOOKS LIKE THE REAL THING*
//---------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------
//CHANGELOG:
//VERSION 1
//7/1/18
//CREATED PROGRAM
//MADE SCHEMATICS
//7/2/18
//MADE PROGRAM BASE AND UPLOADED FOR TEST
//ADDED TEMPERATURE F TO C EQUATION FOR MULTI-CONTINENT USE(USES METRIC AND IMPERIAL UNITS)
//VERSION 9
//7/3/18
//ADDED INCLUDED DEBUGGING SERVICING FOR THE DHT11(STILL WORKING ON THE LCD)
//ADDED MORE COMMENTS FOR LEARNERS
//NEEDED FIXES SO FAR:
// - F-C CONVERSION BUG
// - CHECK COMMENTS FOR ACCURACY
// - DELETE ANY UNNECCESSARY LINES
//VERSION 10
//7/5/18
//REMOVED THE CELSIUS FUNCTION TO FIX THE BUG
//ADDED SERIAL PORT USE INSTEAD OF THE DISPLAY
//MORE COMMENTING
//---------------------------------------------------------------------------------------------

//               NOTES:
//-WORKS MOSTLY WITH ARDUINO GENUINO OR UNO
//-SET MAINLY FOR FAREHNHEIT, REQUIRES CONFIGURATION FOR CELCIUS
//-HOOK UP TO A BATTERY PACK FOR USE SO THAT THE TRICORDER CAN BE MORE PORTABLE
