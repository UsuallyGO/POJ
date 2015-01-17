
#include <stdio.h>
#include <math.h>

#define CUBE 3
#define MAXCASE 25000000 

#define PRINT printf("Comes here\n")

short sum[MAXCASE];
int num[110];
int counter;

int main()
{
    int left, right;
    int first, second;
    int index;
    int a1, a2, a3, a4, a5;
    scanf("%d %d %d %d %d", &a1, &a2, &a3, &a4, &a5);

    index=0;
    for(first=-50; first<0; first++)
        num[index++] = first;
    for(first=1; first<=50; first++)
        num[index++] = first;

    for(first=0; first<index; first++)//every x is in num[]
       for(second=0; second<index; second++){
           left = a1*pow(num[first], CUBE) + a2*pow(num[second], CUBE);
	   left = left*(-1);
	   if(left < 0)
	       left += MAXCASE;
	   sum[left]++;
       }

    for(left=0; left<index; left++)
       for(first=0; first<index; first++)
           for(second=0; second<index; second++){
	       right = a3*pow(num[left], CUBE) + a4*pow(num[first], CUBE) + a5*pow(num[second], CUBE);
	       if(right > MAXCASE || right < MAXCASE*(-1))
	           continue;
	       else{
	           if(right < 0)
		       right += MAXCASE;
		       if(sum[right])
		           counter += sum[right];
	       }
	   }

    printf("%d\n", counter);
    return 0;
}
