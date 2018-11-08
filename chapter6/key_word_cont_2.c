struct key{
	char *word;
	int count;
}keytab[] = {
	"auto",0,
	"break",0,
	"case",0,
	"char",0,
	"const",0,
	"continue",0,
	"default",0,
	/* ... */
	"unsighed",0,
	"void",0,
	"while",0,
};

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 1000

struct key *binsearch(char*,struct key *,int);

/* count C keywords:pointer version */
int main()
{
	char word[MAXWORD];
	struct key *p;
	
	while(getword(word,MAXWORD) != EOF)
		if(isalpha(word[0]))
			if((p = binsearch(word,keytab,NEKYS)) >= NULL)
				p->count++;
	for(p = keytab;p < keytab + NEKYS;p++)
		if(p->count > 0)
			printf("%d %s\n",p->count,p->word);
	return 0;
}

/* binsearch:find word in tab[0]...tab[n-1] */
struct key *binsearch(char *word,struct key *tab,int n)
{
	int cond;
	struct key *low = &tab[0];
	struct key *high = &tab[n];
	struct key *mid;

	while(low < high){
		mid = low + (high-low) / 2;
		if((cond = strcmp(word,mid->word)) < 0)
			hight = mid;
		else if(cond > 0) 
			low = mid + 1;
		else 
			return mid;
	}
	return NULL;
}

/* getword:get next word or character from input */
int getword(char *word,int lim)
{
	int c,getch(void);
	void ungetch(int);
	char *w = word;
	
	while(isspace(c = getch()))
		;
	if(c != EOF)
		*w++ = c;
	if(!isalpha(c)){
		*w = '\0';
		return c;
	}
	for(;--lim > 0;w++)
		if(!isalnum(*w = getch())){
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
}







