
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define DEBUG 0

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

//#if DEBUG
void show(Path *p, int nums)
{
    int index;
    
    for(index=0; index<nums; index++)
    {
	printf("%d-%d:%d\n", p[index].source, p[index].end, p[index].value);
    }
}
//#endif

int Bellman_Ford(Path *p, int vertex, int edges)
{
    int *dist;
    int first, second;

    dist = (int*)malloc(sizeof(int)*(vertex+1));
    for(first=0; first<vertex+1; first++)
//	dist[first] = INT_MAX;
	dist[first] = 0x3f3f3f3f;
#if DEBUG
    printf("Bellman_ford vertex:%d edges:%d\n", vertex, edges);
#endif

    dist[1] = 0;
    for(first=1; first<vertex; first++)
	for(second=0; second<edges; second++)
	{
#if DEBUG
	    printf("End dist[%d]:%d\n", p[second].end, dist[p[second].end]);
	    printf("Source dist[%d]:%d\n", p[second].source, dist[p[second].source]);
#endif
	    if(dist[p[second].end] > (dist[p[second].source] + p[second].value))
		dist[p[second].end] = dist[p[second].source] + p[second].value;
	}
    
    for(first=0; first<edges; first++)
    {	    	    
#if DEBUG
	printf("dist[%d]:%d  %d+%d\n", p[first].end, dist[p[first].end], dist[p[first].source], p[first].value);
#endif
	if(dist[p[first].end] > (dist[p[first].source] + p[first].value))
	{
	    free(dist);
	    return 0;
	}
    }
#if DEBUG
    for(first=1; first<=vertex; first++)
    {
	printf("dist[%d]:%d\n", first, dist[first]);
    }
#endif
    
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

	for(first=0; first<fp.paths; first++)
	{
	    scanf("%d %d %d", &pp[edges].source, &pp[edges].end, &pp[edges].value); 
//	    result = find(pp, edges, pp[edges].source, pp[edges].end);
//	    if(result >= 0)
//	    {
#if DEBUG
		printf("source:%d  end:%d value:%d\n", pp[edges].source, pp[edges].end, pp[edges].value);
		printf("result source:%d end:%d value:%d\n", pp[result].source, pp[result].end, pp[result].value);
#endif
		//if(pp[result].value > pp[edges].value)
	//	{
//		    pp[result].value = pp[edges].value;
//		    result = find(pp, edges, pp[edges].end, pp[edges].source);
//		    pp[result].value = pp[edges].value;
	//	}
//	    }
//	    else
//	    {
//		if(pp[edges].source != pp[edges].end)
//		{
		    edges++;
		    pp[edges].source = pp[edges-1].end;
		    pp[edges].end = pp[edges-1].source;
		    pp[edges].value = pp[edges-1].value;
//		}
		edges++;
//	    }
#if DEBUG
	    printf("Pre pp[%d]  %d  %d  %d\n", edges-1, pp[edges-1].source, pp[edges-1].end, pp[edges-1].value);
#endif
	}

	for(first=0; first<fp.worms; first++)
	{
	    scanf("%d %d %d", &pp[edges].source, &pp[edges].end, &pp[edges].value);
	    result = find(pp, edges, pp[edges].source, pp[edges].end);
	    if(result >= 0)
		pp[result].value = pp[edges].value*(-1);
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
#if DEBUG
	printf("After Bellman result:%d\n", result);
#endif
	if(result)
	    printf("NO\n");
	else
	    printf("YES\n");
	
	free(pp);
	index++;
    }

    return 0;
}
