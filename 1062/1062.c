
#include <stdio.h>
#include <limits.h>

<<<<<<< HEAD
#define MAX_VERTEX	110
#define FALSE		0
#define TRUE		1

#define DEBUG		0

int matrix[MAX_VERTEX][MAX_VERTEX];
int weight[MAX_VERTEX]; //level
=======
#define MAX_VERTEX  110
#define TRUE	    1
#define FALSE	    0

typedef struct subject_t
{
    int value;
    int weight;
    int subs;
}Sub;

int matrix[MAX_VERTEX][MAX_VERTEX];
Sub array[MAX_VERTEX];
int allow[MAX_VERTEX];
>>>>>>> origin/master
int visit[MAX_VERTEX];

int Dijstra(int vertex)
{
<<<<<<< HEAD
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
=======
    int first, second;
    int last;
    int dist[MAX_VERTEX];
    int tmp;


    dist[1] = 0;
    visit[1] = TRUE;
    for(first=1; first<=vertex; first++)
	dist[first] = matrix[0][first];


    for(first=2; first<=vertex; first++)
    {
	tmp = INT_MAX;
	for(second=2; second<=vertex; second++)
	{
	   if(!visit[second]&&tmp>dist[second])
	   {
		last = second;
		tmp = dist[second];
	   }
	}
	if(tmp == INT_MAX)
	    break;

	visit[second] = TRUE;

	for(second=2; second<=vertex; second++)
	{
	   if(!visit[second]&&dist[second]>dist[last]+matrix[last][second])
		dist[second] = dist[last] + matrix[last][second];
	}
    }

    tmp = INT_MAX;
    for(first=2; first<=vertex; first++)
    {
	printf("dist[%d]:%d\n", first, dist[first]);
	if(dist[first] == INT_MAX)
	    continue;
	dist[first] = dist[first] + array[first].value;
	if(tmp > dist[first])
	    tmp = dist[first];
    }

    return tmp;
>>>>>>> origin/master
}

int main()
{
<<<<<<< HEAD
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
=======
    int limit, subjects;
    int vertex;
    int first, second;
    int tmp;
    int max_li;
    int tmp_less;
    int less;

    scanf("%d %d", &limit, &subjects);

    for(vertex=1; vertex<=subjects; vertex++)
    {
	scanf("%d %d %d", &array[vertex].value, &array[vertex].weight, &array[vertex].subs);
	for(first=0; first<array[vertex].subs; first++)
	{
	    scanf("%d", &tmp);
	    scanf("%d", &matrix[vertex][tmp]);
	}
    }

    for(first=1; first<=vertex; first++)
	matrix[0][first] = array[first].value;

    less = INT_MAX;
    for(first=1; first<=vertex; first++)
    {
	max_li = array[first].weight;
	for(second=1; second<=vertex; second++)
	{
	    if(array[second].weight>max_li || max_li-array[second].weight>limit)
	    {
		visit[second] = TRUE;
	    }
	    else
	    {
		visit[second] = FALSE;
	    }
	}

	tmp_less = Dijstra(vertex);
	if(tmp_less < less)
	    less = tmp_less;
    }

    printf("%d\n", less);

    return 0;
>>>>>>> origin/master
}
