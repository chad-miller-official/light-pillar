#include <avr/io.h>

; I know I'm breaking calling convention, but we need this fast
.global analog_to_digital
.func analog_to_digital
analog_to_digital:
	ldi r18, 0x1
	out _SFR_IO_REG_P(ADMUX), r18
	ldi r18, 0xE0
	out _SFR_IO_REG_P(ADCSRA), r18
	sbi _SFR_IO_REG_P(ADCSRA), 0x6
	
	waitForSystem:
		sbis _SFR_IO_REG_P(ADCSRA), 0x4
		rjmp waitForSystem
		
	in r18, _SFR_IO_REG_P(ADCL)
	in r19, _SFR_IO_REG_P(ADCH)
	ret
.endfunc
