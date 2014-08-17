#ifndef JELEK_H
#define JELEK_H

/**
*   @CR_W: Width of the character
*   @CR_H: Height of the character
*   @TXT_LEN: Number of characters in the string
*   @TXT_BIT: Length of the string in pixels
*/

#define CR_W 6
#define CR_H 8
#define TXT_LEN 7
#define TXT_BIT (TXT_LEN * CR_W)

/* Extern declarations for all the letters
	in led.c */

extern char A[8][6];
extern char B[8][6];
extern char C[8][6];
extern char D[8][6];
extern char E[8][6];
extern char F[8][6];
extern char G[8][6];
extern char H[8][6];
extern char I[8][6];
extern char J[8][6];
extern char K[8][6];
extern char L[8][6];
extern char M[8][6];
extern char N[8][6];
extern char O[8][6];
extern char P[8][6];
extern char Q[8][6];
extern char R[8][6];
extern char S[8][6];
extern char T[8][6];
extern char U[8][6];
extern char V[8][6];
extern char W[8][6];
extern char X[8][6];
extern char Y[8][6];
extern char Z[8][6];
extern char PAD[8][6];
#endif
