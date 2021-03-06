
#include <stdio.h>
#include <string.h>

#define DEBUG 0

#define MAX 1001
#define INI 99999

int Graph[MAX][MAX];
int House[MAX];
int Last[MAX];
int front[MAX];
int Queue[10000];
int record[MAX];

int pig_houses;
int customers;
int S, T;
int cur;
int head, tail;

inline int EnQue(int x)
{
    Queue[tail] = x;
    tail++;
}

inline int DeQue()
{
    head++; 
    return Queue[head-1];
}

inline int QueEmpty()
{
    if(head == tail)
	return 1;
    else
	return 0;
}

inline int Min(int a, int b)
{
    return a < b ? a : b;
}

int BFS()
{
    int i, j, k;
    int min;
    int visit[MAX];

//    memset(visit, 0, sizeof(visit));
    memset(record, 0, sizeof(record));
    memset(front, -1, sizeof(front));
    visit[S] = 1;
    tail = 0;
    head = 0;
    EnQue(S);
    min = INI;
    record[S] = INI;
    while(!QueEmpty())
    {
	k = DeQue();
#if DEBUG
	printf("k:%d\n", k);
#endif
	if(k == T)
	    break;

	for(i = S; i <= T; i++)
	{
	    if(!record[i] && Graph[k][i] > 0) 
	    {
		EnQue(i);
		front[i] = k;
//		visit[i] = 1;
		record[i] = Min(record[k], Graph[k][i]);
		//if(min > Graph[k][i])
		 //   min = Graph[k][i];
#if DEBUG
		printf("Graph[%d][%d]:%d min:%d\n", k, i, Graph[k][i], min);
#endif
	    }
	}
    }
    if(k != T)
	return 0;
    else 
	return 1;

//    if(k != T)
//	min = 0;
 //   return min;
}

int EK()
{
    int max;
    //int u, f;
    int u;

    max = 0;
//    while((f=BFS()) != 0)
    while(BFS())
    {
#if DEBUG
	printf("In EK(), get f:%d\n", f);
#endif
	for(u = T; u > S; u = front[u])
	{	
//	    Graph[front[u]][u] -= f;
//	    Graph[u][front[u]] += f;
	    Graph[front[u]][u] -= record[T];
	    Graph[u][front[u]] += record[T];
	}
//	max += f;
	max += record[T];
    }

    return max;
}

void ShowGraph()
{
    int i, j;

    for(i = S; i <= T; i++)
    {
	for(j = S; j <= T; j++)
	    printf("%d  ", Graph[i][j]);
	printf("\n");
    }
}

int main()
{
    int i, j, k;
    int tmp;
    int ans;

    while(scanf("%d %d", &pig_houses, &customers) != EOF)
    {
	for(i = 1; i <= pig_houses; i++)
	    scanf("%d", &House[i]);

	S = 0;
	T = customers + 1;
	memset(Last, 0, sizeof(Last));
	memset(Graph, 0, sizeof(Graph));
	for(i = 1; i <= customers; i++)
	{
	    scanf("%d", &k);
	    for(j = 1; j <= k; j++)
	    {
		scanf("%d", &tmp);	
#if DEBUG
		printf("Last[%d]:%d\n", tmp, Last[tmp]);
#endif
		if(Last[tmp] == 0)
		    Graph[S][i] += House[tmp];		    
		else
		    Graph[Last[tmp]][i] = INI;

		Last[tmp] = i;
	    }
	    scanf("%d", &Graph[i][T]);
	}

#if DEBUG
	ShowGraph();
#endif
	ans = EK();
	printf("%d\n", ans);
    }

    return 0;
}
