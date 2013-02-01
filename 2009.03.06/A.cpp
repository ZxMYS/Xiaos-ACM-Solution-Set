#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<sstream>
using namespace std;
#define LOOP(x,y,z) for((x)=(y);(x)<=(z);(x)++)
#define LOOPB(x,y,z) for((x)=(y);(x)<(z);(x)++)
#define RLOOP(x,y,z) for((x)=(y);(x)>=(z);(x)--)
#define RLOOPB(x,y,z) for((x)=(y);(x)>(z);(x)--)
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a,m,n,s,t,l,tt[100001];

int bs(int l,int r,int c){
if(l>=r) return l;
int t=(l+r)>>1;
if(tt[t]>=c) return bs(l,t,c);
if(tt[t]<c) return bs(t+1,r,c);
}

float f1,f2;
int main()
{
freopen("A.in","r",stdin);
freopen("A.out","w",stdout);

while(scanf("%d",&n)!=EOF){
    m=0;
    tt[0]=0;
    tt[1]=0;
    LOOPB(i,0,n){
    scanf("%d",&t);
    if(tt[0]==0||t>tt[tt[0]]){
        tt[++tt[0]]=t;
        m++;
    }else
        tt[bs(1,tt[0],t)]=t;
    }
    printf("%d\n",m);
    
}
}
