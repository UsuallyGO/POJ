
#include <stdio.h>

#define INVALID -1
#define VALID 0
#define START 11
#define END -2

#define MAX 50

int BOARD[MAX][MAX];
int start_x, start_y;
int end_x, end_y;

//remeber that, start and end are also valid
int validCheck(int x, int y, int m, int n)
{
    if(x < 0 || x >= m)
	return 0;
    if(y < 0 || y >= n)
	return 0;

    if(BOARD[x][y] == INVALID)
	return 0;
    else
	return 1;
}

int checkLeft(int m, int n)
{
    int x, y;
    int counter;

    counter = 0; 
    x = start_x;
    y = start_y;

    while(1)
    {
	if(x = end_x && y == end_y)
	    break;
	
	if(FindNext(&x, &y, LEFT))
	{
	}
	
    }
    return counter;
}

int checkRight(int m, int n)
{
}

int checkShort(int m, int n)
{
}

int main()
{
    int cases, m, n;
    int i, j, k;
    char str[MAX];

    scanf("%d", &cases);
    for(i = 0; i < cases; i++)
    {
	//do not need to clear the board
	scanf("%d %d", &m ,&n);
	for(j = 0; j < m; j++)
	{
	    scanf("%s", str);
	    for(k = 0; k < n; k++)
	    {
		switch(str[k]):
		{
		case '#':
		    BOARD[j][k] = INVALID;
		    break;
		case '.':
		    BOARD[j][k] = VALID;
		    break;
		case 'S':
		    BOARD[j][k] = START;
		    start_x = j;
		    start_y = k;
		    break;
		case 'E':
		    BOARD[j][k] = END;
		    end_x = j; 
		    end_y = k;
		    break;
		default:
		    ;//should not be here
		}
	    }
	}//finish in getting the board
	printf("%d ", checkLeft(m, n));
	printf("%d ", checkRight(m, n));
	printf("%d\n", checkShort(m, n));
    }

    return 0;
}
