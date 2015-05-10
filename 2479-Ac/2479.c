
#include <stdio.h>

#define MAX 50004

int nums[MAX];
int dp[MAX];

inline int maxSeq(int start, int end)
{
    int i, j, tmp, max;

    max = -1;
    tmp = 0;
    for(i = start; i <= end; i++)
    {
	if(tmp > 0)
	    tmp += nums[i];
	else
	    tmp = nums[i];
	
	if(tmp > max)
	    max = tmp;
    }

    return max;
}

int main()
{
    int cases;
    int i, j, n;
    int left, right, max;

    scanf("%d", &cases);
    while(cases-- > 0)
    {
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	    scanf("%d", &nums[i]);
	
	for(j = 0; j < n-1; j++)//right sequence at least has nums[n-1]
	    dp[j] = maxSeq(0, j);

	max = 0;
	for(j = 1; j < n; j++)
	{
	    right = maxSeq(j, n-1);
	    if(max < dp[j-1] + right)
		max = dp[j-1] + right;
	}
	printf("%d\n", max);
    }

    return 0;
}
