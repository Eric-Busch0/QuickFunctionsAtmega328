#ifndef QUICKTIME_C
#define QUICKTIME_C
#define one_ms 1000
#define ten_ms 100
#define hundred_ms 10
#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
int get_counter_start(int del_val);
void delay(int del_val);
void setup_interrupt();
void setup_pwm_pind6();
void run_pwm_pind6();
void setup_pwm_pinb3();
void run_pwm_pinb3();
#endif