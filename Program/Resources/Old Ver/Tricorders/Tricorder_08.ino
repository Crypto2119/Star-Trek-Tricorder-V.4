// include the library code:
//dht
//liquidcrystal
//=============================
// for DHT11,                 |
//      (PIN 1)Data: D7       |
//      (PIN 2)VCC: 5V or 3V  |
//      (PIN 3)GND: GND       |
//=============================
#include <LiquidCrystal.h>
#include "DHT.h"

// set the DHT Pin
#define DHTPIN 8

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {

  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  dht.begin();
  lcd.print("TRICORDER SETUP.");//setup
  delay((random(10, 1000)));//waits random 10-1000 millisecs (0.01-3 secs)
  lcd.clear();//clears lcd
  lcd.print("TRICORDER SETUP..");//setup
  delay((random(10, 1000)));//waits random 10-1000 millisecs (0.01-3 secs)
  lcd.clear();//clears lcd
  lcd.print("TRICORDER SETUP...");//setup
  delay((random(10, 1000)));//waits random 10-1000 millisecs (0.01-3 secs)
  lcd.clear();//clears lcd
  lcd.print("TRICORDER SETUP.");//setup
  delay((random(10, 1000)));//waits random 10-1000 millisecs (0.01-3 secs)
  lcd.clear();//clears lcd
  lcd.print("TRICORDER SETUP..");//setup
  delay((random(10, 1000)));//waits random 10-1000 millisecs (0.01-3 secs)
  lcd.clear();//clears lcd
  lcd.print("TRICORDER SETUP...");//setup
  delay((random(10, 1000)));//waits random 10-1000 millisecs (0.01-3 secs)
  lcd.clear();//clears lcd
  lcd.print("TRICORDER SETUP.");//setup
  delay((random(10, 1000)));//waits random 10-1000 millisecs (0.01-3 secs)
  lcd.clear();//clears lcd
  lcd.print("TRICORDER SETUP..");//setup
  delay((random(10, 1000)));//waits random 10-1000 millisecs (0.01-3 secs)
  lcd.clear();//clears lcd
  lcd.print("TRICORDER SETUP...");//setup
  delay((random(10, 1000)));//waits random 10-1000 millisecs (0.01-3 secs)
  lcd.clear();//clear lcd 
  pinMode(LED_BUILTIN, OUTPUT);//defines the output
  
  
  
}

void loop() {
  // Print a message to the LCD.
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
    return;
  }

  lcd.print(f);//PRINTS THE TERMPERATURE IN F
  lcd.setCursor(7,1);//RESETS THE CURSOR TO THE SECOND ROW
  lcd.print(h); //PRINTS THE HUMIDITY
  delay((random(900, 1000))); digitalWrite(LED_BUILTIN, HIGH);//WAITS 900-1000 MILLISECS(0.9-1 SECS)AND TURNS ON THE LED
  lcd.clear();//CLEARS LCD
  lcd.print("CELSIUS: ");//WRITES TEXT
  lcd.print(5/9*(f-32));//CONVERTS TEMPERATURE F TO C
  delay((random(900, 1000))); digitalWrite(LED_BUILTIN, LOW);//WAITS 900-1000 MILLISECS(0.9-1 SECS)AND TURNS OFF THE LED

  lcd.clear();//CLEARS LCD
}
