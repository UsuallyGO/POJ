
#include <stdio.h>
#include <string.h>

#define MAX_NUM 1001
#define STR_LEN 22
#define LETTERS 30

#define TRUE 1
#define FALSE 0

#define DEBUG 0

typedef struct Edge_t
{
    int to;
    int next;
    int pos;
    int flag;
}Edge;

char Str[MAX_NUM][STR_LEN];
int Head[LETTERS];
Edge Edges[MAX_NUM];
int top;
int counter;
int In[LETTERS];
int Out[LETTERS];
int Ans[MAX_NUM];

int Cmp(const void *a, const void *b)
{
    return strcmp(a, b);
}

void Init()
{
    int index;
    
    top = 0;
    counter = 0;
    memset(Edges, 0, sizeof(Edges));
    memset(In, 0, sizeof(In));
    memset(Out, 0, sizeof(Out));
    memset(Ans, 0, sizeof(Ans));
    for(index = 0; index < LETTERS; index++)
        Head[index] = -1;
}

void AddEdge(int u, int v, int index)
{
    Edges[top].to = v;
    Edges[top].next = Head[u]; //the words start with u, arranged by a list
    Edges[top].flag = FALSE;
    Edges[top].pos = index;
    Head[u] = top++;
}

void Dfs(int start, int nums)
{
    int i;

    for(i = Head[start]; i != -1; i = Edges[i].next)
    {
        if(!Edges[i].flag)
	{
	    Edges[i].flag = TRUE;
	    Dfs(Edges[i].to, nums);
	    Ans[counter++] = Edges[i].pos;;
	}
    }
}

int Eluer()
{
    int c1, c2, c3;
    int c;
    int index;
    int start;

    c1 = c2 = c3 = 0;
    start = 0;
    for(index=0; index<LETTERS; index++)
    {
        c = In[index] - Out[index]; 
	if(c == 1)
	    c1++;
	else if(c == -1)
	{
	    start = index;
	    c2++;
	}
	else if(c != 0)
	    c3++;
    }

    if((c1+c2+c3)==0 || (c1==1 && c2==1 && c3 == 0))
        return start;
    else
        return -1;// no Eluer circuit
}

void ShowStr(int num)
{
    int index;

    for(index = 0; index < num; index++)
        printf("%s\n", Str[index]);
}

int ShowEdge(int num)
{
    int index;

    for(index = 0; index < num; index++)
    {
        printf("Edge[%d]: %s next:", index, Str[Edges[index].pos]);
	if(Edges[index].next == -1)
	    printf("-1 ");
	else
	    printf("%s", Str[Edges[Edges[index].next].pos]);
	
        printf(" to:%d\n", Edges[index].to);
    }
}

int main()
{
    int cases, num;
    int index;
    int u, v;
    int start;

    scanf("%d", &cases);
    while(cases > 0)
    {
        Init();
        scanf("%d", &num);
	for(index=0; index<num; index++)
	    scanf("%s", Str[index]);
#if DEBUG
        ShowStr(num);
#endif
	for(index = num-1; index >= 0; index--)
	{
	    u= Str[index][0] - 'a';
	    v = Str[index][strlen(Str[index])-1] - 'a';
	    AddEdge(u, v, index);
	    Out[u]++;
	    In[v]++;
	}
        qsort(Str, num, STR_LEN, Cmp);	
#if DEBUG
        ShowStr(num);
	ShowEdge(num);
#endif
	start = Eluer();
	if(start < 0)
	{
	    printf("***\n");
	}
	else
	{
	    Dfs(start, num);
#if DEBUG
        for(index = 0; index < num; index++)
	    printf("%d ", Ans[index]);
	printf("\n");
#endif
	for(index = num-1; index >= 0; index--)
	{
	    if(index != 0)
	        printf("%s.", Str[Ans[index]]);
	    else
	        printf("%s\n", Str[Ans[index]]);
	}
	}
        cases--;
    }

    return 0;
}
