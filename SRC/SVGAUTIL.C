#include "dibuixos.h"

void WaitForRetrace()
{
_waitVRnz:
	asm {
	   mov dx,3dah
		in	al,dx
		test	al,8
		jnz	_waitVRnz
	}
_waitVRz:
	asm {
		in	al,dx
		test	al,8
		jz	_waitVRz
	}
}

/* Getvgapalette16 gets the entire 16 color palette */
/* PalBuf contains RGB values for all 16 colors     */
/* R,G,B values range from 0 to 63	            */
/* Usage: 					    */ 
/*  DacPalette16 dac16;                             */
/*						    */
/*  getvgapalette(&dac16);			    */
bool pascal getvgapalette16(MemReal *mr)
{
	SimInt si;

	memset(&si,0,sizeof si);
	si.eax=0x1017;
	si.ecx=16;
	si.es=mr->realseg;
	if (!simint(&si,0x10))
		return FALSE;

	return TRUE;
}

/* Setvgapalette16 sets the entire 16 color palette */
/* PalBuf contains RGB values for all 16 colors     */
/* R,G,B values range from 0 to 63	            */
/* Usage: 					    */ 
/*  DacPalette16 dac16;                             */
/*						    */
/*  setvgapalette(&dac16);			    */
bool pascal setvgapalette16(MemReal *mr)
{
	SimInt si;

	memset(&si,0,sizeof si);
	si.eax=0x1012;
	si.ecx=16;
	si.es=mr->realseg;
	if (!simint(&si,0x10))
		return FALSE;

	return TRUE;
}

/* Getvgapalette256 gets the entire 256 color palette */
/* PalBuf contains RGB values for all 256 colors      */
/* R,G,B values range from 0 to 63	              */
/* Usage:					      */
/*  DacPalette256 dac256;			      */
/*						      */
/* getvgapalette256(&dac256);			      */
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

/* Setvgapalette256 sets the entire 256 color palette */
/* PalBuf contains RGB values for all 256 colors      */
/* R,G,B values range from 0 to 63	              */
/* Usage:					      */
/*  DacPalette256 dac256;			      */
/*						      */
/* setvgapalette256(&dac256);			      */
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
