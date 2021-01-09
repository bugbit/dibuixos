#include <graphics.h>
#include <fonts.h>
#include <stdio.h>
#include <stdlib.h>
#include <bios.h>
#include <ctype.h>
#include <math.h>
#include <mem.h>
#include <dos.h>
#include <string.h>
#include <time.h>

#define O_MOV		1
#define O_FIN		2

#define MaxDibujos sizeof(ListaDibujos)/sizeof(struct LISTADIBUJOSTIPO)

#define sqr(x)((x)*(x))

#define funcion(z)(32*sin((z)/6))
/* #define funcion(z)(26*sin(((z)-1)/20)*2*M_PI) */

const static char esperestr[]="Prem una tecla per continuar";

const static char *Titulo[]={
  "DIBUIXOS",
  "MATEMATICS",
  NULL
  };

static int near color,maxx,maxy,medx,medy,divx,divy;

static void *near pascal Menu1(int x,int y);
static void *near pascal (*menu)(int,int)=Menu1;

static void near triangulo(),near mandelbrot(),near helecho1(),near
helecho2(),near arbol1(),near arbol2(),near isla(),near isla3D(),near copa(),
near ventana_estelar();

typedef struct CARACTER  {
  int rad0,rad,x0,y0,x,y,anc,anc0;
  double ang0,ang,aang;
  char car[2],modo;
  } CAR;

const static struct LISTADIBUJOSTIPO  {
  char *nombre,WaitKey;
  void near (*prg)();
  } ListaDibujos[]= {
  "A. Triangle de Sierpinski",1,triangulo,
  "B. Mandelbrot",0,mandelbrot,
  "C. Finestra Estelar",1,ventana_estelar,
  "D. Falguera I",1,helecho1,
  "E. Falguera II",1,helecho2,
  "F. Arbre I",1,arbol1,
  "G. Arbre II",1,arbol2,
  "H. Candela",1,isla,
  "I.  Tulipa",0,isla3D,
  "J. Rellotge de Sorra",1,copa
  };

struct HELECHO  {
  double x,y,a,b;
  };

static void near _fastcall hel_1(struct HELECHO *hel),near _fastcall hel_2(
struct HELECHO *hel),near _fastcall hel_3(struct HELECHO *hel),near
_fastcall hel_4(struct HELECHO *hel),near _fastcall arb_1(struct HELECHO *hel
),near _fastcall arb_2(struct HELECHO *hel),near _fastcall arb_3(struct
HELECHO *hel),near _fastcall arb_4(struct HELECHO *hel);

static void near _fastcall (*hel_progs[])(struct HELECHO *hel)={ hel_1,hel_2,hel_3,hel_4 };
static void near _fastcall (*arb_progs[])(struct HELECHO *hel)={ arb_1,arb_2,arb_3,arb_4 };

static int near inicio()  {

	int gdriver = DETECT, gmode, errorcode;

	registerfarbgidriver(CGA_driver_far);
	registerfarbgidriver(EGAVGA_driver_far);
	registerfarbgidriver(IBM8514_driver_far);
	registerfarbgidriver(Herc_driver_far);
	registerfarbgidriver(ATT_driver_far);
	registerfarbgidriver(PC3270_driver_far);
	registerfarbgifont(bold_font_far);
	registerfarbgifont(simplex_font_far);
	initgraph(&gdriver, &gmode, "");
	if ((errorcode= graphresult()) != grOk)  {
	  printf("\r\n\r\n\aError : %s. %s",esperestr,grapherrormsg(errorcode));
	  bioskey(0);
	  }
		 else  {
	  color=getmaxcolor();
	  medx=(maxx=getmaxx()) >> 1;
	  medy=(maxy=getmaxy()) >> 1;
	  }
	return errorcode;
	}

static void near _fastcall Plot(int near a,int near b)  {

  int col=getpixel(a,b);

  putpixel(a,b,(col<color) ? col+1 : col);

  }

static void near PlotDouble(double a,double b)  {

  Plot(floor(a),maxy-floor(b));

  }

static int near _fastcall Relx(int near rel)  {

  return (long) maxx*rel/255;

  }

static int near _fastcall Rely(int near rel)  {

  return (long) rel*maxy/175;

  }

static void near triangulo(void)  {

  int a,b,c,d,e,f,x,y,g,h;

  a=(x=maxx) >> 1;
  y=b=0;
  c=Relx(26);
  e=x-c;
  f=d=maxy;
  x=a;
  Plot(a,b);
  Plot(c,d);
  Plot(e,f);
  do  {
	 Plot(x,y);
	 switch (random(3))  {
		case 0:g=a; h=b; break;
		case 1:g=c; h=d; break;
		default:g=e; h=f;
		}
	 x=((g-x)+(x << 1)+1) >> 1;
	 y=((y-h)+(h << 1)+1) >>1;
	 } while (!bioskey(1));
  
  }

static void near mandelbrot()  {

  int si,n,x,y;
  double x2,y2,re,im,zr,zi,z,esc=5.0/(double) maxx; /* 34.0 */

  for (y=0,x2=maxx/2,y2=maxy/2;y<=maxy;y++)
	 for (x=0;x<=maxx && !bioskey(1);x++)  {
		zr=re=(x-x2)*esc-.8;
		zi=im=(y-y2)*esc;
		for (si=n=1;n++<=20 && si;)  {
		  z=2*zr*zi;
		  zr=zr*zr-zi*zi+re;
		  zi=z+im;
		  si=hypot(zr,zi)<4;
		  }
		if (si) Plot(x,y);
		}

  }

static void near _fastcall hel_1(struct HELECHO *hel)  {

  hel->a=0;
  hel->b=.16*hel->y;

  }

static void near _fastcall hel_2(struct HELECHO *hel)  {

  hel->a=.2*hel->x-.26*hel->y;
  hel->b=.23*hel->x+.22*hel->y+1.6;

  }

static void near _fastcall hel_3(struct HELECHO *hel)  {

  hel->a=.28*hel->y-.15*hel->x;
  hel->b=.26*hel->x+.24*hel->y+.44;

  }

static void near _fastcall hel_4(struct HELECHO *hel)  {

  hel->a=.85*hel->x+.04*hel->y;
  hel->b=.85*hel->y-.04*hel->x+1.6;

  }

static void near _fastcall arb_1(struct HELECHO *hel)  {

  hel->a=.05*hel->y;
  hel->b=0;

  }

static void near _fastcall arb_2(struct HELECHO *hel)  {

  hel->a=.1*hel->x;
  hel->b=.1*hel->y+.2;

  }

static void near _fastcall arb_3(struct HELECHO *hel)  {

  hel->a=.42*hel->x+.42*hel->y;
  hel->b=.42*hel->y-.42*hel->x+.2;

  }

static void near _fastcall arb_4(struct HELECHO *hel)  {

  hel->a=.42*hel->x-.42*hel->y;
  hel->b=.42*hel->y+.42*hel->x+.2;

  }

static int near hel_rnd()  {

  return random(4);

  }

static int near hel_rnd2()  {

  int r=random(32767),i=(r>=328);

  if (i)
	 if (r<2621)
		++i;
		  else
		i=(r<4915) ? 2 : 3;

  return i;

  }

static int near arb_rnd2()  {

  int r=random(32767),i=(r>=1638);

  if (i)
	 if (r<6553)
		++i;
		  else
		i=(r<7863) ? 2 : 3;

  return i;

  }

static void near helecho(int near (*rnd)(),void near _fastcall (*progs[])(
struct HELECHO *hel),double ancho,double alto)  {

  struct HELECHO helecho;
  double x0=(double) medx;

  PlotDouble((helecho.x=random(51)),(helecho.y=random(55)));
  ancho *= (double) maxx;
  alto *= (double) maxy;
  do  {
	 progs[rnd()](&helecho);
	 helecho.x=helecho.a;
	 helecho.y=helecho.b;
	 helecho.a=helecho.x*ancho+x0;
	 helecho.b=helecho.y*alto;
	 PlotDouble(helecho.a,helecho.b);
	 } while(!bioskey(1));

  }

static void near helecho1()  {

  helecho(hel_rnd,hel_progs,1.0/12,1.0/8);

  }

static void near helecho2()  {

  helecho(hel_rnd2,hel_progs,1.0/12,1.0/8);

  }

static void near arbol1()  {

  helecho(hel_rnd,arb_progs,1.5,1.5);

  }

static void near arbol2()  {

  helecho(arb_rnd2,arb_progs,1.5,1.5);

  }

static void near isla()  {

  double r1,r2,x=Relx(126),y=Rely(40);
  int f;

  r1=70;
  r2=20;
  do  {
	 for(f=50;f<=150;f++) 
		PlotDouble(x+r1*sin((double) f/100*M_PI),y+r2*cos((double) f/100*
		M_PI));
	 --r1;
	 --r2;
	 } while (!bioskey(1));

  }

static void near isla3D()  {

  int x,v,y,x0=100+((maxx-200) >> 1),y0=95+((maxy-(2*95)) >> 1);

  for(x=-100;x<=100;x++)
	 for (v=-floor(sqrt(1E4-sqr(x))),y=-v;y>=v && !bioskey(1);--y)
		Plot(x0+x,floor(y0-funcion(hypot(x,y))+0.707*(double) y));

  }

static void near copa()  {

  int x,y,escy=(long) sqr((long) medx)/medy;

  do  {
	 x=random(medx);
	 y=random((long) sqr((long) x)/escy);
	 x=medx-random(medx-x);
	 Plot(x,y);
	 Plot(maxx-x,y);
	 Plot(maxx-x,maxy-y);
	 Plot(x,maxy-y);
	 } while (!bioskey(1));

  }

static void near WriteWaitKey()  {

  outtextxy(0,maxy+1,"Prem una tecla per anar al menu");

  }

static void near ventana_estelar()  {

  int p=maxy >> 1,x,y,salir=0,tecla,cx=(maxx-maxy) >> 1;

  outtextxy(33 << 3,maxy+1,"R : Redibuixar");
  do  {
	 x=random(p);
	 y=random(p);
	 Plot(cx+p+x,p+y);
	 Plot(cx+p+y,p+x);
	 Plot(cx+p-x,p+y);
	 Plot(cx+p+y,p-x);
	 Plot(cx+p-x,p-y);
	 Plot(cx+p-y,p-x);
	 Plot(cx+p+x,p-y);
	 Plot(cx+p-y,p+x);
	 delay(50);
	 if ((tecla=bioskey(1)))
		if (!(salir=toupper(tecla & 0xFF)!='R'))  {
		  bioskey(0);
        bar(0,0,maxx,maxy);
		  randomize();
		  }
	 } while (!salir);

  }

static void near settextcenter()  {

  settextjustify(CENTER_TEXT,TOP_TEXT);

  }

static void near settextnormal()  {

  settextjustify(LEFT_TEXT,TOP_TEXT);

  }

static void *near pascal Menu2(int x,int y)  {

  int num;
  struct LISTADIBUJOSTIPO *dibujo=(struct LISTADIBUJOSTIPO *) &ListaDibujos;

  for (num=MaxDibujos;num-->0;y += textheight((dibujo++)->nombre))
	 outtextxy(x,y,dibujo->nombre);

  return Menu2;

  }

static void *near pascal Menu1(int x,int y)  {

  int divx=textwidth("Y"),cars=strlen(ListaDibujos[0].nombre),num=(cars+
  MaxDibujos) >> 2;
  double ancho,alto,ax=(double) divx/num,ay=((maxy==199) ? 0.31 : .5)*
  (double) divy/num;

  ancho=alto=0;
  do  {
	 setusercharsize(ancho,divx,alto,divy);
	 bar(x,y,x+cars*ancho,y+MaxDibujos*divy);
	 Menu2(x,y);
	 ancho += ax;
	 alto += ay;
	 } while (--num>=0);

  return Menu2;

  }

static void near _fastcall  setcharsize(int mulx,int divx)  {

  switch (maxy) {
	 case 199:setusercharsize(mulx,divx,3,10);break;
	 default:setusercharsize(mulx,divx,1,2);
	 }

  }

static int near MostrarListaDibujos()  {

  int num,y;
  struct LISTADIBUJOSTIPO *dibujo;

  cleardevice();
  randomize();
  settextstyle(SIMPLEX_FONT,HORIZ_DIR,USER_CHAR_SIZE);
  setcharsize(1,1);
  divy=textheight("A");
  y=(maxy-((MaxDibujos+4)*divy)) >> 1;
  settextcenter();
  outtextxy(medx,y,"Tria una Opci¢, [ESC] Sortir");
  settextnormal();
  menu=menu(((maxx-textwidth(ListaDibujos[0].nombre)) >> 1),y+(divy << 1));
  setcharsize(6,10);
  settextcenter();
  outtextxy(medx,y+((3+MaxDibujos)*divy),
  "Programa realitzat per Oscar Hern ndez Ba¤¢ en Turbo C++ 1.01");
  settextstyle(DEFAULT_FONT,HORIZ_DIR,0);
  settextnormal();
  while ((num=toupper(bioskey(0) & 0x00FF))!=27 && (num<'A' || num>'A'+
  MaxDibujos-1));
  if (num!=27)  {
	 randomize();
	 maxy -= 9;
	 medy -= 4;
	 dibujo=&ListaDibujos[num-'A'];
	 cleardevice();
	 if (dibujo->WaitKey) 
		WriteWaitKey();
		  else
		outtextxy(0,maxy+1,"Prem una tecla per cancel.lar el dibuix");
	 dibujo->prg();
	 if (!dibujo->WaitKey && !bioskey(1))  {
		bar(0,maxy+1,maxx,maxy+8);
		WriteWaitKey();
		}
	 bioskey(0);
	 maxy += 9;
	 medy += 4;
	 }

  return num;

  }

static void near _fastcall  pre_mover(CAR *pobjs)  {

  int modo,fin;
  double resul;
  CAR *objs;

  do
	 for (objs=pobjs,modo=fin=1;modo && objs->modo!=O_FIN;objs++)  {
		if ((modo=objs->modo))  {
		  bar(objs->x0,objs->y0,objs->x,objs->y);
		  objs->rad=min(objs->rad+objs->anc,objs->rad0);
		  objs->ang -= objs->aang;
		  while (objs->ang<0) objs->ang += 2*M_PI;
		  if (objs->rad==objs->rad0 && ((resul=fabs(objs->ang-objs->ang0))==0
		  || resul<=objs->aang))  {
			 objs->ang=objs->ang0;
			 objs->anc=objs->anc0;
			 ++pobjs;
			 }
		  }
			 else
		  ++objs->modo;
		fin=0;
		objs->anc=min(objs->anc+5,objs->anc0);
		setusercharsize(objs->anc,divx,objs->anc,divy);
		objs->x0=medx+objs->rad*cos(objs->ang);
		objs->y0=medy-objs->rad*sin(objs->ang);
		objs->x=objs->x0+textwidth(objs->car);
		objs->y=objs->y0+textheight(objs->car);
		outtextxy(objs->x0,objs->y0,objs->car);
		delay(7);
		}
	 while (!fin);
  }

static void near _fastcall  pre_inicio(CAR *objs)  {

  char **str=&Titulo,*str2;
  int cars,rad,arad,anc;
  double alfa,beta;

  settextstyle(BOLD_FONT,HORIZ_DIR,USER_CHAR_SIZE);
  rad=medy;
  arad=rad/(sizeof(Titulo)/sizeof(char *));
  arad += arad >> 1;
  divx=textheight("Y");
  divy=textheight("Y");
  anc=120*rad/348;
  do  {
	 cars=strlen(*str);
	 setusercharsize(anc,divx,anc,divy);
	 alfa=atan((double) ((textwidth(*str) >> 1))/(double) (textheight(*str) >> 1));
	 beta=M_PI_2-alfa;
	 alfa /= (double) (cars >> 1);
	 if (!(cars & 1)) beta += alfa/2;
	 for (str2=*str+cars;cars-->0;objs++)  {
		*objs->car=*--str2;
		objs->rad0=rad;
		objs->ang0=beta;
		objs->ang=2*M_PI;
		objs->rad=objs->modo=0;
		objs->aang=alfa;
		objs->anc0=anc;
		objs->anc=1;
		beta += alfa;
		}
	 rad -= arad;
	 anc >>= 1;
	 } while (*++str);
  objs->modo=O_FIN;

  }

void pre_espere()  {

  char titulo[sizeof(esperestr)+1];
  int len=strlen(esperestr),k,y,by;

  settextstyle(SIMPLEX_FONT,HORIZ_DIR,USER_CHAR_SIZE);
  setusercharsize(1,1,1,1);
  settextcenter();
  for (y=medy+((medy-42) >> 1),k=1;k<=len;k++) {
	 if (k>1) bar(0,y,maxx,y+42);
	 strncpy(titulo,esperestr,(by=(k >> 1)+(k & 1)));
	 strcpy(titulo+by,esperestr+len-(k >> 1));
	 outtextxy(medx,y,titulo);
	 }
  bioskey(0);

  }

void Presentacion()  {

  CAR objetos[40];

  setmem(&objetos,sizeof(objetos),0);
  delay(1000);
  pre_inicio(&objetos);
  pre_mover(&objetos);
  settextstyle(DEFAULT_FONT,HORIZ_DIR,0);
  pre_espere();

  }

int main(void)  {

  if (!inicio())  {
	 setfillstyle(EMPTY_FILL,color);
	 Presentacion();
	 while (MostrarListaDibujos()!=27);
	 closegraph();
	 }

  return 0;

  }