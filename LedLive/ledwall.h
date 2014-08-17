#ifndef LEDFAL_H
#define LEDFAL_H

#include "signs.h"

/**
*   @WAIT: how many times will a frame appear
*   @LED_LEN: Width of the display in pixels
*   @LED_HGT: Height of the display in pixels
*   @PORT_DIR_OUT: set the data direction to output on all pins of the port
*   @PORT_DIR_IN: set the data direction to input on all pins of the port
*   @PORT_FULL_OUT: disable all pin on the port
*   @PORT_FULL_IN: enable all pin on the port
*
*   @NO_CLR: it's not divided because it's the same leg for both shift registers
*   @CLK_GND_LED: set clock to one on the ground shift register
*   @SER_GND_LED: set a and b serial input to 1 on the ground shift register
*   @CLK_VCC_LED: set clock to one on the phase shift register
*   @SER_VCC_LED: set a and b serial input to 1 on the phase shift register
*/

#define WAIT 10
#define LED_LEN 8
#define LED_HGT 8
#define PORT_DIR_OUT 0xFF
#define PORT_DIR_IN 0x00
#define PORT_FULL_OUT 0x00
#define PORT_FULL_IN 0xFF

#define NO_CLR 0b00001000
#define SER_GND_LED (NO_CLR | 0b00000001)
#define CLK_GND_LED (NO_CLR | 0b00000100)
#define SER_VCC_LED (NO_CLR | 0b00000010)
#define CLK_VCC_LED (NO_CLR | 0b00100000)

typedef unsigned char POS;

/* initialize ports for input and output */
void init_ports();

/**
*	void putpx - put out one single pixel on the LED matrix
*				this function controls the costum hardware,
*				namely two shift registers, that drive the led panel
*
*	@x: x position
*	@y:	y position
*/
void putpx(POS x,POS y);

/* it manages the next frame to be displayed by print frame, holding a constant distance
	between frame_start and frame_end */
void print_array(char (*text[TXT_LEN])[CR_H][CR_W]);

/* this function manages the actual frame printing by keeping counters logically attached to the frame
	and counters that are used by the actual display to print out pixels on a given coordinate*/
void print_frame(char (*text[TXT_LEN])[CR_H][CR_W], char frame_start, char frame_end);

#endif
