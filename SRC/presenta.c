#include "dibuixos.h"

#define text1_lines sizeof(*text1)/sizeof(*text1)

static MemReal pal;
static char *text1[]=
{
	"A",
	"Microbyt",
   "production"
};

static int pre_init()
{
	int ret=mrealloc(&pal,256);

	if (issucess(ret))
	{
		dib_initgraph(svga256gdriver,SVGA640x400x256);

		ret=getvgapalette256(&pal);
	}

	return ret;
}

static void presen1()
{
	int h;
	int y;

	setcolor(15);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,4);
	h=textheight("A");
	y=maxy-(text1_lines*h)/2;
   outtextxy(maxx/2,maxy/2,"A");
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
		presen1();
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