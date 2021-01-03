#include "dibuixos.h"

static int check()
{
	int gdriver=DETECT,gmode, errorcode;

//	if (!check386())
//		return seterror("A 386 or higher processor required.");

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

int init()
{
	return check();
}