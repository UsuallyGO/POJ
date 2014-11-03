
#include <stdio.h>
#include <string.h>

#define DEBUG 0
#define LENGTH 255
#define CHAR_BASE 'A'

int CheckSum(char *str, int len)
{
    int sum;
    int tmp;
    int index;

    sum = 0;
    for(index=0; index<len; index++)
    {
	if(str[index] == ' ')
	    tmp = 0;
	else
	    tmp = str[index] - CHAR_BASE + 1;
    
	sum += tmp*(index+1);
    }

    return sum;
}


int main()
{
   char sequence[LENGTH];
   int length;
   int sum;

    while(1)
    {
	length = 0;
	while(1)
	{
	    scanf("%c", &sequence[length]);
	    if(sequence[length] == '\n')
		break;

	    length++;
	}
	sequence[length] = '\0';
	
	if(!strcmp(sequence, "#"))
	    break;
	
	sum = CheckSum(sequence, length);
#if DEBUG
	printf("%s %d\n", sequence, length);
#endif
	printf("%d\n", sum);
    }

    return 0;
}
