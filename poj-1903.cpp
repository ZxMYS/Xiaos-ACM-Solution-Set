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
int i,j,k,a,m[500],n,s,t,l[500],tt[500];
char str[500];

void dfs(int now,int depth){
    if(now+n-depth<t)return;
    if(depth==n){
        if(s!=0)return;
        if(now>t){
            int i;
            LOOPB(i,0,now)
                l[i]=m[i]+1;
            t=now;
        }
        return;
    }
    dfs(now,depth+1);
    s^=tt[depth];
    m[now]=depth;
    dfs(now+1,depth+1);
    s^=tt[depth];
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d",&n);
LOOPB(i,0,n){
    scanf("%s",&str);
    tt[i]=0;
    j=0;
    while(str[j]){
        tt[i]+=1<<(str[j++]-'A');
    }
}
t=0;s=0;
dfs(0,0);
printf("%d\n",t);
if(t==0)return 0;
printf("%d",l[0]);
LOOPB(i,1,t){
    printf(" %d",l[i]);
}
printf("\n");
}
