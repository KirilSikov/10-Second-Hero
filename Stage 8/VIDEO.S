; Authors: Enrik R and Kiril S
; this has the Setscreen and Physbase stuff

	xdef	_getVideoBase
	xdef	_setVideoBase
	xref 	superOn
	xref 	superOff

SCREEN	equ 	$FFFF8201
OFFSET 	equ 	8
 
_getVideoBase:
	move.l	a0,-(sp) 	
	clr.l	d0		

	jsr	superOn

	lea	SCREEN,a0
	movep.w	(a0),d0		
	lsl.l 	#8,d0

	jsr	superOff

	move.l 	(sp)+,a0
	rts

_setVideoBase:
	link	a6,#0
	movem.l	d0/a0,-(sp)

	jsr	superOn

	move.l 	OFFSET(a6),d0
	lsr.l 	#8,d0
	lea 	SCREEN,a0
	movep.w d0,0(a0)

	jsr	superOff

	movem.l (sp)+,d0/a0
	unlk	a6
	rts

old_ssp:	ds.l	1
