
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
};


struct Node* root;

int getNum()
{
    static int index = 100;
    int arr[100];  
    int i;

    for(i = 0; i < 100; i++)
	arr[i] = i+1;

    i = rand()%index;
    index--;
    return arr[i];
}

inline struct Node* getNode(int key)
{
    struct Node *tmp;

    tmp = (struct Node*)malloc(sizeof(struct Node));
    tmp->key = key;
    tmp->left =NULL;
    tmp->right = NULL;

    return tmp;
}

void TreapAdd(int num)
{
    struct Node* parent;
    struct Node* cur;

    cur = root;
    while(cur != NULL)
    {
	parent = cur;
	if(cur->key > num)
	    cur= cur->left;
	else
	    cur= cur->right;
    }
    
    //cur is NULL now, parent points to it
    cur = getNode(num);
    if(root == NULL)
	root = cur;
    else
    {
	if(parent->key > num)
	    parent->left = cur;
	else
	    parent->right = cur;
    }
}

void visit(struct Node *tmp)
{
    if(tmp->left != NULL)
	visit(tmp->left);
    if(tmp->right != NULL)
	visit(tmp->right);
    printf("%d ", tmp->key);
}


void ShowPre()
{
    struct Node *tmp;

    tmp = root;
    if(tmp == NULL)
    {
	printf("Empty tree\n");
	return;
    }
    visit(tmp);
}

int main()
{
    int num;
    char c;

    srand((unsigned int)time(0));
    root = NULL;
    while(1)
    {
	printf("0 means finish:");
	scanf("%c", &c);
	if(c == '0')
	    break;

	num = getNum();
	printf("Get num :%d\n", num);
        TreapAdd(num);
	printf("Display trees:\n");
	ShowPre();
	printf("\n");
//	fflush(stdin);
	getchar();
    }

    return 0;
}
