void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT); //DEFINES THE BUILT IN LED AS THE OUTPUT IN THIS PROGRAM
}

void loop() {//CREATES A LOOP
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN, HIGH); //TURNS ON THE LED
  delay(1000); //WAITS 1000 MILLISECS (1 SECS)
  digitalWrite(LED_BUILTIN, LOW); //TURNS OFF THE LED
  delay(1000); //WAITS 1000MILLISECS (1 SECS)
}
