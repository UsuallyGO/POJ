
#include <stdio.h>
#include <string.h>

#define LEFT -1
#define RIGHT -2

#define DEBUG 0

void Show(int *p, int len)
{
    int index = 0;

    printf("Paren:");
    for(index=0; index<len; index++)
	printf("%d ", p[index]);

    printf("\n");
}

int main()
{
    int index;
    int eles;
    int count;
    int last, current;
    int outter;
    int inner;
    int pare[200];
    int calc[200];

    scanf("%d", &index);
    while(index>0)
    {
	memset(pare, 0, sizeof(pare));
	memset(calc, 0, sizeof(calc));
	scanf("%d", &eles);
	inner = 0;
	outter = 0;
	last = 0;
	for(count=0; count<eles; count++)
	{
	    scanf("%d", &current);
	    inner = current - last;
	    while(inner-->0)
		pare[outter++] = LEFT;

	    pare[outter++] = RIGHT;

	    last = current;
	}

	last = -1;
	current = 0;
	for(inner=0; inner<outter; inner++)
	{
	    switch(pare[inner])
	    {
		case LEFT:
		    calc[++last] = pare[inner];
		    break;
		case RIGHT:
		    current = 0;
		    while(calc[last]!=LEFT)
		    {
			current += calc[last--];
		    }
		    current++;
		    calc[last] = current;
		    printf("%d ", current);
		    break;
		default:
		    ;
	    }
	}
	printf("\n");

#if DEBUG
	Show(pare, outter);
#endif

	index--;
    }

}
