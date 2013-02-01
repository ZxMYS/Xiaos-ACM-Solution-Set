#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cassert>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<sstream>
using namespace std;
#define LOOP(x,y,z) for((x)=(y);(x)<=(z);(x)++)
#define LOOPB(x,y,z) for((x)=(y);(x)<(z);(x)++)
#define RLOOP(x,y,z) for((x)=(y);(x)>=(z);(x)--)
#define RLOOPB(x,y,z) for((x)=(y);(x)>(z);(x)--)
#define ABS(x) ((x)<0?-(x):(x))
#define PI 3.1415926535898
int i,j,k,a,m,n,s,t,l,tt,cas;
const int oo=1<<29;
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
set<int> mine;
set<int>::iterator iter2,iter;
double f[12];
double p,pp;

inline double func(int i){
    if(i==0)
        return 1;
    if(i==1)
        return p;
    if(i==2)
        return (1-p)+p*p;
    return (1-pow(p-1,i-1))/(2-p)*pp+p;
}

inline double calc(int s,int e){
    return func(e-s);
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
while(scanf("%d%lf",&n,&p)!=EOF){
    pp=1+p*p-2*p;
    mine.clear();
    LOOPB(i,0,n){
        f[i]=0;
        scanf("%d",&t);
        mine.insert(t);
    }
    if(mine.find(1)!=mine.end())
        goto L1;
    mine.insert(0);
    iter2=iter=mine.begin();
    iter++;
    i=1;
    f[0]=1;
    for(;iter!=mine.end();iter2=iter,i++,iter++){
        if(iter!=mine.begin()&&*iter2==*iter-1)goto L1;
        f[i]=f[i-1]*calc(*iter2+1,*iter-1)*(1-p);
    }
    printf("%.7lf\n",f[i-1]);
    continue;
    L1:
        printf("0.0000000\n");
}
}
