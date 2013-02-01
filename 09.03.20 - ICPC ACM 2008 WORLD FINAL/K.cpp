#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<map>
#include<queue>
#include<list>
#include<sstream>
using namespace std;
#define LOOP(x,y,z) for((x)=(y);(x)<=(z);(x)++)
#define LOOPB(x,y,z) for((x)=(y);(x)<(z);(x)++)
#define RLOOP(x,y,z) for((x)=(y);(x)>=(z);(x)--)
#define RLOOPB(x,y,z) for((x)=(y);(x)>(z);(x)--)
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define PI 3.1415926535898
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a,m,n,s,t,l,tt,r,c,r1,r2,c1,c2;
const int maxn = 50000;
const int maxm = 120000;
struct node
{
    int b , c;
    int next;
}e [maxm];
int h [maxn];
int p [maxn];
int w [maxn];
int f [maxn];
int hsp;
int adjust1(int t)
{
    int d = h[t];
    while ( t > 1 )
    {
    int t1 = t >> 1;
    if ( w[ h[t1] ] <= w[d] ) break;
    h[t] = h[t1];
    p[ h[t] ] = t;
    t = t1;
    }
    h[t] = d;
    p[d] = t;
    return 0;
}

int adjust2(int t)
{
    int d = h[t];
    while (t < hsp)
    {
    int t1 = t << 1;
    if ( t1 > hsp ) break;
    if ( t1 < hsp )
    if ( w[ h[ t1 + 1 ] ] < w[ h[t1] ] ) t1 ++;
    if ( w[ h[t1] ] >= w[d] ) break;
    h[t] = h[t1];
    p[ h[t] ] = t;
    t = t1;
    }
    h[t] = d;
    p[d] = t;
    return 0;
}

int adjustd(int d)
{
    adjust1(p[d]);
    adjust2(p[d]);
    return 0;
}


int delmin()
{
    p[ h[1] ] = 0;
    h[1] = h[ hsp -- ];
    if ( hsp <= 0 ) return 0;
    p[ h[1] ] = 1;
    adjust2(1);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out","w",stdout);
    #endif
    scanf("%d%d%d%d%d%d",&r,&c,&r1,&c1,&r2,&c2;
    
    memset(w , 0x7f , sizeof(w));
    memset(f , 0 , sizeof(f));
    w[1] = 0;

    for (int i = 1; i <= n; i ++) p[i] = h[i] = i;
    hsp = n;
    for (int i = 1; i <= m; i ++)
    {
    int u , v , c;
    scanf("%d%d%d\n" , &u , &v , &c);
    e[i].b = v;
    e[i].c = c;
    e[i].next = f[u];
    f[u] = i;
    }

    while ( p[n] > 0 )
    {
    int d = h[1];
    delmin();
    int i = f[d];
    while (i)
    {
    int s = w[d] + e[i].c;
    if ( w[ e[i].b ] > s )
    {
    w[ e[i].b ] = s;
    adjustd(e[i].b);
    }
    i = e[i].next;
    }
    }
    printf("%d\n" , w[n]);
    return 0;
}
