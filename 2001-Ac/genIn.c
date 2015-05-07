
#include <stdio.h>
#include <time.h>

#define RANGE 5

int main()
{
    int i, j, cases;
    int length;
    char letters[RANGE] = { 'a', 'b', 'c', 'd', 'e'};

    srand((unsigned int)time(NULL));
    cases = rand()%100 + 1; //how many words

    for(i = 0; i < cases; i++)
    {
	length = rand()%15 + 1;	
	for(j = 0; j < length; j++)
	    printf("%c", letters[rand()%RANGE]); 
	printf("\n");
    }
    return 0;
}
