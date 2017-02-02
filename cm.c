#include <stdio.h>
#include <mydef.h>

/* cm: returns the combination of n taken r at a time, returns 0 if input is invalid (n < r) */
bignum cm(bignum n, bignum r)
{
	if (r == 0 || n == r)
		return 1;
	return cm(n - 1, r) + cm(n - 1, r - 1);
}
