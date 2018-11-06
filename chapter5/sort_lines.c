#include <stdio.h>
#include <string.h>

#define MAXLINES 5000	/* max #lines to be sorted */

/* 
 * the array of MAXLINES elements,each element of which
 * is a pointer to a char.
 *
 */
char *lineptr[MAXLINES];

int readlines(char *lineptr[],int nlines);
void writelines(char *lineptr[],int nlines);

void qsort(char *lineptr[],int left,int right);

/* sort input lines */
int main()
{
	int nlines; 	/* number of input lines read */
	
	if((nlines = readlines(lineptr,MAXLINES)) >= 0){
		qsort(lineptr,0,nlines-1);
		writelines(lineptr,nlines);
		return 0;
	}else{
		printf("error:input too big to sort\n");
		return 1;
	}
}


