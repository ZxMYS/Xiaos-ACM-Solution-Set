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
int i,j,k,a,m,n,s,t,l,tt,cas;
vector<int> ga[200];
int match[200];
bool chk[200];
bool find(int n){
    int i;
    LOOPB(i,0,ga[n].size()){
        if(!chk[ga[n][i]]){
            chk[ga[n][i]]=true;
            if(match[ga[n][i]]==-1||find(match[ga[n][i]])){
                match[ga[n][i]]=n;
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
scanf("%d",&cas);
while(cas--){
    scanf("%d",&n);
    LOOPB(i,0,n){
        ga[i].clear();
        match[i]=-1;
    }
    scanf("%d",&m);
    LOOPB(i,0,m){
        scanf("%d%d",&a,&k);
        a--;k--;
        ga[a].push_back(k);
    }
    a=0;
    LOOPB(i,0,n){
        LOOPB(j,0,n)
            chk[j]=false;
        if(find(i))a++;
    }
    printf("%d\n",n-a);
}
}
