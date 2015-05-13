
#include <stdio.h>

int arr[3][3] = {1, 2, 3, 11, 22, 33, 111,222,333};

int main()
{
    int *p;
    int i;

    p = (int *)arr;
    for(i = 0; i < 9; i++)
	printf("p[%d]:%d ", i, p[i]);
    printf("\n");

    return 0;
}
