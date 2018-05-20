TITLE ex3_1

INCLUDE Irvine32.inc

.code
main PROC
	mov ax, 4000h
	mov bx, 1000h
	mov cx, 1500h
	sub ax, bx
	sub ax, cx
	call Dumpregs
	call waitmsg
	exit
main ENDP
END main