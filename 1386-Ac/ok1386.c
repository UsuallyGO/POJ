#include<stdio.h>
#include<string.h>

struct node{
   int in,out;

}degree[26];
int father[26],rank[26],mem[27],vis[26],top;

int find(int t){
    int tmp=t;
    while(father[tmp]!=tmp) tmp=father[tmp];
    father[t]=tmp;
    return tmp;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int i,n;
        char buf[1001];
        scanf("%d",&n);
        for(i=0;i<26;i++) {father[i]=i;rank[i]=0;}
        memset(degree,0,sizeof(degree));
    memset(vis,0,sizeof(vis));
    top=0;
        
        for(i=0;i<n;i++){
            scanf("%s",buf);
            int a=buf[0]-'a',b=buf[strlen(buf)-1]-'a';
            if(!vis[a]) {vis[a]=1;mem[++top]=a;}
        if(!vis[b]) {vis[b]=1;mem[++top]=b;}
            degree[a].out++;degree[b].in++;
            a=find(a);b=find(b);
            if(a!=b){
                if(rank[a]<rank[b]) father[a]=b;
                else{
                    father[b]=a;
                    if(rank[a]==rank[b]) rank[a]++;
                }
            }
        }
        
        int tmp=find(mem[1]),flag=0;
        for(i=2;i<=top;i++) if(find(mem[i])!=tmp) {flag=1;break;}
        if(flag) {printf("The door cannot be opened.\n");continue;}
        
        int sum=0,flag1=0,flag2=0,ok=1;
        for(i=1;i<=top && sum<=2 && ok;i++){
            if(degree[mem[i]].in!=degree[mem[i]].out){
                sum++;
                if(degree[mem[i]].in==degree[mem[i]].out+1) flag1++;
                else if(degree[mem[i]].out==degree[mem[i]].in+1) flag2++;
                else ok=0;
            }
        }
        if(ok){
            if(flag1==1&&flag2==1 || flag1==0&&flag2==0) printf("Ordering is possible.\n");
            else printf("The door cannot be opened.\n");
        }
        else printf("The door cannot be opened.\n");
        
    }
    //system("pause");
    return 0;
}
