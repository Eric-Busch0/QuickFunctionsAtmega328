#include "quickTime.h"

int get_counter_start(int del_val){
	int one_second = 15625;

	float counts_away = (one_second/1000.0)*del_val;

	float diff = 65536 - counts_away;

	return (int)diff;
}

void delay(int del_val){
	/* Delay value measured in ms 
	   Set TCNT1 to appropriate value to adjust
	*/
	TCCR1B |= (1<<CS10) | (1 <<CS12); //set clock pre-scaler to 1024
	TCNT1 = get_counter_start(del_val);
	while((TIFR1 & (1 << TOV1)) == 0); // while timer overflow bit is not 1
	TCNT1 = 0; // reset timer counter 1 to be 0
	TIFR1 = (1<<TOV1); //write 1 to timer overflow bit to clear

}


void setup_interrupt(int scale){
	/* interrupt default to 1 sec
	   time(ms) = one_second/scale
	   a scale of 1 corresponds to a 1sec interrupt
	   a scale of 15625 corresponds to a 1ms interrupt
	   "one_ms" , "ten_ms", "hundred_ms" can be passed as an argument to set to the correpsponding interrupt times
	   scale of 1 corresponds 

	*/
	int one_second = 15625;
	
	sei(); // enable system interrupts
	TCCR1B |= (1<<CS10) | (1 <<CS12) | (1<<WGM12); //set clock pre-scaler to 1024
	TIMSK1 |= (1<<OCIE1A);
	OCR1A |= one_second/scale;
}

void setup_pwm_pind6(){
	DDRD |= (1<<6) ; // configure port d pin 6 to be an output, pin 6 on arduino uno
	TCCR0A |= (1<<WGM00) | (1<<WGM01) | (1<<COM0A1);
	TCCR0B |= (1<<CS00);

}


void run_pwm_pind6(){
	// run a quick pwm test on port d pin 6, pin 6 on arduino uno
	for (uint8_t brightness=0;brightness<255;brightness++)
	{
		OCR0A = brightness;
		_delay_ms(10);
	}
	for (uint8_t brightness=255; brightness>0; brightness--)
	{
		OCR0A = brightness;
		_delay_ms(10);
	}
}


void setup_pwm_pinb3(){
	DDRB |= (1<<3); // configure Port D pin 3 as an output, pin 11 on arduino uno
	TCCR2A |= (1<<WGM20) | (1<<WGM21) | (1<<COM2A1); // set to fast PWM mode and setup to work on non inverted clear on compare match
	TCCR2B |= (1<<CS20);
}


void run_pwm_pinb3(){
		/* run a quick pwm test on port b pin3, pin 11 on arduino uno
		   creates a breathing effect if led is connected
		*/
		for(uint8_t brightness = 0; brightness < 255; brightness++){
			OCR2A = brightness;
			_delay_ms(10);
		}
		for(uint8_t brightness = 255; brightness > 0; brightness--){
			OCR2A = brightness;
			_delay_ms(10);
		}
}


ISR(TIMER1_COMPA_vect){
	/*quick interrupt service routine test
	  toggle port d pin 7, pin 7 on arduino uno
	*/
	PORTD ^= (1 << 7);
}