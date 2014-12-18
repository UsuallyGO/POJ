
#include <stdio.h>
#include <stdlib.h>

typedef struct Node_t 
{
   int value;
   struct Node_t *next;
}Node;

Node *head;

void AddSort(int n)
{
    Node *prev;
    Node *cur;
    Node *tmp;

    prev = head;
    cur = head->next;
    tmp = (Node*)malloc(sizeof(Node));
    tmp->value = n;
    tmp->next = NULL;

    for(;cur!=NULL; cur=cur->next)
    {
	if(cur->value > n)
	{
	    tmp->next = cur;
	    prev->next = tmp;
	    return ;
	}
	else
	    prev = cur;
    }
    prev->next=tmp;
}

void Destroy()
{
    Node *cur;

    cur = head->next;
    while(cur != NULL)
    {
	head->next = cur->next;
	free(cur);
	cur = head->next;
    }
}

void Show()
{
    Node *cur;

    cur = head->next;
    for(; cur!=NULL; cur=cur->next)
        printf("%d ", cur->value);
    printf("\n");
}

int Median(int nums)
{
    int counter;
    Node *tmp;

    tmp = head;
    for(counter=0; counter<=nums/2; counter++)
        tmp = tmp->next;

    return tmp->value;
}

int main()
{
    int nums;
    int tmp;
    int cases;

    head = (Node*)malloc(sizeof(Node));
    head->next = NULL;

    while(scanf("%d", &nums)!=EOF)
    {
	cases = nums;
        while(cases-->0)
        {
            scanf("%d", &tmp);	
	    AddSort(tmp);
        }
	Show();
	tmp = Median(nums);
	printf("%d\n", tmp);
	Destroy();
    }
    return 0;
}
