/* working */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct list {	
	int count;
	char *word;
	struct list *next;
} A = {0, NULL, NULL};	/* the linked list */

struct page {
	int count;
	struct list *List;
	struct page *next;

} B = {0, NULL, NULL};

int perm2(char *digits, int n, char *symbols);
int permute(char *symbols, int n);

char *pluck(const char *s, int n);
int add(struct list *, char *s);
int dups(struct list *r, char *s);
int print(struct page *r);
int combine(struct list *r);
int count (char c, char *s);
int inlist(struct list *r);
int twins(char *s, char *t);

struct page *current;

/* combination of argv[1] taken argv[2] at a time */
int main(int argc, char *argv[])
{
	if (argc != 3) {
		printf("%s string nplaces\n", argv[0]);
		return 1;
	} 
	current = &B;
	permute(argv[1], atoi(argv[2]));
	combine(A.next);
	print(B.next);
	return 0;
}


/* permute: convenient wrapper for the permutation program */
int permute(char *symbols, int n)
{
	int m = strlen(symbols); 	/* no. of objects */
	char digits[m]; 		
	strcpy(digits, symbols);

	digits[n] = '\0';	/* n is the no. of places */

	perm2(digits, n, symbols);

//	read(A.next);

	return 0;
}

/* print: prints a page list */
int print(struct page *r)
{
	if (r == NULL)
		return 0;
	static int i = 0;
	printf("%s \n", r->List->word );
//	printf("%s %d\n", r->List->word, ++i);
	return print(r->next);
}

/* combine: creates a list of combinations */
int combine(struct list *r)
{
	if (r == NULL) {
		return 0;
	}
	if (!inlist(r)) { 
		current->next = (struct page *)malloc(sizeof(struct page));
		current = current->next;
		current->List = r;
		current->count++;
		current->next = NULL;
	}
	return combine(r->next);
}

/* inlist: returns 1 if list r is already in the B tree, 0 otherwise */
int inlist(struct list *r)
{
	struct page *temp;
	for (temp = B.next; temp != NULL; temp = temp->next)
		if (twins(temp->List->word, r->word))
			return 1;
	return 0;
}

/* twins: returns 1 if the letters of s are combinatorially equivalent to the letters of t, 0 otherwise */
int twins(char *s, char *t)
{
	int n;
	if ((n = sizeof(s) - 1) != sizeof(t) - 1)
		return 0;
	int i;
	for (i = 0; i < n; i++)
		if (count(s[i], s) != count (s[i], t))
			return 0;
	return 1;
}

/* count: returns the number of occurrences of c in s */
int count (char c, char *s)
{
	int i;
	for (i = 0; *s != '\0'; s++)
		if (*s == c)
			i++;
	return i;
}


/* read: reads list */
int read(struct list *r)
{
	if (r == NULL)
		return 0;
//	printf("%s\t%d\n", r->word, r->count);
	printf("%s\n", r->word);
	read(r->next);
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
		//r->next = NULL;
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
