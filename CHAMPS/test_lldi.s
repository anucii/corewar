.name		"test_lldi"
.comment	"champion for comparison purposes w/ the test written in f_lldi.c"

		ld %4075,r2
		lldi 4,%0,r3
		lldi %4,%0,r16
		lldi r2,r3,r4
		st r3,56

