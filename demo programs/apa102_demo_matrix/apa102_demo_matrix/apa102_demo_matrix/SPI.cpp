/*
 * SPI.cpp
 *
 * Created: 11/11/2020 11:53:10
 *  Author: Adam
 */ 

#include "SPI.h"

void SPI::SPIinit() {
	// Set MOSI, SCK, SS as Output
	DDRB |= (1 << PB5) | (1 << PB3) | (1 << PB2);
	
	// Enable SPI, Set as Master, Prescaler: Fosc/16
	SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);
}

void SPI::SPIsend(uint8_t data) {
	// Load data into the buffer
	SPDR = data;
	
	// Wait until transmission complete
	while(!(SPSR & (1<<SPIF)));
}