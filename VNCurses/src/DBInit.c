#include "dibuixos.h"

int check()
{
	return RET_SUCESS;

}

int init()
{
	
	initscr();
	printw("Lines: %d Cols:%d",LINES,COLS);
	getch();

	return RET_SUCESS;
}

void end()
{
	endwin();
	// if (iscancel())
	// 	getch();
}
