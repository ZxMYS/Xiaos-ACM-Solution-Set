#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<sstream>
#include<assert.h>
#include<list>
#include<iostream>
using namespace std;
#define LOOP(x,y,z) for((x)=(y);(x)<=(z);(x)++)
#define LOOPB(x,y,z) for((x)=(y);(x)<(z);(x)++)
#define RLOOP(x,y,z) for((x)=(y);(x)>=(z);(x)--)
#define RLOOPB(x,y,z) for((x)=(y);(x)>(z);(x)--)
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a,b,m,n,s,t,l,tt;
bool ga[26][26];
struct point{
    vector<int> a;
    }edge[26];

int dfs(int s,int now){
int i,t,tt=now;
    LOOPB(i,0,edge[s].a.size()){
        if(ga[s][edge[s].a[i]]){
            ga[edge[s].a[i]][s]=ga[s][edge[s].a[i]]=false;
            t=dfs(edge[s].a[i],now+1);
            ga[edge[s].a[i]][s]=ga[s][edge[s].a[i]]=true;
            tt=MAX(t,tt);
        }
    }
    return tt;
}
    
int main()
{
#ifdef ONLINE_JUDGE
#else
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
while(1){
    tt=-1;
    scanf("%d%d",&n,&m);
    if(n==0)break;
    LOOPB(i,0,n){
        memset(ga[i],0,sizeof(ga[i]));
        edge[i].a.clear();
    }
    LOOPB(i,0,m){
        scanf("%d%d",&a,&b);
        ga[a][b]=ga[b][a]=true;
        edge[a].a.push_back(b);
        edge[b].a.push_back(a);
    }
    LOOPB(i,0,n){
        t=dfs(i,0);
        tt=MAX(t,tt);
    }
    printf("%d\n",tt);
}
}
