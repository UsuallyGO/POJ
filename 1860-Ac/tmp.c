#include <stdio.h>
#include <iostream>
#include <map>
#include <stack>
#include <string.h>
#define INF 0x3f3f3f3f
using namespace std;
   
int n, m, s;
double v;
double dis[110];
int t;
   
struct node
{
    int x, y;
    double r, c;
} Map[210];
   
bool Bellman_Ford()
{
    memset(dis, 0, sizeof(dis));
    dis[s] = v;
    for(int i = 1; i <= n-1; i++)
    {
        bool flag = false;
        for(int j = 0; j < t; j++)
        {
            if(dis[Map[j].y] < (dis[Map[j].x]-Map[j].c)*Map[j].r)
            {
                dis[Map[j].y] = (dis[Map[j].x]-Map[j].c)*Map[j].r;
                flag = true;
            }
        }
        if(!flag)
        {
            break;
        }
    }
    for(int i = 0; i < t; i++)
    {
        if(dis[Map[i].y] < (dis[Map[i].x]-Map[i].c)*Map[i].r)
        {
            return true;
        }
    }
    return false;
}
   
void Solve()
{
    int a, b;
    double Rab, Rba, Cab, Cba;
    while(~scanf("%d%d%d%lf", &n, &m, &s, &v))
    {
        t = 0;
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d%lf%lf%lf%lf", &a, &b, &Rab, &Cab, &Rba, &Cba);
            Map[t].x = a;
            Map[t].y = b;
            Map[t].r = Rab;
            Map[t++].c = Cab;
            Map[t].x = b;
            Map[t].y = a;
            Map[t].r = Rba;
            Map[t++].c = Cba;
        }
        if(Bellman_Ford())
        {
            printf("YESn");
        }
        else
        {
            printf("NOn");
        }
    }
}
   
int main()
{
    Solve();
   
    return 0;
}
