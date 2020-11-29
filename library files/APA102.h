/*
 * APA102.h
 *
 * Created: 11/11/2020 10:33:47
 *  Author: Adam
 */ 

// include config.h file if exists
#if defined __has_include
#  if __has_include ("config.h")
#    include "config.h"
#  endif
#endif

#ifndef LEDStripX
#define LEDStripX 10
#endif

#ifndef LEDArrayX
#define LEDArrayX 8
#endif
#ifndef LEDArrayY
#define LEDArrayY 8
#endif

#ifndef APA102_H_
#define APA102_H_

#include <avr/io.h>

class APALED {
	public:
	// mode 0 = USART, mode 1 = SPI
	// MODE 0 NOT YET IMPLEMENTED
	APALED(uint8_t mode = 1);
	void setLED(uint8_t R, uint8_t G, uint8_t B, uint8_t brightness); // RGB range 0 - 255, brightness range 0 - 31
	void setLEDColor(uint8_t R, uint8_t G, uint8_t B);
	void setLEDBrightness(uint8_t brightness);
	void refresh();
	private:
	uint8_t mode;
	uint8_t R;
	uint8_t G;
	uint8_t B;
	uint8_t brightness;
};

class APALEDStrip {
	public:
	APALEDStrip();
	void setLED(uint8_t x, uint8_t R, uint8_t G, uint8_t B, uint8_t brightness); // x - LED index
	void setLEDcolor(uint8_t x, uint8_t R, uint8_t G, uint8_t B);
	void setLEDbrightness(uint8_t x, uint8_t brightness);
	void refresh();
	private:
	uint8_t leds[LEDStripX][4];	
};

class APALEDArray {
	public:
	APALEDArray();
	void setLED(uint8_t x, uint8_t y, uint8_t R, uint8_t G, uint8_t B, uint8_t brightness); // x, y - LED coordinates
	void setLEDcolor(uint8_t x, uint8_t y, uint8_t R, uint8_t G, uint8_t B);
	void setLEDbrightness(uint8_t x, uint8_t y, uint8_t brightness);
	void refresh();
	private:
	uint8_t pixels[LEDArrayX][LEDArrayY][4];
};

#endif /* APA102_H_ */