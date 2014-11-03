
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 1

typedef struct TableMoveSpace
{
    int start;
    int end;
} MoveTable;

MoveTable MvRecord[300];
int Arrange[300];

int NodeCmp(const void* a, const void *b)
{
	
    	return ((MoveTable*)a)->start - ((MoveTable*)b)->start;
}

#if DEBUG
void DisplayRecord(MoveTable *array, int len)
{
    int index;

    for(index=0; index<len; index++)
    {
	printf("%d  %d\n", array[index].start, array[index].end);
    }
}
#endif

int main()
{
    int ck_times;
    int recrd_nums;
    int index;
    int insidex;
    int last;
    int casecount;
    int tmp;

    scanf("%d", &ck_times);

    while(ck_times--)
    {
	memset(MvRecord, 0, sizeof(MoveTable)*300);
	scanf("%d", &recrd_nums);
	for(index=0; index<recrd_nums; index++)
	{
	   scanf("%d%d", &MvRecord[index].start, &MvRecord[index].end); 
	   MvRecord[index].start = (MvRecord[index].start+1)/2;
           MvRecord[index].end = (MvRecord[index].end+1)/2;

	   if(MvRecord[index].start > MvRecord[index].end)
	   {
		tmp = MvRecord[index].start;
		MvRecord[index].start = MvRecord[index].end;
		MvRecord[index].end = tmp;
	   }
	}

	qsort(MvRecord, recrd_nums, sizeof(MoveTable), NodeCmp);
	
#if DEBUG
	DisplayRecord(MvRecord, recrd_nums);
#endif

	memset(Arrange, 0, sizeof(int)*300);
	casecount = 0; 
    
	for(index=0; index<recrd_nums; index++)
	{
		if(Arrange[index]==0)
		{
		    casecount++;
		    last = MvRecord[index].end;
		    Arrange[index] = 1;

		    for(insidex=index+1; insidex<recrd_nums; insidex++)
		    {
			if((last<MvRecord[insidex].start) && Arrange[insidex]==0)
			{
			    Arrange[insidex] = 1;
			    last = MvRecord[insidex].end;
			}
		    }
		}
	}

	printf("%d\n", casecount*10);
    }

    return 0;
}


