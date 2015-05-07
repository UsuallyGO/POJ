
#include <stdio.h>
#include <string.h>

#define LETTERS 26
#define CASES 2000
#define MAX 20000
#define STR_LEN 22

#define CHAR_TO_INT(x) (x - 'a')

struct Node
{
    unsigned int count;
    struct Node *son[LETTERS];
};

struct Node root[MAX];
int node_count = 0;

void clearNode(struct Node *tmp)
{
    int i;

    tmp->count = 0; 
    for(i = 0; i < LETTERS; i++)
	tmp->son[i] = NULL;
}

void addTrie(char *str)
{
    int str_len;
    int i, index;
    struct Node *tmp;

    str_len = strlen(str);
    tmp = &root[0];
    for(i = 0; i < str_len; i++)
    {
	index = CHAR_TO_INT(str[i]);	
	if(tmp->son[index] == NULL)
	{
	    node_count++;
	    tmp->son[index] = &root[node_count];
	    clearNode(tmp->son[index]);
	}
	tmp = tmp->son[index];
	tmp->count++;
    }
}

void getPrefix(char *str)
{
    int str_len;
    int i, index;
    struct Node *tmp;

    printf("%s ", str);
    str_len = strlen(str);
    tmp = &root[0];
    for(i = 0; i < str_len; i++)
    {
	index = CHAR_TO_INT(str[i]);	
	printf("%c", str[i]);
	if(tmp->son[index]->count == 1)
	    break;
	tmp = tmp->son[index];
    }
    printf("\n");
}

int main()
{
    char str[CASES][STR_LEN];
    int i, j;

    i = 0;
    node_count = 0;
    while(scanf("%s", str[i]) != EOF)
	addTrie(str[i++]);

    for(j = 0; j < i; j++)
	getPrefix(str[j]);


    return 0;
}

