
#include <stdio.h>
#include <string.h>

#define DEBUG 0
#define CAVANS 8

#define VERY_MUCH 200000

struct OneStep
{
    int x;
    int y;
    int depths;
};

struct OneStep Queue[VERY_MUCH];
int visit[CAVANS][CAVANS];
int Curr_p, Seek_p;

inline void enQueue(int x, int y, int depth)
{
    Queue[Curr_p].x = x;
    Queue[Curr_p].y = y;
    Queue[Curr_p].depths = depth;
    Curr_p++;
    visit[x][y] = 1;
}

inline struct OneStep deQueue()
{
    Seek_p++;
    return Queue[Seek_p-1];
}

inline int checkPos(int x, int y)
{
    if(x < 0 || x >= CAVANS)
	return 0;
    if(y < 0 || y >= CAVANS)
	return 0;
    return 1;
}

int knightTravel(int start_x, int start_y, int end_x, int end_y)
{
    struct OneStep tmpStep;
    int x, y, depth;

#if DEBUG
    printf("start_x:%d start_y:%d end_x:%d end_y:%d\n", 
	    start_x, start_y, end_x, end_y);
#endif
    memset(visit, 0, sizeof(visit));
    memset(Queue, 0, sizeof(Queue));
    Queue[0].x = start_x;
    Queue[0].y = start_y;
    Queue[0].depths = 0;
    Curr_p = 1;
    Seek_p = 0;

    while(1)
    {
	tmpStep = deQueue();
	x = tmpStep.x;
	y = tmpStep.y;
	depth = tmpStep.depths+1;
	
	if(x == end_x && y == end_y)
	    return tmpStep.depths;
	
	if(checkPos(x+2, y-1) && !visit[x+2][y-1])
	    enQueue(x+2, y-1, depth);;
	if(checkPos(x+1, y-2) && !visit[x+1][y-2])
	    enQueue(x+1, y-2, depth);;
	if(checkPos(x-1, y-2) && !visit[x-1][y-2])
	    enQueue(x-1, y-2, depth);;
	if(checkPos(x-2, y-1) && !visit[x-2][y-1])
	    enQueue(x-2, y-1, depth);;
	if(checkPos(x-2, y+1) && !visit[x-2][y+2])
	    enQueue(x-2, y+1, depth);;
	if(checkPos(x-1, y+2) && !visit[x-1][y+2])
	    enQueue(x-1, y+2, depth);;
	if(checkPos(x+1, y+2) && !visit[x+1][y+2])
	    enQueue(x+1, y+2, depth);;
	if(checkPos(x+2, y+1) && !visit[x+2][y+1])
	    enQueue(x+2, y+1, depth);;
    }
}

int main()
{
    char c, num;
    char str[20];
    int start_x, start_y;
    int end_x, end_y;
    int steps;

    while(1)
    {
	if(scanf("%s", str) == EOF)
	    break;
	c = str[0];
	num = str[1];
	start_x = c - 'a';
	start_y = num - '0' - 1;
	printf("To get from %c%c to ", c, num);

//	if(scanf("%s", str) == EOF)
//	    break;
	scanf("%s", str);
	c = str[0];
	num = str[1];
	end_x = c - 'a'; 
	end_y = num - '0' - 1;
	printf("%c%c takes ", c, num);

	steps = knightTravel(start_x, start_y, end_x, end_y);
	printf("%d knight moves.\n", steps);
    }

    return 0;
}
