/*
 * SPI.h
 *
 * Created: 11/11/2020 11:52:59
 *  Author: Adam
 */ 

#ifndef SPI_H_
#define SPI_H_

#include <avr/io.h>

class SPI {
	public:
	static void SPIinit();
	static void SPIsend(uint8_t data);
};

#endif /* SPI_H_ */