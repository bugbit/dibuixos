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

