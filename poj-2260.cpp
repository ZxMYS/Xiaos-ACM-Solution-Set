#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<sstream>
#include<assert.h>
#include<list>
#include<iostream>
using namespace std;
#define LOOP(x,y,z) for((x)=(y);(x)<=(z);(x)++)
#define LOOPB(x,y,z) for((x)=(y);(x)<(z);(x)++)
#define RLOOP(x,y,z) for((x)=(y);(x)>=(z);(x)--)
#define RLOOPB(x,y,z) for((x)=(y);(x)>(z);(x)--)
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a,m,n,s,t,l,tt,rows[101],cols[101];
float f1,f2;
int main()
{
#ifdef ONLINE_JUDGE
#else
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
while(1){
    scanf("%d",&n);
    memset(rows,0,sizeof(rows));
    memset(cols,0,sizeof(cols));
    if(0==n)break;
    LOOPB(i,0,n)
    LOOPB(j,0,n){
        scanf("%d",&a);
        rows[i]+=a;
        cols[j]+=a;
    }
    s=t=-1;
    LOOPB(i,0,n){
        if(rows[i]&1==1)
            if(s==-1)s=i;else goto L1;
        if(cols[i]&1==1)
            if(t==-1)t=i;else goto L1;
    }
    if(s==-1&&t==-1)
        printf("OK\n");
    else
        printf("Change bit (%d,%d)\n",s+1,t+1);
    continue;
    L1:
        printf("Corrupt\n");
}
}
