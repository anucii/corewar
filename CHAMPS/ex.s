.name "zork"
.comment "just a basic living prog"
# retenir que la valeur d'un registre occupe 4 octets
# but : ecrire sur l'instruction live la serie d'octets suivante
#ERR		0x10 0x01 0x03 0x00 (26850176) mais l'opc vaut 0x40(decalages)
#		0x10 0x40 0x03 0x00 (272630528)

		
	ld	%90,r2 #afficher Z
	ld	%97,r3 #afficher a
#	ld	%268501760,r4 #instruction de remplacemnt
	ld	%272630528,r4
	ld	%255,r1		#unexistant register

l2:	sti	r2,%:live,%1
	sti r4,%:live,%0 #remplacer l'instruction live par un aff
	sti r4,:disp,%0	#meme tentative, mais avec une indirection ->echec 
					#l'indirection semble interpretee comme une valeur absolue
	sti r1,%:disp,%6
	and	r1,%0,r1
live:	live %0
pppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseisseppissepissepissepissepissepissepisseissepissepissepissepissepissepissepisseisse:	live %-1
disp:	aff		r2 #afficher Z si intact
		aff r2
		sti	r2,%:caca,%1
caca:
	zjmp	%:live
	fork	%:live
