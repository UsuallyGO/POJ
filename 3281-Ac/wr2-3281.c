
#include <stdio.h>
#include <string.h>

#define DEBUG 1
#define MAX 200

int Graph[MAX][MAX];
int transport[MAX];
int Queue[10000];
int cows, foods, drinks;
int cur, tail;
int S, T;

void showGraph()
{
    int i, j, k;

    printf("    S   ");
    for(i = 1; i <= foods; i++)
	printf("F%-2d ", i);
    for(i = 1; i <= cows; i++)
	printf("C%-2d ", i);
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
	    printf("C%-2d ", i-foods);
	else if(i <= foods+cows+drinks)
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

inline void EnQue(int x)
{
    Queue[tail++] = x;
}

inline int DeQue()
{
    return Queue[cur++];
}

int QueEmpty()
{
    if(cur >= tail)
	return 1;
    else
	return 0;
}

int EKs()
{
    int visit[MAX];
    int prev[MAX];
    int i, seek_i;
    int max, flow;

    max  = 0;
    flow = 1; //in this problem, flow is always 1
    //memset(visit, 0, sizeof(visit));
    //memset(prev, 0, sizeof(prev));
    while(1)
    {
	memset(visit, 0, sizeof(visit));
	memset(prev, 0, sizeof(prev));

	cur = tail = 0;
	visit[S] = 1;
	EnQue(S);
	seek_i = 0;
	while(!QueEmpty())
	{
	    seek_i = DeQue();
#if DEBUG
	    printf("seek_i :%d\n",seek_i);
#endif
	    if(seek_i == T)
		break;

	    for(i = S; i <= T; i++)
	    {
		if(!visit[i] && Graph[seek_i][i] > 0)
		{
		    EnQue(i);
		    visit[i] = 1;
#if DEBUG
		    printf("visit[%d] = 1\n", i);
#endif
		    prev[i] = seek_i;
		}
	    }
	}

	if(seek_i != T)
	    break;
	
	for(i = T; i > S; i = prev[i])
	{
	    Graph[prev[i]][i] -= flow;
	    Graph[i][prev[i]] += flow;
	}
	max++;
    }

    return max;
}

int main()
{
    int i, j, k, l, m;
    int tmp, res;

    while(scanf("%d %d %d", &cows, &foods, &drinks) != EOF)
    {
	S = 0;
	T = cows + foods + drinks + 1;
	memset(transport, 0, sizeof(transport));

	for(i = 1; i <= foods; i++)
	    Graph[S][i] = 1;

	for(i = 1; i <= cows; i++)
	{
	    scanf("%d %d", &j, &k);
	    if(j == 0)
		Graph[S][cows+i] = 1;
	    else
	    {
		for(l = 1; l <=j; l++)
		{
		    scanf("%d", &tmp);
		    if(!transport[tmp])
		    {
			transport[tmp] = foods + i;
			Graph[tmp][foods+i] = 1;
		    }
		    else
			Graph[transport[tmp]][foods+i] = 1;
		}
	    }

	    if(k == 0)
		Graph[cows+i][T] = 1;
	    else
	    {
		for(l = 1; l <= k; l++)
		{
		    scanf("%d", &tmp);
		    if(!transport[foods+cows+tmp])
		    {
			transport[foods+cows+tmp] = foods+i;
			Graph[foods+i][foods+cows+tmp] = 1;
		    }
		    else
			Graph[foods+i][transport[foods+cows+tmp]] = 1;
		}
	    }

	}
	for(i = cows+foods+1; i <= cows+foods+drinks; i++)
	    Graph[i][T] = 1;
#if DEBUG
	showGraph();
#endif
	res = EKs();
	printf("%d\n", res);
    }

    return 0;
}
