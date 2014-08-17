#include <avr/io.h>
#define F_CPU 2400000UL /* it is here because delay.h needs it */
#include <util/delay.h>
#include "signs.h"
#include "ledwall.h"

void print_array(char (*text[TXT_LEN])[CR_H][CR_W])
{
    char frame_start = 0;
    char frame_end = TXT_BIT;
	char i;
    while (1)
    {
		for ( i = 0; i < WAIT; i++)
        	print_frame(text,frame_start,frame_end);
        if (frame_end == TXT_BIT)   /* if the frame is at the end of the text, simply wind it up */
            frame_end = -1;
        if (frame_start == TXT_BIT)
            frame_start = -1;
        frame_start++;
        frame_end++;
    }
}

void print_frame(char (*text[TXT_LEN])[CR_H][CR_W], char frame_start, char frame_end)
{
      /*  @i:   used for the height, it can be used directly for the led pixels
          @j:   sort of a pointer navigating in the frame horizontally
          @k:   the direct counter for the display to be used
        */
    unsigned char i, j, k;
    unsigned char curr_ch, curr_px; /* current character and the current pixel in it, that needs drawing */

    for (i = 0; i < CR_H; i++)
    {
        k = 0;
        j = frame_start - 1;
        /* it tests antivalency, not smaller than, because it may need to loop over */
        do
        {
            /* if it is the end of the text wind it up, else just get the next px */
            if (j == TXT_BIT)
                j = 0;
            else
                j++;

            curr_ch = j / CR_W; /* get the current character */
            curr_px = j % CR_W; /* get the position in that character */

            if((*text[curr_ch])[i][curr_px] == 1) {
                putpx(i,k);
            }

			if(text[curr_ch] == &PAD)
			{
				_delay_ms(1);
			}

            k++;
			if (k == LED_LEN)
				break;
        } while (j != frame_end);
    }
}

void putpx(POS x,POS y)
{
	POS j = 0, i = 0;

	if (x < 0 || x > (LED_LEN - 1) || y < 0 || y > (LED_HGT - 1)) {
		_delay_ms(5);
		return;
	}

	PORTA = PORT_FULL_OUT;
	
	PORTA = (SER_GND_LED);
	PORTA = (SER_GND_LED | CLK_GND_LED);

	while ((j++) != x) {
		PORTA = NO_CLR;
		PORTA = CLK_GND_LED;
	}

	PORTA = SER_VCC_LED;
	PORTA = (SER_VCC_LED | CLK_VCC_LED);

	while((i++) != y) {
		PORTA = NO_CLR;
		PORTA = CLK_VCC_LED;

	}
	_delay_ms(5); /* wait delay between individual pixels being displayed */
}

/* initialize all ports for transmission, PORTA is the LED matrix */
void init_ports()
{
	DDRA = PORT_DIR_OUT;
	DDRB = PORT_DIR_OUT;
	DDRD = PORT_DIR_OUT;

	PORTA = PORT_FULL_OUT;
	PORTB = PORT_FULL_IN;
	PORTD = PORT_FULL_IN;
}
