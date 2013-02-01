#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<memory.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<list>
using namespace std;
#define LOOP(x,y,z) for((x)=(y);(x)<=(z);(x)++)
#define LOOPB(x,y,z) for((x)=(y);(x)<(z);(x)++)
#define RLOOP(x,y,z) for((x)=(y);(x)>=(z);(x)--)
#define RLOOPB(x,y,z) for((x)=(y);(x)>(z);(x)--)
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define PI 3.1415926535898
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a,m,n,w,s,t[500],tt[500],l;
double width[500],ans;
float f1,f2;
int main()
{
scanf("%d%d",&n,&w);
while(n!=0){
    memset(tt,0,sizeof(tt));
    ans=0.01;
    LOOPB(i,0,n)
        scanf("%d",&t[i]);
    sort(t,t+n);
    a=w-1;m=1;i=0;
    while(i<n){
    while(t[i]<=a&&i<n){
        tt[m]++;
        i++;
    }
    a+=w;
    m++;
    }
    a=*max_element(tt,tt+m);
    LOOPB(i,1,m)
        width[i]=tt[i]*1.0/a;
    m--;
    LOOP(i,1,m){
        ans+=((m-i)*1.0/(m-1))*width[i];
    }
    printf("%.7lf\n",ans);
    scanf("%d%d",&n,&w);
}
}
