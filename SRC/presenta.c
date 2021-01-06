#include "dibuixos.h"

static MemReal pal;

static bool pre_init()
{
	if (!mrealloc(&pal,256))
		return FALSE;

	dib_initgraph(svga256gdriver,SVGA640x400x256);

	if (!getvgapalette256(&pal))
		return FALSE;

	return TRUE;
}

static void pre_deinit()
{
	mrfree(&pal);

	dib_closegraph();
}

int presentacion()
{
	bool ok=pre_init();

	if (ok)
	{
		setrgbpalette(15,200,200,200);
		setcolor(15);
		outtextxy(getmaxx()/2,getmaxy()/2,"Helloword");
		setvgapalette256(&pal);
		outtextxy(getmaxx()/2,getmaxy()/2,"Helloword");

		while (!canceled);
	}

	pre_deinit()

	returnforbool(ok);
}