
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define DEBUG 0

#if DEBUG
void show(char p[][8], int len)
{
    int index;
    int second;

    for(index=0; index<len; index++)
    {
	for(second=0; second<8; second++)
	    printf("%c ", p[index][second]);
	printf("\n");
    }
}
#endif

char bound[100] = "+---+---+---+---+---+---+---+---+";


int main()
{
    char input[400];
    char qipan[8][8];
    char output[38];
    int index;
    int length;
    int row, col;
    int tmp;
    memset(qipan, 'z', 8*8);

    for(tmp=0; tmp<2; tmp++)
    {
	//fgets(input, 200, stdin);
	gets(input);
	length = strlen(input) - 1;
	index = 7;

	while(index < length)
	{
	    if(!islower(input[index]))
	    {
		col = input[index+1] - 'a';
		row = 8 - input[index+2] + '0';
		if(tmp ==0)
		    qipan[row][col] = input[index];
		else
		    qipan[row][col] = tolower(input[index]);
		index += 4;
	    }
	    else
	    {
		col = input[index] - 'a';
		row = 8 - input[index+1] + '0';
		if(tmp == 0)
		    qipan[row][col] = 'P';
		else
		    qipan[row][col] = 'p';
		index += 3;
	    }
	}
    }

#if DEBUG
    show(qipan, 8);
#endif
    printf("%s\n", bound);
    for(index=0; index<8; index++)
    {
	memset(output, 0, 34);
	if(index%2 == 0)
	    strcpy(output, "|...|:::|...|:::|...|:::|...|:::|");
	else
	    strcpy(output, "|:::|...|:::|...|:::|...|:::|...|");
	
	for(col=0; col<8; col++)
	{
	    if(qipan[index][col] != 'z')
		output[col*4+2] = qipan[index][col];
	}
	printf("%s\n", output);
	printf("%s\n", bound);
    }

    return 0;
}
