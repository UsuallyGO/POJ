

#include <stdio.h>
#include <limits.h>
#include <string.h>

#define DEBUG	    0
#define MAX_NUM	    2001
#define MAX_LEN	    10

typedef struct Truck_t
{
    int u;
    int v;
    int w;
    int sign;
}Truck;

char	arr[MAX_NUM][MAX_LEN];
int Matrix[MAX_NUM][MAX_NUM];
int Dist[MAX_NUM];
int Set[MAX_NUM];

int FindDistance(const char *s1, const char *s2, int len)
{
    int index;
    int counter;

    counter = 0;
    for(index=0; index<len; index++)
	if(s1[index] != s2[index])
	    counter++;

    return counter;
}

int Prim(int n)
{
    int sum;
    int min, u;
    int index;
    int first, second;
    Dist[0] = 1;
    Set[0] = 1;

    for(index=1; index<n; index++)
	Dist[index] = Matrix[0][index];

    sum = 0;
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
	sum += min;
	
	for(first=1; first<n; first++)
	{
	    if(Dist[first]>Matrix[u][first] && Matrix[u][first]!=0)
		Dist[first] = Matrix[u][first];	
	}
    }

    return sum;
}

int main()
{
    int n;
    int first, second;
    int counter;
    int dis;
    int index;

    do
    {
	scanf("%d", &n);
	if(!n)
	    break;

	for(index=0; index<n; index++)
	    scanf("%s", arr[index]);

	memset(Matrix, 0, sizeof(Matrix));
	counter = 0;
	for(first=0; first<n; first++)
	{
	    for(second=0; second<n; second++)
	    {
		dis = FindDistance(arr[first], arr[second], 7);	
		Matrix[first][second] = dis;
	    }
	}

	for(first=0; first<n; first++)
	{
	    Set[first] = 0;
	    Dist[first] = INT_MAX;
	}

	dis = Prim(n);
	printf("The highest possible quality is 1/%d.\n", dis);
    }while(1);
}
