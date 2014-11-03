
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define DEBUG 0
#define TREE_LEN   30 

typedef struct Node
{
    char    elem;
    struct Node *left;
    struct Node *right;
}BTree;

char Pre[TREE_LEN];
char In[TREE_LEN];
char Post[TREE_LEN];



#if DEBUG
void Display(char* str, int len)
{
    int index = 0;

    for(index=0; index<len; index++)
    {
	printf("%c", str[index]);
    }

//    printf("Len:%d \n", index);
}
#endif

void BuildPreIn(char *pre, char *in, int len, BTree **root)
{
    char *tmp;
    int left;
    int right;
    BTree *tnode;

    if(pre==NULL || in==NULL)
	return;

    if(len == 0)
	return;

    tnode = (BTree*)malloc(sizeof(BTree));
    tnode->elem = pre[0];
    tnode->left = NULL;
    tnode->right = NULL;

    if(*root == NULL)
	*root = tnode;

#if DEBUG
    printf("*root:%c ", (*root)->elem);
    printf("pre:%c in:%c len:%d \n", pre[0], in[0], len);
#endif
    tmp = in;
    while(*tmp != *pre)
	tmp++;

    left = tmp-in;
    right = len-left-1;

    BuildPreIn(pre+1, in, left, &((*root)->left));
    BuildPreIn(pre+left+1, in+left+1, right, &((*root)->right));
}

void PostVisit(BTree *root)
{
    if(root == NULL)
	return;
    
    if(root->left != NULL)
        PostVisit(root->left);
    if(root->right != NULL)
        PostVisit(root->right);

    printf("%c", root->elem);

}

int main()
{
    BTree* mytree;

    while(1)
    {
	mytree = NULL;
	if(scanf("%s %s", Pre, In)==EOF)
	    break;
/*
	scanf("%s", Pre);
	if(Pre[0]==EOF)
	    break;
        getchar();
        scanf("%s", In);
	getchar();
	*/

#if DEBUG
	Display(Pre, strlen(Pre));
	Display(In, strlen(In));
#endif
	BuildPreIn(Pre, In, strlen(Pre), &mytree);
	PostVisit(mytree);
	printf("\n");
    }

    return 0;
}
