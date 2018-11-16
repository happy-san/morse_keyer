#include <stdio.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef BASE_PIN
	// base pin of the transistor which is acting as a switch
	#define BASE_PIN   12

#ifndef SWITCH_DIT
	// switch related to DIT
	#define SWITCH_DIT 32

#ifndef SWITCH_DAH
	// switch related to DAH
	#define SWITCH_DAH 22

#ifndef DIT
	// for sending CW @15 WPM, the DIT's interval should be around 80ms
	#define DIT 80

#endif	// DIT
#endif	// SWITCH_DAH
#endif	// SWITCH_DIT
#endif	// BASE_PIN

// plays the buzzer when SWITCH_DIT / SWITCH_DAH are pressed
void play_buzzer(unsigned int);

// function called when SWITCH_DIT is pressed which further calls play_buzzer()
void pressed_SWITCH_DIT();

// function called when SWITCH_DAH is pressed which further calls play_buzzer()
void pressed_SWITCH_DAH();

// function called when neither SWITCH_DIT / SWITCH_DAH is pressed
void none_pressed();

// records the DIT's and DAH's in a queue
void record(bool);