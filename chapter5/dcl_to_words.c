#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum {NAME,PARENS,BRACKETS};

void dcl(void);
void dirdcl(void);

int gettoken(void);
int tokentype;			/* type of last token */
char token[MAXTOKEN]; 	/* last token string */
char name[MAXTOKEN];	/* identifier name */
char datatype[MAXTOKEN];/* data typde = char,int,etc. */
char out[1000];			/* output string */

/* convert declaration to words */
int main()
{
	while(gettoken() != EOF){	/* 1st token in line */
		strcpy(datatype,token);	/* is the datatype */
		out[0] = '\0';
		dcl();					/* parse rest of line */
		if(tokentype != '\n')
			printf("syntax error\n");
		printf("%s :%s %s\n",name,out,datatype);
	}
	return 0;
}

/* undcl:convert word description to declaration 
int main()
{
	int type;
	char temp[MAXTOKEN];

	while(gettoken() != EOF){
		strcpy(out,token);
		while((type = gettoken()) != '\n')
			if(type == PARENS || type == BRACKETS)
				strcat(out,token);
			else if(type == '*'){
				sprintf(temp,"(*%s)",out);
				strcpy(out,temp);
			}else if(type == NAME){
				sprintf(temp,"%s %s",token,out);
				strcpy(out,temp);
			}else
				printf("invalid input at %s\n",token);
		printf("%s\n",out);
	}
	return 0;
}
*/

/* return next token */
int gettoken(void)
{
	int c,getch(void);
	void ungetch(int);
	char *p = token;

	while((c = getch()) == ' ' || c == '\t')
		;
	if(c == '('){
		if((c = getch()) == ')'){
			strcpy(token,"()");
			return tokentype = PARENS;
		}else{
			ungetch(c);
			return tokentype = '(';
		}	
	}else if(c == '['){
		for(*p++ = c;(/p++ = getch()) != ']';)
			;
		*p = '\0';
		return tokentype = BRACKETS;
	}else if(isaplpha(c)){
		for(*p++ = c;isalnum(c = getch());)
			*p++ = c;
		*p = '\0';
		ungetch(c);
		return tokentype = NAME;	
	}else
		return tokentype = c;
	
}
