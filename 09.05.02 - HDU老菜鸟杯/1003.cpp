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
int i,j,k,a,m,n,s,t,l,tt,cas;
unsigned int c[1001][1001];
long long int f[1001];
int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
while(scanf("%d%d",&n,&k)!=EOF){
    LOOP(i,0,n){
        c[i][0]=1;
        c[i][1]=i;
    }
    k<<=1;
    LOOP(i,1,n){
        LOOP(j,2,i)
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%k;
    }
    /*LOOP(i,0,n){
        LOOP(j,0,n)
            cout<<c[i][j]<< ' ';
        cout<<endl;
    }*/
    memset(f,0,sizeof(f));
    k>>=1;
    f[0]=1;
    f[1]=1;
    f[2]=1;
    LOOP(i,3,n){
        s=i-1;
        l=(s)>>1;
        LOOP(j,0,l){
            if(s-j!=j){
                f[i]+=(((f[j]*f[s-j])%k*c[s][j]))%k;
                f[i]%=k;
            }else{
                f[i]+=(((f[j]*f[j])%k*(c[s][j]>>1)))%k;
                f[i]%=k;
            }
        }
        //f[i]>>=1;
    }
    cout<<(f[n])<<endl;
}
}
