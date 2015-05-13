
#include <string.h>
#include <stdio.h>

#define DEBUG 0
#define WORD_YES 'Y'
#define WORD_NO  'N'
#define NEXT_NUM 10
#define STR_LEN  11
#define TRIE_LEN 100000

#define CHAR_TO_INT(x) (x - '0')


typedef struct Trie
{
    int next[NEXT_NUM];
    char word;
}TrieNode;

TrieNode trie[100000];
int trie_len;

void clearTrie()
{
   trie_len = 0; 
   memset(trie, 0, 100000*sizeof(TrieNode));
}



int checkTrie(char *num)
{
    int i;
    int num_len;
    int index;
    int seek;
    TrieNode *tmp;
    int sign;

    num_len = strlen(num);
    //tmp = trie[trie_len];
    tmp = &trie[0];
    sign = 1;
    for(i = 0; i < num_len ; i++)
    {
	index = CHAR_TO_INT(num[i]);
#if DEBUG
	printf("index:%d \n", index);
#endif
	if(tmp->next[index] == 0)//not exist
	{
	    trie_len++;
	    tmp->next[index] = trie_len;
	    trie[tmp->next[index]].word = WORD_NO;
	    sign = 0;
#if DEBUG
	    printf("trie_len:%d", trie_len);
	    printf("num:%s char:%c\n", num, num[i]);
#endif
	}
	else//this digit has exist
	{
#if DEBUG
	    printf("num:%s  char:%c exist\n", num, num[i]);
#endif
	    if(trie[tmp->next[index]].word == WORD_YES)
		break;
	}
	tmp = &trie[tmp->next[index]];
	if(i == num_len -1)
	    tmp->word = WORD_YES;
    }
    return sign;
}

int main()
{
    int cases, n, m;
    int i, j, k;
    char num[STR_LEN];
    int sign;

    scanf("%d", &cases);
    for(i = 0; i < cases; i++)
    {
	scanf("%d", &n);
	clearTrie();
	trie_len = 0;
	sign = 0;
	for(j = 0; j < n; j++)
	{
	    scanf("%s", num);
	    if(!sign)
		sign = checkTrie(num);
	}
	if(sign)
	    printf("NO\n");
	else
	    printf("YES\n");
    }

    return 0;
}
