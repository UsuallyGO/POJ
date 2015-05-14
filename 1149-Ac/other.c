#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#define inf 99999999
#define M 10100
#define N 1100
using namespace std;
int pigh[M],edge[N][N],p[N],a[N],pre[N],m,n,flow;
queue<int >Q;
void ek()
{
  while(1)
  {
    while(!Q.empty())Q.pop();
    memset(a,0,sizeof(a));
    memset(p,0,sizeof(p));
    a[0]=inf;
    Q.push(0);
    while(!Q.empty())
    {
      int u=Q.front();
      Q.pop();
      for(int v=0;v<=n+1;v++)
      {
        if(!a[v]&&edge[u][v]>0)
        {
          a[v]=min(a[u],edge[u][v]);
          p[v]=u;
          Q.push(v);
        }
      }
      if(a[n+1])break;
    }
    if(!a[n+1])break;
    for(int u=n+1;u!=0;u=p[u])
    {
      edge[p[u]][u]-=a[n+1];
      edge[u][p[u]]+=a[n+1];
    }
    flow+=a[n+1];
  }
}
int main()
{
  int i,j,k,u,b;
  while(~scanf("%d%d",&m,&n))
  {
    flow=0;
    memset(pigh,0,sizeof(pigh));
    memset(edge,0,sizeof(edge));
    memset(pre,0,sizeof(pre));
    for(i=1; i<=m; i++)
      scanf("%d",&pigh[i]);
    for(i=1; i<=n; i++)
    {
      scanf("%d",&k);
      while(k--)
      {
        scanf("%d",&u);
        if(!pre[u])
        {
          edge[pre[u]][i]+=pigh[u];
          pre[u]=i;
        }
        else
        {
          edge[pre[u]][i]=inf;
          pre[u]=i;
        }
      }
      scanf("%d",&b);
      edge[i][n+1]+=b;
    }
    ek();
//		for(i=0;i<=n+1;i++)
//		{
//			for(j=0;j<=n+1;j++)
//			{
//				cout<<edge[i][j]<<" ";
//			}
//			cout<<endl;
//		}
    printf("%d\n",flow);
  }
  return 0;
}
