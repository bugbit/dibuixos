#include "dibuixos.h"

static MemReal pal;
static char *text1[]=
{
	"A",
	"Microbyt",
	"production",
	NULL
};

static char text2[]="My First Demo";

static char *text3[]=
{
	"Develop",
	"in",
	"BC 4.52 + PowerPack for DOS",
	"DPMI 16",
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

static int pre_fadeout()
{
	int x;

	for(x=63;x>=0;x--)
	{
		if (canceled)
			return RET_CANCEL;
		WaitForRetrace();
		setrgbpalette(WHITE,x,x,x);
	}

	return RET_SUCESS;
}

static int presen1()
{
	char **text;
	int htext;
	int y,x;

	setrgbpalette(WHITE,0,0,0);
	setcolor(WHITE);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,8);
	for(htext=0,text=text1;*text;)
	  htext +=textheight(*text++);
	x=medx;
	y=(maxy-htext)/2;
	for (text=text1;*text;text++)
	{
		outtextxy(x,y,*text);
		y +=textheight(*text);
	}
	for(x=0;x<=63;x++)
	{
		if (canceled)
			return RET_CANCEL;
		WaitForRetrace();
		setrgbpalette(WHITE,x,x,x);
	}
	for(x=0;x<=63;x++)
	{
		if (canceled)
			return RET_CANCEL;
		WaitForRetrace();
	}

	return pre_fadeout();
}

static int presen2()
{
	char titulo[sizeof(text2)+1];
	int len=strlen(text2),len2=len/2,k,j;

	setwritemode(XOR_PUT);
	cleardevice();
	setvgapalette256(&pal);
	for (k=1;k<len2;k++)
	{
		strncpy(titulo,text2,k);
		strcpy(titulo+k,text2+len-k);
		outtextxy(medx,medy,titulo);

		for(j=15;j-->0;)
		{
			WaitForRetrace();
			if (canceled)
				return RET_CANCEL;
		}
		outtextxy(medx,medy,titulo);
	}
	outtextxy(medx,medy,text2);
	setwritemode(COPY_PUT);

	return pre_fadeout();
}

static void pre_deinit()
{
	mrfree(&pal);
}

int presentacion()
{
	int ret=pre_init();

	if (issucess(ret))
	{
		if (issucess((ret=presen1())))
		{
			if (issucess((ret=presen2())))
			{
         }
		}
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