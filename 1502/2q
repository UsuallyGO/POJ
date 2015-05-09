#include <cstring>
#include <cstdio>
#include <algorithm>
#define MAX 120
#define INF 100000000
using namespace std;
int G[MAX][MAX], d[MAX];
bool vis[MAX];
char st[120];
int atoi(char* s)
{
    int ans = 0;
    for(int i = 0; i < strlen(s); i++)
    {
        ans *= 10; ans += (s[i] - '0');
    }
    return ans;
}

void showBoard(int n)
{
    int i, j;

    for(i = 1; i <=n; i++)
    {
	for(j = 1; j <=n; j++)
	{
	    printf("%3d ", G[i][j]);
	    if(j % 20 == 0)
		printf("\n");
	}
	printf("\n");
    }
}
int main()
{
    int n, temp, sd, node;
    scanf("%d", &n);
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; i++) G[i][i] = -1;
    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j <= i - 1; j++)
        {
            scanf("%s", st);
            if(st[0] == 'x') G[i][j] = G[j][i] = -1;
            else G[i][j] = G[j][i] = atoi(st);
        }
    }
    showBoard(n);
    int res;
        memset(vis, 0, sizeof(vis));
        for(int j = 1; j <= n; j++) d[j] = INF;
        d[1] = 0; sd = INF;
        for(int j = 1; j <= n; j++)
        {
            node = 0; sd = INF;
            for(int k = 1; k <= n; k++)
                if(!vis[k] && sd > d[k]) {node = k; sd = d[k];}
            if(!node) break;
            vis[node] = true;
	    printf("J:%d min:%d\n", j-1, sd);
            for(int k = 1; k <= n; k++)
                if(!vis[k] && G[node][k] != -1 && d[k] > d[node] + G[node][k])
                    d[k] = d[node] + G[node][k];

        }
        int mx = -1;
        for(int j = 1; j <= n; j++) if(d[j] > mx) mx = d[j];
        res = mx;
    printf("%d\n", res);
}
