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
int i,j,k,a,m,n,s=0,t,l,tt,nt,np,nf;
vector<int> in[100],out[100];
int stat[100],stat2[100];
inline int getrun(){
    LOOPB(i,0,np)
        stat2[i]=stat[i];
    LOOPB(i,0,nt){
        LOOPB(j,0,in[i].size()){
            if(!stat2[in[i][j]]) goto L1;
            stat2[in[i][j]]--;
        }
        return i;
        L1:;
    }
    return -1;
}

inline void tokens(){
    printf("Places with tokens: ");
    LOOPB(m,0,np)
        if(stat[m])printf(" %d(%d)",m+1,stat[m]);
    putchar('\n');
}

inline void dead(){
    printf("dead afrter %d transitions\n",l);
    tokens();
}

inline void stillalive(){
    printf("still alive after %d transitions\n",l);
    tokens();
}

inline void solve(){
    L2:
    int run;
    run=getrun();
    if(run==-1){
        dead();
        return;
    }
    LOOPB(i,0,out[run].size())
        stat[out[run][i]]++;
    LOOPB(i,0,in[run].size()){
        assert(stat[in[run][i]]>0);
        stat[in[run][i]]--;
    }
    l++;
    
    if(l==nf){
        stillalive();
        return;
    }
    goto L2;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d",&np);
while(np){
    l=0;
    printf("Case %d: ",++s);
    LOOPB(i,0,np)
        scanf("%d",&stat[i]);
    scanf("%d",&nt);
    LOOPB(i,0,nt){
        in[i].clear();
        out[i].clear();
    }
    LOOPB(i,0,nt){
        scanf("%d",&t);
        while(t){
            if(t<0)
                in[i].push_back((-t)-1);
            else
                out[i].push_back(t-1);
            scanf("%d",&t);
        }
    }
    scanf("%d",&nf);
    solve();
    putchar('\n');
    scanf("%d",&np);
}
}
