#include <avr/io.h>

.global analog_to_digital
.func analog_to_digital
analog_to_digital:
	ldi r18, 1
	out _SFR_IO_REG_P(ADMUX), r18
	ldi r18, 224
	out _SFR_IO_REG_P(ADCSRA), r18
	sbi _SFR_IO_REG_P(ADCSRA), 6
	
	wait:
		sbis _SFR_IO_REG_P(ADCSRA), 4
		rjmp wait
		
	in r18, _SFR_IO_REG_P(ADCL)
	in r19, _SFR_IO_REG_P(ADCH)
	ret
.endfunc
