
#include <stdio.h>
//#include <stdlib.h>
#include <string.h>

#define MAX_NUM 30
#define CTON(x)	(x-'A')

int Matrix[MAX_NUM][MAX_NUM];
int Degree[MAX_NUM];
int Sorted[MAX_NUM];
int SIGN;

void Show(int n)
{
    int first, second;
    
    for(first=0; first<n; first++)
    {
	for(second=0; second<n; second++)
	    printf("%d ", Matrix[first][second]);
	
	printf("\n");
    }
}

void ShowDegree(int n)
{
    int index;

    printf("Degree:");
    for(index=0; index<n; index++)
	printf("%d ", Degree[index]);
    printf("\n");
}

void ShowSort(int n)
{
    int index = 0;

    for(index=0; index<n; index++)
	printf("%c", Sorted[index]+'A');
}

int ToPo(int n)
{
    int counter;
    int index;
    int curr, flag;
    int loc;
    int tmpdegree[MAX_NUM];

    counter = 0;
    flag = 0;
    memcpy(tmpdegree, Degree, sizeof(Degree));

    while(counter<n)
    {
	loc = 0;
	for(index=0; index<n; index++)
	    if(tmpdegree[index]==0)
	    {
		curr = index;
		loc++;
	    }

	if(loc == 0) 
	    return -1;
	else if(loc > 1)
	    flag = -2;
	
	Sorted[counter] = curr; //find in-degree zero vertex
	tmpdegree[curr] = -1;
	for(index=0; index<n; index++)
	{
	    if(Matrix[curr][index])
		tmpdegree[index]--;
	}
	counter++;
    }
    return flag;
}

int main()
{
   int index;
   int n, m;
   int result;
   char c1, c2;
   char nons[100];

    while(1)
    {
	scanf("%d %d", &n, &m);
	fgets(nons, 100, stdin);
	if(!n && !m)
	    break;

	memset(Matrix, 0, sizeof(Matrix));
	memset(Degree, 0, sizeof(Degree));
	SIGN = 0;
	for(index=0; index<m; index++)
	{
	    scanf("%c<%c", &c1, &c2);
	    fgets(nons, 100, stdin);

	    if(SIGN != 0)
		continue;

	    Matrix[CTON(c1)][CTON(c2)] = 1;
	    Degree[CTON(c2)]++;

	    result = ToPo(n);
	    if(!result)
	    {
		SIGN = 1;
		printf("Sorted sequence determined after %d relations: ", index+1);
		ShowSort(n);
		printf(".\n");
	    }
	    else if(result == -1)
	    {
		SIGN = -1;
		printf("Inconsistency found after %d relations.\n", index+1);
	    }
	    else
		continue;
	}
	if(SIGN == 0)
	    printf("Sorted sequence cannot be determined.\n");
    }

    return 0;
}

