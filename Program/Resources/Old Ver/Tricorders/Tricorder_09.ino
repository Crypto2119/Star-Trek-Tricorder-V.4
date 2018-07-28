//=============================================================
//            SETUP:                                          |
//-------------------------------------------------------------
//*THIS PROGRAM WAS INTENDED FOR USE WITH THE ARDUINO UNO R3* |
//-------------------------------------------------------------
//GO TO SKETCH AND DOWNLOAD THE LIBRARIES BELOW:              |
//  1.DHT.H                                                   |
//  2.LIQUIDCRYSTAL.H                                         |
//-------------------------------------------------------------
//=============================================================
//SETUP THE CORRECT TOOLS:                                    |
//- SET BOARD TO THE CORRECT BOARD                            |
//- SET THE CORRECT BOARD (IF POSSIBLE)                       |
//- SET THE UPLOAD SPEED TO 115200 OR YOUR OWN BOARD SPEED    |
//=============================================================
//=============================================================
// for DHT11,                                                 |
//      (PIN 1)Data: D7                                       |
//      (PIN 2)VCC: 5V or 3V                                  |
//      (PIN 3)GND: GND                                       |
//=============================================================
//---------------------------------------------------------------
//CHECK THE SCHEMATIC FOR THE LCD DISPLAY IN THE ZIP FILE       |
//---------------------------------------------------------------
#include <LiquidCrystal.h>//LIBRARY FOR THE LCD DISPLAY
#include "DHT.h"//LIBRARY FOR THE DHT11 (NAME OF THE HUMIDITY SENSOR)

// set the DHT Pin
#define DHTPIN 8//STATES POSITION OF THE DHT11 DATA PINS

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {

  // BEGINS THE SETUP OF THE PROGRAM: 
  lcd.begin(16, 2);
  dht.begin();
  pinMode(LED_BUILTIN, OUTPUT);//defines the output
  lcd.print("TRICORDER SETUP");//setup
  delay((random(1000, 3000)));
  lcd.setCursor(7,1);//RESETS THE CURSOR TO THE SECOND ROW
  lcd.print(".");
  delay((random(10, 30)));
  lcd.clear();
  lcd.print("..");
  delay((random(10, 30)));
  lcd.clear();
  lcd.print("...");
  delay((random(10, 30)));
  lcd.clear();
  lcd.setCursor(7,1);//RESETS THE CURSOR TO THE SECOND ROW
  lcd.print(".");
  delay((random(10, 30)));
  lcd.clear();
  lcd.print("..");
  delay((random(10, 30)));
  lcd.clear();
  lcd.print("...");
  delay((random(10, 30)));
  lcd.clear();
  lcd.setCursor(7,1);//RESETS THE CURSOR TO THE SECOND ROW
  lcd.print(".");
  delay((random(10, 30)));
  lcd.clear();
  lcd.print("..");
  delay((random(10, 30)));
  lcd.clear();
  lcd.print("...");
  delay((random(10, 3000)));
  lcd.clear();
  pinMode(LED_BUILTIN, OUTPUT);//defines the output
 }
 
void loop() {//BEGINS MAIN PART OF THE PROGRAM
  // PRINT DATA TO THE LCD.
  lcd.print("Temp(F) |  Humidity|");
  delay((random(10, 30)));//waits 10-30 millisecs (0.01-0.03)
  digitalWrite(LED_BUILTIN, HIGH);//turns on the led
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1); //RESETS CURSOR TO THE FIRST ROW 
  // read humidity
  float h = dht.readHumidity();//SETS UP THE DHT11 IN HUMIDITY
  //read temperature in Fahrenheit
  float f = dht.readTemperature(true);//TESTS THE DHT11 IN TEMPERATURE (F)
  float c = dht.readTemperature(true);//TEST THE DHT11 IN TEMPERATURE (C)

  delay((random(10, 30)));//waits 10-30 millisecs (0.01-0.03)
  digitalWrite(LED_BUILTIN, LOW);//turns off the led
  if (isnan(h) || isnan(f)) {//if there is an error, the error message will show on screen
    lcd.print("|==| TRICORDER ERROR |==|");//error message
    delay(1000);
    lcd.print("REALIGN DHT11 PINS");//TROUBLESHOOTING TIPS
    delay(1000);
    lcd.print("CHECK PINS");//TROUBLESHOOTING TIPS
    return;//RESETS THE CURSOR AND CLEARS THE LCD
  }
  lcd.print(f);//PRINTS THE TERMPERATURE IN F
  lcd.setCursor(7,1);//RESETS THE CURSOR TO THE SECOND ROW
  lcd.print(h); //PRINTS THE HUMIDITY
  delay((random(900, 1000))); digitalWrite(LED_BUILTIN, HIGH);//WAITS 900-1000 MILLISECS(0.9-1 SECS)AND TURNS ON THE LED
  lcd.clear();//CLEARS LCD
  lcd.print("CELSIUS: ");//WRITES TEXT
  (7,1);//RESETS CURSOR TO THE SECOND ROW
  lcd.print(5/9*(f-32));//CONVERTS TEMPERATURE F TO C WITH THE CONVERSION EQUATION (5/9*(F-32) USES ACII CHARS)
  delay((random(900, 1000))); digitalWrite(LED_BUILTIN, LOW);//WAITS 900-1000 MILLISECS(0.9-1 SECS)AND TURNS OFF THE LED
  lcd.clear();//CLEARS LCD
}
//OBJECTIVE:
//THE OBJECTIVE OF THIS PROJECT IS TO CREATE A STAR TREK TRICORDER AS REAL AS POSSIBLE.
//THIS ALSO MEANS THAT IT MUST SHOW REAL DATA IN THE SURROUNDINGS, OR IT WILL WORK AS A PROP.
//*USE A CASE THAT LOOKS LIKE THE REAL THING*
//CHANGELOG:
//7/1/18
//CREATED PROGRAM
//MADE SCHEMATICS
//7/2/18
//MADE PROGRAM BASE AND UPLOADED FOR TEST
//ADDED TEMPERATURE F TO C EQUATION FOR MULTI-CONTINENT USE(USES METRIC AND IMPERIAL UNITS)
//7/3/18
//ADDED INCLUDED DEBUGGING SERVICING FOR THE DHT11(STILL WORKING ON THE LCD)
//ADDED MORE COMMENTS FOR LEARNERS
//NEEDED FIXES SO FAR:
//-F-C BUG
//-CHECK COMMENTS FOR ACCURACY
//-DELETE ANY UNNECCESSARY LINES

