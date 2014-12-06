
#include <stdio.h>
#include <string.h>

#define MAX_NUM 500

int Graph[MAX_NUM][MAX_NUM];
int Matrix[MAX_NUM][MAX_NUM];
int Visited[MAX_NUM];
int Source[MAX_NUM];

int Hungary(int u, int m)
{
    int index;

    for(index=1; index<=m; index++)
    {
	if(!Visited[index] && Matrix[u][index])
	{
	    Visited[index] = 1;
	    if(!Source[index] || Hungary(Source[index], m))
	    {
		Source[index] = u;
		return 1;
	    }
	}
    }

    return 0;
}

int main()
{
    int cases;
    int n, m;
    int index;
    int first, second;
    int counter;
    char c;
    int result;
    int tmpx, tmpy;

    scanf("%d", &cases);
    do
    {
	if(cases == 0)
	    break;
	cases--;

	scanf("%d %d", &n, &m);
	memset(Matrix, 0, sizeof(Matrix));
	memset(Source, 0, sizeof(Source));
	memset(Graph, 0, sizeof(Graph));

	counter = 1;
	for(first=1; first<=n; first++)
	{
	    for(second=1; second<=m; second++)
	    {
		scanf("%c", &c);
		if(c == '*')
		{
		    printf("first:%d second:%d couner:%d\n", first, second, counter);
		    Graph[first][second] = counter++;
		}
	    }
	}

	for(first=1; first<=n; first++)
	    for(second=1; second<=m; second++)
		if(!Graph[first][second])
		{
		    tmpx = first - 1;
		    tmpy = second;
		    if(tmpx > 0)
		    {
			if(!Graph[tmpx][tmpy])
			    Matrix[Graph[first][second]][Graph[first][second]] = 1;
		    }

		    tmpx = first;
		    tmpy = second + 1;
		    if(second<=m)
		    {
			if(!Graph[tmpx][tmpy])
			    Matrix[Graph[first][second]][Graph[first][second]] = 1;
		    }

		    tmpx = first + 1;
		    tmpy = second;
		    if(tmpx <= n)
		    {
			if(!Graph[tmpx][tmpy])
			    Matrix[Graph[first][second]][Graph[first][second]] = 1;
		    }

		    tmpx = first;
		    tmpy = second-1;
		    if(tmpy > 0)
		    {
			if(!Graph[tmpx][tmpy])
			    Matrix[Graph[first][second]][Graph[first][second]] = 1;
		    }
		}

	counter--;
	printf("counter:%d\n", counter);
	result = 0;
	for(index=1; index<=counter; index++)
	{
	    memset(Visited, 0, sizeof(Visited));
	    if(Hungary(index, counter))
		result++;
	}
	printf("result:%d\n", result);
	result = counter/2 - result;

	printf("%d\n", result);
    }while(1);

    return 0;
}
