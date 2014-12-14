
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

#define DEBUG    0
#define MAX_NUM    300

typedef struct Node_t
{
	int elem;
	struct Node_t *next;
}Node;

int Matrix[MAX_NUM][MAX_NUM];
int PRE[MAX_NUM];
int VISIT[MAX_NUM];
Node* Queue;

void Que()
{
	Queue = (Node*)malloc(sizeof(Node));
	Queue->elem = 0;
	Queue->next = NULL;
}

void QueEn(int i)
{
	Node *tmp;
	Node *prev;
	
	prev = Queue;
	tmp = Queue->next;
	while(tmp != NULL)
	{
		prev = tmp;
		tmp = tmp->next;
	}

	tmp = (Node*)malloc(sizeof(Node));
	tmp->elem = i;
	tmp->next = NULL;

	prev->next = tmp;
}

void QueDel()
{
	Node *tmp;
	Node *prev;

	prev = Queue;
	tmp = Queue->next;

	if(tmp != NULL)
	{
		prev->next = tmp->next;
		free(tmp);
	}
	else //emtpy queue
		;
}

int QueFront()
{
	Node *tmp;

	tmp = Queue->next;
	if(tmp != NULL)
		return tmp->elem;
	else
		return -1;
}

int QueEmpty()
{
	if(Queue->next != NULL)
		return 0;
	else
		return 1;	
}

void QueClear()
{
	while(!QueEmpty())
	{
		QueDel();
	}

	free(Queue);
}

int Min(int a, int b)
{
	if(a <= b)
		return a;
	else
		return b;
}

int BFS(int start, int end)
{
	int tmp;
	int index;

	memset(PRE, 0, sizeof(PRE));
	memset(VISIT, 0, sizeof(VISIT));	

	Que();
	QueEn(start);

	while(!QueEmpty())
	{
		tmp = QueFront();
		QueDel();
#if DEBUG
//		printf("Que:%d ", tmp);
#endif 
		for(index=start; index<=end; index++)
		{
			if(!VISIT[index] && Matrix[tmp][index]>0)
			{
				PRE[index] = tmp;
				VISIT[index] = 1;
				if(index == end)
				{
					QueClear();
					return 1;
				}
				QueEn(index);
			}
		}
	}
	return 0;
}

int Edmons_Karp(int start, int end)
{
	int flows;
	int d;
	int index;

	flows = 0;
	while(BFS(start, end))
	{
		d = INT_MAX;
		for(index=end; index!=start; index=PRE[index])
			d = Min(d, Matrix[PRE[index]][index]);

		for(index=end; index!=start; index=PRE[index])
		{
			Matrix[PRE[index]][index] -= d;
			Matrix[index][PRE[index]] += d;
		}
		flows += d;
	}
	return flows;
}

#if DEBUG
void PrintGraph(int nums)
{
	int first, second;

	for(first=1; first<=nums; first++)
	{
		for(second=1; second<=nums; second++)
			printf("%d ", Matrix[first][second]);
		printf("\n");
	}
}

void PrintQue(int nums)
{
	Node *tmp;

	tmp = Queue->next;

	while(tmp != NULL)
	{
		printf("%d ", tmp->elem);
		tmp = tmp->next;
	}
}
#endif

int main()
{
	int enums, vnums;
	int x, y, value;
	int index;
	int maxflow;
	int tmp;

	while(scanf("%d %d", &enums, &vnums) != EOF)
	{
		memset(Matrix, 0, sizeof(Matrix));

		for(index=1; index<=enums; index++)
		{
			scanf("%d %d %d", &x, &y, &value);
			Matrix[x][y] += value;
		}
#if DEBUG
		PrintGraph(vnums);
#endif
		maxflow = Edmons_Karp(1, vnums);
		printf("%d\n", maxflow);
#if 0 
		printf("Input nodes nums:");
		scanf("%d", &tmp);
		Que();
		for(index=0; index<tmp; index++)
		{
			scanf("%d", &value);
			QueEn(value);
		}
		printf("Print Queue.\n");
		while(!QueEmpty())
		{
			tmp = QueFront();
			printf("%d ", tmp);
			QueDel();
		}
#endif
	}

	return 0;
}
