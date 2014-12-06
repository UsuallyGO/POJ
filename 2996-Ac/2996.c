
#include <stdio.h>
#include <string.h>

#define DEBUG 0

char output[500];
int olen;
char tmp[10];

#if DEBUG
void show(char (*p)[8], int len)
{
    int first, second;

    for(first=0; first<len; first++)
    {
	for(second=0; second<8; second++)
	    printf("%c ", p[first][second]);

	printf("\n");
    }
}
#endif

void findp(char (*p)[8], int len, char c)
{
    int first, second, third;

    for(first=7; first>=0; first--)
    {
	for(second=0; second<8; second++)
	   if(p[first][second] == c)
	   {
		sprintf(tmp, "%c%d,", 'a'+second, 8-first);
		strcat(output, tmp);
	    }

    }
}

void find(char (*p)[8], int len, char c) 
{
    int first, second, third;

    for(first=7; first>=0; first--)
    {
	for(second=0; second<8; second++)
	    if(p[first][second] == c)
	    {
		sprintf(tmp, "%c%c%d,", c, 'a'+second, 8-first);
		strcat(output, tmp);
	    }
    }

}

void Find(char (*p)[8], int len, char c)
{
    int first, second, third;

    for(first=0; first<8; first++)
    {
	for(second=0; second<8; second++)
	    if(p[first][second] == c)
	    {
		sprintf(tmp, "%c%c%d,", c-32, 'a'+second, 8-first);
		strcat(output, tmp);
	    }
    }
}

void Findp(char (*p)[8], int len, char c)
{
    int first, second, third;

    for(first=0; first<8; first++)
    {
	for(second=0; second<8; second++)
	    if(p[first][second] == c)
	    {
		sprintf(tmp, "%c%d,", 'a'+second, 8-first);
		strcat(output, tmp);
	    }
    }
}

int main()
{
    char line[33];
    char qipan[8][8];
    int first, second;
    int fin, sin;
    olen = 0;

    fin = 0;
    for(first=0; first<17; first++)
    {
	scanf("%s", line);
	if(first%2 == 0)
	    continue;
	
	sin = 0;
	for(second=2; second<33; second+=4)
	{
	    qipan[fin][sin++] = line[second];    
	}

	fin++;
    }

#if DEBUG
    show(qipan, 8);
#endif

    printf("White: ");
    find(qipan, 8, 'K');
    find(qipan, 8, 'Q');
    find(qipan, 8, 'R');
    find(qipan, 8, 'B');
    find(qipan, 8, 'N');
    findp(qipan, 8, 'P');
    output[strlen(output)-1] = '\0';
    printf("%s\n", output);

    memset(output, 0, 500);
    printf("Black: ");
    Find(qipan, 8, 'k');
    Find(qipan, 8, 'q');
    Find(qipan, 8, 'r');
    Find(qipan, 8, 'b');
    Find(qipan, 8, 'n');
    Findp(qipan, 8, 'p');
    output[strlen(output)-1] = '\0';
    printf("%s\n", output);

    return 0;
}
