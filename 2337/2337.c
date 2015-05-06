
#include <stdio.h>
#include <string.h>

#define DEBUG 1
#define CASES 1001
#define STRLEN 21

typedef struct Edge_t
{
    int pos;
    int start;
    int end;
    int flag;
}Edge;

char dict[CASES][STRLEN];
Edge Arr[CASES];
int Matrix[CASES][CASES];
int Circuit[CASES];
int top;
int counter;

void ShowArr(int num)
{
    int first, second;

    for(first = 0; first < num; first++)
    {
        printf("Pos:%d Start:%d End:%d\n", Arr[first].pos, Arr[first].start, Arr[first].end);
    }
}

int Cmp(const void *s1, const void *s2)
{
    return strcmp(s1, s2);
}

void MatrixOper(int num)
{
    int index;
    int first, second;

    qsort(dict, num, STRLEN, Cmp);

    for(index = 0; index < num; index++)
    {
        Arr[index].pos = index;
	Arr[index].start = dict[index][0] - 'a';
	Arr[index].end = dict[index][strlen(dict[index])-1] - 'a';
    }

#if DEBUG
    ShowArr(num);
#endif
    memset(Matrix, 0, CASES*CASES*sizeof(int));
    for(first = 0; first < num; first++)
        for(second = 0; second < num; second++)
	{
	    if(first != second)
	    {
	        if(Arr[first].end == Arr[second].start)
		{
		    Matrix[Arr[first].pos][Arr[second].pos] = 1;
//		    Matrix[Arr[second].pos][Arr[first].pos] = 1;
		}

		if(Arr[first].start == Arr[second].end)
		{
		    Matrix[Arr[second].pos][Arr[first].pos] = 1;
//		    Matrix[Arr[first].pos][Arr[second].pos] = 1;
		}
	    }
	}
}

void Dfs(int index, int num)
{
    int first;

    top++;
    Circuit[top] = index;
    for(first = 0; first < num; first++)
    {
        if(Matrix[Circuit[top]][first])
	{
	    Matrix[Circuit[top]][first] = 0;
	    Matrix[first][Circuit[top]] = 0;
	    Dfs(first, num);
	    break;
	}
    }
}

void Fleury(int start, int num)
{
    int index;
    int bridge;

    top = 0;

    memset(Circuit, 0, CASES*sizeof(int));
    Circuit[top] = start;
    counter = 0;
    while(top >= 0)
    {
        bridge = 1;
        for(index = 0; index < num; index++)
	{
	     if(Matrix[Circuit[top]][index])
	     {
	         bridge = 0;
		 break;
	     }
	}

	if(bridge)
	{
	    printf("%s", dict[Circuit[top]]);
	    counter++;
	    if(counter<num)
		printf(".");
	    else
	        printf("\n");
	    top--;
	}
	else
	{
	    top--;
	    Dfs(Circuit[top+1], num);
	}
    }
}

void ShowMatrix(int num)
{
    int first, second;

    for(first = 0; first < num; first++)
    {
        for(second = 0; second < num; second++)
	{
	    printf("%d ", Matrix[first][second]);
	}
	printf("\n");
    }
}

void Euler(int num)
{
    int start;
    int x, y;
    int first, second;
    int degree[num];

    MatrixOper(num);
#if DEBUG
    ShowMatrix(num);
#endif 
    memset(degree, 0, sizeof(int)*num);
    for(first=0; first<num; first++)
    {
	for(second = 0; second < num; second++)
	{
	    if(Matrix[first][second])
	    {
	        degree[first]--;
		degree[second]++;
	    }
	}
    }

    x = 0;
    y = start = -1;
    for(first = 0; first < num; first++)
    {
        if(degree[first] != 0)
	    x++;
	if(degree[first] == -1)
	    start = first;
        if(degree[first] == 1)
	    y = first;
    }

    if(x!=0 && x!=2)
        printf("***\n");
    else if( y < 0 || start < 0)
        printf("***\n");

    Fleury(start, num);
}

int main()
{
    int index;
    int cases;
    int num;
    int first;

    scanf("%d", &cases);
    index = 0; 
    while(index < cases)
    {
        scanf("%d", &num); 
	for(first = 0; first < num; first++)
	    scanf("%s", dict[first]);
	
	Euler(num);
        index++;
    }
    
    return 0;
}
