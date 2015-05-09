
#include <stdio.h>
#include <time.h>

char letters[8] = {'a', 'b', 'c', 'd', 'e','f', 'g', 'h'};

int main()
{
    int cases;
    int nums;
    int i;

    srand((unsigned int)time(NULL));    
    cases = rand()%100 + 1;

    for(i = 0; i <= cases; i++)
    {
	nums = rand()%8;	
	printf("%c", letters[nums]);
	nums = rand()%8 + 1;
	printf("%d ", nums);
	nums = rand()%8;
	printf("%c", letters[nums]);
	nums = rand()%8 + 1;
	printf("%d \n", nums);
    }

    return 0;
}
