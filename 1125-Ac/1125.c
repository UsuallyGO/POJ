
#include <stdio.h>
#include <string.h>

#define MAX_INT		0x3fffffff
#define MAX_VERTEX	100
#define DEBUG		0

int Matrix[MAX_VERTEX][MAX_VERTEX];
int Dist[MAX_VERTEX][MAX_VERTEX];

#if DEBUG
void Show(int array[][MAX_VERTEX], int vertex)
{
	int first, second;

	for(first=1; first<=vertex; first++)
	{
		for(second=1; second<=vertex; second++)
			printf("%d ", array[first][second]);
		printf("\n");
	}
		
}
#endif

void Floyid(int vertex)
{
	int first, second;
	int k;

	for(first=1; first<=vertex; first++)
		for(second=1; second<=vertex; second++)
			Dist[first][second] = Matrix[first][second];

	for(k=1; k<=vertex; k++)
		for(first=1; first<=vertex; first++)
			for(second=1; second<=vertex; second++)
			{
				if(Dist[first][second] > Dist[first][k]+Dist[k][second])
					Dist[first][second] = Dist[first][k] + Dist[k][second];
			}
}

int FindShort(int vertex, int *num, int *dis)
{
	int first, second;
	int row_max, min;
	int row;
	int flag;

	min = MAX_INT;
	row = 1;
	flag = 0;
	for(first=1; first<=vertex; first++)
	{
		row_max = 0;
		for(second=1; second<=vertex; second++)
		{
			if(Dist[first][second] == MAX_INT)
				flag++;

			if(Dist[first][second] > row_max)
				row_max = Dist[first][second];
		}

		if(row_max < min)
		{
			min = row_max;
			row = first;
		}
	}

	if(flag == vertex)
		return -1;

	*dis = min;
	*num = row;

	return 1;
}

int main()
{
	int vertex;
	int index;
	int first, second;
	int tmp;

	do
	{
		scanf("%d", &vertex);
		if(!vertex)
			break;

		memset(Matrix, 0, sizeof(int)*MAX_VERTEX*MAX_VERTEX);
		for(index=1; index<=vertex; index++)
		{
			scanf("%d", &first);
			for(second=0; second<first; second++)
			{
				scanf("%d", &tmp);
				scanf("%d", &Matrix[index][tmp]);
			}
		}

		for(first=1; first<=vertex; first++)
			for(second=1; second<=vertex; second++)
			{
				if(first!=second && !Matrix[first][second])
						Matrix[first][second] = MAX_INT;
			}

#if DEBUG
		Show(Matrix, vertex);
#endif
		Floyid(vertex);
#if DEBUG
		Show(Dist, vertex);
#endif
		if(FindShort(vertex, &first, &second)<0)
			printf("disjoint\n");
		else
			printf("%d %d\n", first, second);
	}while(1);
	
	return 0;
}
