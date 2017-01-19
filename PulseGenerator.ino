#define pinOutRect A0
#define pinInAct 6

#define PULSE_WIDTH 3

void setup()
{
	// Set pin mode
	pinMode(pinOutRect, OUTPUT);
	pinMode(pinInAct, INPUT);

	digitalWrite(pinOutRect, LOW);

}

void loop()
{
	// Generate rectangle puls when input is high

	// RECT PULSE
	if(digitalRead(pinInAct) == 1) {

		// Set signal for rectangle pulse
		if (analogRead(pinOutRect) == 255) analogWrite(pinOutRect, 0);
		else analogWrite(pinOutRect, 255);

		// Delay for oulse width
		delay(PULSE_WIDTH);
  }
}
