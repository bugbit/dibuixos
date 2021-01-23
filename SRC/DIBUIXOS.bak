#include "dibuixos.h"

static char dib_error[128];
int svga256gdriver,Twk256gdriver,svgagdriver=-1,svgagmode=-1;
bool canceled;
void interrupt (*keyb9_oldint)()=NULL;
int maxx,maxy,medx,medy;

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
	if (svgagdriver>=0)
	{
		if (gdriver==svgagdriver && gmode==svgagmode)
			return;

		closegraph();
	}
	initgraph(&gdriver,&gmode,"");
	svgagdriver=gdriver;
	svgagmode=gmode;
	maxx=getmaxx();
	maxy=getmaxy();
	medx=maxx/2;
	medy=maxy/2;
}

void dib_closegraph()
{
	if (svgagdriver>=0)
		closegraph();
	svgagdriver=-1;
	svgagmode=-1;
}

void interrupt keyb9_int()
{
	if (inport(0x60)==1)
		canceled=TRUE;
	else
		keyb9_oldint();
}

static void deinit()
{
	if (svgagdriver>=0)
		dib_closegraph();
	if (keyb9_oldint)
		setvect(0x9,keyb9_oldint);
}

int main()
{
	int ret=init();

	if (issucess(ret))
		ret=presentacion();

	if (ret==RET_ERROR)
	{
		printf("%s\a\n",dib_error);
      getch();
	}
	else
		while (!canceled);

	deinit();

	return EXIT_SUCCESS;
}