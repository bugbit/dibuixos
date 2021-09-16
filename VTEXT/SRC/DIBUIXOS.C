#include "dibuixos.h"

static char dib_error[128];


int seterror(char *fmt,...)
{
	va_list args;
	va_start (args, fmt);

	vsprintf (dib_error,fmt, args);
	va_end (args);

	return RET_ERROR;
}

int main()
{
	asm {
		mov ax,0x1a00
		int 0x10

	}
	return EXIT_SUCCESS;
}
