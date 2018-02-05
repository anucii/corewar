#!/bin/sh
[ $1 -a $2 -a $3 ] || \
		echo "Script launched with default values\n[Usage: ./diff_report.sh <DUMP_VAL> <contendant1> \
<contendant2> ...]"
[ -x "./corewar" -a -x "./asm" ] || make
[ -e "./CHAMPS/golem.cor" ] || ./asm ./CHAMPS/golem.s
[ -e "./CHAMPS/allcmds.cor" ] || ./asm ./CHAMPS/allcmds.s 
[ $1 ] && VAL=$1 || VAL=1586
[ $2 ] && C1=$2 || C1="CHAMPS/golem.cor"
[ $3 ] && C2=$3 || C2="CHAMPS/allcmds.cor"
[ $4 ] && C3=$4 || C3=""
[ $5 ] && C4=$5 || C4=""

./corewar $C1 $C2 $C3 $C4 -v 0 -dump $VAL > dump_rscl
./RESSOURCES/corewar $C1 $C2 $C3 $C4 -d $VAL > dump_zaz
diff -a dump_rscl dump_zaz
