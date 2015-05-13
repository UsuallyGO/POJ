
#include <stdio.h>
#include <time.h>

char NUMBERS[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int main()
{
    int n, m, k;
    int i, j, t;
    char str[11];
    
    srand((unsigned int)time(NULL));
    n = rand()%10 + 1;
    printf("%d\n", n);
    
    for(i = 0; i < n; i++)
    {
	m = rand()%9 + 1;	
	printf("%d\n", m);
	for(j = 0; j < m; j++)
	{
	    k = rand()%9 + 1;
	    for(t = 0; t < k; t++)
		str[t] = NUMBERS[rand()%10];
	    str[k] = '\0';
	    printf("%s\n", str);
	}
    }

    return 0;
}
