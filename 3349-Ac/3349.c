
#include <stdio.h>
#include <stdlib.h>

#define ARMS  6
#define HASH_KEY  999983
#define ARMMAX 1000001

typedef struct Snow_t
{
    int arms[ARMS];
    struct Snow_t *next;
}Snow;

Snow* Arr[ARMMAX];

void SortArr(Snow *s)
{
    int i, j;
    int tmp;

    for(i = 0; i < ARMS; i++)
    {
        for(j = i+1; j < ARMS; j++)
	{
	    if(s->arms[i] > s->arms[j])
	    {
	        tmp = s->arms[i];
		s->arms[i] = s->arms[j];
		s->arms[j] = tmp;
	    }
	}
    }
}

int HashSame(Snow *s1, Snow *s2)
{
   int index;
   int i;

   SortArr(s1);
   SortArr(s2);
   for(index = 0; index < ARMS; index++)
   {
       if(s1->arms[index] != s2->arms[index])
           return 0;
   }
   return 1;
}

int HashSnow(Snow *s)
{
    int sum;
    int index;
    Snow *tmp;

    sum = 0;
    for(index=0; index < ARMS; index++)
        sum += s->arms[index];

    sum = sum%HASH_KEY;
    tmp = Arr[sum];
    if(tmp == NULL)
    {
        Arr[sum] = s;
	return 0;
    }
    else
    {
        do
	{
	    index = HashSame(s, tmp);
	    if(index)
	        return 1;
	    if(tmp->next == NULL)
	        break;
	    else
	        tmp = tmp->next;
	}while(1);

	tmp->next = s;
	return 0;
    }
}

int main()
{
   int cases;
   int index;
   int i;
   Snow *snow;

   for(index = 0; index < ARMMAX; index++) 
       Arr[index] = NULL;

   scanf("%d", &cases);
   index = 0;
   while(index < cases)
   {
       snow = (Snow*)malloc(sizeof(Snow));
       snow->next = NULL;
       for(i = 0; i < ARMS; i++)
           scanf("%d ", &snow->arms[i]);
	i = HashSnow(snow);
	if(i)
	{
	    printf("Twin snowflakes found.\n");
	    return 0;
	}
       index++;
   }
   printf("No two snowflakes are alike.\n");
   return 0;
}

