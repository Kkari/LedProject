#include "signs.h"
#include "ledwall.h"

int main()
{
    char (*text[TXT_LEN])[8][6];
    text[0] = &P;
    text[1] = &A;
    text[2] = &L;
	text[3] = &I;
	text[4] = &N;
	text[5] = &K;
	text[6] = &A;

	init_ports();
	print_array(text);

	return 0;
}
