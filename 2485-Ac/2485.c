

#include <stdio.h>

#define MAX_NUM	   510 

typedef struct Edge_t
{
    int u;
    int v;
    int w;
    int sign;
}Edge;

Edge arr[MAX_NUM*MAX_NUM];
int  Matrix[MAX_NUM][MAX_NUM];
int  Father[MAX_NUM];

void Sort(int n)
{
    int first, second;
    Edge tmp;

    for(first=0; first<n; first++)
	for(second=0; second<n-1; second++)
	{
	    if(arr[second].w > arr[second+1].w)
	    {
		tmp = arr[second];
		arr[second] = arr[second+1];
		arr[second+1] = tmp;
	    }
	}
}

int FindFather(int i)
{
    while(Father[i] != -1)
	i = Father[i];

    return i;
}

int Kruskal(int n)
{
   int index;
   int px, py;
   int max;

    max = 0;
   for(index=0; index<n; index++)
   {
	px = FindFather(arr[index].u);
	py = FindFather(arr[index].v);

	if(px != py)
	{
	  //  arr[index].sign = 1;
	   if(max < arr[index].w)
		max = arr[index].w;
	    Father[py] = px;
	}
   }
   
   return max;
}

int FindMax(int n)
{
    int max;
    int index;

    max = 0;
    for(index=0; index<n; index++)
    {
	if(arr[index].sign)
	{
	    if(max < arr[index].w)
		max = arr[index].w;
	}
    }

    return max;
}

void ShowSpinTree(int n)
{
    int index;

    for(index=0; index<n; index++)
    {
	if(arr[index].sign)
	    printf("%d--->%d:%d\n", arr[index].u, arr[index].v, arr[index].w);
    }
    printf("---------------------------------\n");
}

void MakeSet(int n)
{
    int index;

    for(index=0; index<n; index++)
	Father[index] = -1;
}

void Show(int n)
{
    int index;

    for(index=0; index<n; index++)
    {
	printf("%d---->%d:%d\n", arr[index].u, arr[index].v, arr[index].w);
    }
    printf("-----------------------------\n");
}

int main()
{
    int n;
    int cases;
    int first, second;
    int counter;
    int dist;

	scanf("%d", &cases);
    do
    {
	scanf("%d", &n);

	for(first=0; first<n; first++)
	    for(second=0; second<n; second++)
		scanf("%d", &Matrix[first][second]);

	counter = 0;
	for(first=0; first<n; first++)
	{
	    for(second=first+1; second<n; second++)
	    {
		if(Matrix[first][second] == 0)
		    continue;
		arr[counter].w = Matrix[first][second];
		arr[counter].u = first;
		arr[counter].v = second;
		arr[counter].sign = 0;
		counter++;
	    }
	}

	MakeSet(n);
	Sort(counter);
//	Show(counter);
        dist = Kruskal(counter);
//	dist = FindMax(counter);
//	ShowSpinTree(counter);
	printf("%d\n\n", dist);
	
	cases--;
    }while(cases > 0);

    return 0;
}
