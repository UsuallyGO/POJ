
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LETTERS 26
#define DIC_MAX 100000 

typedef struct Node_t{
    int num;
    struct Node_t *next[LETTERS];
}Node;

Node *Root;
char* dic[DIC_MAX];

Node* CreateNode(void)
{
   Node *tmp;
   int index;

   tmp = (Node*)malloc(sizeof(Node));
   tmp->num = -1;
   for(index=0; index<LETTERS; index++)
        tmp->next[index] = NULL;
   return tmp;
}

void TrieInsert(char str[], int len, int pos)
{
    int index;
    char c;
    Node *tmp;
    Node *cur;
    int length;
    int i;

    i = 0;
    cur = Root;
    length = strlen(str);
    while(str[i] != '\0' && i < len){
        c = str[i];
	index = c - 'a';

        if(cur->next[index] == NULL){
	    tmp = CreateNode();
	    cur->next[index] = tmp;
	}
	if(i == length-1)
	    cur->next[index]->num = pos;
	cur = cur->next[index];
	i++;
    }
}

int TrieSearch(char str[], int len)
{
    Node *cur;
    int index;
    char c;
    int i;
    int length;

    cur = Root;
    i = 0;
    length = strlen(str);
    while(str[i] != '\0' && i < len)
    {
        c = str[i];
	index = c - 'a';

	if(cur->next[index] == NULL)
	    return -1;
	if(i == length-1)
	    return cur->next[index]->num;
	cur = cur->next[index];
	i++;
    }
    return -1;
}

void TrieInit()
{
    int index;
    Root = (Node*)malloc(sizeof(Node));
    Root->num = -1;
    for(index = 0; index < LETTERS; index++)
        Root->next[index] = NULL;
}

void GetStr(char *str, int len)
{
    int index;
    char c;
    
    index = 0;
    do{
        c = getchar();
	if(c=='\0' || c=='\n' || c==' ' || c==EOF)
	{
	    str[index] = '\0';
	    break;
	}
	str[index++] = c;
    }while(1);
}

int main()
{
    char *word1;
    char word2[100];
    int index;

    index = 0;
    TrieInit();
    while(1)
    {
        word1 = (char*)malloc(100);
	GetStr(word1, 100);
	if(word1[0] == '\0')
	    break;
	dic[index] = word1;
	GetStr(word2, 100);
	TrieInsert(word2, 100, index);
	index++;
    }

    while(1)
    {
        GetStr(word2, 100);
	if(word2[0] == '\0')
	    break;
	index = TrieSearch(word2, 100);
	if(index < 0)
	    printf("eh\n");
	else
	    printf("%s\n", dic[index]);
    }
    
    return 0;
}
