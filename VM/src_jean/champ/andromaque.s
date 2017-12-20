.name		"Andromaque"
.comment	"Attempt to display Andromaque on stdout"

#		ld		%4278190080,r1
#		ld		%16711680,r2
#		ld		%65280,r3
#		ld		%255,r4

#		ld		%1097753714,r5
#		ld		%1869439345,r6
#		ld		%1969553408,r7

#		live	%0
		
#		and		r5,r1,r8
#		aff		r8
#		and		r5,r2,r8
#		aff		r8
		
#		ld		%1090519040,r9
#		and		r9,r1,r8
#		aff		r8
#		ld		%32,r8
#		aff		r8
#		and		r9,r4,r8
#		aff		r8

		st		r1,:live		

		ld		%0,r2
		ld		%0,r3

		ld		%:display,r2
		aff		r2
		aff		r3
		ld		:display,r3
		aff		r2
		aff		r3
ca:
dag:
adf:
2df:
3df:
rrr:
rdf:
adf:
adf:
adf:
adf:
adf:
adf:
adf:
adf:
adf:
adf:
adf:
adf:
adf:
auto:	ld		:auto,r4
		aff		r4

live:	live %:live	
display:	ld		%65,r1
			aff		r1
			ld		%110,r1
		aff		r1
		ld		%100,r1
		aff		r1
		ld		%114,r1
		aff		r1
		ld		%111,r1
		aff		r1
		ld		%109,r1
		aff		r1
		ld		%97,r1
		aff		r1
		ld		%113,r1
		aff		r1
		ld		%117,r1
		aff		r1
		ld		%101,r1
		aff		r1
