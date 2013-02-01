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
int a[20],b[20];
int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
//No problem! :D
//No problem. :(
scanf("%d",&n);
l=0;
while(n>=0){
    printf("Case %d:\n",++l);
    LOOPB(i,0,12)
        scanf("%d",&a[i]);
    LOOPB(i,0,12)
        scanf("%d",&b[i]);
    LOOPB(i,0,12){
        if(n>=b[i]){
            printf("No problem! :D\n");
            n-=b[i];
        }else
            printf("No problem. :(\n");
        n+=a[i];
    }
    scanf("%d",&n);
}
}
