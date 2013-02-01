#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<assert.h>
#include<string.h>
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
int i,j,k,a,m,n,s,t,l,tt,cas,ans;
char tmp,str[500];
float f1,f2;
vector<int> link[210];
bool chk[2001];
int match[2001];


inline bool find(int n){
    int i;
    LOOPB(i,0,link[n].size()){
        if(!chk[link[n][i]]){
            chk[link[n][i]]=true;
            if(match[link[n][i]]==-1||find(match[link[n][i]])){
                match[link[n][i]]=n;
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
scanf("%d",&n);
while(n){
    scanf("%d%d",&m,&k);
    RLOOP(i,n+m,0){
        link[i].clear();
    }
    LOOPB(i,0,k){
        scanf("%*d%d%d",&a,&s);
        if(!a||!s)
            continue;
        link[a].push_back(s);
        match[s]=-1;
    }
    ans=0;
    RLOOP(i,n-1,0){
        memset(chk,0,sizeof(chk));
        if(find(i))
            ans++;
    }
    printf("%d\n",ans);
    scanf("%d",&n);
}
}
