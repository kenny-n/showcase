TITLE	Combinations Calculator	

; Author: 		Kenny Ngo
; Date: 		06/11/17
; Description:	A system is required for statistics students to use for drill and practice in combinatorics.
; In particular, thesystem will ask the student to calculate the number of combinations of r items taken from
; a set of n items (i.e., nCr ). The system generates random problems with n in [3 .. 12] and r in [1 .. n].
; The student enters his/her answer, and the system reports the correct answer and an evaluation of the
; student’s answer. The system repeats until the student chooses to quit.

INCLUDE Irvine32.inc

WriteBuffer MACRO	buffer
	push	edx
	mov		edx, OFFSET buffer
	call	WriteString
	pop		edx
ENDM

MIN = 3
MAX = 13
	
.data
	programTitle		BYTE	"Combinations Calculator", 0
	myName				BYTE	"Programmed by Kenny Ngo", 0
	instructions1		BYTE	"I'll give you a combinations problem. You enter your answer,", 0
	instructions2		BYTE	"and I'll let you know if you’re right.", 0
	message1			BYTE	"Problem:", 0
	message2			BYTE	"Number of elements in the set: ", 0
	message3			BYTE	"Number of elements to choose from the set: ", 0
	promptGuess			BYTE	"How many ways can you choose? ", 0
	userString			BYTE	10 DUP(0)
	answer				DWORD	?
	valN				DWORD	?
	valR				DWORD	?
	divisor				DWORD	?
	display1			BYTE	"There are ", 0
	display2			BYTE	" combinations of ", 0
	display3			BYTE	" items from a set of ", 0
	period				BYTE	".", 0
	result				DWORD	?
	correct				BYTE	"You are correct!", 0
	incorrect			BYTE	"You need more practice.", 0
	promptAnother		BYTE	"Another problem? (y/n): ", 0
	yesResponse			BYTE	"y", 0
	noResponse			BYTE	"n", 0
	userResponse		BYTE	15 DUP(0)
	invalid				BYTE	"Invalid Response. ", 0
	goodBye				BYTE	"Results certified by Kenny Ngo. Goodbye.", 0

.code
main PROC
	call	Randomize
	call	introduction
	AnotherRun:
		push	OFFSET valN		;ebp+12
		push	OFFSET valR		;ebp+8
		call	showProblem

		push	OFFSET answer
		call	getData
		
		mov		eax, valN
		cmp		eax, valR
		jne		NotEqual		
		mov		result, 1
		jmp		Next
		
		NotEqual:
			push	OFFSET divisor	;ebp+20
			push	valN			;ebp+16
			push	valR			;ebp+12
			push	OFFSET result	;ebp+8
			call	combinations

		Next:
			push	result			;ebp+20
			push	answer			;ebp+16
			push	valR			;ebp+12
			push	valN			;ebp+8
			call	showResults
			call	CrLf	

		call	runAnother					
		cmp		ecx, 1
		je		AnotherRun

	call	farewell
	exit	; exit to operating system
main ENDP

;introduces program to user
introduction PROC
	WriteBuffer programTitle
	call	CrLf
	WriteBuffer myName
	call	CrLf
	WriteBuffer instructions1
	call	CrLf
	WriteBuffer instructions2
	call	CrLf
	call	CrLf
	ret
introduction ENDP

;showProblem: generates the random numbers and displays the problem
;showProblem accepts addresses of n and r.
showProblem PROC
	push	ebp
	mov		ebp, esp
	mov		edi, [ebp+12]
	mov		ebx, 0
	mov		ecx, 0

	;random number generator
	GetN:		
		mov		eax, MAX
		call	RandomRange
		call	validateRandom		
		cmp		ebx, 0				;Check if valid input 0 = FALSE
		je		GetN

		mov		[edi], eax
		mov		edi, [ebp+8]
		add		eax, 1
		mov		ebx, 0
		jmp		GetR

	Reset:
		pop		ebx
		pop		eax
	
	GetR:						
		push	eax
		push	ebx
		call	RandomRange
		call	validateRandom
		cmp		ebx, 0				;Check if valid input 0 = FALSE
		je		Reset

		mov		[edi], eax
		pop		ebx
		mov		ebx, eax

		WriteBuffer	message1
		call	CrLf
	
		pop		eax
		sub		eax, 1
	
		WriteBuffer	message2
		call	WriteDec
		call	CrLf
	
		mov		eax, ebx
		WriteBuffer	message3
		call	WriteDec
		call	CrLf
		call	CrLf

		pop		ebp
		ret		9
showProblem ENDP

; This procedure is used to validate the random integers.  
; The range is compared against the MAX and MIN limits and put in array if valid.
validateRandom PROC
	cmp		ecx, 2
	jg		JumpR

	cmp     eax, MAX
	jg      OutOfRange
	cmp     eax, MIN
	jl      OutOfRange
	mov		ebx, 1
	mov		ecx, eax
	ret

	JumpR:
		cmp     eax, 1
		jl      OutOfRange
		mov		ebx, 1
		ret

	OutOfRange:
		mov		ebx, 0
		ret
validateRandom ENDP

;getData
getData PROC
	push	ebp
	mov		ebp, esp
	mov		edi, [ebp+8]
	mov		eax, 0
	mov		[edi], eax

	GetString:
		WriteBuffer	promptGuess
		mov		edx, OFFSET userString
		mov		ecx, 9
		call	ReadString
		mov		ecx, eax
		mov		esi, OFFSET userString

	Validate:
		mov		ebx, [ebp+8]
		mov		eax, [ebx]
		mov		ebx, 10
		mul		ebx
	
		mov		ebx, [ebp+8]
		mov		[ebx], eax
		mov		al, [esi]
		cmp		al, 48
		jl		OutOfRange

		cmp		al, 57
		jg		OutOfRange

		inc		esi
		sub		al, 48
		
		mov		ebx, [ebp+8]
		add		[ebx], al

		loop	Validate
		jmp		EndLoop

	OutOfRange:
		WriteBuffer	invalid
		call	CrLf
		call	CrLf
		jmp		GetString

	EndLoop:
		call	CrLf
		pop		ebp
		ret		8
getData ENDP

; calculates n!/(r!(n-r)!) , and stores the value in result.
combinations	PROC
	push	ebp
	mov		ebp,esp

	mov		eax, [ebp+16]	; (n-r)!
	sub		eax, [ebp+12]
	mov		ebx, eax
	push	ebx
	call	factorial

	mov		edx,[ebp+20]	
	mov		[edx],eax

	mov		ebx, [ebp+12]	; r!
	push	ebx
	call	factorial

	mov		edx,[ebp+20]
	mov		ebx, [edx]
	mul		ebx
	mov		ebx, [ebp+20]
	mov		[ebx], eax

	mov		ebx, [ebp+16]   ; n!
	push	ebx
	call	factorial

	mov		edx, [ebp+20]            
	mov		ebx, [edx]

	mov		edx, 0
	div		ebx				; divide n! by divisor (r!*(n-r)!)
	mov		ebx, [ebp+8]
	mov		[ebx],eax

	pop		ebp
	ret		16
combinations	ENDP

; do the calculations
factorial   PROC
	mov		eax, DWORD ptr [esp+4]
	cmp		eax, 1
	jle		EndRecursion
	dec		eax
	push	eax
	call	factorial
	mov		esi, DWORD ptr [esp+4]
	mul		esi

	EndRecursion:
		ret 4
factorial   ENDP

; show results to the user based on user input
showResults PROC
	push	ebp
	mov		ebp, esp
	
	WriteBuffer	display1
	mov		eax, [ebp+20]
	call	WriteDec

	WriteBuffer	display2
	mov		eax, [ebp+8]
	call	WriteDec

	WriteBuffer	display3
	mov		eax, [ebp+12]
	call	WriteDec
	call	CrLf

	mov		eax, [ebp+16]
	mov		ebx, [ebp+20]
	cmp		eax, ebx
	je		UserCorrect
	jmp		UserIncorrect

	UserCorrect:
		WriteBuffer	correct
		call	CrLf
		jmp		Done

	UserIncorrect:
		WriteBuffer	incorrect
		call	CrLf
		jmp		Done

	Done:
		pop		ebp
		ret		15
showResults ENDP

; used to check if the user wants to run the program again.
runAnother PROC
Asking:
	WriteBuffer	promptAnother
	mov		edx, OFFSET userResponse			;user response
	mov		ecx, 14								;max characters
	call	ReadString							;get user response

	mov		esi, OFFSET userResponse			;The user string into esi
	mov		edi, OFFSET yesResponse				;Yes string to coninue in edi
	cmpsb										;Compare strings
	mov		ecx, 1								;yes to continue
	je		Exiting								;if yes, Exit procedure			
	
	mov		esi, OFFSET userResponse			;The user string into esi
	mov		edi, OFFSET noResponse				;No string to coninue in edi
	cmpsb										;Compare strings
	mov		ecx, 0								;no to continue
	je		Exiting								;if no, Exit procedure	

	WriteBuffer	invalid					;Invalid string
	call CrLf
	jmp		Asking	

Exiting:
	call	CrLf
	ret
runAnother ENDP

;says goodbye
farewell PROC
	WriteBuffer goodBye
	call	CrLf
	call	CrLf
	ret
farewell ENDP

END main