
#include <stdio.h>

#define MAX 105

#define MINIMUM -99999
int nums[MAX][MAX];

int main()
{
    int n, tmp, max;
    int i, j, k;

    scanf("%d", &n);
    max = MINIMUM;
    for(i = 0; i < n; i++)
    {
	tmp = 0;
	for(j = 0; j < n; j++)
	{
	    scanf("%d", &nums[i][j]);
	    if(tmp > 0)
		tmp += nums[i][j];
	    else
		tmp = nums[i][j];

	    if(tmp > max)
		max = tmp;
	}
    }

    for(i = 0; i < n-1; i++)
    {
	for(j = i+1; j < n; j++)
	{
	    tmp = 0;
	    for(k = 0 ; k < n; k++)
	    {
		nums[i][k] += nums[j][k];
		if(tmp > 0)
		    tmp += nums[i][k];
		else
		    tmp = nums[i][k];

		if(tmp > max)
		    max = tmp;
	    }
	}
    }
    printf("%d\n", max);

    return 0;
}
