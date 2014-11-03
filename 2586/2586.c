
#include <stdio.h>
#include <string.h>

int surplus, deficit;

int Sum(int *sales, int len)
{
    int index=0; 
    int sum;

    sum = 0;
    for(index=0; index<len; index++)
	sum += sales[index];

    return sum;
}

int Arrange(int *sales, int dnum)
{
    int index = 0;
    int insidex = 0;
    int sum;
    int flag;

    for(index=0; index<12; index++)
    {
	if(index%5 < (5-dnum))
	    sales[index] = surplus;
	else
	    sales[index] = -deficit;
    }

    for(index=0; index<8; index++)
    {
	sum = 0;
	for(insidex = 0; insidex<5; insidex++)
	    sum += sales[index + insidex];
	
	if(sum >= 0)
	    return -1;
    }

    return 0;
}

int main()
{
    int sales[12];
    int index;
    int result;

    while(scanf("%d %d", &surplus, &deficit) != EOF)
    {
	memset(sales, sizeof(int), 12);	
	
	for(index=1; index<6; index++)
	{
	    result = Arrange(sales, index);
	    if(result == 0)
		break;
	}

	result = Sum(sales, 12);
	if(result > 0)
	   printf("%d\n", result);
	else
	    printf("Deficit\n");
    }

    return 0;
}
