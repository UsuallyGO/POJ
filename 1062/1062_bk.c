
#include <stdio.h>
#include <limits.h>

#define MAX_VERTEX	110
#define TRUE		1
#define FALSE		2
#define BIGGER		0
#define LESS		1
#define WHATEVER	2

typedef struct subject_t
{
	int value;
	int weight;
	int subs;
	int borl;
}Subject;

int dist[MAX_VERTEX];
int path[MAX_VERTEX];
Subject array[MAX_VERTEX];
int matrix[MAX_VERTEX][MAX_VERTEX];

void Dijstra(int arr[][MAX_VERTEX],int vertex)
{
	int first, second;
	int visit[MAX_VERTEX];
	int min;
	int prev;

	dist[1] = 0;
	path[1] = 1;
	visit[1] = TRUE;

	for(first=2; first<=vertex; first++)
	{
		if(arr[1][first]>0)
		{
			dist[first] = arr[1][first];
			path[first] = 1;
		}
		else
		{
			dist[first] = INT_MAX;
			path[first] = -1;
		}

		visit[first] = FALSE;
	}

	for(first=2; first<=vertex; first++)
	{
		min = INT_MAX;
		for(second=2; second<=vertex; second++)
		{
			if(visit[second]==FALSE && dist[second]<min)
			{
				min = dist[second];
				prev = second;
			}
		}

		visit[prev] = TRUE;
		for(second=1; second<=vertex; second++)
		{
			if(visit[second]==FALSE && arr[prev][second]>0 && (dist[prev]+arr[prev][second])<dist[second])
			{
				dist[second] = min + arr[prev][second];
				path[second] = prev;
			}
		}
	}
}

void check(int vertex)
{
	int first;
	int min, index;

	min = INT_MAX;
	index = 1;
	for(first=2; first<=vertex; first++)
	{
	//	printf("To %d, distance:%d\n", first, dist[first]);
		if(dist[first]!=INT_MAX && ((dist[first]+array[first].value)<min))
		{
			min = dist[first] + array[first].value;
			index = first;
		}
	}

	printf("%d\n", min);
}


int main()
{	
	int  limit, subjects;
	int first, second;
	int tmp;
	scanf("%d %d", &limit, &subjects);

	for(first=1; first<=subjects; first++)
	{
		scanf("%d %d %d", &array[first].value, &array[first].weight, &array[first].subs);
		for(second=1; second<=array[first].subs; second++)
		{
			scanf("%d", &tmp);
			scanf("%d", &matrix[first][tmp]);
		}
	}

	array[1].borl = WHATEVER;
	for(first=1; first<=subjects; first++)
	{
		for(second=1; second<=subjects; second++)
		{
			if(array[first].borl == BIGGER)
			{
				if(array[second].weight < array[first].weight)
					matrix[first][second] = 0;
				else if(array[second].weight == array[first].weight)
					 array[second].borl = WHATEVER;
				else
					array[second].borl = LESS;	
			}
			else if(array[first].borl == LESS)
			{
				if(array[second].weight > array[first].weight)
					matrix[first][second] = 0;
				else if(array[second].weight == array[first].weight)
					array[second].borl = WHATEVER;
				else
					array[second].borl = BIGGER;
			}
			else
			{
				if(array[second].weight > array[first].weight)
					array[second].borl = LESS;
				else if(array[second].weight < array[first].weight)
					array[second].borl = BIGGER;
				else
					array[second].borl = WHATEVER;
			}

			if(abs(array[first].weight-array[second].weight) > limit)
			{
				if(matrix[first][second]>0)
					matrix[first][second] = 0;
			}
		}
	}

	Dijstra(matrix, subjects);
	check(subjects);

	return 0;
}
