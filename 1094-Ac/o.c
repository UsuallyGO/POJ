#include<iostream>  
#include<stdio.h>  
#include<string.h>  
#include<memory.h>  
using namespace std;  
int map[27][27],q[27],deg[27];  
int Toposort(int n)  
{  
    int c=0,temp[27],loc,m,flag=1;  
    for(int i=1; i<=n; i++)  
        temp[i]=deg[i];  
    for(int i=1; i<=n; i++)  
    {  
        m=0;  
        for(int j=1; j<=n; j++)  
            if(temp[j]==0)  
            {  
                m++;  
                loc=j;  
            }  
        if(m==0)return 0;//有环  
        if(m>1)flag=-1;//无序  
        q[c++]=loc;  
        temp[loc]=-1;  
        for(int j=1; j<=n; j++)  
            if(map[loc][j]==1)  
                temp[j]--;  
    }  
    return flag;  
}  
int main()  
{  
    int m,n,flag;  
    char b[5];  
    while(cin>>m>>n)  
    {  
        memset(map,0,sizeof(map));  
        memset(deg,0,sizeof(deg));  
        if(m==0&&n==0)break;  
        flag=0;  
        for(int i=1; i<=n; i++)  
        {  
            scanf("%s",b);  
            if(flag)continue;  
            int x=b[0]-'A'+1;  
            int y=b[2]-'A'+1;  
            map[x][y]=1;  
            deg[y]++;  
            int s=Toposort(m);  
            if(s==0)  
            {  
                cout<<"Inconsistency found after "<<i<<" relations."<<endl;  
                flag=1;  
            }  
            if(s==1)  
            {  
                cout<<"Sorted sequence determined after "<<i<<" relations: ";  
                for(int j=0; j<m; j++)  
                    printf("%c",q[j]-1+'A');  
                cout<<"."<<endl;  
                flag=1;  
            }  
        }  
        if(!flag)  
        {  
            cout<<"Sorted sequence cannot be determined."<<endl;  
        }  
    }  
    return 0;  
} 
