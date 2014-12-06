
#include <stdio.h>
#include <string.h>

#define DEBUG		0
#define MAX_VERTEX	10000
#define MAX_LENGTH	40

typedef struct Edge_t
{
	int x;
	int y;
	double rate;
}Edge;

char names[MAX_VERTEX][MAX_LENGTH];
double dist[MAX_VERTEX];
Edge eArr[MAX_VERTEX];

int Bellman_Ford(int edges)
{
	int k;
	int first, second;

	for(first=1; first<=edges; first++)
			dist[first] = 0;

	dist[1] = 1;

	for(k=2; k<=edges; k++)
	{
		for(first=0; first<edges; first++)
		{
			if(dist[eArr[first].y] < dist[eArr[first].x]*eArr[first].rate)
				dist[eArr[first].y] = dist[eArr[first].x]*eArr[first].rate;
		}
	}
#if DEBUG
	printf("\n");
	for(first=0; first<edges; first++)
		printf("dist[%d]:%lf\n", first, dist[first]);

	printf("\n");
#endif
	for(first=0; first<edges; first++)
	{
#if DEBUG
		printf("dist[%d]:%lf dist[%d]*%lf:%lf\n", eArr[first].y,
							dist[eArr[first].y], eArr[first].x, eArr[first].rate,
							dist[eArr[first].x]*eArr[first].rate);
#endif
		if(dist[eArr[first].y] < dist[eArr[first].x]*eArr[first].rate)
				return -1;
	}

	return 0;
}

int FindName(char name[], int n)
{
	int index;

	for(index=1; index<=n; index++)
		if(!strcmp(names[index], name))
			return index;

	printf("Can't find name %s\n", name);
	return -1;
}
#if DEBUG
void ShowEdges(int vetex)
{
	int index;

	for(index=0; index<vetex; index++)
		printf("%d->%d:%lf\n", eArr[index].x, eArr[index].y, eArr[index].rate);
}
#endif

int main()
{
	int n;
	int index;
	int edges;
	int first, second;
	int counter;
	char tmp[MAX_LENGTH];
	double tr;

	counter = 0;
	do
	{
		counter++;
		scanf("%d", &n);
		if(!n)
			break;

		for(index=1; index<=n; index++)
			scanf("%s", names[index]);

		scanf("%d",&index);
		for(edges=0; edges<index; edges++)
		{
			scanf("%s", tmp);
			eArr[edges].x = FindName(tmp, n);
			scanf("%lf", &eArr[edges].rate);
			scanf("%s", tmp);
			eArr[edges].y = FindName(tmp, n); 
		}

#if DEBUG
		ShowEdges(edges);
#endif 

		printf("Case %d: ", counter);
		if(Bellman_Ford(edges) < 0)
			printf("Yes\n");
		else
			printf("No\n");

	}while(1);

	return 0;
}
