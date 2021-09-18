#include <stdio.h>
#include <alloc.h>

#include "dibuixos.h"

static bool check386()
{
	asm {
		or	bx,0F000h		// try to set bits 12-15
		push	bx
		popf
		pushf
		pop	ax
		and	ax,0F000h	// if bits 12-15 are cleared, then 80286
		jz	is286
	}
	return TRUE;
	is286:
	return FALSE;
}

static bool checkVGA()
{
	asm {
		mov ax,0x1a00
		int 10h
		cmp al,0x1a
		jne isnot
		cmp bl,7
		jae isvga
	}
isnot:
	return FALSE;
isvga:
	return TRUE;
}

int check()
{
	if (!check386())
		return seterror("A 386 or higher processor required.");

	if (!checkVGA())
		return seterror("VGA or compatible graphics adapter required.");

	return RET_SUCESS;

}

static void setMode80x50()
{
	// change a mode 80/50
	// Set mode 80x25
	// Next, change the font 8x8 (from 16x8) with a reset
	asm {
		mov ax,3
		int 0x10
		// Next, change the font 8x8 (from 16x8) with a reset
		mov ax,0x1112
		xor bl,bl
		int 0x10
		//mov ax,0x1202
		//mov bl,0x30
		//int 0x10
	}
}

int init()
{
	unsigned long freeini,freeend,memuse;

	freeini=coreleft();
	setMode80x50();
	cputs("Set Mode 80x50\r\n");
	freeend=coreleft();
	memuse=freeend-freeini;
	cprintf("He usado %8lu bytes\r\nQuedan %8lu bytes libres\r\n",memuse,freeend);

	return RET_SUCESS;
}

void end()
{
	if (iscancel())
		getch();
}
