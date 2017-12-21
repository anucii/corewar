.name		"ldi_power"
.comment	"similar to test_lldi2.s : aims to test the ldi function"

		and %3,%6,r11
		ldi 17,%1,r3
		st r3, 61
		and %16,%17,r16
		and %10,%5,r15
		or %24,%52,r14
		or %6,%43,r13
