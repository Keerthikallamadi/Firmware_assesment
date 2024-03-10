#include<NoDelay.h>
#include <Arduino.h>

noDelay LEDtime(250);//Creating a noDelay varible set to 250ms
noDelay LEDtime1(500);//Creating a noDelay varible set to 500ms

const int lm35_pin = A0;  /* LM35 O/P pin */
int LED_pin = 13;         // arduino on board led pin is D13 
int state_of_LED = LOW;     //initially i took led state is low 
void setup() {
  Serial.begin(9600); // initiallize the serial debug 
   pinMode(LED_pin, OUTPUT); // setting the mode of on board led  D13 is  output mode
}

void loop() {
  int temp_adc_value; // Taking variable to store the values 
  float temp_value;  // Taking another variable for store the values
  temp_adc_value = analogRead(lm35_pin);  /* Reading Temperature */
  temp_value = (temp_adc_value * 5.0); /* Convert adc value to equivalent voltage */
  temp_value = (temp_value/10); /* LM35 gives output of 10mv/°C */
  
  Serial.print("Temperature = "); // monitoring the values on serial monitoring
  Serial.print(temp_value);
  Serial.print(" Degree Celsius\n");
 
  
 if(temp_value<30){
  if(LEDtime.update())//Checks to see if set time has past
  {
    // if the LED is off turn it on and vice-versa:
    if (state_of_LED == LOW)
      state_of_LED = HIGH;
    else
      state_of_LED = LOW;

    // set the LED with the ledState of the variable:
    digitalWrite(LED_pin, state_of_LED);
    
  }
} if(temp_value>30){
  if(LEDtime1.update())//Checks to see if set time has past
  {
    // if the LED is off turn it on and vice-versa:
    if (state_of_LED == LOW)
      state_of_LED = HIGH;
    else
      state_of_LED = LOW;

    // set the LED with the ledState of the variable:
    digitalWrite(LED_pin, state_of_LED);
     
  }
}
}