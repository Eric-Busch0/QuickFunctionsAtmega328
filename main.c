#define F_CPU 16000000

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "quickTime.h"



int main(void)
{
	//setup_interrupt(hundred_ms); //uncomment to test interrupt

	//DDRD |= (1<<7); //uncomment to test delay

	//setup_pwm_pind6(); //uncomment to test pwm on portd pin 6

	//setup_pwm_pinb3(); //uncomment to test pwm port b pin 3

    while (1) 
    {
		//PORTD ^= (1<<7);	//uncomment to test delay
		//delay(1000);	//uncomment to test delay

		//run_pwm_pind6();	//uncomment to test pwm on portd pin6

		//run_pwm_pinb3();	//uncomment to test pwm port b pin 3


    }
	
}