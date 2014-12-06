
#include <stdio.h>
#include <limits.h>

#define MAX_NUM  501

typedef struct Edge_t
{
    int u;
    int v;
    int w;
    int sign;
}Edge;

int Matrix[MAX_NUM][MAX_NUM];
int Dist[MAX_NUM];
Edge Arr[MAX_NUM*MAX_NUM];
int Set[MAX_NUM];

int Prim(int n, int m)
{
    int max;
    int min, u;
    int index;
    int first, second;
    Dist[0] = 1;
    Set[0] = 1;

    for(index=1; index<n; index++)
	Dist[index] = Matrix[0][index];

    max = 0;
    for(index=1; index<n; index++)
    {
	min = INT_MAX;
	for(first=1; first<n; first++)
	{
	    if(Set[first]!=1 && Dist[first]<min && Dist[first]>0)
	    {
		min = Dist[first];
		u = first;
	    }
	}

	Set[u] = 1;
	if(max < min)
	    max = min;
	
	for(first=1; first<n; first++)
	{
	    if(Dist[first]>Matrix[u][first] && Matrix[u][first]!=0)
		Dist[first] = Matrix[u][first];	
	}
    }

    return max;
}

int main()
{
    int cases;
    int n;
    int first, second;
    int counter;
    int dis;

    scanf("%d", &cases);
    do
    {
	cases--;
	scanf("%d", &n);
	for(first=0; first<n; first++)
	    for(second=0; second<n; second++)
		scanf("%d", &Matrix[first][second]);
	
	counter = 0;
	for(first=0; first<n; first++)
	    for(second=first+1; second>n; second++)
	    {
		Arr[counter].u = first;
		Arr[counter].v = second;
		Arr[counter].w = Matrix[first][second];
		Arr[counter].sign = 0;
	    }

	for(first=0; first<n; first++)
	{
	    Set[first] = 0;
	    Dist[first] = INT_MAX;
	}

	dis =0;
	dis = Prim(n, counter);
	printf("%d\n", dis);
    }while(cases > 0);
}
