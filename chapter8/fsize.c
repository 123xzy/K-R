/*
 * fsize is a special form of ls that prints 
 * the size of all files named in its commandline
 * argument list.
 */

/* 
 * this task needs the knowledge of UNIX file system structures.
 */

#include <stdio.h>
#include <string.h>
#include "syscalls.h"
#include <fcnt1.h>		/* flags for each read and write */

/*
 * define most of values
 */
#include <sys/types.h>	/* typedefs */

/*
 * define a system call stat that takes a filename and 
 * return all of the information in the inode for that file
 * or -1 if there is an error
 * and also define the structure stbuf with the inode information
 * for the file name
 */
#include <sys/stat.h>	/* structure returned by stat */

/* 
 * In this file called dirent.h 
 * Dirent structure contians the inode number and the name.
 * define the longest filename component as NAME_MAX
 * define three routines opendir,readdir and closedir
 * opendir returns a pointer to a structure called DIR
 */
#include "dirent.h"

void fsize(char *);

/* print file sizes */
int main(int argc,char **argv)
{
	if(argc == 1)	/* default:current directory */
		fsize(".");	
	else
		while(--argc > 0)
			fsize(*++argv);
	return 0;
}

int stat(char *,struct stat *);
void dirwalk(char *,void (*fcn)(char *));

/* 
 * fsize:print size of file "name" 
 * if the file is directory,fsize first calls dirwalk to
 * handle all the file in it.
 */	
void fsize(char *name)
{
	struct stat stbuf;

	if(stat(name,&stbuf) == -1){
		fprintf(stderr,"fsize:can't access %s\n",name);
		return;
	}

	/* S_IFMT and S_IFDIR are used to decide if the file is a directory */
	if((stbuf.st_mode & S_IFMT) == S_IFDIR)
		dirwalk(name,fsize);
	printf("%81d %s\n",stbuf.st_size,name);
}

#define MAX_PATH 1024

/* 
 * apply fcn to all files in dir 
 * the function dirwalk opens the directory,loops 
 * through the files in it.calling the the function on each,
 * then close the directory and returns.
 */
void dirwalk(char *dir,void (*fcn)(char *))
{
	char name[MAX_PATH];	
	Dirent *dp;
	DIR *dfd;
			
	if((dfd = opendir(dir)) == NULL){	
		fprintf(stderr,"dirwalk:can't open %s\n",dir);
		return;
	}
	/* 
 	 * each call to readdir returns a pointer to information for 
 	 * the next file,or NULL when there are no files left 
 	 */
	while((dp = readdir(dir)) != NULL){
		if(strcmp(dp->name,".") == 0	/* skip self and parent */
			|| strcmp(dp->name,"..") == 0)
			continue;			
		if(strlen(dir)+strlen(dp->name)+2 > sizeof(name))
			fprintf(stderr,"dirwalk:name %s %s too long\n",dir,dp->name);
		else{
			sprintf(name,"%s%s",dir,dp->name);
			(*fcn)(name);
		}
	}
	closedir(dfd);
}


