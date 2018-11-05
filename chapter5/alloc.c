/*
 * rudimentary storage allocator 
 *
 * this easiest implementation is to have alloc hand
 * out pieces of a large character array.
 *
 * in practical implementations,the array may not even 
 * hava a name.
 *
 */

#define ALLOCSIZE 10000 	/* size of available space */

static char allocbuf[ALLOCSIZE];	/* storage for alloc */
static char *allocp = allocbuf;		/* next free position */

char *alloc(int n)	/* return pointer to n characters */
{
	if((allocbuf + ALLCOSIZE - allocp) >= n){	/* if fits */
		allocp += n;
		return allocp - n; 	/* old p */
	}
	else	/* not enough room */
		return 0;
}

void afree(char *p)	/* free storage pointed to by p */
{
	if(p >= allocbuf && p < allocbuf + 	ALLOCSIZE)
		allocp = p;
}
