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

	initscr();
	resizeterm(50,80);
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
