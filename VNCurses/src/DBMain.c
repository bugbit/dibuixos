#if WIN32
#include "pch.h"
#endif
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
	int ret=check(),i;

	if (issucess(ret))
		ret=init();

	return EXIT_SUCCESS;
}
