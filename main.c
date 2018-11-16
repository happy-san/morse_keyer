#include "morse.h"

int main()
{
	// if  wiringPiSetupPhys() returns -1, exit the program
	if(-1 == wiringPiSetupPhys())
		return EXIT_FAILURE;

	// BASE_PIN is set to output
	pinMode(BASE_PIN,   OUTPUT);

	// SWITCH_DIT, SWITCH_DAH are set to get user input
	pinMode(SWITCH_DIT, INPUT);
	pinMode(SWITCH_DAH, INPUT);

	for(;;)
	{
		// if SWITCH_DIT was pressed
		if(digitalRead(SWITCH_DIT))
		{
			pressed_SWITCH_DIT();
		}
		// if SWITCH_DAH was pressed
		else if(digitalRead(SWITCH_DAH))
		{
			pressed_SWITCH_DAH();
		}
		// if no switch was pressed
		else
		{
			none_pressed();
		}
	}

	return EXIT_SUCCESS;
}