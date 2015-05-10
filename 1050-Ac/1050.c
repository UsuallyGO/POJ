
#include <stdio.h>
#include <string.h>

#define DEBUG 1
#define MAX 1000
#define MINIMUM -99999

void showDP(int p[][MAX], int n)
{
    int i, j;

    for(i = 0; i < n; i++)
    {
	for(j = 0; j < n; j++)
	    printf("%3d ", p[i][j]);
	printf("\n");
    }
}

void showDP2(int *p, int n)
{
    int i = 0;
    for(i = 0; i < n; i++)
	printf("%d ", p[i]);
    printf("\n");
}

int main()
{
    int n;
    int i, j;
    int nums[MAX];
    int dp[MAX][MAX];
    int dp2[MAX];
    int sum, temp;

    scanf("%d", &n);
    memset(dp, 0, sizeof(dp));
    for(i = 0; i < n; i++)
    {
	sum = 0; 
	temp = MINIMUM;
	for(j = 0; j < n; j++)
	{
	   scanf("%d", &nums[j]); 

	   sum += nums[j];
	   if(temp < sum)
	    temp = sum;

	    dp[i][j] = temp;
	    if(sum < 0)
		sum = 0;
	}
    }

#if DEBUG
    showDP(dp, n);
#endif

    temp = MINIMUM;
    sum = 0;
    memset(dp2, 0, sizeof(dp2));
    for(i = 0; i < n; i++)
    {
	sum = 0;
	temp = MINIMUM;
	for( j = 0; j < n; j++)
	{
	    sum += dp[j][i];
	    if(temp < sum)
		temp = sum;
	    dp2[i] = temp;
	    if(sum < 0)
		sum = 0;
	}
    }

#if DEBUG
    showDP2(dp2, n);
#endif
    temp = MINIMUM;
    for(i = 0; i < n; i++)
    {
	if(temp < dp2[i])
	    temp = dp2[i];
    }

    printf("%d\n", temp);
    return 0;
}
