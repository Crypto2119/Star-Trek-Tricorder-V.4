String inData;
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin
#include <LiquidCrystal.h>//LIBRARY FOR THE LCD DISPLAY
#include "DHT.h"//LIBRARY FOR THE DHT11 (NAME OF THE HUMIDITY SENSOR)
// set the DHT Pin
#define DHTPIN 8//STATES POSITION OF THE DHT11 DATA PINS

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
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
  Serial.begin(115200);
    pinMode(LED_BUILTIN, OUTPUT);

  // reserve 200 bytes for the inputString:
}

void loop() {
    while (Serial.available() > 0)
    {
        char recieved = Serial.read();
        inData += recieved; 

        // Process message when new line character is recieved
        if (recieved == 'n')
        {
            Serial.print("Message Received: ");
            Serial.print(inData);

            float x = Serial.read();
            if(x = 1){
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
            else if (x = 0){
                 if (buttonState == LOW) {
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
    else {
    lcd.clear();
    lcd.print("Press The Button To Initiate Scan");   
    float q = dht.readTemperature(true);
    delay(1000);
    float f = dht.readTemperature(true);//SETS UP THE DHT11 IN TEMPERATURE (F)
    if (f<q) {//if the delayed temperature is greater than the later temperature, then save the temp to temporary ram for display
      float g = q;
      lcd.clear();
      lcd.print("Highest Temperature");
      Serial.print("Hightest Temperature");
      delay(500);
      lcd.print(g);
      Serial.print(g);
      if (g<q) {//if the highest stored temperature is smaller than the newer temperature then do below
        Serial.print("Highest Temperature");
        lcd.print("Hightest Temperature");
        delay(500);
        lcd.print(q);
        Serial.print(q);
        }
      } else {//if these situations do not apply, then below will activate
        lcd.print("Highest Temperature");
        Serial.print("Highest Temperature");
        lcd.print(f);
        Serial.print(f);
        }
      }
  }
}
            }

            inData = ""; // Clear recieved buffer
        }
    
	//Change Log:
	//Reverted the Button Function Back to Before Because of Glitches