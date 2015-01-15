
#include <stdio.h>
#include <string.h>

#define DEBUG 0
#define MAX_NUM 500002

int toSort[MAX_NUM];
int unSort[MAX_NUM];
long long counter;

void merge(int *unsort, int first, int mid, int last, int *sort)
{
    int i = first, j = mid+1; //last half starts from mid+1
    int k = 0;

    while(i<=mid && j<=last)
        if(unsort[i] <= unsort[j])
	    sort[k++] = unsort[i++];
	else
	{
	    sort[k++] = unsort[j++];
	    counter += mid-i+1;
	}
    
    while(i <= mid)
        sort[k++] = unsort[i++];
    while(j <= last)
        sort[k++] = unsort[j++];

    for(i=0; i<k; i++)
        unsort[first + i] = sort[i];
}

void merge_sort(int *unsort, int first, int last, int *sort)
{
    int mid;

    if(first < last)
    {
        mid = (first + last) / 2;

	merge_sort(unsort, first, mid, sort);
	merge_sort(unsort, mid+1, last, sort);
	merge(unsort, first, mid, last, sort);
    }
}

void display(int *arr, int count)
{
    int index;

    for(index=0; index<count; index++)
        printf("%d ", arr[index]);
}

int main()
{
    int num;
    int index;

    do
    {
        scanf("%d", &num);
	if(!num)
	    break;

	index = 0;
	counter = 0;
	memset(unSort, 0, sizeof(unSort));
	memset(toSort, 0, sizeof(toSort));
        while(index < num)
	    scanf("%d", &unSort[index++]);
	
	merge_sort(unSort, 0, num-1, toSort); //num is reachable
	printf("%lld\n", counter);
#if DEBUG
        display(toSort, num);
#endif
	
    }while(1);

    return 0;
}
