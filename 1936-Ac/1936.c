
#include <stdio.h>
#include <string.h>

char str1[100002];
char str2[100002];

int findc(char c, char *str, int start)
{
    int len;
    int index;

    len = strlen(str);
    for(index=start; index<len; index++)
	if(str[index] == c)
	    return index;
    return -1;
}

int decode(char *str1, char *str2)
{
    int len1;
    int i, j;
    int res;
    int subdex;;

    len1 = strlen(str1);

    subdex = 0;
    for(i=0; i<len1; i++)
    {
	res = findc(str1[i], str2, subdex);
	if(res >= 0)
	    subdex = res+1;
	else
	    return -1;
    }
    return 0;
}

int main()
{
    while(scanf("%s %s", str1, str2) != EOF)
    {
	if(!decode(str1, str2))
	    printf("Yes\n");
	else
	    printf("No\n");
    }
    return 0;
}
