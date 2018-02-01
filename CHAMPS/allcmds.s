.name   "AllCmds"
.comment  "Testing every instruction from the subject set"

		st  r1,:live
		st  r1,r9
		ld  -5,r2
		ld  %-5,r8
		ld  %1,r7
live: 	live %42
add: 	add  r1,r2,r3
		add  r9,r8,r9
		sub  r9,r3,r10
		and  -15,%15,r11
		and  %-15,15,r12
		and  r11,r12,r13
		xor  -15,%15,r11
		xor  %-15,15,r12
		xor  r11,r12,r13
		or  -15,%15,r11
		or  %-15,15,r12
		or  r11,r12,r13
		zjmp %:live
		zjmp %:loop
		zjmp %2
		fork %:live
loop: 	fork %-4
		ldi  r13,r12,r15
		ldi  :live,%1,r14
		sti  r1,:again,%1
		sti  r1,%:again,r7
		lld  %-5,r8
		lld  -5,r2
		lldi :live,%1,r14
		lldi :again,%2000,r6
		sti  r6,:leap,%1
leap:	lfork %:live
		sti  r6,%:leap,%1
again:	live %42
		ld  %16777216,r6
		sti  r6,%:aff,%1
aff:	aff  r1
