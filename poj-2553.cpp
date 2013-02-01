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
int i,j,k,a,m,n,t,l,tt[5001];
vector<int> p[5001],p2[5001],s;
bool chk[5001];

void dfs(int n){
    chk[n]=true;
    int i,j=p[n].size();
    LOOPB(i,0,j)
        if(!chk[p[n][i]])
            dfs(p[n][i]);
    s.push_back(n);
}

void dfs2(int n){
    chk[n]=true;
    int i,j=p2[n].size();
    LOOPB(i,0,j)
        if(!chk[p2[n][i]])
            dfs2(p2[n][i]);
    tt[n]=l;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d",&n);
while(n!=0){
    scanf("%d",&m);
    s.clear();
    LOOPB(i,0,n){
        p[i].clear();
        p2[i].clear();
        chk[i]=false;
    }
    LOOPB(i,0,m){
        scanf("%d%d",&a,&k);
        a--;k--;
        p[a].push_back(k);
        p2[k].push_back(a);
    }
    LOOPB(i,0,n)
        if(!chk[i])
            dfs(i);
    LOOPB(i,0,n)
        chk[i]=false;
    j=s.size()-1;
    l=0;
    RLOOP(i,j,0)
        if(!chk[s[i]]){
            l++;
            dfs2(s[i]);
        }
    LOOP(i,0,l)
        chk[i]=true;
    LOOPB(i,0,n){
        k=p[i].size();
        LOOPB(j,0,k)
            if(tt[i]!=tt[p[i][j]])
                chk[tt[i]]=false;
        }
    LOOPB(i,0,n)
        if(chk[tt[i]]){
            printf("%d",i+1);
            break;
        }
    LOOPB(i,i+1,n)
        if(chk[tt[i]]){
            printf(" %d",i+1);
        }
    printf("\n");
    scanf("%d",&n);
}
}
