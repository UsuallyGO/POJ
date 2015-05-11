
#include <stdio.h>
#include <time.h>

int main()
{
    int cases;
    int i, j, k;
    int m, n, tmp;

    srand((unsigned int)time(0));
    cases = rand()%1000+1 + 500;
    for(i = 0; i < cases; i++)
    {
	m = rand()%10 + 1;
	n = rand()%10 + 1;
	printf("%d %d\n", m, n);

	for(j = 0; j < m; j++)
	{
	    for(k = 0; k < n; k++)
		printf("%2d ", rand()%100 + 1);
	    printf("\n");
	}

    }
    
    return 0;
}
