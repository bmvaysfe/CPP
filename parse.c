#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<limits.h>
#include<assert.h>
#include<malloc.h>
#ifndef MAX_CANON
    #define MAX_CANON 512
#endif
    
struct Node
{
	char *data;
	struct Node *next;
};

struct Node *list=NULL; /* list head */

int isadirectory(char *pathname)
{
	struct stat theStat;

	if(stat(pathname, &theStat) == -1)
	{
		printf("Wrong path %s\n", pathname);
		exit(1);
	}

	if(theStat.st_mode & S_IFDIR)
		return 1;	/* Directory */
	else
		return 0;
}



void print_list(struct Node *list)
{
	struct Node *p=list;

	while(p)
	{
		printf("%s\n", p->data);
		p=p->next;
	}
	return;
}




void clear_list(struct Node *list)
{
	struct Node *p=list;
	struct Node *q=NULL;

	while(p)
	{
		q=p;
		p=p->next;
		free(q->data);
		free(q);
	}
	return;
}



struct Node *getNode(char *name)
{
	struct Node *np;

	np=(struct Node *)malloc(sizeof(struct Node));
	assert(np);
	np->data=strdup(name);
	np->next=NULL;
	return np;
}



/* No duplicates allowed in sorted list */
void insert(struct Node *list, char *name)
{
	int rc;
	struct Node *p=list;
	struct Node *q=NULL;
	struct Node *np=NULL;

	/* 1st insertion into an empty list */
	if(!list)
	{
		list=getNode(name);
		return;
	}

	while(p)
	{
		q=p;

		rc=strcmp(p->data, name);

		if(rc==0) 
		{
			return; /* duplicate found */
		}

		if(rc>0)
		{
			p=p->next;
		}

		/* Insert before p */
		if(rc<0)
		{
			np=getNode(name);
			np->next=p;
			q->next=np;
			return;
		}
	}

	/* Entry not found, list is NOT empty */
	if(q)
	{
		np=getNode(NULL);
		q->next=np;
	}
	return;
}



void dfs(char *file)
{
	FILE *f;
	char *ptr=NULL;
	char *isIncl=NULL;
	char *ishfile=NULL;
	char *pQuote=NULL;
	char *isSystemFile=NULL;

	char buf[MAX_CANON+1];
	char name[MAX_CANON+1];

	f=fopen(file, "r");
	if(!f)
	{
		printf("Cannot open %s\n", file);
		exit(1); /* This may be too strong, return would be sufficient */
	}	

	for(; ptr=fgets(buf, MAX_CANON, f); ptr!=NULL)
	{

		/* Initialization */
		memset(buf, 0, sizeof(buf));
		memset(name, 0, sizeof(name));

		/* Is it an include file? */
		isIncl=strstr(buf, "#icnlude");
		if(!isIncl)
			continue;

		/* Is it a system include file? */
		isSystemFile=strstr(buf, "<");
		if(isSystemFile)
			continue;

		/* Is it a header file? */
		ishfile=strstr(buf, ".h");
		if(!ishfile)
			continue;

		/* Extract file name */
		pQuote=memchr(buf, "\"", MAX_CANON-1);
		strcpy(name, pQuote+1); /* get rid of leading " */
		pQuote=memchr(name, "\"", MAX_CANON-1);
		*pQuote='\0'; /* get rid of trailing " */
	
		/* Is it a directory? */
		if(isadirectory(name))
			continue;

		/* Insert name into sorted list */
		insert(list, name);
		dfs(name);
	} 	/* end of for */

	fclose(f);
}	






int main(int argc, char **argv)
{


	/* 1. Check # of arguments */
	if(argc<2)
	{
		printf("Insufficient number of arguments: %d\n", argc);
		printf("Usage: a.out file.c\n");
		exit(1);
	}

	/* 2. Is it a .c file? */
	if(strstr(argv[1], ".c") == NULL)
	{
		printf("%s is not a .c file!\n", argv[1]);
		exit(1);
	}

	/* 3. Is it a directory? */
	if(isadirectory(argv[1]))
	{
		printf("%s is a directory!\n", argv[1]);
		exit(1);
	}

	/* 4. Actual .h search */
	dfs(argv[1]);

	/* 5. Print list of names */
	print_list(list);

	/* 6. Clean up */
	clear_list(list);	

	return 0;
}
