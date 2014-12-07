
#include <stdio.h>
#include <string.h>

#define MAX_NUM	10002
#define STR_LEN	20

char Dict[MAX_NUM][STR_LEN];
int  Get[MAX_NUM];

void SpellCheck(char *to_check, int nums)
{
    int dicLen;
    int strLen;
    int index;
    int counter;
    int str_index, dict_index;
    int diff;

    printf("%s", to_check);
    strLen = strlen(to_check);
    counter = 0;
    for(index=0; index<nums; index++)
    {
	dicLen = strlen(Dict[index]);
	diff = 0;
	if(strLen == dicLen)
	{
	    for(str_index=0, dict_index=0; str_index<strLen; str_index++, dict_index++)
	    {
		if(to_check[str_index] != Dict[index][dict_index])
		    diff++;
	    }
	    if(diff == 0)
	    {
		printf(" is correct\n");
		return ;
	    }
	    else if(diff == 1)
		Get[counter++] = index;
	    else
		;
	}
	else if(strLen == dicLen + 1)
	{
	   for(str_index=0, dict_index=0; str_index<strLen && dict_index<dicLen; str_index++, dict_index++) 
	   {
		if(to_check[str_index] != Dict[index][dict_index])
		{
		    diff++;
		    dict_index--;
		}
	   }
	   if(diff <= 1)
	    Get[counter++] = index;
	}
	else if(strLen == dicLen - 1)
	{
	    for(str_index=0, dict_index=0; str_index<strLen && dict_index<dicLen; str_index++, dict_index++)
	    {
		if(to_check[str_index] != Dict[index][dict_index])
		{
		    str_index--;
		    diff++;
		}
	    }
	    if(diff <= 1)
		Get[counter++] = index;
	}
	else
	    ;
    }

    printf(": ");
    for(index=0; index<counter; index++)
	printf("%s ", Dict[Get[index]]);
    printf("\n");
}

int main()
{
    int dictNum;
    char tmp[STR_LEN];

    dictNum = 0;
    while(1)
    {
	scanf("%s", Dict[dictNum]);
	if(Dict[dictNum][0] == '#')
	    break;
	else
	    dictNum++;
    }
//    printf("dictNum:%d\n", dictNum);

    while(1)
    {
	scanf("%s", tmp);
	if(tmp[0] == '#')
	    break;
	
	SpellCheck(tmp, dictNum);
    }

    return 0;
}
