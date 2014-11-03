
#include <stdio.h>

#define OPEN '-'
#define CLOSE '+'

int Mask[] = {
		63624, 62532, 61986, 61713,
		36744, 20292, 12066, 7953,
		35064, 17652, 8946, 4593,
		34959, 17487, 8751, 4383,
	     };

int count;

int DFS(int state, int old)
{
    int index;

    if(state == 0x0)
    {
	printf("%d\n", count);
	return count;
    }

    for(index=old+1; index<16; index++)
    {
	count++;
	if(DFS(state^Mask[index], index) != -1)
	{
	    printf("%d %d\n", index/4+1, index%4+1);
	    return count;
	}
	else
	    count--;
    }
    return -1;
}

int main()
{
    char qipan[4];
    int index;
    int insidex;
    int state;
    int result;

    state = 0;
    for(index=0; index<4; index++)
    {
	scanf("%s", qipan);
	getchar();

	for(insidex=0; insidex<4; insidex++)
	{
	    state <<= 1;
	    if(qipan[insidex] == CLOSE)
		state += 1;
	}

    }

    DFS(state, -1);

    return 0;
}

