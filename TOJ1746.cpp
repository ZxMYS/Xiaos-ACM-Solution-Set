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
int i,j,k,m,n,s,t,l,tt;
unsigned long long int f[600][600][20],ans[20];
const int BASE=10000;

void add(unsigned long long int a[],unsigned long long int b[]){
s=MAX(a[0],b[0]);
LOOP(t,1,s){
    a[t]+=b[t];
    a[t+1]+=a[t]/BASE;
    a[t]%=BASE;
}
a[0]=s;
if(a[s+1])a[0]++;
};

void addnum(unsigned long long int a[],unsigned long long int b){
a[1]+=b;
s=a[0];
LOOP(t,1,s){
    a[t+1]+=a[t]/BASE;
    a[t]%=BASE;
}
if(a[s+1])a[0]++;
}

int main()
{
#ifdef ONLINE_JUDGE
#else
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
LOOP(i,0,599)
LOOP(j,0,599){
        memset(f[i][j],0,sizeof(f[0][0]));
        //f[i][j][0]=f[i][j][1]=1;
}
while(1){
    scanf("%d",&n);
    if(n==0)break;

    f[1][1][0]=f[1][1][1]=1;
    memset(ans,0,sizeof(ans));
    LOOP(i,2,n){
    LOOPB(j,1,i){
        if(j>1)add(f[i][j],f[i-1][j-1]);//else{f[i][j][0]=f[i][j][1]=1;}
        if(j<i)add(f[i][j],f[i-j][j]);
    }
    }
    LOOP(i,1,n)
        add(ans,f[n][i]);
    /=if(n!=1)addnum(ans,1);
    printf("%llu",ans[ans[0]--]);
    RLOOP(i,ans[0],1)
        printf("%4llu",ans[i]);
    printf("\n");
}
}
