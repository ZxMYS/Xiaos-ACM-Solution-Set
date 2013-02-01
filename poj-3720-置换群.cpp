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
int i,j,k,a,m,n,s,t,l,tt,cas,ans;
const int oo=1<<29;
typedef struct {int v,p;} node;
node grump[10101];
int nxt[10101];

inline bool cmp(const node& a,const node& b){
    return a.v<b.v;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
ans=0;
m=oo;
scanf("%d",&n);
LOOP(i,1,n){
    scanf("%d",&grump[i].v);
    grump[i].p=i;
    nxt[i]=-1;
    m=min(grump[i].v,m);
}
sort(grump+1,grump+1+n,cmp);
LOOP(i,1,n){
    if(nxt[i]==-1){
        t=1;
        s=tt=grump[i].v;
        nxt[i]=grump[i].p;
        j=nxt[i];
        while(j!=i){
            t++;
            s=min(s,grump[j].v);
            tt+=grump[j].v;
            nxt[j]=grump[j].p;
            j=nxt[j];
        }
        ans+=min(tt+(t-2)*s,tt+(t+1)*m+s);
    }
}
printf("%d\n",ans);

}
