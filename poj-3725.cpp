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
int i,j,k,a,m,n,s,t,l;
int ans,tt;
int deal(int k,int m){
    int t=m,tt,ttt=10,w;
    w=1;
    tt=m-1;
    if(tt==0)return 0;
    while(t<k){
        t+=tt*ttt;
        ttt*=10;
        w++;
    }
    t-=tt*(ttt/10);
    //w--;
    return w;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
while(scanf("%d%d",&k,&m)!=EOF){
    ans=0;
    t=(int)floor(log10((long double)m));
    t=(int)pow(10,t);
    tt=deal(k,m/t);
    printf("tttt=%d\n",tt);
    //deal2(tt,m);
}

}
