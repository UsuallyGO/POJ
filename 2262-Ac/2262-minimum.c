
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_NUM 1000000

int PrimeTable[MAX_NUM];
int LASTONE;

//Applied for num >= 3
int IsPrime(int num)
{
    int sqrt_root;
    int index;

    sqrt_root = (int)sqrt((double)num);

    for(index=3; index<=sqrt_root; index++)
	if(num%index == 0)
	    return 0;
    
    return 1;
}


int main()
{
    int index;
    int number;
    int little_end;
    int big_end;
    int little_index;
    int big_index;

    LASTONE = 0;
    for(index=3; index<MAX_NUM; index++)
    {
	if(IsPrime(index))
	    PrimeTable[LASTONE++] = index;
    }

    while(1)
    {
	scanf("%d", &number);
	if(number == 0)
	    break;

	little_end = floor(number/2.0);
	big_end = ceil(number/2.0);

        for(index=0; index<LASTONE; index++)
	{
	    if(PrimeTable[index] > little_end)
	    {
		little_index = index - 1;
		big_index = index;
		break;
	    }

	    if(PrimeTable[index] == little_end)
	    {
		little_index = index;

		if(PrimeTable[index] == big_end)
		    big_index = index;
		else
		    big_index = index + 1;
	    }
	}

	while(little_index>=0 && big_index<LASTONE)
	{
	    if((PrimeTable[little_index]+PrimeTable[big_index]) == number)
	    {
		printf("%d = %d + %d\n", number, PrimeTable[little_index], PrimeTable[big_index]);
		break;
	    }
	    else if((PrimeTable[little_index]+PrimeTable[big_index]) > number)
		little_index--;
	    else
		big_index++;
	}
	if(little_index<0 || big_index>=LASTONE)
	    printf("Goldbach's conjecture is wrong.\n");
    }

    return 0;
}
