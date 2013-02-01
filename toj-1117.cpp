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
int i,j,k,a,m,n,s,t,l,tt,cas;
int ans,tot;
int aa,cz,bz;
bool f[2100];

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d%d",&n,&m);
l=0;
while(n){
    printf("Case %d: ",++l);
    memset(f,0,sizeof(f));
    tot=n*m;
    ans=0;
    LOOPB(i,0,m){
        scanf("%d",&aa);
        f[aa]=1;
    }
    cz=0;bz=0;
    RLOOPB(j,tot,0){
        if(f[j])
            cz++;
        else
            bz++;
            
        if(cz>bz){
            ans+=cz-bz;
            cz=0;
            bz=0;
        }
    }
    printf("%d\n",ans);
    scanf("%d%d",&n,&m);
}
}
