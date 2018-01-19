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

	jmp $

	; the lines below are nasm directives, NOT x86 instructions
	; they tell nasm to fill the rest of the space from our
	; current location to 510 bytes with zeros
	; then set the last two bytes (dw = define word) to AA55
	; this is by convention, since the firmware validates the bootloader
	; by reading the last two bytes and confirming that they are AA55
	; the firmware will not execute the bootloader without it
	times 510-($-$$) db 0
	dw 0xAA55	; BIOS looks for AA55 at the end of the sector

