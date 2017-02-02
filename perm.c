#include <stdio.h>

int printp(int *place);
int perm(int *place, int m, int *symbol, int n );
int main(int argc, char **argv)
{

	return 0;
}

int perm(int *place, int m, int *symbol, int n )
{
	if (m <= 0) {
		printp(place);
		return 0;
	}
	int i;
	for (i = 1; i <= n; i++)
		if (symbol[i] == 0) {
			symbol[i] = 1;
			perm(place, m - 1, symbol, n);
			symbol[i] = 0;
		}
	return 0;
}

/* printp: prints an integer sequence, the first of which is the cardinal number of the set */
int printp(int *place)
{
	int i;
	for (i = 1; i <= place[0]; i++)
		printf("%d ", place[i]);
	putchar('\n');
	return 0;
}
/*
	if the buffer is full
		print
		return
	for each place in the marker that is not yet marked
		copy its corresponding symbol to the buffer
		mark it
		pass it to the next recursion
	return
*/
