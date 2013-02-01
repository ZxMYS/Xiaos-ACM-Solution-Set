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
int i,j,k,a,m,n,s,t,l,tt[101][101],ga[101][101];
int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d",&n);
LOOPB(i,0,n)
    LOOPB(j,0,n)
        scanf("%d",&ga[i][j]);
LOOPB(i,0,n)
    LOOPB(j,0,n)
        if(j>0)tt[i][j]=tt[i][j-1]+ga[i][j];
        else tt[i][j]=ga[i][j];
l=0;
LOOPB(i,0,n)
    LOOPB(j,i,n){
    s=tt[1][j]-(i>0?tt[1][i-1]:0);
    m=s;
    LOOPB(k,2,n){
        if(m<0)m=0;
        m+=tt[k][j]-(i>0?tt[k][i-1]:0);
        if(m>l)l=m;
    }
}
printf("%d\n",l);
}
