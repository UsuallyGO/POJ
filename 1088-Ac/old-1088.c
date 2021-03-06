
#include <stdio.h>
#include <string.h>

#define MAX 105

int BOARD[MAX][MAX];
int dp[MAX][MAX];
int m, n;

int checkPos(int x, int y)
{
    if(x < 0 || x >= m)
	return 0;
    if(y < 0 || y >= n)
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
    int k, max;
    int tempx, tempy;
    int top, bottom, left, right;

    if(dp[i][j] != 0)
	return dp[i][j]; 
    
    top = bottom = left = right = 0;
    tempx = i - 1;
    tempy = j;
    if(checkPos(tempx, tempy) && BOARD[i][j] > BOARD[tempx][tempy])
	top = dfs(tempx, tempy);

    tempx = i + 1;
    tempy = j;
    if(checkPos(tempx, tempy) && BOARD[i][j] > BOARD[tempx][tempy])
	bottom = dfs(tempx, tempy);

    tempx = i;
    tempy = j + 1;
    if(checkPos(tempx, tempy) && BOARD[i][j] > BOARD[tempx][tempy])
	right = dfs(tempx, tempy);

    tempx = i;
    tempy = j - 1;
    if(checkPos(tempx, tempy) && BOARD[i][j] > BOARD[tempx][tempy])
	left = dfs(tempx, tempy);

    max = Max(top, bottom, right, left);
    dp[i][j] = max + 1;
    return dp[i][j];
}

int main()
{
    int i, j;
    int max;

    while(scanf("%d%d", &m, &n) != EOF)
    {
    memset(dp, 0, sizeof(dp));
    memset(BOARD, 0, sizeof(BOARD));
    for(i = 0; i < m; i++)
	for(j = 0; j < n; j++)
	    scanf("%d", &BOARD[i][j]);
    
    max = 0;
    for(i = 0; i < m; i++)
	for(j = 0; j < n; j++)
	{
	    dp[i][j] = dfs(i, j);
	    if(max < dp[i][j])
		max = dp[i][j];
	}

    printf("%d\n", max);
    }

    return 0;
}
