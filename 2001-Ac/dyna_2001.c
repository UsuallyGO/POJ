
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define DEBUG 1

#define STR_LEN 25
#define LETTERS 26
#define STR_NUM 2000

#define CHAR_TO_INT(x) (x - 'a')
#define INT_TO_CHAR(x) (x + 'a')

struct Node 
{
    unsigned int times;
    struct Node* son[LETTERS];
};

void clearNode(struct Node *node)
{
    int i;

    node->times = 0;
    for(i = 0; i < LETTERS; i++)
	node->son[i] = NULL;
}

void addTrie(struct Node *root, char *str)
{
    struct Node *tmp;
    int str_len;
    int i, index;

    tmp = root;
    str_len = strlen(str);
    for(i = 0; i < str_len; i++)
    {
	index = CHAR_TO_INT(str[i]);
	if(tmp->son[index] == NULL) //add a new branch
	{
	    tmp->son[index] = (struct Node*)malloc(sizeof(struct Node));
	    assert(tmp->son[index] != NULL);
	    clearNode(tmp->son[index]);//clear it
	    //tmp->son[index]->time++; //one more son
	}
	tmp = tmp->son[index];
	tmp->times++;
    }
}

void getPrefix(struct Node *root, char *str)
{
    int index, i, str_len;
    struct Node *tmp;

    str_len = strlen(str);
    tmp = root;
    printf("%s ", str);
    for(i = 0; i < str_len; i++)
    {
	index = CHAR_TO_INT(str[i]);	
	tmp = tmp->son[index];
//	printf("%c", INT_TO_CHAR(index));
	printf("%c", str[i]);
	if(tmp->times == 1)
	    break;
    }
    printf("\n");
}

int main()
{
    struct Node *root;
    char str[STR_NUM][STR_LEN];
    int i, counter, res;

    counter = 0;
    root = (struct Node*)malloc(sizeof(struct Node));
    while(scanf("%s", str[counter]) != EOF)
    {
	addTrie(root, str[counter]);
	counter++;
    }

    for(i = 0; i < counter; i++)
	getPrefix(root, str[i]);

    return 0;
}

