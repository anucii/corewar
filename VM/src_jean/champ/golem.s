.name 		"golem"
.comment	"clay champion for testing purposes"

			st r1,r7 	#backup champion number
fail_val:	ld %48,r16	#value to display if replacement failed
			ld %16777216,r2	#source code of a live instruction
			sti r2,%:replaced,%0
			sti r7,%:replaced,%1
			sti r2,%0,%96
			sti r7,%0,%90
			st	r2,42
			st	r3,43
replaced:	aff r16
store1:		aff r16
store2:		aff r16
live:		live %2
