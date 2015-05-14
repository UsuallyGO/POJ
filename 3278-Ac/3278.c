
#include <stdio.h>
#include <assert.h>
#include <string.h>

#define MAX 100001
#define MAX_LENGTH 200005

struct Node
{
    int steps;
    int pos;
};

struct Node Queue[MAX_LENGTH];
int visit[MAX];
int Que_Index, Seek_Index;

void enQueue(int pos, int steps)
{
    assert(Que_Index < MAX_LENGTH);

    Queue[Que_Index].pos = pos;
    Queue[Que_Index].steps = steps;
    Que_Index++;
    visit[pos] = 1;
}

struct Node deQueue()
{
    struct Node tmp;

    assert(Seek_Index < MAX_LENGTH);

    tmp.steps = Queue[Seek_Index].steps;
    tmp.pos = Queue[Seek_Index].pos;
    Seek_Index++;

    return tmp;
}

void BFS(int n, int k)
{
    struct Node current;
    int next_pos, next_steps;

    memset(visit, 0, MAX*sizeof(int));
    Queue[0].steps = 0;
    Queue[0].pos = n;
    Que_Index = 1;//points to the next node
    Seek_Index = 0;
    visit[n] = 1;

    while(1)
    {
	current = deQueue();
	if(current.pos == k) //sure to be break
	{
	    printf("%d\n", current.steps);
	    break;
	}
	
	next_pos = current.pos;
	next_steps = current.steps;

	if(next_pos - 1 >= 0 && !visit[next_pos-1])//can go back
	    enQueue(next_pos-1, next_steps+1);

	if(next_pos + 1 <= MAX && !visit[next_pos+1]) //can go forward one step
	    enQueue(next_pos+1, next_steps+1);

	if(next_pos*2 <= MAX && !visit[next_pos*2]) //can jump
	    enQueue(next_pos*2, next_steps+1);
    }
}

int main()
{
    int n, k;

    scanf("%d %d", &n ,&k);
    BFS(n, k);

    return 0;
}