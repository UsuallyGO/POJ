
#include <stdio.h>
#include <string.h>

#define DEBUG 1
#define MAX 500

int cows, foods, drinks;
int Graph[MAX][MAX];
int Queue[100000];
int S, T;
int cur, tail;

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

inline void EnQue(int i)
{
    Queue[tail] = i;
    tail++;
}

inline int DeQue()
{
    cur++;
    return Queue[cur-1];
}

inline int QueEmpty()
{
    if(cur >= tail)
	return 1;
    else 
	return 0;
}

int APs()
{
    int i, count;
    int visit[MAX];
    int prev[MAX];
    int seek_i;

    count = 0;
    memset(visit, 0, sizeof(visit));
    while(1)
    {
	cur = tail = 0;
	EnQue(S);
	seek_i = 0;
	visit[S] = 1;
	memset(prev, 0, sizeof(prev));
	while(!QueEmpty())
	{
	    seek_i = DeQue(); 
#if DEBUG
	    printf("seek_i:%d\n", seek_i);
#endif
	    if(seek_i == T)
		break; 

	    for(i = S; i <= T; i++)
	    {
		if(!visit[i] && Graph[seek_i][i] > 0)
		{
		    EnQue(i);
		   // if(i > foods && i < foods+cows+drinks)//i is cow
		    visit[i] = 1;
		    prev[i] = seek_i;
		}
	    }
	}
	if(seek_i != T)
	    break;
	else
	    count++;
	for(i = prev[T]; i > S; i = prev[i])
	    visit[i] = 2;
	for(i = S; i <= T; i++)
	    if(visit[i] != 2)
		visit[i] = 0;
	visit[T] = 0;
    }

    return count;
}

int main()
{
    int i, j, k, l, m;
    int tmp, res;

    S = 0;
    while(scanf("%d %d %d", &cows, &foods, &drinks) != EOF)
    {
	T = cows + foods + drinks + 1;
	memset(Graph, 0, sizeof(Graph));
	for(i = 1; i <= foods; i++)
	    Graph[S][i] = 1;
	
	for(i = 1; i <= cows; i++)
	{
	    scanf("%d %d", &j, &k);
#if DEBUG
	    printf("j:%d k:%d\n", j, k);
#endif
	    if(j == 0)
		Graph[S][foods+i] = 1;
	    else
		for(l = 1; l <= j; l++)
		{
		    scanf("%d", &tmp);
		    Graph[tmp][foods+i] = 1;
		}
	    if(k == 0)
		Graph[foods+i][T] = 1;
	    else
		for(l = 1; l <= k; l++)
		{
		    scanf("%d", &tmp);
		    Graph[foods+i][foods+cows+tmp] = 1;
		}
	}

	for(i = 1; i <= drinks; i++)
	    Graph[foods+cows+i][T] = 1;
#if DEBUG
	showGraph();
#endif
	res = APs();
	printf("%d\n", res);
    }

    return 0;
}
