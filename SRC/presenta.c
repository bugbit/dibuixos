#include "dibuixos.h"

//static DacPalette256 pal;
static MemReal pal;

int presentacion()
{
	SimInt si;
	char *x;

	if (!mrealalloc(&pal,256/16))
		return RET_ERROR;

	dib_initgraph(svga256gdriver,SVGA640x400x256);
	//getvgapalette256(&pal);
	memset(&si,0,sizeof si);
	si.eax=0x1017;
	si.ecx=256;
	si.es=pal.realseg;
	if (!simint(&si,0x10))
		return RET_ERROR;

	x=(char *) pal.ptr;

	closegraph();

	return RET_SUCESS;
}