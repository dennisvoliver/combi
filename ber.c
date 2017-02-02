/* tests if (p + 1) * ((n + 1)^p - n^p) = sum(n^k * sum(com(p, p - k), j = 0, p), k = 0, p - 1)
 * = (p + 1) * sum(com(p, k), k = 0, p - 1)
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef int bignum;
bignum com(bignum n, bignum r);
int main(int argc, char **argv)
{
	if (argc < 3) {
		fprintf(stderr, "ber <num> <pow>\n");
		exit(-1);
	}
	int k, j, n, p;
	n = atoi(*++argv);
	p = atoi(*++argv);
	int a = 0;
	for (k = 0; k <= p - 1; k++)
		a += com(p, k) * pow(n, k);
	a *= (p + 1);
	printf("%d = ", a);
	a = 0;
	for (k = 0; k <= p - 1; k++)
		for (j = 0; j <= p; j++)
			a += pow(n, k) * com(p, p - k);
	printf("%d = ", a);
	printf("%d\n", (int) ((p + 1) * (pow(n + 1, p) - pow(n, p))));
}

/* C(n, r) */
bignum com(bignum n, bignum r)
{
	if (r == 0 || n == r)
		return 1;
	return com(n - 1, r) + com(n - 1, r - 1);
}
