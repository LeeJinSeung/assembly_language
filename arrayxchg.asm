TITLE arrayxchg

INCLUDE irvine32.inc
cal_size TEXTEQU<"Size of array?">

.data
arrayD DWORD 1,2,3
.code

main PROC
	mov eax,arrayD
	xchg eax,[arrayD+4]
	xchg eax,[arrayD+8]
	mov arrayD, eax
	mov ebx,[arrayD+4]
	mov ecx,[arrayD+8]
	call Dumpregs
	call waitmsg
	exit
main ENDP

END main