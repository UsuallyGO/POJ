
#include <stdio.h>
#include <string.h>

#define DEBUG 0
#define MAX 45
#define VERY_MUCH 20000

#define INVALID -1
#define VALID 0
#define START 11
#define END -11

#define TOP 2
#define BOTTOM 0
#define RIGHT 1
#define LEFT 3

struct OneStep
{
    int x;
    int y;
    int depth;
};

struct OneStep Queue[VERY_MUCH];
int BOARD[MAX][MAX];
int visit[MAX][MAX];
int steps;
int m, n;

void showBoard()
{
    int x, y;

    for(x = 0; x < m; x++)
    {
	for(y = 0; y < n; y++)
	{
	    printf("%3d", BOARD[x][y]);
	}
	printf("\n");
    }
}

int checkPos(int x, int y)
{
    if(x < 0 || x >= m)
	return 0;
    if(y < 0 || y >= n)
	return 0;
    if(BOARD[x][y] == INVALID)
	return 0;
    return 1;
}

void DFSLeft(int x, int y, int direction)
{
#if DEBUG
    printf("DFSLeft x:%d y:%d dire:%d\n", x, y, direction);
#endif
    steps++;

    if(BOARD[x][y] == END)
	return;

    switch(direction)
    {
    case TOP:
    {
	if(checkPos(x, y+1))
	    DFSLeft(x, y+1, LEFT);
	else if(checkPos(x+1, y))
	    DFSLeft(x+1, y, TOP);
	else if(checkPos(x, y-1))
	    DFSLeft(x, y-1, RIGHT);
	else if(checkPos(x-1, y))
	    DFSLeft(x-1, y, BOTTOM);
	else
	    ;
	break;
    }
    case BOTTOM:
    {
	if(checkPos(x, y-1))
	    DFSLeft(x, y-1, RIGHT);
	else if(checkPos(x-1, y))
	    DFSLeft(x-1, y, BOTTOM);
	else if(checkPos(x, y+1))
	    DFSLeft(x, y+1, LEFT);
	else if(checkPos(x+1, y))
	    DFSLeft(x+1, y, TOP);
	else
	    ;
	break;
    }
    case RIGHT:
    {
	if(checkPos(x+1, y))
	    DFSLeft(x+1, y, TOP);
	else if(checkPos(x, y-1))
	    DFSLeft(x, y-1, RIGHT);
	else if(checkPos(x-1, y))
	    DFSLeft(x-1, y, BOTTOM);
	else if(checkPos(x, y+1))
	    DFSLeft(x, y+1, LEFT);
	else
	    ;
	break;
    }
    case LEFT:
    {
	if(checkPos(x-1, y))
	    DFSLeft(x-1, y, BOTTOM);
	else if(checkPos(x, y+1))
	    DFSLeft(x, y+1, LEFT);
	else if(checkPos(x+1, y))
	    DFSLeft(x+1, y, TOP);
	else if(checkPos(x, y-1))
	    DFSLeft(x, y-1, RIGHT);
	else
	    ;
	break;
    }
    default:
	;//not be here
    }
}

int getDirection(int x, int y)
{
    int direction;

    if(x == 0)
	direction = TOP;
    else if(x == m-1)
	direction = BOTTOM;
    else if(y == 0)
	direction = LEFT;
    else if(y == n-1)
	direction = RIGHT;
    else//should not be here
	;
	
    return direction;
}

void seekLeft(int x, int y, int direction)
{
    switch(direction)
    {
    case TOP:
	DFSLeft(x+1, y, direction);
	break;
    case BOTTOM:
	DFSLeft(x-1, y, direction);
	break;
    case LEFT:
	DFSLeft(x, y+1, direction);
	break;
    case RIGHT:
	DFSLeft(x, y-1, direction);
	break;
    default:
	;//not be here
    }
}

void DFSRight(int x, int y, int direction)
{
    steps++;
#if DEBUG
    printf("DFSRight x:%d y:%d direction:%d\n", x, y, direction);
#endif 

    if(BOARD[x][y] == END)
	return;

    switch(direction)
    {
    case TOP:
    {
	if(checkPos(x, y-1))
	    DFSRight(x, y-1, RIGHT);
	else if(checkPos(x+1, y))
	    DFSRight(x+1, y, TOP);
	else if(checkPos(x, y+1))
	    DFSRight(x, y+1, LEFT);
	else if(checkPos(x-1, y))
	    DFSRight(x-1, y, BOTTOM);
	else
	    ;
	break;
    }
    case BOTTOM:
    {
	if(checkPos(x, y+1))
	    DFSRight(x, y+1, LEFT);
	else if(checkPos(x-1, y))
	    DFSRight(x-1, y, BOTTOM);
	else if(checkPos(x, y-1))
	    DFSRight(x, y-1, RIGHT);
	else if(checkPos(x+1, y))
	    DFSRight(x+1, y, TOP);
	else
	    ;
	break;
    }
    case LEFT:
    {
	if(checkPos(x+1, y))
	    DFSRight(x+1, y, TOP);
	else if(checkPos(x, y+1))
	    DFSRight(x, y+1, LEFT);
	else if(checkPos(x-1, y))
	    DFSRight(x-1, y, BOTTOM);
	else if(checkPos(x, y-1))
	    DFSRight(x, y-1, RIGHT);
	else
	    ;
	break;
    }
    case RIGHT:
    {
	if(checkPos(x-1, y))
	    DFSRight(x-1, y, BOTTOM);
	else if(checkPos(x, y-1))
	    DFSRight(x, y-1, RIGHT);
	else if(checkPos(x+1, y))
	    DFSRight(x+1, y, TOP);
	else if(checkPos(x, y+1))
	    DFSRight(x, y+1, LEFT);
	else
	    ;
	break;
    }
    default:
	;
    }
}

void seekRight(int x, int y, int direction)
{
    switch(direction)
    {
    case TOP:
	DFSRight(x+1, y, direction);
	break;
    case BOTTOM:
	DFSRight(x-1, y, direction);
	break;
    case LEFT:
	DFSRight(x, y+1, direction);
	break;
    case RIGHT:
	DFSRight(x, y-1, direction);
	break;
    default:
	;
    }
}

void Enqueue(int x, int y, int depth, int tail)
{
#if DEBUG
    printf("x:%d y:%d depth:%d\n", x, y, depth);
#endif
   Queue[tail].x = x;
   Queue[tail].y = y;
   Queue[tail].depth = depth;
   visit[x][y] = 1;
}

void seekShortest(int x, int y)
{
    int seek_cur;
    int que_tail;
    struct OneStep one_step;

#if DEBUG
    printf("seekShortest x:%d y:%d\n", x, y);
#endif
    Queue[0].x = x;
    Queue[0].y = y;
    Queue[0].depth = 1;
    seek_cur = 0;
    que_tail = 1;
    visit[x][y] = 1;

    while(1)
    {
	one_step = Queue[seek_cur++];
	x = one_step.x;
	y = one_step.y;
	if(BOARD[x][y] == END)
	{
	   steps = one_step.depth; 
	   break;
	}

	if(checkPos(x-1, y) && !visit[x-1][y])
	    Enqueue(x-1, y, one_step.depth+1, que_tail++);
	if(checkPos(x+1, y) && !visit[x+1][y])
	    Enqueue(x+1, y, one_step.depth+1, que_tail++);
	if(checkPos(x, y-1) && !visit[x][y-1])
	    Enqueue(x, y-1, one_step.depth+1, que_tail++);
	if(checkPos(x, y+1) && !visit[x][y+1])
	    Enqueue(x, y+1, one_step.depth+1, que_tail++);
    }
}

int main()
{
    int cases;
    int i, j, k;
    char str[MAX], c;
    int start_x, start_y;
    int direction;

    scanf("%d", &cases);

    for(i = 0; i < cases; i++)
    {
	scanf("%d %d", &n, &m);
	for(j = 0 ; j < m; j++)
	{
	    scanf("%s", str);
#if DEBUG
	    printf("line[%d]:%s\n", j, str);
#endif
	    for(k = 0; k < n; k++)
	    {
		c = str[k];
		if(c == '#')
		    BOARD[j][k] = INVALID; 
		else if(c == '.')
		    BOARD[j][k] = VALID;
		else if(c == 'S')
		{
		    BOARD[j][k] = START;
		    start_x = j;
		    start_y = k;
		}
		else if(c == 'E')
		    BOARD[j][k] = END;
		else //should not be here
		    ;
	    }

	}
#if DEBUG
	showBoard();
	printf("start_x:%d start_y:%d\n", start_x, start_y);
#endif
	steps = 1;
	direction = getDirection(start_x, start_y);
	seekLeft(start_x, start_y, direction); 
	printf("%d ", steps);
	steps = 1;
	seekRight(start_x, start_y, direction);
	printf("%d ", steps);
	steps = 1;
	memset(visit, 0, sizeof(visit));
	memset(Queue, 0, sizeof(Queue));
	seekShortest(start_x, start_y);
	printf("%d", steps);
	printf("\n");
    }//for cases

    return 0;
}
