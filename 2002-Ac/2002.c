
#include <stdio.h>
#include <stdlib.h>

#define MOSTCASE 20000
#define HASH_BASE 19997
#define X 0
#define Y 1

typedef struct Node_t{
    int x, y;
    struct Node_t *next;
}Node;

int Matrix[1000][2];
Node *arr[HASH_BASE];

int HashKey(int x, int y)
{
    return (x*x + y*y)%HASH_BASE;
}

void HashStore(int x, int y)
{
    int key; 
    Node *tmp;
    Node *cur;

    tmp = (Node*)malloc(sizeof(Node));
    tmp->x = x;
    tmp->y = y;
    tmp->next = NULL;
    key = HashKey(x, y);
    cur = arr[key];

    if(cur == NULL)
        arr[key] = tmp;
    else{
	while(cur->next != NULL)
	    cur = cur->next;
	cur->next = tmp;
    }
}

int HashFind(int x, int y)
{
    int key; 
    Node *tmp;

    key = HashKey(x, y);
    tmp = arr[key];
    while(tmp != NULL){
        if(tmp->x==x && tmp->y==y)
	    return 1;
	tmp = tmp->next;
    }
    return 0;
}

void HashClear()
{
    Node *tmp;
    int index;

    for(index=0; index<HASH_BASE; index++){
        while(arr[index] != NULL){
	    tmp = arr[index];
	    arr[index] = tmp->next;
	    free(tmp);
	}
    }
}

int GetX3(int x1, int y1, int x2, int y2, int sign)
{
    int x3;
    if(sign)
        x3 = x1 + y1 - y2;
    else
        x3 = x1 - y1 + y2;
    return x3;
}

int GetY3(int x1, int y1, int x2, int y2, int sign)
{
    int y3;
    if(sign)
       y3 = y1 - x1 + x2; 
    else
       y3 = y1 + x1 - x2;
    return y3;
}

int GetX4(int x1, int y1, int x2, int y2, int sign)
{
    int x4;
    if(sign)
        x4 = x2 + y1 - y2;
    else
        x4 = x2 - y1 + y2;
    return x4; 
}

int GetY4(int x1, int y1, int x2, int y2, int sign)
{
    int y4;
    if(sign)
        y4 = y2 - x1 + x2;
    else
        y4 = y2 + x1 - x2;
    return y4;
}

int main()
{
    int cases;
    int index;
    int x1, y1;
    int x2, x3, x4;
    int y2, y3, y4;
    int first, second;
    int counter;

    for(index=0; index<MOSTCASE; index++)
        arr[index] = NULL;

    do
    {
        scanf("%d", &cases);
	if(!cases)
	    break;
	counter = 0;
	HashClear();
	for(index = 0; index < cases; index++){
	    scanf("%d %d", &x1, &y1);
	    Matrix[index][X] = x1; // Matrix used to enumate
	    Matrix[index][Y] = y1;
	    HashStore(x1, y1); //Hash table used to check collification
	}

	for(first = 0; first < cases; first++){
	    x1 = Matrix[first][X];
	    y1 = Matrix[first][Y];
	    for(second = first+1; second < cases; second++){
	        x2 = Matrix[second][X];
		y2 = Matrix[second][Y];

		x3 = GetX3(x1, y1, x2, y2, 0);
		y3 = GetY3(x1, y1, x2, y2, 0);
		x4 = GetX4(x1, y1, x2, y2, 0);
		y4 = GetY4(x1, y1, x2, y2, 0);
		if(HashFind(x3, y3) && HashFind(x4, y4))
		    counter++;

		x3 = GetX3(x1, y1, x2, y2, 1);
		y3 = GetY3(x1, y1, x2, y2, 1);
		x4 = GetX4(x1, y1, x2, y2, 1);
		y4 = GetY4(x1, y1, x2, y2, 1);
		if(HashFind(x3, y3) && HashFind(x4, y4))
		    counter++;
	    }
	}
	counter /= 4; 
	printf("%d\n", counter);
    }while(1);

    return 0;
}
