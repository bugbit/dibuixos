#ifndef	__DIBUIXOS_H

#define	__DIBUIXOS_H

#include <dos.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mem.h>
#include <graphics.h>
#include "SVGA256.H"
#include "TWK256.H"

#pragma hdrstop

#define	TRUE	1
#define	FALSE	0

#define	RET_SUCESS		0
#define	RET_ERROR		-1
#define	RET_EXIT		-2
#define	RET_CANCEL		-3

#define	issucess(r)		(r>=RET_SUCESS)
#define	isnosucess(r)	(r<RET_SUCESS)

#define	mrealloc(mr,size)	mreallocpar(mr,size >> 4)

typedef int bool;

typedef struct _MemReal
{
	unsigned int realseg;
	unsigned int selector;
   void far *ptr;
} MemReal;

typedef struct _SimInt
{
	unsigned long edi;
	unsigned long esi;
	unsigned long ebp;
	unsigned long esp;
	unsigned long ebx;
	unsigned long edx;
	unsigned long ecx;
	unsigned long eax;
	unsigned int flags;
	unsigned int es;
	unsigned int ds;
	unsigned int fs;
	unsigned int gs;
	unsigned int ip;
	unsigned int cs;
	unsigned int sp;
	unsigned int ss;
} SimInt;

//extern char dib_error[128];
extern int svga256gdriver,Twk256gdriver;
extern int maxx,maxy;
extern void interrupt (*keyb9_oldint)();
extern bool canceled;

bool check386();
int _pascal mreallocpar(MemReal *mr,int paragraphs);
int _pascal mrfree(MemReal *mr);
int _pascal simint(SimInt *sim,int interruptNumber);
int seterror(char *fmt,...);
int grseterror(int errorcode);
void interrupt keyb9_int();
void dib_initgraph(int gdriver,int gmode);
void dib_closegraph();

// svgautil

int pascal getvgapalette256(MemReal *mr);
int pascal setvgapalette256(MemReal *mr);

int init();
int presentacion();

#endif
