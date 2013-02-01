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
int i,j,k,a,m,n,s,t,l,tt,cas;
bool root[10001],chk[10001];
vector<int> ga[10001];
int f[10001];

int father(int root){
    if(f[root]==root)
        return root;
    f[root]=father(f[root]);
    return f[root];
}

bool lca(int root){
    f[root]=root;
    int i;
    LOOPB(i,0,ga[root].size()){
        if(lca(ga[root][i]))return true;
        f[ga[root][i]]=root;
    }
    chk[root]=true;
    if(root==a&&chk[k]){
        tt=father(k);
        return true;
    }else if(root==k&&chk[a]){
        tt=father(a);
        return true;
    }
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d",&cas);
while(cas--){
    scanf("%d",&n);
    LOOPB(i,0,n){
        chk[i]=false;
        root[i]=true;
        ga[i].clear();
    }
    LOOPB(i,1,n){
        scanf("%d%d",&a,&k);
        a--;k--;
        root[k]=false;
        ga[a].push_back(k);
    }
    scanf("%d%d",&a,&k);
    a--;k--;
    LOOPB(i,0,n){
        if(root[i])break;
    }
    lca(i);
    printf("%d\n",++tt);
}
}
