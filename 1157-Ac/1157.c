
#include <stdio.h>
#include <string.h>

#define DEBUG 0

#define MINIMAL -999999
#define MAX 105

int weight[MAX][MAX];
int dp[MAX][MAX];
int f, v;

int Max(int i, int j)
{
    return i > j ? i : j;
}

void init()
{
    int i, j;

    for(i = 0; i < MAX; i++)
	for(j = 0; j < MAX; j++)
	    dp[i][j] = MINIMAL;
}

int checkPos(int i, int j)
{
    if(i < 0 || i >= f)
	return 0;
    if(j < 0 || j >= v)
	return 0;
    return 1;
}

void showDP()
{
    int i, j;

    for(i = 0; i < f; i++)
    {
	for(j = 0; j < v; j++)
	    printf("%8d ", dp[i][j]);
	printf("\n");
    }
}

int main()
{
    int i, j;
    int max;

    while(scanf("%d %d", &f, &v) != EOF)
    {
    memset(weight, 0, sizeof(weight));
    init();
    for(i = 0; i < f; i++)
    {
	for(j = 0; j < v; j++)
	    scanf("%d", &weight[i][j]);
    }

    dp[0][0] = weight[0][0];
    for(i = 0; i < f; i++)
    {
	max = dp[i][0];
	for(j = i; j < v; j++)
	{
	    if(weight[i][j] > max)
		max = weight[i][j];

	    dp[i][j] = max;
	}
    }

#if DEBUG
    showDP();
#endif

    for(i = 0; i < f; i++)
    {
	for(j = i; j < v; j++)
	{
	    if(checkPos(i-1, j-1))
	    {
		if(i == j)
		    dp[i][j] = dp[i-1][j-1] + weight[i][j];
		else
		    dp[i][j] = Max(dp[i-1][j-1] + weight[i][j], dp[i][j-1]); 
	    }
	}
    }
#if DEBUG
    showDP();
#endif

    max = MINIMAL;
    for(j = 0; j < v; j++)
    {
	if(dp[f-1][j] > max)
	    max = dp[f-1][j];
    }
    printf("%d\n", max);
    }

    return 0;
}
