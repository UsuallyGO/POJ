#include <stdio.h>
int b[4][2]={{-1,0},{0,-1},{1,0},{0,1}};//方向控制
int n,m,x,y;
void work()
{
    int a[100][100];
    int i,j,x1,y1,s=4;
    char chr;
    for (i=0;i<n;i++)
        for (getchar(),j=0;j<m;j++)
        {
            scanf("%c",&chr);
            if (chr=='N') a[i][j]=0;
            else if (chr=='W') a[i][j]=1;
                else if (chr=='S') a[i][j]=2;
                    else a[i][j]=3;
        }
    x=0;
    y--;
    while (x>=0&&x<n&&y>=0&&y<m&&a[x][y]<4)//边界判断：出界or循环
    {
        x1=x+b[a[x][y]][0];
        y1=y+b[a[x][y]][1];
        a[x][y]=s;//赋为当前步数
        x=x1;
        y=y1;
        s++;
    }
    if (x>=0&&x<n&&y>=0&&y<m) printf("%d step(s) before a loop of %d step(s)\n",a[x][y]-4,s-a[x][y]);
    else printf("%d step(s) to exit\n",s-4);//修正步数
}
int main()
{
    scanf("%d%d%d",&n,&m,&y);
    while (n>0)
    {
        work();
        scanf("%d%d%d",&n,&m,&y);
    }
    return 0;
}
