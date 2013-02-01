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
int i,j,k,a,m,n,s,t[10001],l[10001],tt=0;
vector<int> ga[10001],ga2[10001],qu;
bool chk[10001],out[10001];

void dfs(int n){
    chk[n]=true;
    int i,j=ga[n].size();
    LOOPB(i,0,j)
        if(!chk[ga[n][i]])dfs(ga[n][i]);
    qu.push_back(n);
}

void dfs2(int n){
    chk[n]=true;
    int i,j=ga2[n].size();
    LOOPB(i,0,j)
        if(!chk[ga2[n][i]])dfs2(ga2[n][i]);
    t[n]=s;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d%d",&n,&m);
LOOPB(i,0,m){
    scanf("%d%d",&a,&k);
    a--;k--;
    ga[a].push_back(k);
    ga2[k].push_back(a);
}
LOOPB(i,0,n)
    if(!chk[i])dfs(i);

LOOPB(i,0,n)
    chk[i]=false;

j=qu.size()-1;
s=0;
RLOOP(i,j,0)
    if(!chk[qu[i]]){
        s++;
        dfs2(qu[i]);
    }
LOOPB(i,0,n){
    k=ga[i].size();
    LOOPB(j,0,k)
        if(t[i]!=t[ga[i][j]])
            out[t[i]]=true;
}
a=0;
LOOP(i,1,s){
    if(!out[i]){
        a++;
        if(a>1)goto L1;
        k=i;
    }
}
qu.clear();
LOOPB(i,0,n)
    if(t[i]==k)
        qu.push_back(i);
printf("%d\n",qu.size());
return 0;
L1:
    printf("0\n");
    return 0;
}
