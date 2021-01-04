#ifndef	__DIBUIXOS_H

#define	__DIBUIXOS_H

#include <dos.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <graphics.h>
#include "SVGAUTIL.h"
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

typedef int bool;

//extern char dib_error[128];
extern int svga256gdriver,Twk256gdriver;
extern void interrupt (*keyb9_oldint)();
extern bool canceled;

bool check386();
int seterror(char *fmt,...);
int grseterror(int errorcode);
void interrupt keyb9_int();
void dib_initgraph(int gdriver,int gmode);
int init();
int presentacion();

#endif
