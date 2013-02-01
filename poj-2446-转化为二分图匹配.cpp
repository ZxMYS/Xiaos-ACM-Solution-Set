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
#define oo (1<<29)
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a,m,n,s,t,l,tt,cas,d[40][40],link[32*32+10];
vector<int> ga[32*32+10];
bool chked[32*32+10],used[40][40],tmp;

bool find(int n){
    int i;
    LOOPB(i,0,ga[n].size()){
        if(!chked[ga[n][i]]){
            chked[ga[n][i]]=true;
            if(link[ga[n][i]]==-1||find(link[ga[n][i]])){
                link[ga[n][i]]=n;
                return true;
            }
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
scanf("%d%d%d",&m,&n,&k);
LOOP(i,1,m)
    LOOP(j,1,n)
        used[i][j]=1;
LOOPB(i,0,k){
    scanf("%d%d",&s,&t);
    used[t][s]=0;
}
tt=0;
LOOP(i,1,m)
    LOOP(j,1,n)
        if(used[i][j]){
            d[i][j]=tt;
            link[tt]=-1;
            tt++;
        }
LOOP(i,1,m)
    LOOP(j,1,n){
    if(!used[i][j])continue;
    if(used[i-1][j])
            ga[d[i][j]].push_back(d[i-1][j]);
    if(used[i+1][j])
            ga[d[i][j]].push_back(d[i+1][j]);
    if(used[i][j+1])
            ga[d[i][j]].push_back(d[i][j+1]);
    if(used[i][j-1])
            ga[d[i][j]].push_back(d[i][j-1]);
    }
tt=0;
LOOP(i,1,m)
    LOOP(j,1,m){
        if((i+j)&1)continue;
        memset(chked,0,sizeof(chked));
        if(used[i][j]){
            tmp=find(d[i][j]);
            if(!tmp)
                goto L1;
        }
    }
LOOP(i,1,m)
    LOOP(j,1,m){
        if((i+j)&1){
            if(used[i][j]&&link[d[i][j]]==-1)goto L1;
        }
    }
printf("YES\n");
return 0;
L1:
    printf("NO\n");
    return 0;
}
