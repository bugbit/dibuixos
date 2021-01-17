#include "dibuixos.h"

#define text3_lines sizeof(text3)/sizeof(char *)

static MemReal pal;
static int divy;

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
	"DPMI 16 bits"
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

static void pascal setcharsize(int mulx,int divx)
{
	switch (maxy)
	{
		case 199:setusercharsize(mulx,divx,3,10);break;
		default:setusercharsize(mulx,divx,1,2);
	}
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

static int pascal presen3_2(int x,int y)
{
  int num;
  char **text=(char **) &text3;

  if (canceled)
		return RET_CANCEL;

  WaitForRetrace();
  for (num=text3_lines;num-->0;y += textheight(*text++))
	 outtextxy(x,y,*text);

  return EXIT_SUCCESS;
}

static int pascal presen3_1(int x,int y)
{
  int divx=textwidth("Y"),cars=strlen(text3[0]),num=(cars+text3_lines) >> 2;
  double ancho,alto,ax=(double) divx/num,ay=((maxy==199) ? 0.31 : .5)*
  (double) divy/num;
  int ret=EXIT_SUCCESS,j;

  ancho=alto=0;
  do
  {
	 setusercharsize(ancho,divx,alto,divy);
	 //bar(x,y,x+cars*ancho,y+MaxDibujos*divy);
	 if (isnosucess((ret=presen3_2(x,y))))
		return ret;

	 for(j=5;j-->0;)
	 {
		WaitForRetrace();
		if (canceled)
			return RET_CANCEL;
	 }

	 if (isnosucess((ret=presen3_2(x,y))))
		return ret;

	 ancho += ax;
	 alto += ay;
  } while (--num>=0);
  presen3_2(x,y);

  return ret;
}

static int presen3()
{
	int y;

	setwritemode(XOR_PUT);
	cleardevice();
	setvgapalette256(&pal);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,USER_CHAR_SIZE);
	setcharsize(1,1);
	divy=textheight("A");
	y=(maxy-((text3_lines+4)*divy)) >> 1;
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	presen3_1(((maxx-textwidth(text3[2])) >> 1),y+(divy << 1));
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
				if (issucess((ret=presen3())))
				{
				}
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