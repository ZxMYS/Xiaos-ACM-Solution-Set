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
int i,j,k,a,b,m,n,t,l,tt,cas;
vector<int> ga[1011];
int f[2][1011];
typedef struct {int id,s,l;} qutype;
queue<qutype> qu;
qutype tmp,now;

inline int s(int from){
    while(!qu.empty())qu.pop();
    memset(f[0],-1,sizeof(f[0]));
    memset(f[1],-1,sizeof(f[1]));
    f[0][from]=f[1][from]=-1;
    now.id=from;now.s=0;now.l=-1;
    qu.push(now);
    int i;
    while(!qu.empty()){
        now=qu.front();
        qu.pop();
        LOOPB(i,0,ga[now.id].size()){
            j=ga[now.id][i];
            if(j==now.l) continue;
            if(!(now.s&1)){
                if(f[0][j]!=-1){
                    return f[0][j]+now.s+1;
                }
                else if(f[1][j]==-1)
                    f[1][j]=now.s+1;
            }else{
                if(f[1][j]!=-1){
                    return f[1][j]+now.s+1;
                }
                else if(f[0][j]==-1)
                    f[0][j]=now.s+1;
            }
            tmp.id=j;tmp.s=now.s+1;tmp.l=now.id;
            qu.push(tmp);
        }
    }
    return oo;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d",&cas);
l=0;
while(cas--){
    scanf("%d%d",&n,&m);
    LOOP(i,0,n){
        ga[i].clear();
    }
    LOOPB(i,0,m){
        scanf("%d%d",&a,&b);
        ga[a].push_back(b);
        ga[b].push_back(a);
    }
    tt=oo;
    LOOP(i,1,n){
        t=s(i);
        tt=MIN(t,tt);
    }
    if(tt!=oo)
        printf("Case %d: JYY has to use %d balls.\n",++l,tt);
    else
        printf("Case %d: Poor JYY.\n",++l,tt);
}
}
