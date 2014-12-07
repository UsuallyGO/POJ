
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
Truck trucks[MAX_NUM*1000];
int Father[MAX_NUM];

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

int FindFather(int i)
{
    while(Father[i] != -1)
	i = Father[i];

    return i;
}

void MakeSet(int n)
{
    int index;

    for(index=0; index<n; index++)
	Father[index] = -1;
}

int Kruskal(int n)
{
   int index;
   int px, py;
   int sum;

    sum = 0;
   for(index=0; index<n; index++)
   {
	px = FindFather(trucks[index].u);
	py = FindFather(trucks[index].v);

	if(px != py)
	{
	    trucks[index].sign = 1;
	    Father[py] = px;
	    sum += trucks[index].w;
	}
   }

   return sum;
}

int EdgeSum(int n)
{
    int index;
    int sum;

    sum = 0;
    for(index=0; index<n; index++)
    {
	if(trucks[index].sign)
	{
	    sum += trucks[index].w;
	    #if DEBUG
	    printf("%d--->%d:%d\n", trucks[index].u, trucks[index].v, trucks[index].w);
	    #endif
	}
    }

    return sum;
}

void Sort(int n)
{
    int first, second;
    Truck tmp;

    for(first=0; first<n; first++)
	for(second=0; second<n-1; second++)
	{
	    if(trucks[second].w > trucks[second+1].w)
	    {
		tmp = trucks[second];
		trucks[second] = trucks[second+1];
		trucks[second+1] = tmp;
	    }
	}
}

#if DEBUG
void Show(int n)
{
    int index;

    for(index=0; index<n; index++)
    {
	printf("%d--->%d:%d\n", trucks[index].u, trucks[index].v, trucks[index].w);
    }
}
#endif

int main()
{
   int n;
   int index;
   int first, second;
   int dis;
   int counter;

    do
    {
	scanf("%d", &n);
	if(!n)
	    break;

	for(index=0; index<n; index++)
	    scanf("%s", arr[index]);

	memset(trucks, 0, sizeof(trucks));
	counter = 0;
	for(first=0; first<n; first++)
	{
	    for(second=first+1; second<n; second++)
	    {
		dis = FindDistance(arr[first], arr[second], 7);//strlen(arr[first]));	
		trucks[counter].u = first;
		trucks[counter].v = second;
		trucks[counter].w = dis;
		counter++;
	    }
	}

#if DEBUG
	Show(counter);
	printf("-----------------\n"); 
#endif
	MakeSet(n);
	Sort(counter);
#if DEBUG
	Show(counter);
	printf("-----------------\n"); 
#endif
	dis = Kruskal(counter);
	//dis = EdgeSum(counter);
	printf("The highest possible quality is 1/%d.\n", dis);

    }while(1);

    return 0;
}