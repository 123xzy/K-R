#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "getline.c"

#define MAXLINES 5000   /* max #lines to be sorted */
#ifndef _xzy_H

int getline1(char *line,int max);
int readlines(char *lineptr[],int nlines);
void writelines(char *lineptr[],int nlines);

void qsort(void *lineptr[],int left,int right,int (*comp)(void *,void *));

int numcmp(char *,char *);

#endif _xzy_H

