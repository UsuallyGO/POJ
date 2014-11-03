
#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000002
#define TRUE	1
#define FALSE	0 

int PrimeTable[MAX_LEN];

int Get_PrimeTable(int max)
{
    int index;
    int	step;

    memset(PrimeTable, TRUE, sizeof(PrimeTable));

    PrimeTable[0] = FALSE;
    PrimeTable[1] = FALSE;

    for(index=2; index < max; index++)
    {
	if(PrimeTable[index])	
	{
	    for(step=index+index; step < max; step+=index)
	    {
		if(PrimeTable[step])
		    PrimeTable[step] = FALSE;
	    }
	}
	
    }
}


void ShowTable(int len)
{
    int index;
    int count;

    count = 0;
    for(index=0; index<len; index++)
    {
	if(PrimeTable[index])
	{
	    printf("%d  ", index);

	    if((count+1)%10 == 0)
		printf("\n");

	    count++;
	}
    }
}

int NthPrime(int base, int increase, int nth)
{
    int count;

    count = 0;
    for(; base<MAX_LEN; base+=increase)
    {
	if(PrimeTable[base])
	{
	    count++;
	    if(count == nth)
		return base;
	}

    }

    return -1;
}

int main()
{
    int length;
    int base, increase, nth;
    int result;

    length = MAX_LEN;
#if DEBUG
    scanf("%d", &length);
#endif

    Get_PrimeTable(length);

    while(1)
    {
	scanf("%d%d%d", &base, &increase, &nth);

	if(!base && !increase && !nth)
	    break;
#if DEBUG
	ShowTable(length);
#endif
	result = NthPrime(base, increase, nth);
	printf("%d\n", result);
    }

    return 0;
}

