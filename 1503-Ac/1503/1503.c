
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG 0
#define MAX 105

void Add(char *a, char *ans)
{
    int i, j, tmp, carry;
    int len; 

    len = strlen(a); 
    memset(a+len, '0', MAX-len);
    memset(ans+strlen(ans), '0', MAX-strlen(ans));

    for(i = 0; i < MAX; i++)
    {
	tmp = a[i] - '0' + ans[i] - '0';
	carry = tmp/10;
	tmp = tmp%10;
	ans[i] = tmp + '0';
	ans[i+1] += carry;
    }

    for(i = MAX-1; i > 0; i--)
    {
	if(ans[i] < '1' || ans[i] > '9')
	    ans[i] = '\0';
	else
	    break;
    }
}    

void strRev(char *p)
{
    int i, len;
    char *rp;

    len = strlen(p);
    rp = (char*)malloc(len);

    for(i = 0; i < len; i++)
	rp[i] = p[len-1-i];
    strcpy(p, rp);
    p[len] = '\0';
    free(rp);
}

void _Prefix(char *a)
{
    int i, j;

    for(i = 0; i < MAX; i++)
	if(a[i] != '0')
	    break;
    for(j = 0; j < MAX - i; j++)
	a[j] = a[j+i];
}

int main()
{
    char strA[MAX];
    char ans[MAX];
    int i;

    memset(ans, '0', sizeof(ans));
    ans[MAX-1] = '\0';
    while(scanf("%s", strA) != EOF)
    {
#if DEBUG
	printf("strA:%s\n", strA);
#endif
	_Prefix(strA);
	strRev(strA);
	Add(strA, ans);
#if DEBUG
	strRev(ans);
	printf("%s\n", ans);
	strRev(ans);
#endif
    }

    strRev(ans);
    i = 0;
    while(1) 
    {
	if(ans[i] != '0')
	    break;
	i++;
    }
    printf("%s\n", ans+i);
    return 0;
}
