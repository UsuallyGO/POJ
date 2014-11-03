
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define	MAX_NUM	10000
#define BIT_NUM 0x1F
#define BYTE_SHIFT 5
#define LEN  (1+MAX_NUM/(sizeof(int)*BYTE_SHIFT))

int RealPrim[LEN];

int JudgePrim(int tojudge)
{
   int sqrt_n;
   int index;

   if(tojudge==2)
	return 1;

   sqrt_n = ceil(sqrt(tojudge));

   for(index=2; index<=sqrt_n; index++)
	if((tojudge%index)== 0)
	    return 0;

	return 1;
}

int main()
{
    int count;
    int prim_count;
    int cal_num;
    int first_index;
    int second_index;
    int match_count;
    int	tmp_sum;

    prim_count = 0;

    for(count=2; count<MAX_NUM; count++)
    {
	if(JudgePrim(count)==1)
	{
	    RealPrim[prim_count]=count;
	    prim_count++;
	}
    }

do
{
    scanf("%d", &cal_num);
    if(cal_num==0)
	break;

    RealPrim[prim_count+1]=-1;

    match_count = 0;
    if(JudgePrim(cal_num) == 1)
	match_count++;

    for(first_index=0; first_index<prim_count; first_index++)
    {
	tmp_sum = RealPrim[first_index];

	for(second_index=first_index+1; second_index<prim_count; second_index++)
	{
	    tmp_sum += RealPrim[second_index]; 

	    if(tmp_sum == cal_num)
		match_count++;	

	    if(tmp_sum >= cal_num)
		break;
	}
    }

    printf("%d\n", match_count);
}while(1);

    return 0;
}
