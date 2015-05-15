
#include <stdio.h>
#include <string.h>

#define DEBUG 0
#define MAX 505

int Graph[MAX][MAX];
int Queue[10000];
int cows, foods, drinks;
int S, T;
int cur, tail;

void showGraph()
{
    int i, j, k;

    printf("    S   ");
    for(i = 1; i <= foods; i++)
	printf("F%-2d ", i);
    for(i = 1; i <= cows; i++)
	printf("L%-2d ", i);
    for(i = 1; i <= cows; i++)
	printf("R%-2d ", i);
    for(i = 1; i <= drinks; i++)
	printf("D%-2d ", i);
    printf("T\n");
    for(i = S; i <= T; i++)
    {
	if(i == S)
	    printf("S   ");
	else if(i <= foods)
	    printf("F%-2d ", i);
	else if(i <= foods+cows)
	    printf("L%-2d ", i-foods);
	else if(i <= foods+2*cows)
	    printf("R%-2d ", i-foods-cows);
	else if(i <= foods+2*cows+drinks)
	    printf("D%-2d ", i-foods-cows);
	else
	    printf("T   ");
	for(j = S; j <= T; j++)
	{
	    printf("%-3d ", Graph[i][j]);
	}
	printf("\n");
    }
}

inline int DeQue()
{
    return Queue[cur++];
}

inline void EnQue(int x)
{
    Queue[tail++] = x;
}

inline int QueEmpty()
{
    if(cur >= tail)
	return 1;
    else
	return 0;
}


int EK()
{
    int visit[MAX];
    int prev[MAX];
    int i, seek_i;
    int max, flow;

    max = 0;
    flow = 1;
    while(1)
    {
	memset(visit, 0, sizeof(visit));
	memset(prev, 0, sizeof(prev));

	tail = cur = 0;
	visit[S] = 1;
	EnQue(S);
	while(!QueEmpty())
	{
	    seek_i = DeQue();
#if DEBUG
//	    printf("seek_i:%d\n", seek_i);
#endif
	    if(seek_i == T)
		break;

	    for(i = S; i <= T; i++)
	    {
		if(!visit[i] && Graph[seek_i][i] > 0)
		{
		    EnQue(i);
		    visit[i] = 1;
		    prev[i] = seek_i;
		}
	    }
	}

	if(seek_i != T)
	    break;
	
	for(i = T; i > S; i = prev[i])
	{
#if DEBUG
	    printf("%d-->", i);
#endif
	    Graph[prev[i]][i] -= flow;
	    Graph[i][prev[i]] += flow;
	}
#if DEBUG
	    printf("\n");
#endif

	max += flow;
    }

    return max;
}

int main()
{
    int i, j, k, l, m;
    int tmp, ans;

    while(scanf("%d %d %d", &cows, &foods, &drinks) != EOF)
    {
	S = 0;
	T = 2*cows + foods + drinks + 1;
	memset(Graph, 0, sizeof(Graph));

	for(i = 1; i <= foods; i++)
	    Graph[S][i] = 1;
	for(i = 1; i <= drinks; i++)
	    Graph[foods+2*cows+i][T] = 1;

	for(i = 1; i <= cows; i++)
	{
	    scanf("%d %d", &j, &k);
#if DEBUG
	    printf("j:%d k:%d\n", j, k);
#endif
	    if(j == 0)//no food, S links to left cow[i]
	;//	Graph[S][foods+i] = 1;
	    else
	    {
		for(l = 1; l <= j; l++)
		{
		    scanf("%d", &tmp);
		    Graph[tmp][foods+i] = 1;
		}
	    }
	    
	    Graph[foods+i][foods+cows+i] = 1;//left cow to right cow
	
	    if(k == 0)//no drinks, right cow[i] links to T 
	;//	Graph[foods+cows+i][T] = 1;
	    else
	    {
		for(l = 1; l <=k; l++)
		{
		    scanf("%d", &tmp);
		    Graph[foods+cows+i][foods+2*cows+tmp] = 1;
		}
	    }
	}
#if DEBUG
	showGraph();
#endif
	ans = EK();
	printf("%d\n", ans);
    }

    return 0;
}
