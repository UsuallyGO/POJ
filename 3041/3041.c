
#include <stdio.h>
#include <string.h>

#define MAX_NUM 	600

int Visited[MAX_NUM];
int Matrix[MAX_NUM][MAX_NUM];
int Source[MAX_NUM];

int Hungary(int n, int m)
{
	int index;

	for(index=1; index<=m; index++)
	{
		if(!Visited[index] == Matrix[n][index])
		{
			Visited[index] = 1;
			if(!Source[index] || Hungary(Source[index], m))
			{
				Source[index] = n;
				return 1;
			}
		}
	}	

	return 0;
}

int main()
{
		int n, m;
		int x, y;
		int index;
		int counter;

		while(scanf("%d %d", &n, &m)!=EOF)
		{
			memset(Matrix, 0 ,sizeof(Matrix));
			memset(Source, 0, sizeof(Source));
			for(index=1; index<=m; index++)
			{
				scanf("%d %d", &x, &y);
				Matrix[x][y] = 1;
			}
			
			counter = 0;
			for(index=1; index<=n; index++)
			{
				memset(Visited, 0, sizeof(Visited));
				if(Hungary(index, n))
					counter++;
			}
			printf("%d\n", counter);
		}

		return 0;
}
