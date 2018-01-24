.name			"checksize"
.comment		"checking the size of the fields in the bytecode"
#lld_lil_val:	lld %18,r2
#lld_big_val:	lld %7,r3
#lld_ind:		lld -5,r4

#xor_ddr:		or %24,%12,r5
#xor_dir:		or %6,7,r6
#xor_rrr:		xor r5,r6,r7

#and_ddr:		and %24,%12,r5
and_dir:		and %6,7,r6
and_rrr:		and r5,r6,r7

#				sub r2,r3,r8
#				sub r2,r3,r8


#and_rrr:		and r2,r3,r6
#and_ddr:		and %10,%70000,r7
#and_iir:		and 10,67000,r8
				#sub r2,r3,r9
#				lfork %246000	#0x3c0f0

#sti_rrr:		sti r5,r9,r6
#sti_rdd:		sti r6,%10,%123000
#sti_rid:		sti r7,-1,%5000
#sti_rir:		sti r8,-1,r10

#ldi_ddr:		ldi %5,%13,r9
#ldi_irr:		ldi 5,r2,r10
#ldi_idr:		ldi 6,%15,r11

#lldi_ddr:		lldi %5,%13,r9
#lldi_irr:		lldi 5,r2,r10
#lldi_idr:		lldi 6,%15,r11

#				ld %5,r11
#				ld %5,r11

#str_reg:		st r2,r5
#str_ind:		st r3,-10
#str_label:		st r2,:ld_ind

#or_ddr:			or %24,%12,r5
				live %66

				zjmp %123000	#0x1e078
