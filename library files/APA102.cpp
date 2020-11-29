/*
 * APA102.cpp
 *
 * Created: 11/11/2020 10:34:05
 *  Author: Adam
 */ 

#include "APA102.h"
#include "SPI.h"

APALED::APALED(uint8_t mode /* = 1 */) {
	if (mode) {
		SPI::SPIinit();
	}
	else {
		// USART setup - not implemented yet
	}
}

void APALED::setLED(uint8_t R, uint8_t G, uint8_t B, uint8_t brightness) {
	this->R = R;
	this->G = G;
	this->B = B;
	this->brightness = 224 + brightness;
}

void APALED::setLEDColor(uint8_t R, uint8_t G, uint8_t B) {
	this->R = R;
	this->G = G;
	this->B = B;
}

void APALED::setLEDBrightness(uint8_t brightness) {
	this->brightness = 224 + brightness;
}

void APALED::refresh() {
	for (int i = 0; i < 4; i++) {
		SPI::SPIsend(0);
	}
	SPI::SPIsend(224+this->brightness);
	SPI::SPIsend(this->B);
	SPI::SPIsend(this->G);
	SPI::SPIsend(this->R);
	for (int i = 0; i < 4; i++) {
		SPI::SPIsend(0);
	}
}

APALEDStrip::APALEDStrip() {
	SPI::SPIinit();
	for (int i = 0; i < LEDStripX; i++) {
		leds[i][0] = 224;
		for (int j = 1; j < 4; j++) {
			leds[i][j] = 0;
		}
	}
}

void APALEDStrip::setLED(uint8_t x, uint8_t R, uint8_t G, uint8_t B, uint8_t brightness) {
	leds[x][0] = 224 + brightness;
	leds[x][1] = B;
	leds[x][2] = G;
	leds[x][3] = R;
}

void APALEDStrip::setLEDcolor(uint8_t x, uint8_t R, uint8_t G, uint8_t B) {
	leds[x][1] = B;
	leds[x][2] = G;
	leds[x][3] = R;
}

void APALEDStrip::setLEDbrightness(uint8_t x, uint8_t brightness) {
	leds[x][0] = 224 + brightness;
}

void APALEDStrip::refresh() {
	for (uint8_t i = 0; i < 4; i++) {
		SPI::SPIsend(0);
	}
	for (uint8_t i = 0; i < LEDStripX; i++) {
		for (uint8_t j = 0; j < 4; j++) {
			SPI::SPIsend(leds[i][j]);
		}
	}
	for (uint8_t i = 0; i < 4; i++) {
		SPI::SPIsend(0);
	}
}

APALEDArray::APALEDArray() {
	SPI::SPIinit();
	for (int i = 0; i < LEDArrayX; i++) {
		for (int j = 0; j < LEDArrayY; j++) {
			pixels[i][j][0] = 224;
			for (int k = 1; k < 4; k++) {
				pixels[i][j][k] = 0;
			}
		}
	}
}

void APALEDArray::setLED(uint8_t x, uint8_t y, uint8_t R, uint8_t G, uint8_t B, uint8_t brightness) {
	pixels[x][y][0] = 224 + brightness;
	pixels[x][y][1] = B;
	pixels[x][y][2] = G;
	pixels[x][y][3] = R;
}

void APALEDArray::setLEDcolor(uint8_t x, uint8_t y, uint8_t R, uint8_t G, uint8_t B) {
	pixels[x][y][1] = B;
	pixels[x][y][2] = G;
	pixels[x][y][3] = R;
}

void APALEDArray::setLEDbrightness(uint8_t x, uint8_t y, uint8_t brightness) {
	pixels[x][y][0] = 224 + brightness;
}

void APALEDArray::refresh() {
	for (uint8_t i = 0; i < 4; i++) {
		SPI::SPIsend(0);
	}
	for (uint8_t i = 0; i < LEDArrayX; i++) {
		for (uint8_t j = 0; j < LEDArrayY; j++) {
			for (uint8_t k = 0; k < 4; k++) {
				SPI::SPIsend(pixels[i][j][k]);
			}
		}
	}
	for (uint8_t i = 0; i < 4; i++) {
		SPI::SPIsend(0);
	}
}

