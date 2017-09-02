/* 
 * Author: Sam Faull
 * Details: Generic doebounce code to avoid bouncing when using a pushswitch
 * 
 * Pin allocations: 
 * Pushswitch = D2, LED =  D13
 */

#define LED 13
#define Button 2

bool ButtonState;

void setup() 
{
  pinMode(LED, OUTPUT);
}

void loop() 
{
  ButtonState = digitalRead(Button);
  if (ButtonState)
    digitalWrite(13, HIGH);
  else
    digitalWrite(13, LOW);
  delay(10);

}
