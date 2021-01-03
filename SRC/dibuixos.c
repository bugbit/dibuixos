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

int dib_initgraph(int mode)
{
	int gdriver=DETECT,gmode, errorcode;

	//if (svgamode==mode)
	//		return RET_SUCESS;


}

bool cancel()
{
	return kbhit() && getch()==27;
}

int main()
{
	int ret=init();

	if (ret==RET_ERROR)
		printf("%s\a\n",dib_error);

	//getchar();
	while (!cancel());

   return EXIT_SUCCESS;
}