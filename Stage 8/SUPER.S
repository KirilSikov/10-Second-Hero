; Authors: Enrik R and Kiril S
; this is the super system call stuff for video.s to use

	xdef	superOn
	xdef	superOff

superOn:
	move.l	d0,-(sp)
	clr.l	-(sp)
	move.w 	#$20,-(sp)
	trap	#1
	addq.l	#6,sp
	move.l	d0,old_ssp
	move.l	(sp)+,d0
	rts

superOff:
	move.l 	d0,-(sp)
	move.l	(old_ssp),-(sp)
	move.w	#$20,-(sp)
	trap	#1
	addq.l 	#6,sp
	move.l 	(sp)+,d0
	rts

old_ssp:	ds.l	1
