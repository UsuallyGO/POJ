
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Edge_t 
{
    int source;
    int dest;
    double rate;
    double com;
}Edge;

void DistInitialize(double *p, int len)
{
    int index;

    for(index=0; index<len; index++)
	p[index] = 0;
}

int Bellman_Ford(Edge *p, int num, double *dist, int pots)
{
    int first, second;
    double tmp;


    for(first=1; first< pots; first++)
    {
	for(second=0; second<num; second++)
	{
	    tmp = (dist[p[second].source] - p[second].com)*p[second].rate;
	    if(dist[p[second].dest] < tmp)
		dist[p[second].dest] = tmp;
	}
    }

    for(second=0; second<num; second++)
    {
	tmp = (dist[p[second].source] - p[second].com)*p[second].rate;
	if(dist[p[second].dest] < tmp)
	    return 1;
    }

    return 0;
}

int main()
{
    int points, currs, ori;
    double value;
    int edges;
    int index;
    Edge *eArray;
    double *dist;

    scanf("%d %d %d %lf", &points, &currs, &ori, &value);
    
    index = 0;
    edges = 0;
    eArray = (Edge*) malloc(sizeof(Edge)*currs*2);
    dist = (double *) malloc(sizeof(double)*points);
    while(currs > 0)
    {
	scanf("%d %d", &eArray[edges].source, &eArray[edges].dest);
	scanf("%lf %lf", &eArray[edges].rate, &eArray[edges].com);
	edges++;

	eArray[edges].source = eArray[edges-1].dest;
	eArray[edges].dest = eArray[edges-1].source;
	scanf("%lf %lf", &eArray[edges].rate, &eArray[edges].com);
	edges++;

	currs--;	
    }

//    memset(dist, 0, sizeof(double)*points);
    DistInitialize(dist, points);
    dist[ori] = value;

    index = Bellman_Ford(eArray, edges, dist, points);
    if(index)
	printf("YES\n");
    else
	printf("NO\n");

    return 0;
}
