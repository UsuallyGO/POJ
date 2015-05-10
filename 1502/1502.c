
#include <stdio.h>
#include <string.h>

#define DEBUG 0
#define MAX 110
#define BIG_DISTANCE 100000000 

int NetWork[MAX][MAX];
int Visit[MAX];
int Distance[MAX];

void showBoard(int level)
{
    int i, j;

    for(i = 0; i < level; i++)
    {
	for(j = 0; j < level; j++)
	{
	    printf("%3d ", NetWork[i][j]);
	    if((j+1)%20 == 0)
		printf("\n");
	}
	printf("\n");
    }
}

void Dijstra(int level)
{
    int j, i, u;
    int min;

    memset(Visit, 0, sizeof(Visit));
    memset(Distance, 0, sizeof(Distance));

    Visit[0] = 1;
    for(i = 1; i < level; i++)
    {
	if(NetWork[i][0] > 0)
	    Distance[i] = NetWork[i][0];
    }

    for(j = 1; j < level; j++)
    {
	min = BIG_DISTANCE;
	for(i = 1; i < level; i++) //find the current shorstest path
	{
	    if(!Visit[i] && Distance[i] != 0 && Distance[i]<min)
	    {
		u = i;
		min = Distance[i];
	    }
	}
#if DEBUG
	printf("U:%d min:%d\n", u, min);
#endif
	Visit[u] = 1;

	for(i = 1; i < level; i++)
	{
	    if(!Visit[i] && NetWork[u][i] > 0)
	    {
		if(Distance[i] > Distance[u] + NetWork[u][i] || Distance[i] == 0)//0 means not arrivable
		    Distance[i] = Distance[u] + NetWork[u][i];
	    }
	}
    }
}

void FindMax(int level)
{
    int i, max;

    max = 0;
    for(i = 1; i < level; i++)
    {
#if DEBUG
	printf("Distance[%d]:%d\n", i, Distance[i]);
#endif
	if(Distance[i] > 0 && Distance[i] > max)
	    max = Distance[i];
    }
    printf("%d\n", max);
}

int main()
{
    int level;
    int i, j;
    char str[10];
    int num;

    scanf("%d", &level);
    memset(NetWork, 0, sizeof(NetWork));
    for(i = 1; i < level; i++)
    {
	for(j = 0; j < i; j++)
	{
	    scanf("%s", str);
	    if(str[0] == 'x')
		num = -1;
	    else
		num = atoi(str);
	    NetWork[i][j] = num;
	    NetWork[j][i] = num;
	}
    }
#if DEBUG
    showBoard(level);
#endif
    Dijstra(level);
    FindMax(level);

    return 0;
}
