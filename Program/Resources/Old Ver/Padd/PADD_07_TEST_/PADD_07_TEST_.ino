// include the library code:
//=============================
// for DHT11,                 |
//      (PIN 1)Data: D7       |
//      (PIN 2)VCC: 5V or 3V  |
//      (PIN 3)GND: GND       |
//=============================
#include <LiquidCrystal.h>
//download Dht.
//download <liquidcrystal>

// set the DHT Pin
#define DHTPIN 8 //dht11 in pin8

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  dht.begin();
  for (x = 0; x < 3; x ++)
{
    analogWrite(PWMpin, x);
      lcd.print("PADD||STARTUP...");
    if (sens > threshold){      // bail out on sensor detect
       x = 0;
       break;
    }
    delay(50);
}
  lcd.clear()
  // Print a message to the LCD.
  lcd.print("Temp:  Humidity:");
}

void loop() {
  delay(500);
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // read humidity
  float h = dht.readHumidity();
  //read temperature in Fahrenheit
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(f)) {
    lcd.print("PADD||ERROR");
    return;
  }

  lcd.print(f);
  lcd.setCursor(7,1);
  lcd.print(h);  
}
