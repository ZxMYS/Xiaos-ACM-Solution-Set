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
int i,j,k,m,n,s,t,l,tt,cas;
double vax,vay,vbx,vby,xa,xb,ya,yb,ra,rb,a,b,c,delta,ans,ans1;

int main(){
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d",&cas);
while(cas--){
    scanf("%lf%lf%lf%lf%lf",&xa,&ya,&vax,&vay,&ra);
    scanf("%lf%lf%lf%lf%lf",&xb,&yb,&vbx,&vby,&rb);
    c=(xa-xb)*(xa-xb)+(ya-yb)*(ya-yb)-(ra+rb)*(ra+rb);
    b=2*(xa-xb)*(vax-vbx)+2*(ya-yb)*(vay-vby);
    a=(vax-vbx)*(vax-vbx)+(vay-vby)*(vay-vby);
    delta=b*b-4*a*c;
    if(delta<0)goto IM;
    if(a==0){
        if(b==0)
            if(c==0)ans=0;
            else goto IM;
        else
            ans=-c/b;
    }else{
    ans=(-b+sqrt(delta))/(2*a);
    ans1=(-b-sqrt(delta))/(2*a);
    if(ans<0&&ans1<0)goto IM;
    ans=MIN(ans,ans1);
    }
    printf("%.3lf %.3lf %.3lf %.3lf %.3lf\n",ans,ans*vax+xa,ans*vay+ya,ans*vbx+xb,ans*vby+yb);
    continue;
    IM:
        printf("Impossible\n");
}
}
