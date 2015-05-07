/*
trie树：
利用trie树 查找单词 的简单程序 
*/ 
//法一：自己的方法 
#include<iostream>
#include<cstdio>
using namespace std;

struct trie
{
   bool is;//标记是否是个单词 
   trie *next[11];// 分别代表
   void (*init)(trie *);// 为了初始化is=0，next=NULL 
}node[100000];

trie *root;
bool f;
int k;

void teinit(trie *y)
{
  int i;
  (*y).is=0;
  for(i=0;i<11;++i)
   (*y).next[i]=NULL; 
}

void insert(const char *word)
{
  int i;
  trie *p=root;
  while(*word)
  {
    if(p->next[*word-'0']==NULL)
     {
        p->next[*word-'0']=&node[k++];
     } 
     p=p->next[*word-'0'];
     if(p->is)f=1;// 检测 别的号码 是这个号码的前缀 如：输入 1 12 型数据 
     word++;
  }
  for(i=0;i<11;++i)//  检测此 号码是别的号码的前缀   如：输入  12 1 型数据 
   if(p->next[i]!=NULL)f=1;  
  p->is=true;//单词遍历结束 标记一下说明到此处有个单词 
}


int main()
{
   char ch[80];
   int i,n,t;
   scanf("%d",&t);
   while(t--)
   {
     for(i=0;i<100000;++i)
     {
       node[i].init=teinit;
       node[i].init(&node[i]);
      }
     root=&node[0]; 
     k=1;
     f=0;
     scanf("%d",&n);
     for(i=0;i<n;++i)
      {
        scanf("%s",ch);
        insert(ch);
      }
     if(f)printf("NO\n");
     else printf("YES\n");
   }
//   system("pause");
   return 0;
}
