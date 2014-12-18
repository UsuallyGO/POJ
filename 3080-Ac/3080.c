
#include <stdio.h>
#include <string.h>

char strArr[11][61];

int StrMatch(int start, int len, int nums)
{
    int k;
    int klen;
    int index;

    for(k=1; k<nums; k++)
    {
	klen = strlen(strArr[k]);
	for(index=0; index+len<=klen; index++)
	{
	    if(!strncmp(strArr[0]+start, strArr[k]+index, len))//matched
		break; //cmp next string
	}
	if(index+len > klen) //not matched
	    return -1;
    }
    return 0;
}

void ShowStr(int start, int len)
{
    int index;
    for(index=0; index<len; index++)
	printf("%c", strArr[0][index+start]);

    printf("\n");
}

int FindSeq(int n)
{
    int orilen;
    int len;
    int j;
    int flag;
    int start;
    
    orilen = strlen(strArr[0]);
    flag = 0;
    start = -1;
    for(len=orilen; len>=3; len--) //maximum substring to minimum
    {
        for(j=0; j+len<=orilen; j++)
	{
	    if(!StrMatch(j, len, n))//once all matched 
	    {
		flag = 1;
		if(start < 0)
		    start = j;
		else //in alphabetical order
		{
		    if(strncmp(strArr[0]+start, strArr[0]+j, len)>0)
			start = j;
		}
	    }
	}
	if(flag)
	{
	    ShowStr(start, len);
	    return 0;
	}
    }
    printf("no significant commonalities\n");
    return -1;
}

int main()
{
    int cases;
    int m;
    int index;

    scanf("%d", &cases);
    while(cases-- > 0)
    {
	scanf("%d", &m);
	for(index=0; index<m; index++)
	    scanf("%s", strArr[index]);
	
	FindSeq(m);
    }
    
    return 0;
}
