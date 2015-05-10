
#include <stdio.h>

#define MAX 50005
#define MINIMUM -999999

int main()
{
    int cases;
    int n, i, j;
    int nums[MAX];
    int tmp, sum;
    int dp[MAX];
    int max;

    scanf("%d", &cases);
    while(cases-- > 0)
    {
	scanf("%d", &n);	
	sum = 0; 
	tmp = MINIMUM;
	for(i = 0; i < n; i++)
	{
	    scanf("%d", &nums[i]);

	    sum += nums[i];
	    if(tmp < sum)
		tmp = sum;
	    dp[i] = tmp;
	    
	    if(sum < 0)
		sum = 0;
	}

	tmp = max = MINIMUM;
	sum = 0;
	for( i = n-1; i > 0; i--)
	{
	    sum += nums[i];
	    if(sum > tmp)
		tmp = sum;

	    if(max < dp[i-1] + tmp)
		max = dp[i-1] + tmp;

	    if(sum < 0)
		sum = 0;
	}
	printf("%d\n", max);
    }

    return 0;
}
