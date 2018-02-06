.name		"addresses_X_lldi"
.comment	"testing lldis behaviour when confronted to huges values adresses"

begin:	st r1,:live
live:	live %:begin
		ld %4294967266,r2
		ld %65506,r3
		ld %-30,r4
		ld %-65599,r5
		st r1,400
		lldi 95,%0,r9
		sti r9,310,%0
		lldi r4,%0,r9
		sti r9,310,%0
		lldi %-30,%0,r9
		sti r9,310,%0
		lldi -30,%0,r9
		sti r9,310,%0
		lldi r3,%0,r9
		sti r9,310,%0
		lldi %65506,%0,r9
		sti r9,310,%0
		lldi 65506,%0,r9
		sti r9,310,%0
		lldi r2,%0,r9
		sti r9,310,%0
		lldi %4294967266,%0,r9
		sti r9,310,%0
		lldi 4294967266,%0,r9
		sti r9,310,%0
		lldi r5,%0,r9
		sti r9,310,%0
		lldi %-65599,%0,r9
		sti r9,310,%0
		lldi -65599,%0,r9
		sti r9,310,%0
