.name "test2"
.comment "basic test living prog"

l2:		sti r1,%:live,%1
		and r1,%5,r1

live:	live %2
		zjmp %:live
