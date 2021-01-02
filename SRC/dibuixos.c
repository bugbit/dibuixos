#include "dibuixos.h"

char dib_error[128];
int svgagmode=-1;

int seterror(char *fmt,...)
{
	va_list args;
	va_start (args, fmt);
  
	vsprintf (dib_error,fmt, args);
	va_end (args);
	
	return RET_ERROR;
}

static int check()
{
	int gdriver=DETECT,gmode, errorcode;

	if (!check386())
		return seterror("A 386 or higher processor required.");

	detectgraph(&gdriver,&gmode);

	errorcode=graphresult();

	if (errorcode!=grOk || gdriver!=VGA)
		return seterror("VGA or compatible graphics adapter required.");

	return RET_SUCESS;
}

int dib_initgraph(int mode)
{
	int gdriver=DETECT,gmode, errorcode;

	if (svgamode==mode)
			return RET_SUCESS;

	installuserdriver("Svga256",DetectVGA256);
}

int main()
{
	int ret=check();

	if (ret==RET_ERROR)
		printf("%s\a\n",dib_error);	
}