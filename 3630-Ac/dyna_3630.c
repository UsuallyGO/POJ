
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 0

#define NUM_LEN 11
#define NUMBERS 10
#define CHAR_TO_NUM(x) (x - '0')
#define WORD_YES 'Y'
#define WORD_NO  'N'

struct Node
{
    char word;
    struct Node* son[NUMBERS];
};

void nodeClear(struct Node *node)
{
    int i;

    node->word = WORD_NO; 
    for(i = 0; i < NUMBERS; i++)
	node->son[i] = NULL;
}

int checkTrie(struct Node *root, char *num)
{
    struct Node *tmp;
    int i, LEN;
    int index;
    int res;

#if DEBUG
    printf("num:%s len:%u\n", num, strlen(num));
#endif
    tmp = root;
    LEN = strlen(num);
    res = 1;
    for(i = 0; i < LEN; i++)
    {
	index = CHAR_TO_NUM(num[i]);	
	if(tmp->son[index] == NULL)//not exist
	{
	    tmp->son[index] = (struct Node*)malloc(sizeof(struct Node));
	    nodeClear(tmp->son[index]);
	    tmp->son[index]->word = WORD_NO;
	    res = 0;
	}
	else//exist
	{
	    if(tmp->son[index]->word == WORD_YES) //check is the prefix
		break;
	}
	tmp = tmp->son[index];
	if(i == LEN-1)
	    tmp->word = WORD_YES;
    }

    return res;
}

int main()
{
    int cases, n;
    char num[NUM_LEN];
    int i, j;
    int res, sign;
//    struct Node root[10000];
    struct Node *root;

    scanf("%d", &cases);
    for(j = 0; j < cases; j++)
    {
	scanf("%d", &n);
	root = (struct Node*)malloc(sizeof(struct Node));
	nodeClear(root);
	sign = 0;

	for(i = 0; i < n; i++)
	{
	    scanf("%s", num);
	    if(sign != 1)
		sign = checkTrie(root, num);
	}
	if(sign)
	    printf("NO\n");
	else
	    printf("YES\n");
	
	free(root);
    }

    return 0;
}
