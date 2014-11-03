
#include <stdio.h>
#include <string.h>

#define MAXRECORDS 200

int RecordTrace[MAXRECORDS];

int main()
{
    int n_times;
    int n_datas;
    int data_index;
    int	t_swap;
    int start, end;
    int	max;

    scanf("%d", &n_times);

    while(n_times-- > 0)
    {
	memset(RecordTrace, 0, sizeof(RecordTrace));	

	scanf("%d", &n_datas);
	
	for(data_index=0; data_index<n_datas; data_index++)
	{
	   scanf("%d%d", &start, &end); 

	   start = (start+1)/2;
	   end = (end+1)/2;

	   if(start > end)
	   {
		t_swap = start;
		start = end;
		end = t_swap;
	   }

	   for(; start <= end; start++)
		RecordTrace[start]++;
	}

	max = 0; 
	for(start = 0; start < MAXRECORDS; start++)
	{
	   if(max < RecordTrace[start])
		max = RecordTrace[start];
	}

	printf("%d\n", 10*max);

    } 
}
