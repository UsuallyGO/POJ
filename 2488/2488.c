
#include <stdio.h>
#include <string.h>

#define DEBUG 0

#define MAX 8

#define LEFT_BOTTOM_1 1
#define LEFT_BOTTOM_2 3
#define LEFT_TOP_1 2
#define LEFT_TOP_2 4
#define RIGHT_BOTTOM_1 5
#define RIGHT_BOTTOM_2 7
#define RIGHT_TOP_1 6
#define RIGHT_TOP_2 8

#define VALID 0

struct Step
{
    char c;
    int num;
};

int BOARD[MAX][MAX];
struct Step steps[100*100];
int step_counter = 0;

void showBoard(int m, int n)
{
    int i, j;

    printf("  ");
    for(j = 0; j < n; j++)
	printf("%c ", j + 'A');
    printf("\n");
    for(i = 0; i < m; i++)
    {
	printf("%d ", i+1);
	for(j = 0; j < n; j++)
	    printf("%d ", BOARD[i][j]);
	printf("\n");
    }
    printf("\n");
}

void oneStep(int x, int y, int m, int n)
{
    steps[step_counter].num = x + 1;
    steps[step_counter].c = y + 'A';
    step_counter++;
#if DEBUG
    printf("step_counter:%d coordinate:%c%d\n", step_counter, steps[step_counter-1].c, steps[step_counter-1].num);
    showBoard(m, n);
#endif
}

int BackBefore(int x, int y, int m, int n)
{
    if(BOARD[x][y] <= RIGHT_TOP_2)
	return 0; //should not be back, can seek next direction
}

int newStart(int *x, int *y, int m , int n)
{
    int i, j;
    int *p;

    i = *x;
    j = *y;
    
    for(; i < m; i++)
    {
	for(; j < n; j++)
	{
	    if(BOARD[i][j] == VALID)
	    {
		*x = i;
		*y = j;
		return 1;
	    }
	}
	j = 0;
    }

    return 0;
}

int FindNext(int *x, int *y, int direction, int m, int n)
{
    int delta_x, delta_y;
    int error;

    if(BOARD[*x][*y] >= direction) //can not search in this direction
	return 0;

    switch(direction)
    {
    case LEFT_BOTTOM_1: //1
	delta_y = -2;
	delta_x = -1;
	break;
    case LEFT_BOTTOM_2: //3
	delta_y = -1;
	delta_x = -2;
	break;
    case LEFT_TOP_1: //2
	delta_y = -2;
	delta_x = 1;
	break;
    case LEFT_TOP_2: //4
	delta_y = -1;
	delta_x = 2;
	break;
    case RIGHT_BOTTOM_1: //5
	delta_y = 1;
	delta_x = -2;
	break;
    case RIGHT_BOTTOM_2: //7
	delta_y = 2;
	delta_x = -1;
	break;
    case RIGHT_TOP_1: //6
	delta_y = 1;
	delta_x = 2;
	break;
    case RIGHT_TOP_2: //8
	delta_y = 2;
	delta_x = 1;
	break;
    default:
	;
	//should not be here
    }

    error = 0;
    *x += delta_x;
    *y += delta_y;
    if(*x < 0 || *x >= m)
	error = 1;//error
    if(*y < 0 || *y >= n)
	error = 1;//error
    if(error || BOARD[*x][*y] != VALID)
    {
	*x -= delta_x;
	*y -= delta_y;
	return 0;
    }
    else
    {
	BOARD[*x -delta_x][*y -delta_y] = direction;
	return 1;
    }
}

void showSteps()
{
    int i;

    for(i = 0; i < step_counter; i++)
	printf("%c%d", steps[i].c, steps[i].num);
    printf("\n");
}

void tourCheck(int m, int n)
{
    int i, j;
    int x, y;
    int direction;

    memset(BOARD, 0, sizeof(int)*MAX*MAX); 
    step_counter = 0;

    x = 0; 
    y = 0;
    oneStep(x, y, m, n);
    while(1)
    {
	if(step_counter == m*n)
	    break;

	direction = LEFT_BOTTOM_1;
	while(direction <= RIGHT_TOP_2)
	{
	    if(FindNext(&x, &y, direction, m, n))
	    {
		oneStep(x, y, m, n);
		break;
	    }
	    else
		direction++;
	}

	if(direction > RIGHT_TOP_2)//not find a valid direction
	{
	    BOARD[x][y] = direction;//for non-next position, it's bigger than RIGHT_TOP_2
	    step_counter--;
	    if(step_counter >= 1)
	    {
		BOARD[x][y] = VALID;
		x = steps[step_counter-1].num -1;
		y = steps[step_counter-1].c - 'A';
	    }
	    else //zero, no step now, need a new start
	    {
		if(!newStart(&x, &y, m, n))
		{
		    printf("impossible\n");
		    return;
		}
		else
		{
		    oneStep(x, y, m, n);
		}
	    }
	}
    }

    showSteps();
}

int main()
{
    int cases, i;
    int row, column;

    scanf("%d", &cases);
    for(i = 0; i < cases; i++)
    {
	scanf("%d %d", &row, &column);	
	printf("Scenario #%d:\n", i+1);
	tourCheck(row, column);
	printf("\n");
    }

    return 0;
}
