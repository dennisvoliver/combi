#include <stdio.h>

int comb(char *place, int n, char *symbol, int m);

/* prints m symbols taken n at a time */
int main(int argc, char **argv)
{
	if (argc != 3) {
		fprintf(stderr, "%s m n\n", argv[0]);
		return -1;
	}
	int m = atoi(*++argv);
	char symbol[m];	/* no '\0' because *symbol will not be printed */
	int i;
	for (i = 0; i < m; i++)
		symbol[i] = '0' + i;	/* totally bug prone */
	int n = atoi(*++argv);
	char place[n + 1];
	place[n] = '\0';
	comb(place, n, symbol, m);
	return 0;
}

/* comb: n must be the number of characters in *place and m in *symbol */
int comb(char *place, int n, char *symbol, int m)
{
	/* if no more place, print the buffer */
	if (n <= 0 ) {
		printf("%s\n", place);
		return 0;
	}
	/* if no more symbols, return the buffer */
	if (m <= 0) {
		return 0;
	}
	/* just pass the buffer to the next guy */
	comb(place, n, symbol, m - 1);
	/* when the buffer returns, put your symbol in the buffer then pass it to the next guy again */
	place[n - 1] = symbol[m - 1];
	comb(place, n - 1, symbol, m - 1);
	/* when the buffer returns again, return it to the previous guy */
	return 0;
}
/* Note: All references to "buffer" mean an imaginary object that can be a placeholder to an ordered sequence of symbols (e.g. scrabble tiles)	. It is easier to visualize recursive functions when you imagine them as people passing objects around */
