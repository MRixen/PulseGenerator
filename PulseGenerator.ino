// DESCRIPTION: Generate pulses
// AUTHOR: Manuel-Leonhard Rixen

#define ai_PulseRequest A0
#define ao_pulse A1

#define PULSE_WIDTH_RECTANGLE 3000 //milliseconds
#define PULSE_WIDTH_SINUS 10 //milliseconds

// SINUS
int frequency = 2;
float phase = 3.14/2;
int bias = 127;
int amplitude = 127;
float sample = 0;


enum pulseTypes {
	sinus = 1,
	rectangle = 2,
	sawtooth = 3,
	triangular = 4
};

pulseTypes pulseType;

void setup()
{
	// Set pin mode
	pinMode(ao_pulse, OUTPUT);
	pinMode(ai_PulseRequest, INPUT);

	digitalWrite(ao_pulse, 0);

}

void loop()
{
	// Read input level to select between different pulse types
	switch (analogRead(ai_PulseRequest))
	{
	case sinus:
		// Set signal for sinus pulse
		analogWrite(ao_pulse, amplitude*sin(frequency*((sample)) - phase) + bias);
		delay(PULSE_WIDTH_SINUS);
		sample = sample + (PULSE_WIDTH_SINUS/1000);
		break;
	case rectangle:
		// Set signal for rectangle pulse
		if (analogRead(ao_pulse) == 255) {
			analogWrite(ao_pulse, 0);
			// Delay for pulse low wait
			delay(PULSE_WIDTH_RECTANGLE / 2);
		}
		else {
			analogWrite(ao_pulse, 255);
			// Delay for pulse high wait
			delay(PULSE_WIDTH_RECTANGLE);
		}
		break;
	case sawtooth:
		// Set signal for sawtooth pulse
		break;
	case triangular:
		// Set signal for triangular pulse
		break;
	default:
		break;
	}
}
