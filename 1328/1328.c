
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DEBUG 0

typedef struct IsLand_Pos
{
    int	x;
    int y;
    double left;
    double right;
}IsLand;

int Cmp(const void* a, const void*b)
{
    return ((IsLand*)a)->x - ((IsLand*)b)->x;
}

double Min(double a, double b)
{
    return (a-b)>0?b:a;
}

void ShowIsLands(IsLand *array, int num)
{
    int index;

    for(index=0; index<num; index++)
    {
	printf("%d %d\n", array[index].x, array[index].y);
	printf("%f %f\n", array[index].left, array[index].right);
    }
}

int main()
{
    int num, distance;
    int index;
    IsLand* islands;
    double  slength;;
    int count;
    int radars;
    int flag;

    count = 0;
    do
    {
	scanf("%d %d", &num, &distance);
	if(num==0 && distance==0)
	    break;
	
	count++;
	flag = 0;
	index = 0;
	islands = (IsLand*)malloc(sizeof(IsLand)*num);
	while(index < num)
	{
	   scanf("%d %d",&islands[index].x, &islands[index].y); 
	   if(islands[index].y > distance)
		flag = 1;

	   islands[index].left = islands[index].x - sqrt(distance*distance - islands[index].y*islands[index].y);
	   islands[index].right = islands[index].x + sqrt(distance*distance - islands[index].y*islands[index].y);
	   index++;
	}

	if(flag)
	{
	    printf("Case %d: %d\n", count, -1);
	    free(islands);
	    continue;
	}

	qsort(islands, num, sizeof(IsLand), Cmp);

	index = 1;
	radars = 0;
	slength = islands[0].right;
	while(index < num)
	{
	    if(slength < islands[index].left)
	    {
		radars++;
		slength = islands[index].right;
	    }
	    else
	    {
		slength = Min(slength, islands[index].right);
	    }

	    index++;
	}
	radars++;
#if DEBUG
	ShowIsLands(islands, num);
#endif
	free(islands);
	printf("Case %d: %d\n", count, radars);

    }while(1);

    return 0;
}
