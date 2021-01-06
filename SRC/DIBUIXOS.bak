#include "dibuixos.h"

static char dib_error[128];
int svga256gdriver,Twk256gdriver,svagdriver=-1,svgagmode=-1;
bool canceled;
void interrupt (*keyb9_oldint)()=NULL;
int maxx,maxy;

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

void dib_initgraph(int gdriver,int gmode)
{
	initgraph(&gdriver,&gmode,"");
	maxx=getmaxx();
   maxy=getmaxy();
}

void interrupt keyb9_int()
{
	if (inport(0x60)==1)
		canceled=TRUE;
	else
		keyb9_oldint();
}

static void DeInit()
{
	if (svagdriver>=0)
		closegraph();
	if (keyb9_oldint)
		setvect(9,keyb9_oldint);
}

int main()
{
	int ret=init();

	if (issucess(ret))
		ret=presentacion();

	if (ret==RET_ERROR)
		printf("%s\a\n",dib_error);

	while (!canceled);

	DeInit();

	return EXIT_SUCCESS;
}