
#include <stdio.h>
#include <limits.h>

#define MAX_NUM 101

int Matrix[MAX_NUM][MAX_NUM];
int Set[MAX_NUM];
int Dist[MAX_NUM];

int Prim(int n)
{
    int sum;
    int first, second;
    int index;
    int min,u;

    for(index=1; index<n; index++)
    {
	Dist[index] = Matrix[0][index];
	Set[index] = 0;
    }

    Dist[0] = 0;
    Set[0] = 1;
    sum = 0;

    for(index=1; index<n; index++)
    {
	min = INT_MAX;
	for(first=1; first<n; first++)
	{
	   if(Set[first]!=1 && Dist[first]!=0 && Dist[first]<min)
	   {
		min = Dist[first];
		u = first;
	   }
	}

	sum += min;
	Set[u] = 1;

	for(first=1; first<n; first++)
	{
	    if(Dist[first] > Matrix[u][first])
		Dist[first] = Matrix[u][first];
	}
    }

    return sum;
}

int main()
{
    int n;
    int first, second;
    int sum;

    do
    {
	if(scanf("%d", &n) == EOF)
	    break;
	for(first=0; first<n; first++)
	    for(second=0; second<n; second++)
		scanf("%d", &Matrix[first][second]);
    
	sum = Prim(n);
	printf("%d\n", sum);
    }while(1);

    return 0;
}
