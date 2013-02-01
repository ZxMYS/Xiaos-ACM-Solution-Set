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
#define EPS 1e-3
#define ABS(x) ((x)<0?-(x):(x))
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a,m,n,s,t,l,tt,pp;
typedef struct {long double  x,y;} point;
point p[21];
int ans[21],ans2[21];

bool ok(){
int i,k;
long double ty;
LOOPB(i,0,n){
    ty=0;
    LOOP(k,0,9){
        ty+=exp(p[i].x*(long double)ans[k]);
        if(ty-EPS>p[i].y)return false;
    }
}
return true;
}

bool dfs(int a){
    if(a==-1){
        int i,k;
        long double ty;
        LOOPB(i,0,n){
            ty=0;
            LOOP(k,0,9){
                ty+=exp(p[i].x*(long double)ans[k]);
            }
            if(ABS(ty-p[i].y)>EPS)
                return false;
        }
        return true;
    }
    int i,j=0,k;
    RLOOP(ans[a],ans[a+1],0){
        if(ok()){
            if(ans[a]==0)return false;
            j=j||dfs(a-1);
            if(j)return j;
        }
    }
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d",&n);
LOOPB(i,0,n)
    cin>>p[i].x>>p[i].y;
memset(ans,0,sizeof(ans));
ans[10]=10;
if(dfs(9))
LOOP(i,0,9)
    cout<<ans[i]<<endl;
else
    assert(0);
}
