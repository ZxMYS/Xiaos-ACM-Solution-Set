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
#include<set>
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
int i,j,k,m,n,s,t,l,tt,cas,ans[100][100];
int a[100];

inline int check(){
    int i,K=0;
    LOOP(i,1,n-2){
        if(!((a[i-1]<a[i])^(a[i+1]<a[i])))
            K++;
    }
    if(K>=k)
        return 1;
    return 0;
}
#define maxN 11
int main(){
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
LOOPB(n,3,maxN){
    cout<<n<<':';
    LOOP(k,0,n-2){
        LOOPB(i,0,n)
            a[i]=i;
        ans[n][k]=0;
        ans[n][k]+=check();
        while(next_permutation(a,a+n)){
            ans[n][k]+=check();
        }
        printf("%9d ",ans[n][k]);
    }
    cout<<endl;
}

LOOPB(n,3,maxN){
    cout<<n<<':';
    LOOP(k,0,n-2){
        printf("%9d ",ans[n][k]>>1);
    }
    cout<<endl;
}

LOOPB(n,3,maxN){
    cout<<n<<':';
    LOOP(k,0,n-2){
        ans[n][k]-=ans[n][k+1];
        printf("%9d ",ans[n][k]);
    }
    cout<<endl;
}

LOOPB(n,3,maxN){
    cout<<n<<':';
    LOOP(k,0,n-2){
        ans[n][k]-=ans[n][k+1];
        printf("%9d ",!(ans[n][k]*k%(n-2)));
    }
    cout<<endl;
}
LOOPB(n,3,maxN){
    cout<<n<<':';
    LOOP(k,0,n-2){
        printf("%9d ",ans[n][k]>>1);
    }
    cout<<endl;
}

}
