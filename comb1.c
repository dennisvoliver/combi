#include <stdio.h>
#include <string.h>
int combine(char *symbol, int r);
#include <stdlib.h>

struct list {	
	int count;
	char *word;
	struct list *next;
} A = {0, NULL, NULL};	/* the linked list */

int printc(struct list *r, char *symbols);
int perm2(char *digits, int n, char *symbols);
int permute(char *symbols, int n);

char *pluck(const char *s, int n);
int add(struct list *, char *s);
int dups(struct list *r, char *s);

/*  an implementation of comb.c using perm2 algorithm without using brute force search */
int main(int argc, char *argv[])
{
	if (argc != 3) {
		printf("%s string nplaces\n", argv[0]);
		return 1;
	}
//	permute(argv[1], atoi(argv[2]));
	combine(argv[1], atoi(argv[2]));
	return 0;
}

/* combine: use a permutated map to decide which symbol to print */
int combine(char *symbol, int r)
{
	int n = strlen(symbol);
	char map[n + 1];
	int i;
	for (i = 0; i < n; i++)
		map[i] = (i < r) ? '1' : '0';
	char buf[i + 1];
	 buf[i] = map[i] = '\0';
	perm2(buf, n, map);
	printc(A.next, symbol);
	return 0;
}
/* permute: convenient wrapper for the whole program */
int permute(char *symbols, int n)
{
	int m = strlen(symbols); 	/* no. of objects */
	char digits[m]; 		
	strcpy(digits, symbols);

	digits[n] = '\0';	/* n is the no. of places */

	perm2(digits, n, symbols);

	read(A.next);

	return 0;
}

/* read: reads list */
int read(struct list *r)
{
	if (r == NULL)
		return 0;
	printf("%s\t%d\n", r->word, r->count);
	read(r->next);
}
/* printc: prints *symbols as mapped by *r */
int printc(struct list *r, char *symbols)
{
	int i;
	struct list *current;
	int max = strlen(symbols);
	for (current = r; current != NULL; current = current->next) {
		for (i = 0; i < max; i++)
			if ( *(current->word + i) == '1')
				putchar(symbols[i]);
		putchar('\n');
	}
}
/* dups: checks if string is already in linked list */
int dups(struct list *r, char *s)
{
	if (r == NULL)
		return 0;
	if (strcmp(r->word, s) == 0)
		return 1;
	return dups(r->next, s);
}

/* perm2: permutates m objects taken n at a time */
int perm2(char *digits, int n, char *symbols)
{
	if (n <= 0 ) {
		if (dups(A.next, digits) == 0)
			add(&A, digits);
		return 0;
	}

	int i, m = strlen(symbols);
	for (i = 0; i < m; i++) {
		digits[n - 1] = symbols[i];
		perm2(digits, n - 1, pluck(symbols, i + 1));
	}

	return 0;
}

/* add: adds a character to a list */
int add(struct list *r, char *s)
{
	if (r->next == NULL) {
		r->next = (struct list *)malloc(sizeof(struct list));
		r->next->count = r->count + 1;
		r = r->next; 	/* for convenience */
		r->word = (char *)malloc(sizeof(s));
		strcpy(r->word, s);
		return 0;
	}
	return add(r->next, s);
}

/* pluck: returns a string s without the nth character */
char *pluck(const char *s, int n)
{
	int m = strlen(s);
	if (n < 1 || n > m)
		return NULL;
	char *temp = (char *)malloc(m);
	int i;

	for (i = 0; (*temp = s[i]) != '\0' ; i++) {
		if ((i != (n - 1))) {
			temp++;
		}
	}
	return temp - m + 1;
}

/* testing makefile */
