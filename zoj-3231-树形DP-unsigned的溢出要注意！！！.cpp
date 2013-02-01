#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cassert>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<sstream>
using namespace std;
#define LOOP(x,y,z) for((x)=(y);(x)<=(z);(x)++)
#define LOOPB(x,y,z) for((x)=(y);(x)<(z);(x)++)
#define RLOOP(x,y,z) for((x)=(y);(x)>=(z);(x)--)
#define RLOOPB(x,y,z) for((x)=(y);(x)>(z);(x)--)
#define ABS(x) ((x)<0?-(x):(x))
#define PI 3.1415926535898
int i,j,k,m,n,s,t,l,tt,cas,M,avg;
const unsigned int oo=0xffffffff;
typedef struct {int t;unsigned int v;} bran;
bran tmp;
vector<bran> node[110];
int sum[110],cnt[110];
int a[110];
unsigned f[2][128][128];

void dfs(int now,int p){
    int i;
    cnt[now]=1;
    sum[now]=a[now];
    LOOPB(i,0,node[now].size()){
        if(node[now][i].t==p)
            i=node[now].erase(node[now].begin()+i)-node[now].begin()-1;
        else{
            dfs(node[now][i].t,now);
            sum[now]+=sum[node[now][i].t];
            cnt[now]+=cnt[node[now][i].t];
        }
    }
}

void dp(int now,unsigned int v){
    int i,j,k,p=0,pp=1;
    unsigned int m;
    LOOP(i,0,M)
        f[1][now][i]=f[0][now][i]=oo;
    f[0][now][0]=0;
    LOOPB(i,0,node[now].size()){
        dp(node[now][i].t,node[now][i].v);
        LOOP(j,0,M)
            f[pp][now][j]=oo;
        LOOP(j,0,M){
            LOOP(k,0,j){
                if(f[0][node[now][i].t][j-k]<oo&&f[p][now][k]<oo)
                f[pp][now][j]=min(f[pp][now][j],f[p][now][k]+f[0][node[now][i].t][j-k]);
            }
        }
        swap(p,pp);
    }
    if(p)
        LOOP(j,0,M)
            f[0][now][j]=f[p][now][j];
    RLOOP(j,M,0){
        m=abs(sum[now]-(cnt[now]*avg+j))*v;
        if(f[0][now][j]<oo)
            f[0][now][j]+=m;
        if(j&&f[0][now][j-1]<oo)
            f[0][now][j]=min(f[0][now][j-1]+m,f[0][now][j]);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
while(scanf("%d",&n)!=EOF){
    avg=0;
    LOOPB(i,0,n){
        scanf("%d",&a[i]);
        avg+=a[i];
        node[i].clear();
    }
    M=avg%n;
    avg/=n;
    LOOPB(i,1,n){
        scanf("%d%d%d",&k,&m,&s);
        tmp.t=k;
        tmp.v=s;
        node[m].push_back(tmp);
        tmp.t=m;
        node[k].push_back(tmp);
    }
    dfs(0,-1);
    dp(0,0);
    printf("%u\n",f[0][0][M]);
}
}
