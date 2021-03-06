#include "dibuixos.h"

#define text3_lines sizeof(text3)/sizeof(char *)
#define text4_lines sizeof(text4)/sizeof(char *)

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

static char *text4[]=
{
	"Code",
	"By",
	"Oscar Hernandez Bano"
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

static void text_size(int *w,int *h,char **str,int numlines)
{
	int w1=0,h1=0;

	for (;numlines-->0;str++)
	{
		int w2=textwidth(*str);
		int h2=textheight(*str);

		if (w2>w1)
			w1=w2;
		h1 += h2;
	}

	*w=w1;
	*h=h1;
}

static int pascal writetext(int x,int y,char **text,int numlines)
{
  int num;

  if (canceled)
		return RET_CANCEL;

  WaitForRetrace();
  for (;numlines-->0;y += textheight(*text++))
	 outtextxy(x,y,*text);

  return EXIT_SUCCESS;
}

static void pascal setcharsize(int mulx,int divx)
{
	if (maxy>300)
		setusercharsize(mulx,divx,2,10);
	else if (maxy==199)
		setusercharsize(mulx,divx,3,10);
	else
		setusercharsize(mulx,divx,1,2);
	/*
	switch (maxy)
	{
		case 199:setusercharsize(mulx,divx,3,10);break;
		default:setusercharsize(mulx,divx,1,2);
	}
	*/
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
	WaitForRetrace();
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

	setvgapalette256(&pal);
	for (k=1;k<len2;k++)
	{
		strncpy(titulo,text2,k);
		strcpy(titulo+k,text2+len-k);
		WaitForRetrace();
		cleardevice();
		outtextxy(medx,medy,titulo);

		for(j=15;j-->0;)
		{
			WaitForRetrace();
			if (canceled)
				return RET_CANCEL;
		}
	}
	WaitForRetrace();
	cleardevice();
	outtextxy(medx,medy,text2);

	return pre_fadeout();
}

static int pascal presen3_1(int x,int y)
{
  int steps=30,i,ret=EXIT_SUCCESS,j;

  for(i=1;i<steps;i++)
  {
	 setusercharsize(i,steps,i,steps);
	 WaitForRetrace();
	 cleardevice();
	 if (isnosucess((ret=writetext(x,y,text3,text3_lines))))
		return ret;

	 for(j=10;j-->0;)
	 {
		WaitForRetrace();
		if (canceled)
			return RET_CANCEL;
	 }
  };

  return ret;
}

static int presen3()
{
	int w,h,j;

	settextstyle(SIMPLEX_FONT,HORIZ_DIR,3);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	setvgapalette256(&pal);
	text_size(&w,&h,text3,text3_lines);
	presen3_1((maxx-w)/2,(maxy-h)/2);
	for(j=15;j-->0;)
	{
		WaitForRetrace();
		if (canceled)
			return RET_CANCEL;
	}

	return pre_fadeout();
}

static int presen4_text_init(int salto)
{
	int i=text4_lines;
	char **str=text4,*str1;

	for(;i-->0;*str++)
		for(str1=*str;*str1;str1++)
			if (*str1!=' ')
				*str1 -= salto;
}

static int presen4_text_salto1()
{
	int i=text4_lines;
	char **str=text4,*str1;

	for(;i-->0;*str++)
		for(str1=*str;*str1;str1++)
			if (*str1!=' ')
				(*str1)++;
}

static int presen4_mattrix(int w,int h)
{
	int x,y;

	dib_initgraph(VGA,VGAHI);
	x=(maxx-w)/2;
	y=(maxy-h)/2;
	setactivepage(2);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,3);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	setcolor(GREEN);
	writetext(x,y,text4,text4_lines);
	setvisualpage(2);

	return RET_SUCESS;
}

static int presen4()
{
	int w,h,x,y,j,salto=(int)('A'-' ')-1;

	settextstyle(SIMPLEX_FONT,HORIZ_DIR,3);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	setvgapalette256(&pal);
	text_size(&w,&h,text4,text4_lines);
	presen4_text_init(salto);
	x=(maxx-w)/2;
	y=(maxy-h)/2;
	while (salto-->0)
	{
		WaitForRetrace();
		cleardevice();
		writetext(x,y,text4,text4_lines);
		for(j=10;j-->0;)
		{
			WaitForRetrace();
			if (canceled)
				return RET_CANCEL;
		}
		presen4_text_salto1();
	}
   WaitForRetrace();
	cleardevice();
	writetext(x,y,text4,text4_lines);
	for(j=15;j-->0;)
	{
		WaitForRetrace();
		if (canceled)
			return RET_CANCEL;
	}
	for(j=63;j>=0;j--)
	{
		if (canceled)
			return RET_CANCEL;
		WaitForRetrace();
		setrgbpalette(WHITE,j,255,255);
	}
	for(j=63;j>=0;j--)
	{
		if (canceled)
			return RET_CANCEL;
		WaitForRetrace();
		setrgbpalette(WHITE,0,255,j);
	}

	return presen4_mattrix(w,h);
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
					if (issucess((ret=presen4())))
					{
					}
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