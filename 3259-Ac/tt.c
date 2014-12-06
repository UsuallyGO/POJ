#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int VM=520;
const int EM=2520;
const int INF=0x3f3f3f3f;

struct Edge{
    int u,v;
    int cap;
}edge[EM<<1];

int n,m,k;
int cnt,dis[VM];

void addedge(int cu,int cv,int cw){
    edge[cnt].u=cu;     edge[cnt].v=cv;     edge[cnt].cap=cw;
    cnt++;
}

void show()
{
    int i;

    for(i = 0; i<cnt; i++)
	printf("edge[%d]:%d\n", i, edge[i].cap);
}

int Bellman_ford(){

    printf("n:%d cnt:%d\n", n, cnt);
    for(int i=1;i<=n;i++)
        dis[i]=INF;
    dis[1]=0;
    for(int i=1;i<n;i++)    //n-1次松弛
        for(int j=0;j<cnt;j++)  //枚举每条边
            if(dis[edge[j].v]>dis[edge[j].u]+edge[j].cap)
                dis[edge[j].v]=dis[edge[j].u]+edge[j].cap;
    for(int j=0;j<cnt;j++)
        if(dis[edge[j].v]>dis[edge[j].u]+edge[j].cap)   //判断是否存在负权边
            return 0;
    return 1;
}

int main(){

    //freopen("input.txt","r",stdin);

    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&k);
        cnt=0;
        int u,v,w;
        while(m--){
            scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,w);
            addedge(v,u,w);
        }
        while(k--){
            scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,-w);
        }
	printf("cnt:%d\n", cnt);
	show();
        int ans=Bellman_ford();
        printf("%s\n",ans==0?"YES":"NO");
    }
    return 0;
}
