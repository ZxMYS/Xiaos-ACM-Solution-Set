#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<assert.h>
#include<string.h>
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
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define ABS(x) ((x)<0?-(x):(x))
#define PI 3.1415926535898
int i,j,k,a,m,n,s,t,l,tt,cas;
typedef long long int ll;
ll f[12][1<<11];
ll ans[12][12];
inline bool chk(int stats){
    int i;
    LOOP(i,0,m-1){
        if(stats&1<<i){
            if(i==m-1)return 0;
            if(!(stats&1<<(++i)))return 0;
        }
    }
    return 1;
}
inline ll dp(int n,int stats){
    if(f[n][stats]!=-1)
        return f[n][stats];
    if(n==1)
        return chk(stats);
    int _st=~stats&a,i;
    ll ret=0;
    LOOP(i,0,a){
        if(~i&_st)continue;
        if(!chk(i&stats))continue;
        ret+=dp(n-1,i);
    }
    return f[n][stats]=ret;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
while(scanf("%d%d",&n,&m)&&(n||m)){
    if(n&1&&m&1){
        printf("0\n");
        continue;
    }
    if(n<m)swap(n,m);
    if(ans[n][m]!=0){
        printf("%I64d\n",ans[n][m]);
        continue;
    }
    LOOP(i,0,n)
        memset(f[i],-1,sizeof(f[i]));
    a=(1<<m)-1;
    printf("%I64d\n",ans[n][m]=dp(n,a));
}
}
