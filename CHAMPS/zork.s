.name		""
.comment	"subject example as is"

l2:			sti	r1,%:live,%1
l2:			sti	r2,%:live,%5
			and	r1,%0,r1
live:		live %1
			zjmp %:l2
