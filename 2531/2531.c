
#include <stdio.h>
#include <string.h>

#define MAX 30

int BOARD[MAX][MAX];

int main()
{
    int levels;
    int i, j;
    int dis;

    scanf("%d", &levels);
    memset(BOARD, 0, sizeof(BOARD));
    for(i = 0; i < levels; i++)
    {
	for(j = 0; j < levels; j++)
	{
	    scanf("%d", &dis);
	    BOARD[i][j] = dis;
	    BOARD[j][i] = dis;
	}

    }

    return 0;
}
