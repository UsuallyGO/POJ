
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define DEBUG 1

typedef struct Path_t
{
    int source;
    int end;
    int value;
}Path;

typedef struct Farm_t
{
    int fields;
    int paths;
    int worms;
}Farm;

#if DEBUG
void show(Path *p, int nums)
{
    int index;
    
    for(index=0; index<nums; index++)
    {
	printf("%d-%d:%d\n", p[index].source, p[index].end, p[index].value);
    }
}
#endif

int Bellman_Ford(Path *p, int vertex, int edges)
{
    int *dist;
    int first, second;

    dist = (int*)malloc(sizeof(int)*(vertex+1));
    memset(dist, INT_MAX, sizeof(int)*vertex);

    dist[1] = INT_MIN;
   for(first=1; first<vertex-1; first++)
	for(second=0; second<edges; second++)
	{
	    if(dist[p[second].end] > (dist[p[second].source] + p[second].value))
		dist[p[second].end] = dist[p[second].source] + p[second].value;
	}
    
    for(first=0; first<edges; first++)
	if(dist[p[first].end] > (dist[p[second].source] + p[second].value))
	{
	    free(dist);
	    return 0;
	}
    
    free(dist);
    return 1;
}

int find(Path *p, int nums, int x, int y)
{
    int index = 0;

    for(; index<nums; index++)
	if(p[index].source==x && p[index].end==y)
	    return index;
    
    return -1;
}

int main()
{
    int farms;
    int index;
    int first;
    int edges;
    int nums;
    int result;
    
    Farm fp;
    Path *pp;

    scanf("%d", &farms);

    index = 0;
    while(index < farms)
    {
	memset(&fp, 0, sizeof(fp)); 
	scanf("%d %d %d", &fp.fields, &fp.paths, &fp.worms);
	pp = (Path*)malloc(sizeof(Path)*(fp.paths*2+fp.worms));
	edges = 0;

	for(first=0; first<fp.paths; first++, edges++)
	    scanf("%d %d %d", &pp[edges].source, &pp[edges].end, &pp[edges].value); 
	    
	for(first=0; first<fp.paths; first++, edges++)
	{
	    pp[edges].source = pp[edges-fp.paths].end;
	    pp[edges].end = pp[edges-fp.paths].source;
	    pp[edges].value = pp[edges-fp.paths].value;
	}

	for(first=0; first<fp.worms; first++)
	{
	    scanf("%d %d %d", &pp[edges].source, &pp[edges].end, &pp[edges].value);
	    result = find(pp, edges, pp[edges].source, pp[edges].end);
	    if(result >= 0)
	    {
		pp[result].value = pp[edges].value*(-1);
		continue;
	    }
	    else
	    {
		pp[edges].value = pp[edges].value*(-1);
		edges++;
	    }
	}

#if DEBUG	
	show(pp, edges);
#endif 
	result = Bellman_Ford(pp, fp.fields, edges);
	if(result)
	    printf("NO\n");
	else
	    printf("YES\n");
	
	free(pp);
	index++;
    }

    return 0;
}
