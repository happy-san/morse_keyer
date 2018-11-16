// morse.h  has the definitions of the the Macros and the function prototypes.
#include "morse.h"

void record (bool is_pass)
{
	// is_pass holds true when no switch is pressed by the user and false otherwise
	switch(is_pass)
	{
		case false:
			// TODO record a DIT
			printf("DIT received \n");
		break;

		case true:
				printf("-               -\n");
			// TODO record a gap (?)
		break;
	}
}

void play_buzzer(unsigned int to_repeat)
{
	// to_repeat holds the number of how many times to play the buzzer
	if(to_repeat >= 1)
	{
		// BASE_PIN is set to HIGH, which let's the buzzer to be grounded on cathode side and in turn it starts buzzing
		digitalWrite(BASE_PIN, HIGH);
		// buzzer is played for DIT ms
		delay(DIT);
		// BASE_PIN set to LOW, switching the buzzer off
		digitalWrite(BASE_PIN, LOW);

		// call record() and pass false as a switch was pressed
		record(false);
		play_buzzer(--to_repeat);
	}
}

void pressed_SWITCH_DIT()
{
	// call play_buzzer() to play buzzer 1 time
	play_buzzer(1);
	putchar('\n');
}

void pressed_SWITCH_DAH()
{
	// call play_buzzer() to play buzzer 3 times
	play_buzzer(3);
	putchar('\n');
}

void none_pressed()
{
	delay(DIT);
	// call record() and pass true as no switch is pressed
	record(true);
}