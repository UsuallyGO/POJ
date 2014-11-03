
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG   0
#define YES     1
#define NO      0
#define THE_END 101

int rescount;

int CharCmp(const void *a, const void *b)
{
    return *(char*)a - *(char*)b;
}

int IntCmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

void FreStatis(char *toStatis, int cstrlen, int *result)
{
    char curchar;
    int strcount;
    int	count;

    count = 0;
    strcount = 0;
    rescount = 0;

    curchar = toStatis[0];
    for(; strcount<cstrlen; strcount++)
    {
	if(curchar == toStatis[strcount])
	    count++;
	else
	{
	    result[rescount] = count;
#if DEBUG
	    printf("curchar:%c toStatis[%d]:%c result[%d]:%d@ ", curchar, strcount, toStatis[strcount], rescount, result[rescount]);
#endif
	    curchar = toStatis[strcount];
	    count = 1;
	    rescount++;
	}
    } 

    result[rescount] = count;

#if DEBUG
    printf("result[%d]:%d ", rescount, result[rescount]);
#endif

    result[rescount+1] = THE_END;

#if DEBUG
    printf("result[%d]:%d\n ", rescount+1, result[rescount+1]);
#endif
}

void ShowFre(int *p)
{
    int count;

    count = 0;
    while(1)
    {
	printf("%d", p[count]);

	if(p[count]==THE_END)
	    break;

	count++;
    }

    printf("\n");
}

int FreCmp(int *fre1, int *fre2)
{
    int count;

    count = 0;
    while(1)
    {
	if(fre1[count]==THE_END && fre2[count]==THE_END) 
	    return YES;
	else if(fre1[count]==THE_END || fre2[count]==THE_END)
	    return NO;
	
	if(fre1[count]!=fre2[count])
	    return NO;

	count++;
    }
}

int main()
{
    char encryped[101];
    char original[101];
    int  en_sta[27];
    int  or_sta[27];

    do
    {
	scanf("%s", encryped);
//	getchar();
	scanf("%s", original);
//	getchar();

    #if DEBUG
	printf("encryped:%s\n", encryped);	
	printf("original:%s\n", original);
    #endif

	qsort(encryped, strlen(encryped), sizeof(char), CharCmp);
	qsort(original, strlen(original), sizeof(char), CharCmp);

	FreStatis(encryped, strlen(encryped), en_sta);
	FreStatis(original, strlen(original), or_sta);

	qsort(en_sta, rescount+1,sizeof(int), IntCmp);
	qsort(or_sta, rescount+1,sizeof(int), IntCmp);

    #if DEBUG
	ShowFre(en_sta);
	ShowFre(or_sta);
    #endif

	if(FreCmp(en_sta, or_sta)==YES)
	    printf("YES\n");
	else
	    printf("NO\n");
    }while(0);

    return 0;
}

