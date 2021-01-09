#include "dibuixos.h"

static MemReal pal;
static char *text1[]=
{
	"A",
	"Microbyt",
	"production",
	NULL
};

static int pre_init()
{
	int ret=mrealloc(&pal,sizeof(DacPalette256));

	if (issucess(ret))
	{
		dib_initgraph(svga256gdriver,SVGA640x400x256);

		ret=getvgapalette256(&pal);
	}

	return ret;
}

static int presen1()
{
	char **text;
	int htext;
	int y,x;

	setrgbpalette(15,0,0,0);
	setcolor(15);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,8);
	for(htext=0,text=text1;*text;)
	  htext +=textheight(*text++);
	x=maxx/2;
	y=(maxy-htext)/2;
	for (text=text1;*text;text++)
	{
		outtextxy(x,y,*text);
		y +=textheight(*text);
	}
	for(x=0;x<=63;x++)
		setrgbpalette(15,x,x,x);
	for(x=0;x<=63;x++)
	{
		if (canceled)
			return RET_CANCEL;
		WaitForRetrace();
		}
	for(x=63;x>=0;x--)
		setrgbpalette(15,x,x,x);

	return RET_SUCESS;
}

static void pre_deinit()
{
	mrfree(&pal);

	dib_closegraph();
}

int presentacion()
{
	int ret=pre_init();

	if (issucess(ret))
	{
		ret=presen1();
		/*
		setrgbpalette(15,200,200,200);
		setcolor(15);
		outtextxy(getmaxx()/2,getmaxy()/2,"Helloword");
		setvgapalette256(&pal);
		//outtextxy(getmaxx()/2,getmaxy()/2,"Helloword");
		*/

		while (!canceled);
	}

	pre_deinit();

	return ret;
}