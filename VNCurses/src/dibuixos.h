#ifndef	__DIBUIXOS_H

#define	__DIBUIXOS_H

#define	TRUE	1
#define	FALSE	0

#define	RET_SUCESS		0
#define	RET_ERROR		-1
#define	RET_EXIT		-2
#define	RET_CANCEL		-3

#define	issucess(r)		(r>=RET_SUCESS)
#define	isnosucess(r)	(r<RET_SUCESS)
#define	iscancel()	kbhit()

//typedef int bool;

int check();
int init();
void end();

extern bool canceled;


#endif
