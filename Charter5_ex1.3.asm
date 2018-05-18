TITLE ex1.3
INCLUDE irvine32.inc


.data
str1 BYTE "Assembly language is easy!",0
IntVal = 35
.code

main PROC
	call clrscr
	mov eax, 500
	call delay
	call Dumpregs
	mov edx, OFFSET str1
	call writestring
	call crlf
	mov eax, IntVal
	call writeBin
	call crlf
	call writedec
	call crlf
	call writehex
	call crlf
	call waitmsg
	exit
main ENDP

END main