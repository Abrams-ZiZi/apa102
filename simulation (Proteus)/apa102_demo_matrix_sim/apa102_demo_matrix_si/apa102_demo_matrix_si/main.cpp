/*
 * apa102_demo_matrix_si.cpp
 *
 * Created: 29/11/2020 19:43:52
 * Author : Adam
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "APA102.h"

int main() {
	APALEDArray matrix;
	matrix.refresh();
	
	while(1) {
		// DANISH FLAG
		for (uint8_t i = 0; i < 8; i++) {
			for (uint8_t k = 0; k < 8; k++) {
				matrix.setLEDcolor(i, k, 255, 0, 0);
			}
		}
		for (uint8_t i = 3; i < 5; i++) {
			for (uint8_t j = 0; j < 8; j++) {
				matrix.setLEDcolor(i, j, 255, 255, 255);
				matrix.setLEDcolor(j, i, 255, 255, 255);
			}
		}
		// fade in
		for (uint8_t i = 22; i < 31; i++) {
			for (uint8_t j = 0; j < 8; j++) {
				for (uint8_t k = 0; k < 8; k++) {
					matrix.setLEDbrightness(j, k, i);
				}
			}
			matrix.refresh();
			_delay_ms(10);
		}
		// fade out
		for (uint8_t i = 31; i > 22; i--) {
			for (uint8_t j = 0; j < 8; j++) {
				for (uint8_t k = 0; k < 8; k++) {
					matrix.setLEDbrightness(j, k, i);
				}
			}
			matrix.refresh();
			_delay_ms(10);
		}
		// SWEDISH FLAG
		for (uint8_t i = 0; i < 8; i++) {
			for (uint8_t k = 0; k < 8; k++) {
				matrix.setLEDcolor(i, k, 0, 0, 255);
			}
		}
		for (uint8_t i = 3; i < 5; i++) {
			for (uint8_t j = 0; j < 8; j++) {
				matrix.setLEDcolor(i, j, 255, 255, 0);
				matrix.setLEDcolor(j, i, 255, 255, 0);
			}
		}
		// fade in
		for (uint8_t i = 22; i < 31; i++) {
			for (uint8_t j = 0; j < 8; j++) {
				for (uint8_t k = 0; k < 8; k++) {
					matrix.setLEDbrightness(j, k, i);
				}
			}
			matrix.refresh();
			_delay_ms(10);
		}
		// fade out
		for (uint8_t i = 31; i > 22; i--) {
			for (uint8_t j = 0; j < 8; j++) {
				for (uint8_t k = 0; k < 8; k++) {
					matrix.setLEDbrightness(j, k, i);
				}
			}
			matrix.refresh();
			_delay_ms(10);
		}
	}
}