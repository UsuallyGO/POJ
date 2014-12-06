
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN  100

typedef struct Person_t
{
    char    name[MAX_LEN];
    struct Person_t	*next;
}Person;

typedef Person*	Link;
Link	Head;
Link	Tail;

int AddNode(Person to_add)
{
    Link    pn;

    pn = (Link)malloc(sizeof(Person));
    memcpy(pn, &to_add, sizeof(Person));

     if(Tail == NULL)
     {
	Head=Tail=pn;
     }
     else
     {
	Tail->next = pn;
	Tail = pn;
     }

     pn->next = Head;

   return 0;
}

void Check(w, s)
{
    Link pn;
    Link prev;
    int counter;
    int c;

    pn = Head;
    prev = Tail;

    for(counter=0; counter<w-1; counter++)
    {
	prev = pn;
	pn = pn->next;
    }

    while(pn != NULL)
    {
	for(counter=1; counter<s; counter++)
	{
	    prev = pn;
	    pn = pn->next;
	}
	printf("%s\n", pn->name);

	if(prev != pn)
	{
	    prev->next = pn->next;
	    free(pn);
	    pn = prev->next;
	}
	else
	{
	   free(pn);
	   pn = NULL;
	}
    }
    Head = Tail = NULL;
}

void DestroyLink()
{
    Link pn;
    Link tmp;

    if(Head==NULL)
	return;

    pn = Head;
    Head = NULL;
    do
    {
	tmp = pn;
	if(tmp == Tail)
	    pn = NULL;
	else
	    pn = pn->next;
	free(tmp);
    }while(pn != NULL);
    Tail = NULL; 
}

void Show()
{
    Link pn;

    if(Head == NULL)
	return ;

    pn = Head;
    do
    {
	printf("%s-->", pn->name);
	pn = pn->next;
    }while(pn != Head);

    printf("\n");
}

int main()
{
    Person tmp;
    int  n;
    int index;
    int w,s;
    char c;

    tmp.next = NULL;
    while(scanf("%d", &n)!=EOF)
    {
	Head = Tail = NULL;
	for(index=0; index<n; index++)
	{
	    scanf("%s", tmp.name);	
	    AddNode(tmp);
	}
	scanf("%d%c%d", &w,&c,&s);
	//Show();
	Check(w, s);
	//DestroyLink();
    }

    return 0;
}
