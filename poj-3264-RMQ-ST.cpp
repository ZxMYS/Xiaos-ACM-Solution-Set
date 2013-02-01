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
int i,j,k,a,m,n,q,s,t,l,tt[50001];
int f1[50001][16],f2[50001][16];
int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d%d",&n,&q);
LOOPB(i,0,n){
    scanf("%d",&tt[i]);
    f1[i][0]=f2[i][0]=tt[i];
}
k=(int)(log((double)n)/log(2.0)+1e-5);
LOOP(j,1,k)
for(i=0;i+(1<<j)-1<n;i++){
    m=i+(1<<(j-1));
    f1[i][j]=MIN(f1[i][j-1],f1[m][j-1]);
    f2[i][j]=MAX(f2[i][j-1],f2[m][j-1]);
}
while(q--){
    scanf("%d%d",&s,&t);
    s--;t--;
    k=(int)(log(double(t-s+1))/log(2.0)+1e-5);
    printf("%d\n",MAX(f2[s][k],f2[t-(1<<k)+1][k])-MIN(f1[s][k],f1[t-(1<<k)+1][k]));
}
}
