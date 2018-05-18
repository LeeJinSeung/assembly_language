TITLE a
INCLUDE irvine32.inc


.data
myByte BYTE 0FFh, 0
.code

main PROC
	mov ax, 0
	mov al, myByte
	call writehex
	call crlf
	mov ah, [myByte+1]
	call writehex
	call crlf
	dec ah
	call writehex
	call crlf
	dec ax
	call writehex
	call crlf
	call waitmsg

	exit
main ENDP

END main