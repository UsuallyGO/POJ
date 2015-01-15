
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_COW 100001
#define MAX_FEA 31
#define HASK_KEY 33119

#define DEBUG 1

typedef struct Cow_t
{
    int num;
    struct Cow_t *next;
}Cow;

Cow* Arr[MAX_COW];

int AllCows[MAX_COW][MAX_FEA];
int max;

int CowSame(int index, int key, int features)
{
    int i; 
    Cow *tmp;
    int dis;

    tmp = Arr[key];
    do
    {
       for(i=0; i<features; i++) 
           if(AllCows[index][i] != AllCows[tmp->num][i])
	       break;
	if(i == features)
	{
            dis = fabs(index-Arr[key]->num);
	    if(max < dis)
               max = dis;
	}
	if(tmp->next != NULL)
	   tmp = tmp->next;
	else
	    break;
    }while(1);

    tmp->next = (Cow*)malloc(sizeof(Cow));
    tmp->next->num = index;
    tmp->next->next = NULL;

    return 0;
}

int HashCows(int nums, int features)
{
    int sum;
    int index;
    int i;
    int key;

    for(index = 0; index < nums; index++)
    {
        for(i = 0; i < nums; i++)
	{
	    sum += AllCows[index][i];
	    key = sum%HASK_KEY;
	    if(Arr[key] == NULL)
	    {
	        Arr[key] = (Cow*)malloc(sizeof(Cow));
		Arr[key]->num = index;
		Arr[key]->next = NULL;
	    }
	    else
	    {
	        CowSame(index, key, features);
	    }
	}
    }
}

void ShowAllCows(int nums, int features)
{
    int index;
    int i1;

    for(index = 0; index < nums; index++)
    {
       for(i1 = 0; i1 < features; i1++)
       {
           printf("%d ", AllCows[index][i1]);
       }
       printf("\n");
    }
}

int main()
{
    int nums;
    int features;
    int index;
    int i1;
    int i2;
    int cowfea;
    Cow *cow;

    for(index = 0; index < MAX_COW; index++)
        Arr[index] = NULL;

    scanf("%d %d", &nums, &features);
    index = 1; 
    max = 0;
    while(index <= nums)
    {
        scanf("%d", &cowfea);
	printf("cowfea:%d\n", cowfea);
	    for(i1 = 0; i1 < features; i1++)
	        AllCows[index][i1] = AllCows[index-1][i1] + ((cowfea&(1<<i1))>>i1);

	index++;
    }
    // now Arr is OK
#if 0 
    ShowAllCows(index, features);
#endif
    for(index = 0; index <= nums; index++)
    {
        for(i1 = 0; i1 < features; i1++)
	{
            AllCows[index][i1] -= AllCows[0][i1];
	}
    }
#if DEBUG
    ShowAllCows(index+1, features);
#endif
    HashCows(index+1, features);
    printf("%d\n", max);
    return 0;
}
