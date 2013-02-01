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
int i,j,k,a,m,n,s,t,l,tt,a1,a2,b1,b2,c1,c2,x1,y1;
double x0,y0;
int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif

scanf("%d%d%d%d%d%d%d%d",&a1,&b1,&c1,&a2,&b2,&c2,&x1,&y1);
x0=(c1*b2-c2*b1)/(a2*b2-a1*b1);
y0=(c1*a2-c2*a1)/(a2*b2-a1*b1);
printf("%lf %lf\n",x0,y0);
}
