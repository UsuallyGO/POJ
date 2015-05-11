
#include <stdio.h>
#include <string.h>

#define MAX 105

int BOARD[MAX][MAX];
int dp[MAX][MAX];
int r, c;

int checkPos(int i, int j)
{
    if(i < 0 || i >= r)
	return 0;
    if(j < 0 || j >= c)
	return 0;

    return 1;
}

int Max(int a1, int a2, int a3, int a4)
{
    int max;

    max = a1;
    if(max < a2)
	max = a2;
    if(max < a3)
	max = a3;
    if(max < a4)
	max = a4;

    return max;
}

int dfs(int i, int j)
{
    int max;
    int left, right, up, bottom;

    if(dp[i][j] != 0)
	return dp[i][j];

    left = right = up = bottom = 0;
    if(checkPos(i-1, j) && BOARD[i][j] > BOARD[i-1][j])
	up = dfs(i-1, j);
    if(checkPos(i, j-1) && BOARD[i][j] > BOARD[i][j-1])
	left = dfs(i, j-1);
    if(checkPos(i+1, j) && BOARD[i][j] > BOARD[i+1][j])
	bottom = dfs(i+1, j);
    if(checkPos(i, j+1) && BOARD[i][j] > BOARD[i][j+1])
	right = dfs(i, j+1);

    max = Max(up, left, bottom, right);
    dp[i][j] = max + 1;
    return dp[i][j];
}

int main()
{
    int i, j;
    int max;

    while(scanf("%d%d", &r, &c) != EOF)
    {
    memset(dp, 0, sizeof(dp));
    memset(BOARD, 0, sizeof(BOARD));
    for(i = 0; i < r; i++)
	for(j = 0; j < c; j++)
	    scanf("%d", &BOARD[i][j]);
    
    max = 0;
    for(i = 0; i < r; i++)
	for(j = 0; j < c; j++)
	{
	    dp[i][j] = dfs(i, j);
	    if(max < dp[i][j])
		max = dp[i][j];
	}

    printf("%d\n", max);
    }

    return 0;
}
