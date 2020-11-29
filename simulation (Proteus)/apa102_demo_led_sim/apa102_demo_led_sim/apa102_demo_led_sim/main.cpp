/*
 * apa102_demo_led_sim.cpp
 *
 * Created: 29/11/2020 20:13:40
 * Author : Adam
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "APA102.h"

int main() {
	APALED rgbled;
	rgbled.refresh();
	
	while(1) {
		rgbled.setLED(255, 0, 0, 31);
		rgbled.refresh();
		_delay_ms(50);
		rgbled.setLED(0, 255, 0, 31);
		rgbled.refresh();
		_delay_ms(50);
		rgbled.setLED(0, 0, 255, 31);
		rgbled.refresh();
		_delay_ms(50);
	}
}