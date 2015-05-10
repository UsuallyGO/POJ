#include<stdio.h>
#include<math.h>
#include<string.h>
int b[101],p[101];
int dp[101][2000];
//int f[100][100];
int n,m;
int main()
{
	int i,j,k,t;
	int side;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(dp,-1,sizeof(dp));
		side=0;
		for(i=1;i<=n;i++){
			scanf("%d",&m);
			for(j=1;j<=m;j++){
				scanf("%d%d",&b[j],&p[j]);
				if(b[j]>side){
					side=b[j];
				}
			}
			if(i==1){
				for(j=1;j<=m;j++){
					dp[1][b[j]]=p[j];//初始化，第1行选择以b[i][j]为宽带室，的P=p[i][j] 
				} 
				continue;
			}
			for(j=0;j<=side;j++){
				if(dp[i-1][j]!=-1){
					for(k=1;k<=m;k++){
						int ins;
						if(j<b[k])ins=j;
						else{
							ins =b[k];
						}
						if(dp[i][ins]==-1){
							dp[i][ins]=dp[i-1][j]+p[k];
						}
						else{
							if(dp[i][ins]>(dp[i-1][j]+p[k]))dp[i][ins]=dp[i-1][j]+p[k];
						}
					}
				}
			}
		}
		double ans=0.0;
			for(i=1;i<=side;i++){
				if(ans<(1.0*i/dp[n][i])){
					ans=1.0*i/dp[n][i];
				}
			}
			printf("%.3lf\n",ans);
	}
	return 0;
} 
