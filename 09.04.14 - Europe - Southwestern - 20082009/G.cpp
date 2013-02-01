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
#define PI 3.1415926535898
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a,m,n,s,t,l,tt,ans,MAXN;
bool chk[200001];
typedef struct{int t,v;} ee;
ee tmp;
int f[200001];
vector<ee> ch[200001];
float f1,f2;

int dfs(int p,int n){
    if(chk[n]) return f[n];
    chk[n]=true;
    int i;
    LOOPB(i,0,ch[n].size()){
        if(ch[n][i].t!=p)
        f[n]=MAX(f[n],f[n]+ch[n][i].v+dfs(n,ch[n][i].t));
    }
    ans=MAX(ans,f[n]);
    return f[n];
}

int main()
{
//#ifndef ONLINE_JUDGE
//freopen("in.txt","r",stdin);
//freopen("out","w",stdout);
//#endif
scanf("%d",&n);
while(n){
ans=0;
LOOP(i,0,MAXN){
    ch[i].clear();
}
MAXN=0;
LOOPB(i,0,n){
    scanf("%d%d%d",&a,&k,&t);
    tmp.t=a;
    tmp.v=t;
    ch[k].push_back(tmp);
    tmp.t=k;
    ch[a].push_back(tmp);
    MAXN=MAX(a,MAXN);
    MAXN=MAX(k,MAXN);
}
LOOP(i,0,MAXN){
    chk[i]=0;
    f[i]=0;
}
dfs(-1,tmp.t);
cout<<ans<<endl;
scanf("%d",&n);
}
}
