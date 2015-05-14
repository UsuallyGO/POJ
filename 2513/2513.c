
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG 0

#define MAX_STICKS 50000
#define MAX_MATRIX 50000

char *Dict[MAX_STICKS];
int Matrix[MAX_MATRIX][MAX_MATRIX];
int Father[MAX_MATRIX];
int Visit[MAX_MATRIX];
int Degree[MAX_MATRIX];

int FindStr(char *str, int n)
{
    int index;
    for(index=0; index<n; index++)
    {
	if(strcmp(Dict[index], str) == 0)
	    return index;
    }
    
    return -1;
}

void AddStr(char *str, int n)
{
    if(n < MAX_STICKS)
	Dict[n] = str;	
}

void InitFather()
{
    int index;
    for(index=0; index<MAX_MATRIX; index++)
	Father[index] = -1;
}

int FindFather(int x)
{
    if(Father[x] == -1)
	return x;
    else
    {
	Father[x] = FindFather(Father[x]);
	return Father[x];
    }
}

void Union(int x, int y)
{
    int fx = FindFather(x);
    int fy = FindFather(y);

    if(fx != fy)
	Father[fx] = fy;
}

int EulerCheck(int n)
{
    int zero, z1, z2;
    int first, second;
    int inD, outD;

    zero = 0;
    for(first=0; first<n; first++)
    {
	if(Visit[first] && Father[first] == -1)
	    zero++;
    }
    if(zero > 1)
	return 0;	
    zero = 0;
    z1 = z2 = -1;
    for(first=0; first<n; first++)
    {
	inD = outD = 0;
	for(second=0; second<n; second++)
	{
	    outD += Matrix[first][second];
	    inD += Matrix[second][first];
	}
	Degree[first] = inD - outD;	
	if(Degree[first] == 0)
	    zero++;
	else if(Degree[first] == -1)
	    z1 = first;
	else if(Degree[first] == 1)
	    z2 = first;
    }
    if(zero==n || (zero==n-2 && z1!=-1 && z2!=-1))
	return 1;
    else
	return 0;
}

void ShowDict(int counter)
{
    int index;
    for(index=0; index<counter; index++)
	printf("%s\n", Dict[index]);
}

int main()
{
    char *str;
    char *tmp;
    int counter;
    int x, y;

    counter = 0;
    memset(Matrix, 0, MAX_MATRIX*MAX_MATRIX*sizeof(int)); 
    memset(Visit, 0, MAX_MATRIX*sizeof(int));
    memset(Degree, 0, MAX_MATRIX*sizeof(int));
    InitFather();
    while(1)
    {
	str = (char*)malloc(20*sizeof(char));
	if(fgets(str, 20, stdin) == NULL)
	    break;
	str[strlen(str)-1] = '\0';
	tmp = strtok(str, " ");
	x = FindStr(tmp, counter);
	if(x < 0)
	{
	    x = counter;
	    AddStr(tmp, counter++);
	}
	tmp = strtok(NULL, " ");
	y = FindStr(tmp, counter);
	if(y < 0)
	{
	    y = counter;
	    AddStr(tmp, counter++);
	}
#if DEBUG
    ShowDict(counter);
#endif
	
	Union(x, y);
	Visit[x] = Visit[y] = 1;
	Matrix[x][y]++;
    }
#if DEBUG
    ShowDict(counter);
#endif
    if(EulerCheck(MAX_STICKS))
	printf("Possible\n");
    else
	printf("Impossible\n");
    
    return 0;
}