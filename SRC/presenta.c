#include "dibuixos.h"

int presentacion()
{
	struct palettetype pal;

	dib_initgraph(svga256gdriver,SVGA640x400x256);
   getpalette(&pal);
	closegraph();

	return RET_SUCESS;
}