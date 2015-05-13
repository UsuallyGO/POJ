
#include <stdio.h>
#include <string.h>

#define MAX 300

char strA[MAX];
char strB[MAX];
int dp[MAX][MAX];

int Max(int a, int b)
{
    return a>b ? a:b;
}

int main()
{
    int i, j;

    while(scanf("%s %s", strA+1, strB+1) != EOF)
    {
	memset(dp, 0, sizeof(dp));

	for(i = 1; strA[i]; i++) 
	{
	    for(j = 1; strB[j]; j++)
	    {
		if(strA[i] == strB[j])
		    dp[i][j] = dp[i-1][j-1] + 1;
		else
		    dp[i][j] = Max(dp[i-1][j], dp[i][j-1]);
	    
	    }
	}
	printf("%d\n", dp[strlen(strA+1)][strlen(strB+1)]);
    }

    return 0;
}
