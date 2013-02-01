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
const double pi = acos(-1.0);
#define MaxN 110

int n,K;
int w[MaxN];
int son[MaxN];
vector<int> g[MaxN];
int f[MaxN][MaxN][MaxN];
int sonnum[MaxN][MaxN];
int answer;

void maxi(int &a,int b)
{
     if (b == -1) return;
     if (b > a || a == -1) a = b;
}

void dp(int u,int father)
{
     son[u] = 0;
     for (int i = 0;i!=g[u].size();i++)
     {
         int v = g[u][i];
         if (v == father) continue;
         dp(v,u);
         sonnum[u][++son[u]] = v;
     }
     memset(f[u],-1,sizeof(f[u]));
     f[u][0][1] = w[u];
     
     for (int i = 0;i!=son[u];i++)
     for (int j = 1;j<=K;j++)
     if (f[u][i][j]!=-1)
     {
         for (int k = 0;j + k <= K;k++)
         {
             int v = sonnum[u][i + 1];
             if (f[v][son[v]][k] != -1)
             maxi(f[u][i + 1][j + k],f[u][i][j] + f[v][son[v]][k]);
         }
     }
     f[u][son[u]][0] = 0;
     maxi(answer,f[u][son[u]][K]);
}

int main()
{
    freopen("I.in","r",stdin);
    freopen("I.out","w",stdout);
    while (cin >> n >> K)
    {
        answer = -1;
        for (int i = 0;i!=n;i++) g[i].clear();
        for (int i = 0;i!=n;i++) scanf("%d",&w[i]);  
        for (int i = 1;i<=n-1;i++)
        {
           int x,y;
           scanf("%d%d",&x,&y);
           g[x].push_back(y);
           g[y].push_back(x);
        }
        dp(0,-1);
        cout << answer << endl;
    }    
    return 0;
}
