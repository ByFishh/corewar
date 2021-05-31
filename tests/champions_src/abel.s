.name "Abel"
.comment "L'amér noir."

sti r1, %:hi, %1

hi:	live %234
	ld %0, r3
	zjmp %:hi
