#include "dibuixos.h"

static MemReal pal;

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
		setrgbpalette(15,200,200,200);
		setcolor(15);
		outtextxy(getmaxx()/2,getmaxy()/2,"Helloword");
		setvgapalette256(&pal);
		outtextxy(getmaxx()/2,getmaxy()/2,"Helloword");

		while (!canceled);
	}

	pre_deinit();

	return ret;
}