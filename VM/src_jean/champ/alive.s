.name		"alive"
.comment	"testing the lives declarations"


carry_on:	ld %0,r2
begin:		sti r1,%:live,%1
live:		live %0
fork:		lfork %3
loop:		zjmp %4000		
