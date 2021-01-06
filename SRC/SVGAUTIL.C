#include "dibuixos.h"

bool pascal getvgapalette256(MemReal *mr)
{
	SimInt si;

	memset(&si,0,sizeof si);
	si.eax=0x1017;
	si.ecx=256;
	si.es=mr->realseg;
	if (!simint(&si,0x10))
		return FALSE;

	return TRUE;
}

bool pascal setvgapalette256(MemReal *mr)
{
	SimInt si;

	memset(&si,0,sizeof si);
	si.eax=0x1012;
	si.ecx=256;
	si.es=mr->realseg;
	if (!simint(&si,0x10))
		return FALSE;

	return TRUE;
}
