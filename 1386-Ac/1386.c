
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG 0
#define MAX_LEN 26
#define STR_LEN 100001

int Matrix[MAX_LEN][MAX_LEN];
int Father[MAX_LEN]; //use this array to judge the connectivity
int Visit[MAX_LEN];

#if DEBUG
void ShowMatrix()
{
    int first, second;

    printf("--------------------\n");
    for(first = 0; first < MAX_LEN; first++)
    {
	for(second=0; second<MAX_LEN; second++)
	    printf("%d ", Matrix[first][second]);
	printf("\n");
    }
}
#endif

int DegreeCheck()
{
    int Degree[MAX_LEN];
    int inDeg, outDeg;
    int first, second;
    int zero, z1, z2;

    memset(Degree, 0, MAX_LEN*sizeof(int));
    zero = 0;
    z1 = z2 = -1;
    for(first=0; first<MAX_LEN; first++)
	if(Visit[first] && Father[first] == -1)
	    zero++;
    if(zero > 1)
	return 0;
    zero = 0;
    for(first=0; first<MAX_LEN; first++)
    {
	outDeg = inDeg = 0;
	for(second=0; second<MAX_LEN; second++)
	{
	   outDeg += Matrix[first][second]; 
	   inDeg += Matrix[second][first];
	}

	Degree[first] = inDeg - outDeg;
	if(Degree[first] == 0)
	    zero++;
	else if(Degree[first] == -1)
	    z1 = first;
	else if(Degree[first] == 1)
	    z2 = first;
#if DEBUG
	printf("D[%d]:%d ", first, Degree[first]);
#endif
    }
#if DEBUG
    printf("\n");
    printf("zero:%d z1:%d z2:%d\n", zero, z1, z2);
#endif
    if(zero == MAX_LEN || (zero==MAX_LEN-2 && z1!=-1 && z2!=-1))
	return 1;
    else
	return 0;
}

void InitFather()
{
    int first = 0;
    for(first=0; first<MAX_LEN; first++)
	Father[first] = -1;
}

int FindFa(int x)
{
    if(Father[x] == -1)
	return x;
    else
    {
	Father[x] = FindFa(Father[x]);
	return Father[x];
    }
}

void Union(int x, int y)
{
    int fx = FindFa(x), fy = FindFa(y);    
    if(fx != fy)
    {
	Father[fx] = fy;
    }
}

int main()
{
    int cases;
    int n;
    char str[STR_LEN];
    int first, second;

    scanf("%d", &cases);
    while(cases-- > 0)
    {
	memset(Matrix, 0, MAX_LEN*MAX_LEN*sizeof(int));
	InitFather();
	memset(Visit, 0, MAX_LEN*MAX_LEN*sizeof(int));
	scanf("%d", &n);	
	for(first=0; first<n; first++)
	{
	    scanf("%s", str);
	    Matrix[str[0]-'a'][str[strlen(str)-1]-'a'] += 1;
	    Union(str[0]-'a', str[strlen(str)-1]-'a');
	    Visit[str[0]-'a'] = Visit[str[strlen(str)-1] - 'a'] = 1;
	}
	if(DegreeCheck())
	    printf("Ordering is possible.\n");
	else
	    printf("The door cannot be opened.\n");
#if DEBUG
//    ShowMatrix();
#endif
    }

    return 0;
}
