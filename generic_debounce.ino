/* 
 * Author: Sam Faull
 * Details: Generic doebounce code to avoid bouncing when using a pushswitch
 * 
 * Pin allocations: 
 * Pushswitch = D2, LED =  D13
 */

#define LED 13
#define Button 2

bool STATE = false; // true if a button press has been registered

void setup() 
{
  pinMode(Button, INPUT_PULLUP);  // Enables the internal pull-up resistor
  pinMode(LED, OUTPUT);
}

void loop() 
{
  readInputs();
  setOutputs();    
  delay(10);
}

void readInputs(void)
{
  static bool button_state, last_button_state = false; // Remembers the current and previous button states
  
  button_state = !digitalRead(Button); // active low

  if (!button_state && last_button_state) // on a falling edge we register a button press
    STATE = !STATE;

  last_button_state = button_state;
}

void setOutputs(void)
{
  if (STATE)
    digitalWrite(13, HIGH);
  else
    digitalWrite(13, LOW);
}

