#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<assert.h>
#include<string.h>
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
int i,j,k,a,m,n,s,t,l,tt,cas;
int B[20002],A[20002];
unsigned long long int ans;
float f1,f2;
int main()
{
#ifndef ONLINE_JUDGE
freopen("d.in","r",stdin);
#endif
scanf("%d",&cas);
while(cas--){
    ans=0;
    scanf("%d%d",&n,&m);
    LOOPB(i,0,n)
        scanf("%d",&A[i]);
    LOOPB(i,0,m)
        scanf("%d",&B[i]);
        
    sort(B,B+m);
    LOOPB(i,0,n){
        ans+=lower_bound(B,B+m,A[i])-B;
        //cout<<i<<":"<<lower_bound(B,B+m,A[i])-B<<' '<<A[i]<<endl;
    }
    printf("%llu\n",ans);
}

}
