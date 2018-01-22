BITS 16

;; Samantha Scaglione
;; 19 January 2018

start:
        cli             ; turn off interrupts for the prelude
			; if interrupts are on, a hardware device
			; could alter a register and prevent the
			; computer from booting any further

        mov ax, 07C0h   ; Technically, nothing is enforcing this arbitrary number
        				; but it moves the contents of the bootloader to the ax
        				; general use register


        mov ds, ax      ; This sets the ds data segment equal to ax (aka moves the
        				; value of the ax general use register to the ds data
        				; segment). The ax general use register is the accumulator
        				; register (according to https://en.wikibooks.org/wiki/X86_Assembly/X86_Architecture)
        				; which basically means it will be used for calculations or
        				; math operations. On the other hand, the data segment (ds)
        				; is used "to form addresses when you want to read/write
        				; to memory" (according to https://wiki.osdev.org/Segmentation)
						; therefore, since the two registers are used for different
						; purposes, it is important to have the bootloader segment
						; data in both ds and ax

        add ax, 0020h   ; This adds 0020h to ax
        				; In terms of why, I was a little confused, so I consulted
        				; https://stackoverflow.com/questions/5364270/concept-of-mov-ax-cs-and-mov-ds-ax
						; and the answer by Jerry Coffin helped me understand that
						; since x86 has 16-bit registers but 20-bit addresses, in
						; order to generate an address, "a 16-bit segment register
						; is shifted left four bits, and then a 16-bit offset in
						; some other register is added to that, and the combined
						; total is actually used as the address." We talked about
						; this concept in class, but the stackoverflow entry helped
						; clarify the concept. Basically, this means that in order
						; to have a valid address, we need to add the offset- 0020h
						; to the initialized segment


        mov ss, ax		; This sets the ss stack segment equal to ax (aka moves the
        				; value of the ax general use register to the ss stack
        				; segment). Since the ss stack segment and ds data segment
        				; registers are completely independent of one another and
        				; are uniquely expected for use of certain processor
        				; operations, we have to load the segment data of the new
        				; address we just generated above to the stack segment
        				; According to https://en.wikipedia.org/wiki/Stack_register
        				; the stack segment register is "usually used to store
        				; information about the memory segment that stores the call
        				; stack of the currently executed program"

        mov sp, 1000h	; This sets the sp stack pointer equal to 1000h which
        				; basically means the current stack top is equal to 1000h
        				; This is important because, as the heap grows up, the stack
        				; grows down in memory and is LIFO (last in first out) so it
        				; is important to keep track of the top of the stack

        sti             ; turn the interrupts back on
        				; since the registers are set, we don't need to worry about
        				; a hardware device altering them anymore

		mov ah, 0Eh		; set function code to 0Eh, which is for teletype
		mov al, 43h		; AL is char register, 43h is ASCII for 'C'
		mov bh, 0h		; BH is page number, which we want to be zero
		int 10h			; issue interrupt

		mov al, 44h		; 44h is ASCII for 'D'
		int 10h			; issue interrupt

		mov si, thestring	; point the register SI to the string we want to print

		call print			; the call instruction causes the CPU to execute
							; instructions at the given label until the ret
							; instruction is hit. call puts the current instruction
							; pointer on the stack before it goes to the label ret
							; restores the instruction pointer by reading it from
							; the stack
	jmp $

	; the lines below are nasm directives, NOT x86 instructions
	; they tell nasm to fill the rest of the space from our
	; current location to 510 bytes with zeros
	; then set the last two bytes (dw = define word) to AA55
	; this is by convention, since the firmware validates the bootloader
	; by reading the last two bytes and confirming that they are AA55
	; the firmware will not execute the bootloader without it

	;; START OF PROCEDURE AREA ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

	; start of procedure print
	print:
		mov ah, 0Eh		; set the function code to teletype to prepare for
						; the software interrupt

		loopStart:		; start a loop area
			lodsb			; load a byte from DS:SI into the a register
			cmp al, 0		; check if the register is null or not
			je loopExit		; if the register is null, jump to an exit label
			int 10h			; if the register is not null, issue 10h to print it
			jmp loopStart	; go back to the loop label

		loopExit:
			ret				; ret is the CPU instruction meaning return

	; end of procedure print

	;; END OF PROCEDURE AREA ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

	;; START OF DATA AREA ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

	thestring db 'mcduck', 0

	;; END OF DATA AREA ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

	times 510-($-$$) db 0
	dw 0xAA55	; BIOS looks for AA55 at the end of the sector

