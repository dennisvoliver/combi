/*
 * uses combinatorics to evaluate (n + 1) ^ (p + 1) - n ^ (p + 1)
 * the algorithm  is (n + 1) ^ (p + 1) - n^(p + 1) =
 * sum((n + 1)^k * n^(p - k), k = 0, p) = sum(n^(p - k) * sum(com(k, j) * n^j, j = 0, k), k = 0, * p)
 * = sum(n^k * sum(com(p - j, p - k), j = 0, k), k = 0, p)
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef int bignum;
bignum com(bignum n, bignum r);
int main(int argc, char **argv)
{
	if (argc < 3) {
		fprintf(stderr, "cumb <num> <pow>\n");
		exit(-1);
	}
	int k, j, n, p;
	n = atoi(*++argv);
	p = atoi(*++argv);
	int cumb = 0;

	for (k = 0; k <= p; k++) {
		for (j = 0; j <= k; j++) {
			cumb += pow(n, k) * com(p - j, p - k);
		}
	}

	printf("%d = %d\n", pow(n + 1, p + 1) - pow(n, p + 1), cumb);
}

/* C(n, r) */
bignum com(bignum n, bignum r)
{
	if (r == 0 || n == r)
		return 1;
	return com(n - 1, r) + com(n - 1, r - 1);
}
