
#include <stdio.h>
#include <stdlib.h>

#define EAST  0 
#define NORTH 1
#define WEST  2
#define SOUTH 3
#define MID   4

#define OVER 0
#define CONTI 1

typedef struct position
{
    int robNum;
    int orientation;
} Pos;

void initialQipan(Pos **p, int len, int wid)
{
    int first, second;

    for(first=0; first<len; first++)
    {
	for(second=0; second<wid; second++)
	{
	    p[first][second].robNum = 0;
	    p[first][second].orientation = MID;
	}
    }
}

int main()
{
    int cases;
    int len, wid;
    int index;
    int arg1, arg2;
    int arg3, arg4;
    int first, second;
    int inner;
    int flag;
    char ori;
    Pos **qipan;
    scanf("%d", &cases);

    while(cases>0)
    {
	cases--;

	scanf("%d %d", &wid, &len);
	qipan = (Pos**)malloc(sizeof(Pos*)*len);
	for(arg1=0; arg1<len; arg1++)
	    qipan[arg1] = (Pos*)malloc(sizeof(Pos)*wid);
	initialQipan(qipan, len, wid);

	//printf("Come here.\n");

	scanf("%d %d", &arg1, &arg2);
	index = 0;
	while(index < arg1)
	{
	    scanf("%d %d %c", &arg4, &arg3, &ori);
	    qipan[arg3-1][arg4-1].robNum = index+1;
	    //printf("Come here.\n");
	    switch(ori)
	    {
		case 'E':
		    qipan[arg3-1][arg4-1].orientation = EAST;
		    break;
		case 'N':
		    qipan[arg3-1][arg4-1].orientation = SOUTH;
		    break;
		case 'W':
		    qipan[arg3-1][arg4-1].orientation = WEST;
		    break;
		case 'S':
		    qipan[arg3-1][arg4-1].orientation = NORTH;
		    break;
		default:
		    ;
	    }
	    index++;
	}

	index = 0;
	flag = CONTI;
	while(index < arg2)
	{
	    index++;

	    scanf("%d %c %d", &arg3, &ori, &arg4);
	    if(flag == OVER)
		continue;

	    for(first=0; first<len; first++)
	    {
		for(second=0; second<wid; second++)
		    if(qipan[first][second].robNum == arg3)
		    {
			flag = OVER;
			break;
		    }
		if(flag == OVER)
		    break;
	    }

	   //printf("first:%d second:%d\n", first, second); 
	  // printf("first_second->ori:%d\n", qipan[first][second].orientation);
	    flag = CONTI;
	    arg1 = qipan[first][second].orientation;
	    inner = 1;
	//    printf("orientation arg1:%d\n", arg1);
	    switch(ori)
	    {
		case 'R':
		    while(inner++ <= arg4)
		    {
			arg1++;
			arg1 = arg1%4;
		    }
		    qipan[first][second].orientation = arg1;
		    break;
		case 'L':
		    while(inner++ <= arg4)
		    {
			arg1--;
		    //arg1 = abs(arg1);
			arg1 += 4;
			arg1 = arg1%4;
		    }
		    qipan[first][second].orientation = arg1;
		    break;
		case 'F':
		    switch(arg1)
		    {
			case EAST:
			    while(1)
			    {
				if((second+inner) >= wid)
				{
				    printf("Robot %d crashes into the wall\n", arg3);
				    flag = OVER;
				    break;
				}
				if(qipan[first][second+inner].robNum != 0)
				{
				//    printf("In robNum!=0 first:%d second:%d\n", first, second+inner);
				    printf("Robot %d crashes into robot %d\n", arg3, qipan[first][second+inner].robNum);
				    flag = OVER;
				    break;
				}

				if(inner == arg4)
				{
				    qipan[first][second+inner].robNum = arg3;
				    qipan[first][second+inner].orientation = arg1;
				    //printf("%d %d:%d %d\n", first, second+inner, arg3, arg1);
				    break;
				}

				inner++;
			    }
			    break;
			case SOUTH:
			    while(1)
			    {
				if((first+inner) >= len)
				{
				    printf("Robot %d crashes into the wall\n", arg3);
				    flag = OVER;
				    break;
				}
				if(qipan[first+inner][second].robNum != 0)
				{
				    printf("Robot %d crashes into robot %d\n", arg3, qipan[first+inner][second].robNum);
				    flag = OVER;
				    break;
				}
				if(inner == arg4)
				{
				    qipan[first+inner][second].robNum = arg3;
				    qipan[first+inner][second].orientation = arg1;
				    //printf("%d %d:%d %d\n", first+inner, second, arg3, arg1);
				    break;
				}

				inner++;
			    }
			    break;
			case WEST:
			    while(1)
			    {
				if((second-inner) < 0 )
				{
				    printf("Robot %d crashes into the wall\n", arg3);
				    flag = OVER;
				    break;
				}
				if(qipan[first][second-inner].robNum != 0)
				{
				    printf("Robot %d crashes into robot %d\n", arg3, qipan[first][second-inner].robNum);
				    flag = OVER;
				    break;
				}
				if(inner == arg4)
				{
				    qipan[first][second-inner].robNum = arg3;
				    qipan[first][second-inner].orientation = arg1;
				    //printf("%d %d:%d %d\n", first, second-inner, arg3, arg1);
				    break;
				}

				inner++;
			    }
			    break;
			case NORTH:
			    while(1)
			    {
				if((first-inner) < 0 )
				{
				    printf("Robot %d crashes into the wall\n", arg3);
				    flag = OVER;
				    break;
				}
				if(qipan[first-inner][second].robNum != 0)
				{
				    printf("Robot %d crashes into robot %d\n", arg3, qipan[first-inner][second].robNum);
				    flag = OVER;
				    break;
				}
				if(inner == arg4)
				{
				    qipan[first-inner][second].robNum = arg3;
				    qipan[first-inner][second].orientation = arg1;
				    //printf("%d %d:%d %d\n", first-inner, second, arg3, arg1);
				    break;
				}
				inner++;
			    }
			    break;
			default:
			    ;
		    }
		//    printf("Come here.\n");
		    qipan[first][second].robNum = 0;
		    qipan[first][second].orientation = MID;
		    break;
		default:
		    ;
	    }
	}//instruction
//	printf("cases:%d\n", cases);
	if(flag != OVER)
	    printf("OK\n");

	free(qipan);
    }//cases

    return 0;
}
