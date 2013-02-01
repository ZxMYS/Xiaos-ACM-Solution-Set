#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define _NO_OLDNAMES
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
int i,j,k,a,m,n,s,t,l,tt,a1,a2,b1,b2,c1,c2;
int xxx,xxx2;
double x1,y1;
double x0,y0;
double st1,st2,s1,s2,xt,yt;

inline int dis(x1,y1,x2,y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

inline double side1(double x,double y){
    return a1*x+b1*y+c1;
}

inline double side2(double x,double y){
    return a2*x+b2*y+c2;
}

inline double fx1(double y){
    return ((double)-y*b1-c1)/a1;
}

inline double fx2(double y){
    return ((double)-y*b2-c2)/a2;
}

inline double fy1(double x){
    return ((double)-x*a1-c1)/b1;
}

inline double fy2(double x){
    return ((double)-x*a2-c2)/b2;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif

scanf("%d%d%d%d%d%d%lf%lf",&a1,&b1,&c1,&a2,&b2,&c2,&x1,&y1);
//x0=((double)(c1*b2-c2*b1))/(a1*b2-a2*b1);
//y0=((double)(c1*a2-c2*a1))/(a2*b1-a1*b2);
//printf("%lf %lf\n",x0,y0);
x0=x1;y0=y1;
//printf("%d %d\n",side1(x0,y0),side2(x0,y0));
if(atan(((double)b1)/a1)<atan(((double)b2)/a2)){
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
s1=side1(x0,y0);
s2=side2(x0,y0);
}
