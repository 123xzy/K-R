/* strcpy:copy t to s;array subscript version */
void strcpy(char *s,char *t)
{
	int i;
	
	i = 0;
	while((s[i] = t[i]) != '\0')
		i++;
}


/* 
 * strcpy_version_2
 * 
 * copy t to s;pointer version 1
 *
 */
void strcpy(char *s,char *t)
{
	while((*s = *t) != '\0'){
		s++;
		t++;
	}
}


/*
 * strcpy_version_3
 *
 * strcpy:copy t to s;pointer version 2
 * 
 */
void strcpy(char *s,char *t)
{
	while((*s++ = *t++) != '\0')
		;
}

/* 
 * strcpy_version_4
 *
 * strcpy:copy t to s;pointer version 3
 *
 */
void strcpy(char *s,char *t)
{
	while(*s++ = *t++)
		;
}
