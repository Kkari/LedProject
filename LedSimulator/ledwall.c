#include <stdio.h>
#include "ledwall.h"
#include "signs.h"

char led[CR_H][LED_LEN];

void print_matrix()
{
    int i,j;
    for (i = 0; i < CR_H; i++) {
        for (j = 0; j < LED_LEN; j++) {
            if (led[i][j] == 1)
                printf("1");
            else
                printf(" ");
        }
        puts("");
    }
}

void print_array(char (*text[TXT_LEN])[CR_H][CR_W])
{
    char frame_start = 0;
    char frame_end = TXT_BIT;

    while (1)
    {
        print_frame(text,frame_start,frame_end);
        if (frame_end == TXT_BIT)   /* if the frame is at the end of the text, simply wind it up */
            frame_end = -1;
        if (frame_start == TXT_BIT)
            frame_start = -1;
        frame_start++;
        frame_end++;
        system("cls");
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
                led[i][k] = 1;
            } else {
                led[i][k] = 0;
            }
            k++;
        } while (j != frame_end);
    }
    print_matrix();
}
