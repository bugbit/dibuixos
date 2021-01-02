#include "dibuixos.h"

static char dib_error[128];
int svga256gdriver,Twk256gdriver,svgagmode=-1;

int seterror(char *fmt,...)
{
	va_list args;
	va_start (args, fmt);
  
	vsprintf (dib_error,fmt, args);
	va_end (args);
	
	return RET_ERROR;
}

int grseterror(int errorcode)
{
	strncpy(dib_error,grapherrormsg(errorcode),sizeof(dib_error)); 
	
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

	svga256gdriver= installuserdriver("Svga256",NULL);
	Twk256gdriver= installuserdriver("Twk256",NULL);

	gdriver= svga256gdriver;
	gmode=SVGA640x400x256;

	initgraph(&gdriver,&gmode,"");

	errorcode=graphresult();

	if (errorcode!=grOk)
		return grseterror(errorcode);

	gdriver= Twk256gdriver;
	gmode=TWK320x400x256;

   closegraph();

	initgraph(&gdriver,&gmode,"");

	errorcode=graphresult();

	if (errorcode!=grOk)
		return grseterror(errorcode);

	closegraph();

	return RET_SUCESS;
}

int dib_initgraph(int mode)
{
	int gdriver=DETECT,gmode, errorcode;

	//if (svgamode==mode)
	//		return RET_SUCESS;


}

int main()
{
	int ret=check();

	if (ret==RET_ERROR)
		printf("%s\a\n",dib_error);

	getchar();
}