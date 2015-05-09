
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX 100002

#define DEBUG 0

struct Node
{
    int steps;
    int pos;
    struct Node *next;
};

struct Node *Seek_P;
struct Node *Cur_P;
struct Node *Root;

struct Node deQueue()
{
    struct Node tmp;

    Seek_P = Root->next;
    assert(Seek_P != NULL);
#if DEBUG 
    printf("Seek_P->pos:%d \n", Seek_P->pos);
#endif
    tmp.steps = Seek_P->steps;
    tmp.pos = Seek_P->pos;
    tmp.next = Seek_P->next;

    free(Seek_P);
    Seek_P = tmp.next;
    Root->next = Seek_P;
    return tmp;
}

void enQueue(int pos, int steps)
{
    if(Root->next == NULL)
	Cur_P = Root;

    Cur_P->next = (struct Node*)malloc(sizeof(struct Node)); 
    Cur_P->next->pos = pos;
    Cur_P->next->steps = steps;
    Cur_P->next->next = NULL;
    Cur_P = Cur_P->next;
}

void BFS(int n, int k)
{
    struct Node tmp;

    Root = (struct Node*)malloc(sizeof(struct Node));
    Cur_P = (struct Node*)malloc(sizeof(struct Node)); 
    Root->next = Cur_P;
    Cur_P->steps = 0;
    Cur_P->pos = n;
    Cur_P->next = NULL;
//    Seek_P = Cur_P;
#if DEBUG
    if(Seek_P == NULL)
	printf("Seek_P begin is NULL\n");
    else
	printf("Seek_P->pos begin is:%d\n", Seek_P->pos);
#endif

    while(1)
    {
	tmp = deQueue();

	if(tmp.pos == k)
	{
	    printf("%d\n", tmp.steps);
	    break;
	}

	if(tmp.pos - 1 >= 0)
	    enQueue(tmp.pos-1, tmp.steps+1);

	if(tmp.pos + 1 <= MAX)
	    enQueue(tmp.pos+1, tmp.steps+1);

	if(tmp.pos * 2 <= MAX)
	    enQueue(tmp.pos*2, tmp.steps+1);
    }
}

int main()
{
    int n, k;

    scanf("%d %d", &n, &k);
    BFS(n, k);

    return 0;
}
