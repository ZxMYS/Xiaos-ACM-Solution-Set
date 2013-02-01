#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<assert.h>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<string>
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
#define ABS(x) ((x)<0?-(x):(x))
#define PI 3.1415926535898
const int oo=1<<29;
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a,m,n,s,t,l,tt,cas,q,x,y,z,_x,_y,_z,T_T;
struct es{
    int t;
    int w;
    es(){}
    es(int a,int b){
        t=a;
        w=b;
    }
};
typedef struct es edge;
edge tmp;
vector<edge> ga[50001];
vector<int> E;
vector<int> D;
typedef struct {int v,p;} orz;
orz f1[17][50001 * 2];  //NOTICE!如果开成[50001 * 2][17]就会TLE了。
int pos[50001];
int ww[50001];
void build(int now,int f,int d,int w){
    int i;
    pos[now]=E.size();
    ww[now]=w;
    E.push_back(d);
    D.push_back(now);
    LOOPB(i,0,ga[now].size()){
        if(ga[now][i].t==f)continue;
        build(ga[now][i].t,now,d+1,ga[now][i].w+w);
        E.push_back(d);
        D.push_back(now);
    }
}

const int pow2[20]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288};

inline int mylog2(int x){
    int k=0;
    while(x>=pow2[k++]);
    return k-2;
}

inline int RMQ(int x,int y){
    int k=mylog2(y-x+1);
    if(f1[k][x].v<f1[k][y-(1<<k)+1].v)
        return f1[k][x].p;
    else
        return f1[k][y-(1<<k)+1].p;
}

inline void swap(int &x,int &y){
    int o_o=x;
    x=y;
    y=o_o;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif

T_T=0;
while(scanf("%d",&n)!=EOF){
    if(T_T)putchar('\n');
    else T_T=1;
    E.clear();
    D.clear();
    LOOP(i,0,n){
        ga[i].clear();
    }
    LOOPB(i,1,n){
        scanf("%d%d%d",&a,&k,&s);
        tmp.t=k;
        tmp.w=s;
        ga[a].push_back(tmp);
        tmp.t=a;
        ga[k].push_back(tmp);
    }
    
    //trans to RMQ
    build(0,-1,0,0);

    //RMQ pre-process
    l=E.size();
    LOOPB(i,0,l){
        f1[0][i].v=E[i];
        f1[0][i].p=D[i];
    }

    int k=mylog2(l);
    LOOP(j,1,k)
    for(i=0;i+(1<<j)-1<l;i++){
        m=i+(1<<(j-1));
        if(f1[j-1][i].v<=f1[j-1][m].v){
            f1[j][i]=f1[j-1][i];
        }else{
            f1[j][i]=f1[j-1][m];
        }
    }

    //solve query
    scanf("%d",&q);
    while(q--){
        scanf("%d%d%d",&x,&y,&z);
        _x=x;_y=y;_z=z;
        /*
        if(pos[x]>pos[y])swap(x,y);
        a=RMQ(pos[x],pos[y]);
        tt=ww[x]+ww[y]-ww[a]-ww[a];
        if(pos[a]>pos[z])swap(a,z);
        k=RMQ(pos[a],pos[z]);
        tt+=ww[a]+ww[z]-ww[k]-ww[k];
        t=tt;

        x=_x;y=_y;z=_z;
        if(pos[z]>pos[y])swap(z,y);
        a=RMQ(pos[z],pos[y]);
        tt=ww[z]+ww[y]-ww[a]-ww[a];
        if(pos[a]>pos[x])swap(a,x);
        k=RMQ(pos[a],pos[x]);
        tt+=ww[a]+ww[x]-ww[k]-ww[k];
        t=MIN(t,tt);

        x=_x;y=_y;z=_z;
        if(pos[x]>pos[z])swap(x,z);
        a=RMQ(pos[x],pos[z]);
        tt=ww[x]+ww[z]-ww[a]-ww[a];
        if(pos[a]>pos[y])swap(a,y);
        k=RMQ(pos[a],pos[y]);
        tt+=ww[a]+ww[y]-ww[k]-ww[k];
        t=MIN(t,tt);
        printf("%d\n",t);
        */
        
        //其实[dis(a,b)+dis(b,c)+dis(a,c)]/2就行了……见下：
        /*任意三点的距离等于任意两点之间的距离和除2。来证明一下：这三个顶点a、b、c中，我们选一个a做根节点,考虑这棵树的形态:
        1)     a          2)      a
              /                  / \
             .                  .   .
            .                  .     .
           .                  .       .
          b                  b        c
           \
            .
             .
              c
        容易知道只有以上两种，对于1）有ans=len(a,b)+len(b,c)=(len(a,b)+len(b,c)+len(a,c))/2；
        对于2) 有ans=len(a,b)+len(a,c)=(len(a,b)+len(b,c)+len(a,c))/2;len(i，j)表示i到j的距离。
        在考虑下特殊形式比如两个点相等，或三个点相等，代入上面两种情况，都满足。
        */
        if(pos[z]>pos[y])swap(z,y);
        a=RMQ(pos[z],pos[y]);
        tt=ww[z]+ww[y]-ww[a]-ww[a];
        y=_y;z=_z;
        if(pos[x]>pos[y])swap(x,y);
        a=RMQ(pos[x],pos[y]);
        tt+=ww[x]+ww[y]-ww[a]-ww[a];
        x=_x;y=_y;
        if(pos[x]>pos[z])swap(x,z);
        a=RMQ(pos[x],pos[z]);
        tt+=ww[x]+ww[z]-ww[a]-ww[a];
        tt>>=1;
        printf("%d\n",tt);
    }
}
}
