#include "dibuixos.h"

static int check386()
{
	asm {
		push	sp			; 86/186 will push SP-2;
		pop	ax			; 286/386 will push SP.
		cmp	ax, sp
	}
}

static int setup()
{
}

int main()
{
}