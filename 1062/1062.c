
#include <stdio.h>
#include <limits.h>

#define MAX_VERTEX	110
#define FALSE		0
#define TRUE		1

#define DEBUG		0

int matrix[MAX_VERTEX][MAX_VERTEX];
int weight[MAX_VERTEX]; //level
int visit[MAX_VERTEX];

int Dijstra(int vertex)
{
	int dist[vertex];
	int first, second;
	int less, prev;

	dist[0] = 0;
	for(first=1; first<=vertex; first++)
	{
		if(matrix[0][first])
			dist[first] = matrix[0][first];
		else
			dist[first] = INT_MAX;
#if DEBUG
		printf("dist[%d]:%d\n", first, dist[first]);
#endif
	}


	for(first=1; first<=vertex; first++)
	{
		less = INT_MAX;
		//find the shortest vertex
		for(second=1; second<=vertex; second++)
		{
			if(dist[second]<less && !visit[second])
				prev = second;
		}
#if DEBUG
		printf("prev:%d dist[%d]:%d\n", prev, prev, dist[prev]);
#endif
		visit[prev] = TRUE;

		//from shortest vertex, try to update dist[]
		for(second=1; second<=vertex; second++)
		{
			if(!visit[second] && dist[second]>dist[prev]+matrix[prev][second] && matrix[prev][second]!=0)
				dist[second] = dist[prev] + matrix[prev][second];
		}
	}

	return dist[1];
}

int main()
{
	int m, n;
	int index;
	int first, second;
	int tmp;
	int vertex;
	int less;

	scanf("%d %d", &m, &n);

	vertex = 0;
	for(index=1; index<=n; index++)
	{
		vertex++;
		scanf("%d", &matrix[0][index]);		
		scanf("%d", &weight[vertex]);
		scanf("%d", &tmp);

		for(first=0; first<tmp; first++)
		{
			scanf("%d", &second);
			scanf("%d", &matrix[vertex][second]);
			matrix[second][vertex] = matrix[vertex][second];
		}
	} //end get input

	//level limit
	less = INT_MAX;
	for(first=1; first<=vertex; first++)//every vertex to be base level
	{
		index = weight[first];//base
		for(second=1; second<=vertex; second++)
		{
			if(weight[second]>index || index-weight[second]>m)//m is the limit
					visit[second] = TRUE;
			else
					visit[second] = FALSE;
		}

		tmp = Dijstra(vertex);
#if DEBUG
		printf("tmp:%d\n", tmp);
#endif
		if(tmp < less)
			less = tmp;
	}

	printf("%d\n", less);

	return 0;
}
