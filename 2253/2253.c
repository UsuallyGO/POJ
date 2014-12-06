
#include <stdio.h>
#include <math.h>
#include <float.h>

#define MAX_VERTEX 220
#define DEBUG 0

typedef struct stone_cord
{
	int x;
	int y;
}CORD;

double matrix[MAX_VERTEX][MAX_VERTEX];

#if DEBUG
void show(int max)
{
	int i, j;

	for(i=0; i<max; i++)
	{
		for(j=0; j<max; j++)
		{
			if(matrix[i][j] != FLT_MAX)
				printf("%d %d:%lf\n", i, j, matrix[i][j]);
		}
	}
}
#endif

int power(int x)
{
	return x*x;
}

double max(double a, double b)
{
	if(a > b)
		return a;
	else
		return b;
}

int main()
{
	int cases;
	int index;
	int k, x, y;
	int counter;
	CORD arr[MAX_VERTEX];

	for(x=0; x<MAX_VERTEX; x++)
		for(y=0; y<MAX_VERTEX; y++)
			matrix[x][y] = FLT_MAX;

	counter = 0;
	while(1)
	{
	counter++;
	scanf("%d", &cases);
	if(!cases)
			break;

	for(index=0; index<cases; index++)
		scanf("%d %d", &arr[index].x, &arr[index].y);

	for(x=0; x<cases; x++)
		for(y=0; y<cases; y++)
			matrix[x][y] = sqrt(power(arr[x].x-arr[y].x)+power(arr[x].y-arr[y].y));

#if DEBUG
	show(cases);
	printf("================\n");
#endif
	for(k=0; k<cases; k++)
		for(x=0; x<cases; x++)
			for(y=0; y<cases; y++)
			{
				if(matrix[x][y]>(max(matrix[x][k], matrix[k][y])))
					matrix[x][y] = max(matrix[x][k], matrix[k][y]);
			}
#if DEBUG
	show(cases);
	printf("****************\n");
#endif

	printf("Scenario #%d\n", counter);
	printf("Frog Distance = %.3lf\n", matrix[0][1]);
	}

	return 0;
}
