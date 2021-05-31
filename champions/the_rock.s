.name "Dwayne Johnsson"
.comment "Aussi solide qu'un cailloux"

w1: 	ld 	9,r4
	ld 	900,r5
	sti 	r4, r5, %0
	sub 	r5, r10, r5
	ld 	0,r2
	zjmp 	%:w1
