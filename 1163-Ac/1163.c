
#include <stdio.h>
#include <string.h>

#define MAX 105

int dp[MAX][MAX];

int getDPLeft(int i, int j)
{
    if(i-1 < 0 || j-1 < 0)
	return 0;
    else
	return dp[i-1][j-1];
}

int getDPRight(int i, int j)
{
    if(i-1 < 0)
	return 0;
    else
	return dp[i-1][j];
}

int Max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int n, num;
    int i, j;
    int left, right;
    int max;

    while(scanf("%d", &n) != EOF)
    {
	memset(dp, 0, sizeof(dp));
	for(i = 0; i < n; i++)
	{
	    for(j = 0; j < i+1; j++)
	    {
		scanf("%d", &num);
		left = getDPLeft(i, j);
		right = getDPRight(i, j);
		dp[i][j] = Max(left, right) + num;
	    }
	}

	max = dp[n-1][0];
	for(j = 0; j < n; j++)
	{
	    if(max < dp[n-1][j])
		max = dp[n-1][j];
	}
	printf("%d\n", max);
    }

    return 0;
}

