#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define VI vector<int>
#include<queue>
template <class T> void sw(T &a,T &b){T t; t = a; a = b; b = t;}
template <class T> T sqr(T x) {return x * x;}
using namespace std;
#define MaxN 21000

struct edge
{
       edge(int _to = 0,int _loc = 0){to = _to; loc = _loc;}
       int to,loc;
};

vector<edge> g[MaxN];
int a[MaxN];
int d[MaxN];
int m,n;

bool cmp(int x,int y)
{
     return d[x] > d[y];
}

void dfs(int u,int father,int dep)
{
     if (d[u]) return;
     d[u] = dep;
     for (int i = 0;i!=g[u].size();i++)
     {
         int v = g[u][i].to;
         if (v == father) continue;
         dfs(v,u,dep + 1);
     }
}

int main()
{
    cin >> n >> m;
    while (m--)
    {
          int x,y,loc1,loc2;
          scanf("%d%d",&x,&y);
          loc1 = g[x].size();
          loc2 = g[y].size();
          g[x].push_back(edge(y,loc2));
          g[y].push_back(edge(x,loc1));
    }
    dfs(1,-1,1);
    for (int i = 1;i<=n;i++) a[i] = i;
    sort(&a[1],&a[n] + 1,cmp);

    for (int r = 1;r<=n;r++)
    {
        int u = a[r],fnum;
        vector<int> U;U.clear();
        for (int j = 0;j!=g[u].size();j++)
        if (g[u][j].loc >= 0)
        {
            int v = g[u][j].to;
            if (d[v] + 1 == d[u]) fnum = j;
            if (d[v] < d[u]) continue;
            U.push_back(j);
        }
        if (U.size() % 2) U.push_back(fnum);
        for (int i = 0;i!=U.size();i++)
        if (!(i % 2))
        {
            int x = U[i],y = U[i+1];
            printf("%d %d %d\n",g[u][x].to,u,g[u][y].to);
            g[g[u][x].to][g[u][x].loc].loc = -1;
            g[g[u][y].to][g[u][y].loc].loc = -1;
        }
    }
    return 0;
}

