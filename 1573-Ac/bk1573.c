
#include <stdio.h>
#include <stdlib.h>

#define DEBUG 0

#define EXIT 0
#define LOOP 1
#define FINE 2

#define E -1 
#define N -2 
#define W -3
#define S -4

#if DEBUG
void show(int **p, int len, int wid)
{
    int index, second;

    for(index=0; index<len; index++)
    {
	for(second=0; second<wid; second++)
	    printf("%d ", p[index][second]);
	
	printf("\n");
    }
}
#endif 

int main()
{
    int row, col, pos;
    int **qipan;
    char *qizi;
    int index;
    int sec_in;
    int steps;
    int flags;
    int cur;

    while(1)
    {
	scanf("%d %d %d", &row, &col, &pos);
	if(!row && !col && !pos)
	    break;

	printf("row:%d col:%d pos:%d\n", row, col, pos);
	
	qipan = (int**)malloc(sizeof(int*)*row);
	for(index=0; index<row; index++)
	    qipan[index] = (int*)malloc(sizeof(int)*col);
	
	for(index=0; index<row; index++)
	    free(qipan[index]);
	free(qipan);
    }

    return 0;
}
