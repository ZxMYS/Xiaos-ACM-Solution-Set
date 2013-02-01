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

const int MaxN = 250;
const int MaxK = MaxN * MaxN;
const int Inf = 1000000000;

struct str
{
       str(){len = 0;}
       void in(char ch0)
       {
            scanf("%s",&s);
            len=strlen(s);
       }
       bool operator < (const str &a) const
       {
           for (int i = 0;i!=min(len,a.len);i++)
           {
               if (s[i] < a.s[i]) return 1;
               if (s[i] > a.s[i]) return 0;
           }
           return len < a.len;
       }
       bool operator == (const str &a) const
       {
           if (len != a.len) return 0;
           for (int i = 0;i!=min(len,a.len);i++)
           if (s[i] != a.s[i]) return 0;
           return 1;
       }
       int len;
       char s[20];
};
vector<str> U1,U2;

struct rivalry
{
       str a;
       str b;
       int c;
       void read()
       {
            a.in(' ');
            b.in(' ');  
            U1.push_back(a);
            U2.push_back(b);
            cin >> c;
            scanf("\n");
       }
}r[MaxK];

void maxi(int &a,int b)
{
     if (b>a) a = b;
}

void mini(int &a,int b)
{
     if (b<a) a = b;
}

int g[MaxN][MaxN];
int link[MaxN],dx[MaxN],dy[MaxN],vx[MaxN],vy[MaxN],slack[MaxN];
int m,n;

int find(int x)
{
    if (vx[x]) return 0;
    vx[x] = 1;
    for (int i = 1;i<=n;i++)
    if (!vy[i]){
    if (dx[x] + dy[i] == g[x][i])
    {
        vy[i] = 1;
        if (!link[i] || find(link[i]))
        {
             link[i] = x;
             return 1;
        }
    }else if(dx[x]+dy[i]-g[x][i]<slack[i])
             slack[i]=dx[x]+dy[i]-g[x][i];
    }
    return 0;
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out","w",stdout);
    #endif
    int K;
    while (scanf("%d%d%d\n",&m,&n,&K) > 0)
    {
    U1.clear();U2.clear();
    memset(link,0,sizeof(link));
    for (int i = 1;i<=m;i++)
    for (int j = 1;j<=n;j++)
    g[i][j] = -Inf;
    for (int i = 0;i!=K;i++) r[i].read();
    sort(U1.begin(),U1.end());
    vector<str>::iterator u1 = unique(U1.begin(),U1.end());
    sort(U2.begin(),U2.end());
    vector<str>::iterator u2 = unique(U2.begin(),U2.end());
    
    //for (int i = 0;i!=U1.size();i++) cout << U1[i] << endl; 
    
    for (int i = 0;i!=K;i++)
    {
        int x = (int)(lower_bound(U1.begin(),u1,r[i].a) - U1.begin()) + 1;
        int y = (int)(lower_bound(U2.begin(),u2,r[i].b) - U2.begin()) + 1;
        g[x][y] = -r[i].c;
        //cout << x << " " << y << " " << r[i].c << endl;
    }
    
    memset(dx,0,sizeof(dx));
    memset(dy,0,sizeof(dy));
    //for (int i = 1;i<=n;i++) dy[i] = -Inf;
    for (int i = 1;i<=m;i++)
    for (int j = 1;j<=n;j++)
    maxi(dy[j],g[i][j]);
    
        for (int start = 1;start<=m;start++){
        for(int i=1;i<=n;i++)
            slack[i]=Inf;
        while (1)
        {
              memset(vx,0,sizeof(vx));
              memset(vy,0,sizeof(vy));
              if (find(start)) break;
              int d = 2 * Inf;
              for (int i = 1;i<=n;i++)
                  if (!vy[i])
                        mini(d,slack[i]);
              for (int i = 1;i<=m;i++)
              if (vx[i]) dx[i]-=d;
              for (int i = 1;i<=n;i++)
              if (vy[i]) dy[i]+=d;
        }
        }
    
    int sum = 0;
    for (int i = 1;i<=m;i++) sum-=dx[i];
    for (int j = 1;j<=n;j++) sum-=dy[j];
    cout << sum << endl;
    }
    return 0;
}
