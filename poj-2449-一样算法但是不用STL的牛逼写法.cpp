#include<iostream>
#include<memory>
using namespace std;

#define MAXN 1002
#define MAXM 100002
#define inf 0x3fffffff

struct edge{
    int v,l,next;
};
struct node{
    int v,l;
};

edge e[MAXM],e1[MAXM];
int g[MAXN],g1[MAXN];
int n,m;
int s,t,k;
int h[MAXN];
int q[1000000];

int _cp(const node& a,const node& b)
{
    return a.l+h[a.v]<b.l+h[b.v]?1:0;
}

typedef node elem_t;
struct heap{
    elem_t h[MAXM*10];
    int n,p,c;
    void init(){n=0;}
    void ins(elem_t e){
        for(p=++n;p>1&&_cp(e,h[p>>1]);h[p]=h[p>>1],p>>=1);
        h[p] = e;
    }
    int del(elem_t& e){
        if( !n ) return 0;
        for(e=h[p=1],c=2;c<n&&_cp(h[c+=(c<n-1&&_cp(h[c+1],h[c]))],h[n]);h[p]=h[c],p=c,c<<=1);
        h[p]=h[n--];
        return 1;
    }
};

heap hp;
int c[MAXN];

int a_star()
{
    node pri,next;
    int p,i;
    if( h[s]==inf ) return -1;
    memset( c , 0 , sizeof(c) );
    hp.init();
    pri.v = s , pri.l = 0;
    hp.ins( pri );
    while( hp.del(pri) )
    {
        c[pri.v]++;
        if( c[t]==k ) return pri.l;
        if( c[pri.v]>k ) continue ;
        for( p=g[pri.v] ; p>=0 ; p=e[p].next )
        {
            next.v = e[p].v ;
            next.l = pri.l+e[p].l;
            hp.ins(next);
        }
    }
    return -1;
}

void cal()
{
    int i,f,r;
    for( i=0 ; i<=n ; i++ )
        h[i] = inf;
    h[t] = 0;
    q[0] = t;
    for( f=0,r=1 ; f<r ; f++ )
    {
        for( i=g1[q[f]] ; i>=0 ; i=e1[i].next ){
            if( h[e1[i].v]>h[q[f]]+e1[i].l )
                h[e1[i].v]=h[q[f]]+e1[i].l , q[r++] = e1[i].v;
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out","w",stdout);
    #endif
    int u,v,l,i,tt;
    while(scanf("%d%d",&n,&m)!=-1){
    memset( g , -1 , sizeof(g) );
    memset( g1 , -1 , sizeof(g1) );
    for( i=0 ; i<m ; i++ )
    {
        scanf("%d%d%d",&u,&v,&l);
        e[i].v = v , e[i].l = l;
        e[i].next = g[u] , g[u] = i;
        e1[i].v = u , e1[i].l = l;
        e1[i].next = g1[v] , g1[v] = i;
    }
    scanf("%d%d%d",&s,&t,&k);
    if( s==t ) k++;
    cal();
    tt = a_star();
    printf("%d\n",tt);}
    //system("pause");
}
