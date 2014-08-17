#ifndef LEDFAL_H
#define LEDFAL_H
#include "signs.h"
//TODO: fix issue no more than 18
//TODO: the beginning jumps one when it goes around. find out why

#define LED_LEN 24

void print_char(char (*ch)[CR_H][CR_W]);
void print_array(char (*text[TXT_LEN])[CR_H][CR_W]);
void print_frame(char (*text[TXT_LEN])[CR_H][CR_W], char frame_start, char frame_end);
#endif
