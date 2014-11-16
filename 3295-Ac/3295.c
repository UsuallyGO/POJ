
#include <stdio.h>
#include <string.h>

int Mask[5] = { 0b10000, 0b01000, 0b00100, 0b00010, 0b00001};
int Sit[32];
char calc[110];

int main()
{
    char input[110];
    int	 index, inner;
    int length;
    int in_mask;
    int flag;
    int downer, upper;
    int indexT;

    length = 0b11111;
    for(index=0; index<=length; index++)
	Sit[index] = index;

    while(1)
    {
	memset(input, 0, 110);
	scanf("%s", input);
	if(input[0] == '0')
	    break;
	length = strlen(input);
	
	for(indexT=0; indexT<32; indexT++)
	{
	    memset(calc, 0, 110);
	    for(inner=0; inner<length; inner++)
	    {
		flag = 1;
		switch(input[inner])
		{
		    case 'p':
			in_mask = 0;
			break;
		    case 'q':
			in_mask = 1;
			break;
		    case 'r':
			in_mask = 2;
			break;
		    case 's':
			in_mask = 3;
			break;
		    case 't':
			in_mask = 4;
			break;
		    default:
			flag = 0;
		}
		if(flag == 1)
		{
		    if(Sit[indexT] & Mask[in_mask])
			calc[inner] = '1';
		    else
			calc[inner] = '0';
		}
		else
		    calc[inner] = input[inner];
	    }//inner
	    for(index=length-1; index>=0; index--)
	    {
		switch(calc[index])
		{
		    case 'K':
			downer = calc[index+2] - '0';
			upper = calc[index+1] - '0';
			calc[index] = (downer&&upper) + '0';
			break;
		    case 'A':
			downer = calc[index+2] - '0';
			upper = calc[index+1] - '0';
			calc[index] = (downer||upper) + '0';
			break;
		    case 'N':
			downer = calc[index+1] - '0';
			calc[index] = (!downer&&0x1) + '0';
			break;
		    case 'C':
			downer = calc[index+2] - '0';
			upper = calc[index+1] - '0';
			calc[index] = (!upper||downer) + '0';
			break;
		    case 'E':
			downer = calc[index+2] - '0';
			upper = calc[index+1] - '0';
			if(downer == upper)
			    calc[index] = '1';
			else
			    calc[index] = '0';
			break;
		    default:
			continue;
		}
	    }
	    if(calc[0] == '0')
	    {
		printf("not\n");
		break;
	    }
	}//32 sit
	if(indexT == 32)
	    printf("tautology\n");
    }//while
    return 0;
}
