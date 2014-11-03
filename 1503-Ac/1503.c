
#include <stdio.h>
#include <string.h>

#define DEBUG 0

char a_num[102];
char sum[102];

char* StrRevs(char *string)
{
    int length;
    int first, last;
    char tmp;

    length = strlen(string);
    first = 0;
    last = length-1;

    for(; first <= last; first++, last--)
    {
	tmp = string[first];
	string[first] = string[last];
	string[last] = tmp;
    }

    return string;
}

char* IntegerSum(char *a_add, char *b_add)
{
    int a_len, b_len;
    int index; 
    int tmp;
    char c_trans;
    int carry;


    c_trans = '0';
    carry = 0;
    a_len = strlen(a_add);
    b_len = strlen(b_add);

#if DEBUG
    printf("---------------------\n");
    printf("strlen(a):%d  strlen(b):%d\n", a_len, b_len);
#endif

    if(a_len > b_len)
    {
	memset(b_add+b_len, '0', sizeof(char)*(a_len-b_len));
	b_add[a_len] = '\0';
	b_len = a_len;
    }
    else if(b_len > a_len)
    {
	memset(a_add + a_len, '0', sizeof(char)*(b_len-a_len));
	a_add[b_len] = '\0';
	a_len = b_len;
    }

#if DEBUG
    printf("Alligned strlen(a):%d  strlen(b):%d\n", a_len, b_len);
    printf("---------------------\n");
#endif

    for(index=0; index<a_len; index++)
    {
	tmp = a_add[index] - c_trans + b_add[index] - c_trans + carry;
	carry = tmp/10;
	tmp = tmp%10;

	b_add[index] = tmp + c_trans;
    }

    if(carry)
    {
	b_add[index] = carry + c_trans;
	b_add[index + 1] = '\0';
    }

    return b_add;
}

int main()
{
    int index;

    memset(sum, '\0', sizeof(sum));

    while(1)
    {
	memset(a_num, '\0', sizeof(a_num));

	scanf("%s", a_num);
	if(strcmp(a_num, "0")==0)
	{
	    StrRevs(sum);
	    printf("%s\n", sum);
	    break;
	}

	index = 0;
	while(a_num[index]=='0')
		index++;

	strcpy(a_num, a_num+index);
#if DEBUG
	printf("a_num:%s\n", a_num);	
#endif

	StrRevs(a_num);
#if DEBUG
	printf("---------------------\n");
	printf("a:%s\n", a_num);
	printf("sum:%s\n", sum);
#endif
	IntegerSum(a_num, sum);
#if DEBUG
	StrRevs(sum);
	printf("Caculate:%s\n", sum);
	printf("---------------------\n");
	StrRevs(sum);
#endif
    }

    return 0;
}
