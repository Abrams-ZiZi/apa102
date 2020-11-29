/*
 * apa102_demo_strip_sim.cpp
 *
 * Created: 29/11/2020 19:53:25
 * Author : Adam
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "APA102.h"

int main() {
	APALEDStrip strip;
	strip.refresh();
	
	while(1) {
		for(uint8_t i = 0; i < 5; i++) {
			for (uint8_t j = 0; j < 16; j+=3) {
				strip.setLED(j, 255, 0, 0, 31);
				strip.setLED(j+1, 0, 255, 0, 31);
				strip.setLED(j+2, 0, 0, 255, 31);
			}
			strip.refresh();
			_delay_ms(20);
			for (uint8_t j = 0; j < 16; j+=3) {
				strip.setLED(j, 0, 0, 0, 31);
				strip.setLED(j+1, 0, 0, 0, 31);
				strip.setLED(j+2, 0, 0, 0, 31);
			}
			strip.refresh();
			_delay_ms(20);
		}
		
		for(uint8_t i = 0; i < 7; i++) {
			for (uint8_t j = 0; j < 16; j+=3) {
				strip.setLED(j, 255, 0, 0, 31);
				strip.setLED(j+1, 0, 255, 0, 31);
				strip.setLED(j+2, 0, 0, 255, 31);
			}
			strip.refresh();
			_delay_ms(10);
			for (uint8_t j = 0; j < 16; j+=3) {
				strip.setLED(j, 0, 0, 255, 31);
				strip.setLED(j+1, 255, 0, 0, 31);
				strip.setLED(j+2, 0, 255, 0, 31);
			}
			strip.refresh();
			_delay_ms(10);
			for (uint8_t j = 0; j < 16; j+=3) {
				strip.setLED(j, 0, 255, 0, 31);
				strip.setLED(j+1, 0, 0, 255, 31);
				strip.setLED(j+2, 255, 0, 0, 31);
			}
			strip.refresh();
			_delay_ms(10);
		}
	}
}
