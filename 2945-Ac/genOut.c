
#include <stdio.h>
#include <time.h>

char DNA[4] = {'A', 'C', 'G', 'T'};

int main()
{
    int n, m;
    int i, j;
    int counter = 0;

    srand((unsigned int)time(NULL)); 

    while(1)
    {
    n = rand()%100 + 1;
//    m = rand()%3 + 1;
    m = 2;

    printf("%d %d\n", n, m);

    for(j = 0; j < n; j++)
    {
	for(i = 0; i < m ; i++)
	    printf("%c", DNA[rand()%4]);
	printf("\n");
    }
	if(counter == 5)
	    break;
	counter++;
    }
    printf("0 0\n");

    return 0;
}
