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
int i,j,k,a,m,n,s,t,ch[50001],maxch[50001],u[50001],tt,ans;
vector<int> ga[50001],ansp;
int dfs(int p){
    if(u[p])return 0;
    u[p]=1;
    ch[p]=0;
    maxch[p]=0;
    int i,j;
    LOOPB(i,0,ga[p].size()){
        j=dfs(ga[p][i]);
        ch[p]+=j;
        maxch[p]=MAX(maxch[p],j);
    }
    return ch[p]+1;
}


int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d",&n);
LOOPB(i,1,n){
    scanf("%d%d",&a,&k);
    ga[k].push_back(a);
    ga[a].push_back(k);
}
dfs(1);
ans=(1<<29);
LOOP(i,1,n){
    if(MAX(maxch[i],n-ch[i]-1)<ans){
        ansp.clear();
        ansp.push_back(i);
        ans=MAX(maxch[i],n-ch[i]-1);
    }
    else if(MAX(maxch[i],n-ch[i]-1)==ans){
        ansp.push_back(i);
    }
}
printf("%d",ansp[0]);
LOOPB(i,1,ansp.size()){
    printf(" %d",ansp[i]);
}
putchar('\n');
}
