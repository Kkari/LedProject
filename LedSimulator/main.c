#include <stdio.h>
#include <stdlib.h>
#include "signs.h"
#include "ledwall.h"

int main()
{
    char (*text[TXT_LEN])[8][6];
    text[0] = &A;
    text[1] = &B;
    text[2] = &PAD;
    text[3] = &PAD;
    text[4] = &PAD;
    text[5] = &PAD;
   // text[2] = &C;

   // print_frame(text,6,6);
    print_array(text);
   // printf("%d",*text[0][0][0]);

    return 0;
}
