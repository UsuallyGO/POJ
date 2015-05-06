
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG	1
#define MAXLEN  100001

char** Dict;
int** Matrix;

void MatrixInit(int n)
{
    int first, second;
    
    for(first=0; first<n; first++)
	for(second=0; second<n; second++)
	    Matrix[first][second] = -2;
}

int EulerCheck(int n) //Directed graph Euler check
{
    int first, second;
    int *Degree;
    int zero, z1, z2;

    Degree = (int*)malloc(n*sizeof(int));
    memset(Degree, 0, n*sizeof(int));
    zero = 0;
    z1 = z2 = -1;

    for(first = 0; first<n; first++)
    {
	zero = 0;
	for(second=0; second<n; second++)
	{
	    if(first == second)
		continue;
	    zero += Matrix[first][second];	    
	}

	if(zero == -2*(n-1))
	    return 0;
    }
    zero = 0;
    for(first=0; first<n; first++)
    {
	for(second=0; second<n; second++)
	{
	    if(Matrix[first][second] != -2)
		Degree[first] -= Matrix[first][second];
	    if(Matrix[second][first] != -2)
		Degree[first] += Matrix[second][first];
	}
	if(Degree[first] == 0)
	    zero++;
	else if(Degree[first] == -1)
	    z1 = first;
	else if(Degree[first] == 1)
	    z2 = first;
#if DEBUG
    printf("%d ", Degree[first]);
#endif
    }

    if(zero == n || (zero == n-2 && z1 != -1 && z2 != -1))
	return 1;
    else
	return 0;
#if DEBUG
    printf("\n");
#endif
}

#if DEBUG
void ShowDict(int n)
{
    int counter;

    for(counter=0; counter<n; counter++)
	printf("%s\n", Dict[counter]);
}

void ShowMatrix(int n)
{
    int first, second;

    for(first=0; first<n; first++)
    {
	for(second=0; second<n; second++)
	    printf("%d ", Matrix[first][second]);
	printf("\n");
    }
}
#endif

int main()
{
    int cases;
    int n;
    int index;
    int counter;
    char begin, end;

    scanf("%d", &cases);
    while(cases-- > 0)
    {
	scanf("%d", &n);
	Dict = (char**)malloc(sizeof(char*)*n);
	Matrix = (int**)malloc(sizeof(int*)*n);

	for(index=0; index<n; index++)
	{
	    Matrix[index] = (int*)malloc(sizeof(int)*n);
	    Dict[index] = (char*)malloc(MAXLEN);
	    scanf("%s", Dict[index]);
	}
	MatrixInit(n);

	for(index=0; index<n; index++) //get degrees
	{
	   end = Dict[index][strlen(Dict[index])-1];
	   for(counter=0; counter<n; counter++)
	   {
		if(index == counter)
		    continue;
		begin = Dict[counter][0];
		if(end == begin)
		    if(Matrix[index][counter] == -2)
			Matrix[index][counter] = 1;
		    else
			Matrix[index][counter]++;
	   }
	}
	if(EulerCheck(n))
	    printf("Ordering is possible.\n");
	else
	    printf("The door cannot be opened.\n");
#if DEBUG
	ShowDict(n);
	ShowMatrix(n);
#endif
    };

    return 0;
}
