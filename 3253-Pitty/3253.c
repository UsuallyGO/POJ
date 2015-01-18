
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLANKS 20001

typedef struct Node_t{
    int key;
    struct Node_t *next;
}Node;

Node *Head;
long int sum;
int Arr[MAX_PLANKS];

void QueInit()
{
    Head = (Node*)malloc(sizeof(Node));
    Head->key = -1;
    Head->next = NULL;
}

void QueAscendInsert(int value)
{
    Node *cur;
    Node *tmp;

    tmp = (Node*)malloc(sizeof(Node));
    tmp->key = value;
    tmp->next = NULL;
    cur = Head;
    while(cur->next != NULL)
    {
       if(cur->next->key < value)
           cur = cur->next;
       else
           break;
    }
    tmp->next = cur->next;
    cur->next = tmp;
}

void QueMerge()
{
   Node *cur;
   Node *next;
   int value;

    while(1)
    {
        cur = Head->next;
        if(cur == NULL) // don't have to saw
            break;
        next = cur->next;
        if(next == NULL)
            break;
	Head->next = next->next;
	value = cur->key + next->key;
	sum += value;
	free(cur);
        free(next);
	QueAscendInsert(value);
    }
}

int Cmp(const void *a, const void *b)
{
    return *(int*)b - *(int*)a;
}

int main()
{
    int cases;
    int index;
    int value;

    while(scanf("%d", &cases) != EOF){
    index = 0; 
    sum = 0;
    QueInit();
    memset(Arr, 0, MAX_PLANKS);
    while(index < cases)
        scanf("%d", &Arr[index++]); 
    qsort(Arr, index, sizeof(int), Cmp);
    for(index=0; index<cases; index++)
        QueAscendInsert(Arr[index]);
    QueMerge();
    printf("%ld\n", sum);
    }

    return 0;
}
