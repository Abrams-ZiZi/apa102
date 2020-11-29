/*
 * apa102_demo_led.cpp
 *
 * Created: 29/11/2020 18:44:29
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
	    rgbled.setLED(255, 0, 0, 1);
	    rgbled.refresh();
	    _delay_ms(500);
	    rgbled.setLED(0, 255, 0, 1);
	    rgbled.refresh();
	    _delay_ms(500);
	    rgbled.setLED(0, 0, 255, 1);
	    rgbled.refresh();
	    _delay_ms(500);
    }
}

