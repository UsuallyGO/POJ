
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 0

#define LETTERS 4 

struct Node
{
    char c;
    int counter;
    struct Node* son[LETTERS];
};

int LET_TO_INT(char c)
{
    switch(c)
    {
    case 'A':
	return 0;
    case 'C':
	return 1;
    case 'G':
	return 2;
    case 'T':
	return 3;
    default:
	return -1;
    }
}

void clearNode(struct Node *node)
{
/*
    omit check here
 */
    int i;

    node->c = '-';
    node->counter = 0;
    for(i = 0; i < LETTERS; i++)
	node->son[i] = NULL;
    
}

int checkTrie(struct Node *root, char *seq)
{
/* Not needed here
    if(seq == NULL)
	return -1;
*/
    int LEN, i;
    int num;
    struct Node *tmp;

    tmp = root;
    LEN = strlen(seq);
#if DEBUG
    printf("str length:%d\n", LEN);
#endif
    for(i = 0; i < LEN; i++)
    {
	num = LET_TO_INT(seq[i]);
#if DEBUG
	printf("LET_TO_INT: %d\n", num);
#endif
	if(tmp->son[num] == NULL)
	{
	    tmp->son[num] = (struct Node*)malloc(sizeof(struct Node));
	    clearNode(tmp->son[num]);
	    tmp->son[num]->c = seq[i];	
	}
	tmp = tmp->son[num];

	if(i == LEN-1)
	{
	    tmp->counter++;
	   return tmp->counter; 
	}
    }
}

int main()
{
    int n, m;
    int i, j;
    int res;
    char *sequence;
    int *copy;
    struct Node *root;

    while(1)
    {
	scanf("%d %d", &n, &m);
#if DEBUG
	printf("n:%d m:%d\n", n, m);
#endif
	if(n == 0 && m == 0)
	    break;

	root = (struct Node*)malloc(sizeof(struct Node));
	clearNode(root);
	
	sequence = (char*)malloc(m+1);
	copy = (int*)malloc((n+1)*sizeof(int));
	memset(copy, 0, sizeof(int)*(n+1));

	i = 0; 
	while(i < n)
	{
	    scanf("%s", sequence);	
	    res = checkTrie(root, sequence);	
#if DEBUG
	    printf("str[%d]:%s res:%d\n", i, sequence, res);
#endif
	    copy[res-1]--;
	    copy[res]++;
	    i++;
	}

	for(i = 1; i <= n; i++)
	    printf("%d\n", copy[i]);
#if DEBUG
	printf("-----\n");
#endif
	free(root);
	free(sequence);
	free(copy);
    }

    return 0;
}
