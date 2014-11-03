
#include <stdio.h>
#include <stdlib.h>

#define BLACK	'b'
#define WHITE	'w'	

typedef struct Node_t
{
    int number;
    int step;
    int index;
    struct Node_t *next;
}Node;

Node *Head;

int Mask[16] = { 51200, 58368, 29184, 12544,
		 35968, 20032, 10016, 4880,
		 2248,  1252,  626,   305,
		 140,   78,    39,    19 };


int BFS(int state)
{
    Node *tmp;
    Node *curr;
    Node *tail;
    int index;

    tmp = (Node*)malloc(sizeof(Node));
    tmp->step = 0;
    tmp->next = NULL;
    tmp->index = -1;
    tmp->number = state;

    Head = tmp;
    tail = tmp;
    
    while(1)
    {
	curr = Head;
	if(curr == NULL)
	    break;

	if(curr->number==0x0000 || curr->number==0xFFFF)
	    return curr->step;//here needs to free memory
	
	for(index=curr->index+1; index<16; index++)
	{
	    tmp = (Node*)malloc(sizeof(Node));
	    tmp->number = Head->number^Mask[index];
	    tmp->index = index;
	    tmp->step = Head->step + 1;
	    tmp->next = NULL;

	    if(tmp->number==0x0000 || curr->number==0xFFFF)
		return tmp->step;

	    tail->next = tmp;
	    tail = tmp;
	}

	tmp = Head;
	Head = tmp->next;
	free(tmp);
    }

    return -1;
}

int main()
{
    int initial;
    char line[4];
    int index;
    int insidex;
    int sum;

    while(1)
    {
	initial = 0;
	for(index=0; index<4; index++)
	{
	    scanf("%s", line);
//	    printf("--%s--\n", line);
//	    getchar();

	    for(insidex=0; insidex<4; insidex++)
	    {
		initial <<= 1;	

		if(line[insidex] == WHITE)
		    initial += 1;
	    }
	}

	sum = BFS(initial);
	if(sum != -1)
	    printf("%d", sum);
	else
	    printf("Impossible");
	break;
    }

    return 0;
}
