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
int i,j,k,a,m,n,s,l,tt;
long long int a1,a2,b1,b2,c1,c2,rrr,rr;
long long int xxx,xxx2;
long double x1,y11;
long double x0,y00;
long double st1,st2,s1,s2,xt,xt2,yt1,yt2,yt3,a3,b3,t,c3,r;

inline int dis(long double x1,long double y1,long double x2,long double y2){
    return (long long int)((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

inline long double side1(long double x,long double y){
    return a1*x+b1*y+c1;
}

inline long double side2(long double x,long double y){
    return a2*x+b2*y+c2;
}

inline long double fx1(long double y){
    return ((long double)-y*b1-c1)/a1;
}

inline long double fx2(long double y){
    return ((long double)-y*b2-c2)/a2;
}

inline long double fx3(long double y){
    return ((long double)-y*b3-c3)/a3;
}

inline long double fy1(long double x){
    return ((long double)-x*a1-c1)/b1;
}

inline long double fy2(long double x){
    return ((long double)-x*a2-c2)/b2;
}

inline long double fy3(long double x){
    return ((long double)-x*a3-c3)/b3;
}

int main()
{
//#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
//#endif
//printf("%lf\n",atan(100)-atan(0));
scanf("%lld%lld%lld%lld%lld%lld%lld%lld",&a1,&b1,&c1,&a2,&b2,&c2,&rrr,&rr);
x1=rrr;
y11=rr;
x0=((long double)(c2*b1-c1*b2))/(a1*b2-a2*b1);
y00=fy1(x0);
//printf("%lf %lf\n",x0,y0);
if(atan(((long double)b1)/a1)<atan(((long double)b2)/a2)){
s=a1;
a1=a2;
a2=s;
s=b1;
b1=b2;
b2=s;
s=c1;
c1=c2;
c2=s;
}

s1=side1(x1,y11);
s2=side2(x1,y11);
//printf("%d %d\n",side1(x0,y0),side2(x0,y0));
rr=(long long int)1e7;
LOOP(i,-1,1)
    LOOP(j,-1,1){
        //if(i==0&&j==0)continue;
            xt=floor(x0)+i;
            yt2=floor(y00)+j;
            if(s1*side1(xt,yt2)>0&&s2*side2(xt,yt2)>0){
                rrr=dis(x0+i,y00+j,x0,y00);
                if(rr>rrr){
                    rr=rrr;
                    xt2=xt;
                    yt3=yt2;
                }
            }
    }
LOOP(i,-1,1)
    LOOP(j,-1,1){
        //if(i==0&&j==0)continue;
            xt=ceil(x0)+i;
            yt2=ceil(y00)+j;
            if(s1*side1(xt,yt2)>0&&s2*side2(xt,yt2)>0){
                rrr=dis(x0+i,y00+j,x0,y00);
                if(rr>rrr){
                    rr=rrr;
                    xt2=xt;
                    yt3=yt2;
                }
            }
    }
if(rr==1e7){
    b3=(y00-y11);
    a3=(x1-x0);
    c3=(x0-x1)*x1-(y00-y11)*y11;
t=((x0+x1))/2;
r=((x0+x1))/4;
while(fabs(r)>1e-6){
    yt1=fy1(t);
    yt2=fy2(t);
    if(fabs(yt2-yt1)>1){
        t=t-r;
    }
    else{
        t=t+r;
    }
    r/=2;
}
t=t>0?ceil(t+1e-5):floor(t-1e-5);
printf("%lld %lld\n",(long long int)t,(long long int)(fy2(t)+fy1(t))/2);
}else
printf("%lld %lld\n",(long long int)xt2,(long long int)yt3);
}
