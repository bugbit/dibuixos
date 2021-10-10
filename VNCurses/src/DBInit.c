#if WIN32
#include "pch.h"
#endif
#include "dibuixos.h"

int check()
{
	return RET_SUCESS;

}

int init()
{
	int y,x;

#if XCURSES
	Xinitscr();
#else
	initscr();
#endif
	getmaxyx(stdscr,y,x);
	printw("Lines: %d Cols:%d\nMaxY : %d MaxX : %d",LINES,COLS,y,x);
	/* Lines : 48 LINES : 128 */
	resize_term(50,128);
	getmaxyx(stdscr,y,x);
	printw("Lines: %d Cols:%d\nMaxY : %d MaxX : %d",LINES,COLS,y,x);
	getch();

	return RET_SUCESS;
}

void end()
{
	endwin();
	// if (iscancel())
	// 	getch();
}
