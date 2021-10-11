#ifndef	__DIBUIXOS_H

#define	__DIBUIXOS_H

#define ERR_PAIR     1

#define	issucess(r)		(r==OK)
#define	isnosucess(r)	(r==ERR)
#define	iscancel()	kbhit()

int seterror(char *fmt,...);
int check();
int init(int argc, char *argv[]);
void end();

//extern bool canceled;


#endif
