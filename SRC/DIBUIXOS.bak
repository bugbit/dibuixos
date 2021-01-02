#ifndef	__DIBUIXOS_H

#define	__DIBUIXOS_H

//#include <dos.h> 
#include <stdarg.h>  
#include <stdio.h>
#include <graphics.h>
#include "SVGA256.H"

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

extern char dib_error[128];

bool check386();
int seterror(char *fmt,...);

#endif
