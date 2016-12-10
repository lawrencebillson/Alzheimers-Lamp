/*
Modulate a reading lamp with a carrier of 40Hz- may help with brain activity
Lawrernce Billson, 2016 
*/

#define FREQ 40

int period; // global value, we calculate it once

void setup() {
  period = 1000 / FREQ; // for our period in ms
  pinMode(3, OUTPUT);
}


void loop() {
  int duty;
  int onperiod;
  int offperiod;

  onperiod = map(analogRead(A2), 0 , 1023 , 0 , period); // Read the value, map it into a range of MS between 0 and our max period
  offperiod = period - onperiod;
  


  digitalWrite(3, HIGH);  
  delay(onperiod);      
  digitalWrite(3, LOW);    
  delay(offperiod);     
}
