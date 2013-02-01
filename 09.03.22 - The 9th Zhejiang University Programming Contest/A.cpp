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
int i,j,k,a,m,n,s,t,l,tt;
float f1,f2;
inline int month_days(int year,int month)
{
int x=31;
if(month==2)
{
if((year%100==0&&year%400==0)||(year%100!=0&&year%4==0))
x=29;
else x=28;
}
else if(month==4||month==6||month==9||month==11)x=30;
else x=31;
return x;
}
int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d",&tt);
while(tt--){
    s=0;
    scanf("%d%d",&n,&m);
    LOOP(i,n,m){
        a=i%100;
        k=i%1000;
        if(a==k)a=(int)1e6;
        f1=sqrt((float)a);
        f2=sqrt((float)k);
        if(f1==(int)f1) a=(int)f1;
        else a=(int)1e6;
        if(f2==(int)f2) k=(int)f2;
        else k=(int)1e6;
        if(a>0&&a<=12){
            s++;
            if(k>0&&k<=month_days(i,a)){s++;}
        }
        if(k>0&&k<=12){
            s++;
            if(a>0&&a<=month_days(i,k)){s++;}
        }
    }
    printf("%d\n",s);
}
}
