#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<assert.h>
#include<iostream>
#include<iomanip>
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
int i,j,k,a,m,n,s,t,x,y,z,l,tt;
char tmp,str[500];
double orz;
int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d%d%d%d",&x,&y,&z,&n);
orz=0;
LOOPB(i,0,n){
    printf("%0.10lf 0 0 ",orz);
    orz+=(x*1.0)/n;
    printf("%0.10lf %d %d\n",orz,y,z);
}
}
