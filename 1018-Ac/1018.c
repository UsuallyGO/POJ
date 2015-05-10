
#include<stdio.h>
#include<string.h>

#define MAX_DEVICES 105 
#define MAX_BANDWIDTH 1000

#define min(x, y) ((x) < (y) ? (x) : (y))

int dp[MAX_DEVICES][MAX_BANDWIDTH];
int b[MAX_DEVICES];
int p[MAX_DEVICES];

int main()
{
    int cases;
    int n, m;
    int i, j, k, l, l2;
    double res, tmp;
    int label;
    
    scanf("%d", &cases);
    for(i = 0; i < cases; i++)
    {
	memset(dp, 0, sizeof(dp));
	memset(b, 0, sizeof(b));
	memset(p, 0, sizeof(p));
	scanf("%d", &n); //n devices
	for(j = 0; j < n; j++)
	{
	    scanf("%d", &m);//m alternatives
	    for(k = 0; k < m; k++)
		scanf("%d %d", &b[k], &p[k]);

	    if(j == 0)
	    {
		for(l = 0; l < m; l++)
		{
		    if(dp[j][b[l]] == 0)
			dp[j][b[l]] = p[l];
		    else
			dp[j][b[l]] = min(dp[j][b[l]], p[l]);
		}
	    }
	    else
	    {
		for(l2 = 0; l2 < MAX_BANDWIDTH; l2++)
		{
		    if(dp[j-1][l2] != 0)
		    {
			for(l = 0; l < m; l++)
			{
			    if(l2 <= b[l])
				label = l2;
			    else
				label = b[l];

			    if(dp[j][label] == 0)
				dp[j][label] = dp[j-1][l2] + p[l];
			    else
				dp[j][label] = min(dp[j][label], dp[j-1][l2] + p[l]);
			}
		    }
		}
	    }
	}

	res = 0.0;
	tmp = 0.0;
	for(k = 0; k < MAX_BANDWIDTH; k++)
	{
	    if(dp[n-1][k] != 0)
	    {
		tmp = (1.0*k)/(1.0*dp[n-1][k]);
		if(res < tmp)
		    res = tmp;
	    }
	}
	printf("%.3f\n", res);
    }

    return 0;
}
