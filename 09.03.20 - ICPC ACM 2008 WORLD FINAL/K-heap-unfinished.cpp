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
int i,j,k,d1,d2,a,m,n,s,t,l,tt,r,c,r1,r2,c1,c2;
const int maxn = 40000;
const int maxm = 40000;
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

inline int getid(int x,int y,int d){        //  1
    return d*10000+x*100+y;                 //0 * 2
}                                           //  3

inline bool fx(int d1,int d2){
    if(d1>d2){
        l=d1;d1=d2;d2=l;
    }
    return ((d1==1)&&(d2==3))||((d1==0)&&(d2==2));
}
int dijkstra(int s,int t){
    memset(w , 0x7f , sizeof(w));
    w[s] = 0;
    for (int i = 1; i <= k; i ++) p[i] = h[i] = i;
    hsp = t;
    /*for (int i = 1; i <= m; i ++)
    {
    int u , v , c;
    scanf("%d%d%d\n" , &u , &v , &c);
    e[i].b = v;
    e[i].c = c;
    e[i].next = f[u];
    f[u] = i;
    }*/

    while ( p[t] > 0 )
    {
    int d = h[s];
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
    return w[t];
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out","w",stdout);
    #endif
while(1){
    scanf("%d%d%d%d%d%d",&r,&c,&r1,&c1,&r2,&c2);
    r1--;r2--;c1--;c2--;
    if(r==0)break;
    memset(f , 0 , sizeof(f));
    tt=(r<<1)-1;
    k=0;
    LOOPB(i,0,tt)
        if(i&1)
            LOOPB(j,1,c){
                scanf("%d",&a);
                LOOPB(d1,0,4){
                    s=getid(i>>1,j-1,d1);
                    LOOPB(d2,0,4){
                        if(fx(d1,d2))continue;
                        t=getid(i>>1,j,d2);
                        e[k].b=t;
                        e[k].c=(d1==d2)?a:2*a;
                        e[k].next=f[s];
                        f[s]=k;
                        k++;
                        e[k].b=s;
                        e[k].c=(d1==d2)?a:2*a;
                        e[k].next=f[t];
                        f[t]=k;
                        k++;
                    }
                }
            }
        else
            LOOPB(j,0,c){
                scanf("%d",&a);
                LOOPB(d1,0,4){
                    s=getid(i>>1,j,d1);
                    LOOPB(d2,0,4){
                        if(fx(d1,d2))continue;
                        t=getid((i>>1)+1,j,d2);
                        e[k].b=t;
                        e[k].c=(d1==d2)?a:2*a;
                        e[k].next=f[s];
                        f[s]=k;
                        k++;
                        e[k].b=s;
                        e[k].c=(d1==d2)?a:2*a;
                        e[k].next=f[t];
                        f[t]=k;
                        k++;
                    }
                }
            }
    
   
    LOOPB(d1,0,4){
        s=getid(r1,c1,d1);
    LOOPB(d2,0,4){
        t=getid(r2,c2,d2);
        printf("%d\n" , dijkstra(s,t));
    }
    }
}
    return 0;
}
