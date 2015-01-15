
#include <stdio.h>
#include <stdlib.h>

#define DEBUG 0

typedef struct Node_t
{
    int value;
    struct Node_t *next;
}Node;

Node* Head;

void List_init()
{
    Head = (Node*)malloc(sizeof(Node)); 
    Head->value = 0;
    Head->next = NULL;
}

int List_addDes(int to_add)
{
    int counter;
    Node *prev;
    Node *cur;

    prev = Head;
    cur = Head->next;
    counter = 0;

    while(cur != NULL)
    {
        if(cur->value > to_add)//go ahead
	{
	    prev = cur;
	    cur = cur->next;
	    counter++;
	}
	else
	    break;
    }

    cur = (Node*)malloc(sizeof(Node));
    cur->value = to_add;
    cur->next = prev->next;

    prev->next =cur;

    return counter;
}

void List_destroy()
{
    Node *tmp;
    
    tmp = Head->next;

    while(tmp != NULL)
    {
        Head->next = tmp->next;
	free(tmp);
	tmp = Head->next;
    }
}

void List_display()
{
    Node *tmp;

    tmp = Head->next;
    while(tmp != NULL)
    {
        printf("%d-->", tmp->value);
	tmp = tmp->next;
    }
}

int main()
{
    int num;
    int value;
    int counter;

    do
    {
        scanf("%d", &num);
        if(!num)
            break;

        counter = 0;	
	List_init();
	while(num-->0)
	{
	   scanf("%d", &value); 
           counter += List_addDes(value);
	}
	printf("%d\n", counter);
#if DEBUG
	List_display();
	printf("-------------------\n");
#endif
	List_destroy();
    }while(1);

    return 0;
}
