
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NUM	    300

typedef struct Elemen_t 
{
    int num;
    char c;
}Elemen;

typedef struct Point_t
{
    int x;
    int y;
    int dis;
}Point;

typedef struct QueEle_t
{
    Point  QData;
    struct QueEle_t *next;
}QueEle;

typedef QueEle* Queue; 
Queue Head;
Queue Tail;

Elemen Arr[MAX_NUM][MAX_NUM];
int m, n;
int  Matrix[MAX_NUM][MAX_NUM];
int  Visit[MAX_NUM][MAX_NUM];
int  DIREC_X[4] = {-1, 0, 1, 0};
int  DIREC_Y[4] = {0, 1, 0, -1};

int Set[MAX_NUM];
int Dist[MAX_NUM];

int Prim(int n)
{
    int sum;
    int first, second;
    int index;
    int min,u;

    for(index=1; index<n; index++)
    {
	Dist[index] = Matrix[0][index];
	Set[index] = 0;
    }

    Dist[0] = 0;
    Set[0] = 1;
    sum = 0;

    for(index=1; index<n; index++)
    {
	min = INT_MAX;
	for(first=1; first<n; first++)
	{
	   if(Set[first]!=1 && Dist[first]!=0 && Dist[first]<min)
	   {
		min = Dist[first];
		u = first;
	   }
	}

	sum += min;
	Set[u] = 1;

	for(first=1; first<n; first++)
	{
	    if(Dist[first] > Matrix[u][first])
	    {
		Dist[first] = Matrix[u][first];
	    }

	}
    }

    return sum;
}


int PosJudge(int x, int y)
{
    if((x>=0 && x<m) && (y>=0 && y<n))
    {
	//printf("return 1\n");
	return 1;
    }
    else
    {
//	printf("return 0\n");
	return 0;
    }
}

void Enqueue(Point to_add)
{
    QueEle *qe;

    qe = (QueEle*)malloc(sizeof(QueEle));
    memcpy(&qe->QData, &to_add, sizeof(Point));
    qe->next = NULL;

    if(Tail == NULL)
	Head = Tail = qe;
    else
    {
	Tail->next = qe;
	Tail = qe;
    }
}

Point Dequeue()
{
    QueEle* tmp;
    Point  pt;
   if(Head == NULL)
   {
	pt.dis = -100;    
	return pt;
   }

    tmp = Head;
    if(Head == Tail)
	Head = Tail = NULL;
    else
       Head = Head->next;

    pt = tmp->QData;
    free(tmp);
    return pt;
}

int  BFS(int x, int y)
{
    int direction;
    int tmpx, tmpy;
    Point pt;
    Point pt2;

    pt.x = x;
    pt.y = y;
    pt.dis = 0;
    Enqueue(pt);
    while(Head != NULL)
    {
	pt = Dequeue();	
	//memset(Visit, 0, sizeof(Visit));
	if(pt.dis < 0)
	    break;
	
	//printf("In BFS Dequeue(). pt.x:%d pt.y:%d pt.dis:%d\n", pt.x, pt.y, pt.dis);
	Visit[pt.x][pt.y] = 1;
	for(direction=0; direction<4; direction++)
	{
	    tmpx = pt.x + DIREC_X[direction];
	    tmpy = pt.y + DIREC_Y[direction];
	    if(PosJudge(tmpx, tmpy))
	    {
		if(Visit[tmpx][tmpy])
		    ;
		else
		{
		    //printf("Before switch(). c:%c\n", Arr[pt.x+DIREC_X[direction]][pt.y+DIREC_Y[direction]].c);
		    switch(Arr[tmpx][tmpy].c)
		    {
			case '#':
			    break;
			case ' ':
			    pt2.x = tmpx;
			    pt2.y = tmpy;
			    pt2.dis = pt.dis+1;
			    Visit[pt2.x][pt2.y] = 1;
			    Enqueue(pt2);
			    //printf("Enqueued %d %d.\n", pt2.x, pt2.y);
			    break;
			case 'A':
			case 'S':
			    Visit[pt.x][pt.y] = 1;
			    if(Matrix[Arr[x][y].num][Arr[tmpx][tmpy].num] > pt.dis+1)
				Matrix[Arr[x][y].num][Arr[tmpx][tmpy].num] = pt.dis+1;;
			    //printf("Matrix[%d][%d]:%d\n", Arr[x][y].num, Arr[pt.x+DIREC_X[direction]][pt.y+DIREC_Y[direction]].num, pt.dis+1);
			    break;
		    }
		}
	    }
	    else
		continue;
	}
    }

    return 0;    
}

void GetDist(int x, int y)
{
    int first, second;

    for(first=0; first<x; first++)
    {
	for(second=0; second<y; second++)
	{
	    if(Arr[first][second].c=='A'||Arr[first][second].c=='S')
	    {
		//memset(Matrix, 0, sizeof(Matrix));
		memset(Visit, 0, sizeof(Visit));
		BFS(first, second);
	    }
	}
    }
}

void ShowMatrix(int x, int y)
{
    int first, second;

    for(first=0; first<x; first++)
    {
	for(second=0; second<y; second++)
	{
	    if(Matrix[first][second] == INT_MAX)
		printf("0 ");
	    else
		printf("%d ", Matrix[first][second]);
	}
	printf("\n");
    }
}

void Show(int x, int y)
{
    int first, second;

    printf("-------------------------\n");
    for(first=0; first<x; first++)
    {
	for(second=0; second<y; second++)
	{
//	    if(Arr[first][second].c == ' ')
//		printf("~");
//	    else
		printf("%c", Arr[first][second].c);

//	    if(Arr[first][second].c=='A' || Arr[first][second].c=='S')
//		printf("(%d)", Arr[first][second].num);
	}
	printf("\n");
    }
}

void ShowPoint(int n)
{
    int index;

    for(index=0; index<n; index++)
    {
//	printf("%d:%c\n", points[index].num, points[index].c);
    }
}

int main()
{
    int cases;
    int first, second;
    char tmp[200];
    int counter;
    int result;

    scanf("%d", &cases);
    while(1)
    {
	if(!cases)
	    break;
	
	scanf("%d %d", &n, &m);
	counter = 0;
	for(first=0; first<m; first++)
	{
	    fgets(tmp, 200, stdin);
	    //gets(tmp);
	    for(second=0; second<n; second++)
	    {
		scanf("%c", &Arr[first][second].c);
		if(Arr[first][second].c=='A' || Arr[first][second].c=='S')
		    Arr[first][second].num = counter++;
	    }
	}

//	ShowPoint(counter);
	for(first=0; first<counter; first++)
	    for(second=0; second<counter; second++)
		Matrix[first][second] = INT_MAX;
	GetDist(m, n);
	//Show(m, n);
	//ShowMatrix(counter, counter);
	result = Prim(counter);
	printf("%d\n", result);
	cases--;
    }
    return 0;
}
