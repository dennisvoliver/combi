comb : comb.c comb1 comb2 perm2
	gcc -o comb comb.c
comb1 : comb1.c
	gcc -o comb1 comb1.c
comb2 : comb2.c
	gcc -o comb2 comb2.c
perm2 : perm2.c
	gcc -o perm2 perm2.c
