#include "dibuixos.h"

bool check386()
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

// paragraphs = Number of paragraphs (16 bytes blocks)
bool _pascal mrealalloc(MemReal *mr,int paragraphs)
{
	int seg,selector;

	// Allocate DOS Memory Blocal
	asm {
		mov ax,0100h
		mov bx,paragraphs
		int 31h
		jnc realllocok
	}

	return FALSE;

realllocok:
	seg=_AX;
	selector=_DX;
	mr->realseg=seg;
	mr->selector=selector;
   mr->ptr=MK_FP(selector,0);

	return TRUE;
}

bool _pascal simint(SimInt *sim,int interruptNumber)
{
	asm {
		mov ax,0300h
		mov bx,interruptNumber
		lea di,sim
		xor cx,cx
		int 31h
		jnc simintok
	}

	return FALSE;
simintok:

	return TRUE;
}

