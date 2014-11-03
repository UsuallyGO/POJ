
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

    if(num%2 == 0)
	return 0;

    sqrt_root = (int)sqrt((double)num);

    for(index=2; index<=sqrt_root; index++)
	if(num%index == 0)
	    return 0;
    
    return 1;
}

int E_IsPrime(int max)
{
    int index;
    int in_index;
    int	length;

    for(index=2; index<max; index++)
	PrimeTable[index] = 1;

    for(index=2; index<max; index++)
    {
	if(PrimeTable[index])
	{
	    for(in_index=index+index; in_index<max; in_index+=index)
		PrimeTable[in_index]=0;
	}
    }

    length = 0;
    for(index=3; index<max; index++)
    {
	if(PrimeTable[index])
	{
	    PrimeTable[length++] = index;
	}
    }

    return length;
}

void ShowPrimeTable(int table[], int len)
{
    int index;

    for(index=0; index<len; index++)
    {
	printf("%d ", PrimeTable[index]);

	if((index+1)%10 == 0)
	    printf("\n");
    }
}


int main()
{
    int number;
    int little_index;
    int big_index;

    LASTONE = 0;
    LASTONE = E_IsPrime(MAX_NUM);
/*
    for(little_index=3; little_index<MAX_NUM; little_index++)
    {
	if(IsPrime(little_index))
	    PrimeTable[LASTONE++] = little_index;
    }
    */

//    ShowPrimeTable(PrimeTable, LASTONE);

    while(1)
    {
	scanf("%d", &number);
	if(number == 0)
	    break;

	little_index = 0;
	for(big_index=0; big_index<LASTONE; big_index++)
	{
	    if(PrimeTable[big_index] >= number)
	    {
		big_index--;
		break;
	    }
	}
	if(big_index == LASTONE)
	    big_index--;

	while(little_index <= big_index)
	{
	    if((PrimeTable[little_index]+PrimeTable[big_index]) == number)
	    {
		printf("%d = %d + %d\n", number, PrimeTable[little_index], PrimeTable[big_index]);
		break;
	    }
	    else if((PrimeTable[little_index]+PrimeTable[big_index]) < number)
		little_index++;
	    else
		big_index--;
	}

	if(little_index > big_index)
	    printf("Goldbach's conjecture is wrong.\n");
    }

    return 0;
}
