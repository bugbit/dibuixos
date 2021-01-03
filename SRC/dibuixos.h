#ifndef	__DIBUIXOS_H

#define	__DIBUIXOS_H

//#include <dos.h> 
#include <stdarg.h>
#include <stdio.h>  
#include <stdlib.h>
#include <string.h>
#include <conio.h>
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

typedef int bool;

//extern char dib_error[128];
extern int svga256gdriver,Twk256gdriver;

bool check386();
int seterror(char *fmt,...);
int grseterror(int errorcode);
int init();
bool cancel();

#endif
