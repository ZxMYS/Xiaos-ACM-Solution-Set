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
#define d0  1000000
#define d1   100000
#define d2    10000
#define d3     1000
#define d4      100
const int oo=1<<29;
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a,m,n,s,t,l,tt,cas;
bool hash[10101];
int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d",&n);
while(n){
    k=0;
    memset(hash,0,sizeof(hash));
    l=i2s(n).length();
    do{
        k++;
        hash[n]=true;
        n*=n;
        n=(((n/d1)-(n/d0*10))*d1+((n/d2)-(n/d1*10))*d2+((n/d3)-(n/d2*10))*d3+((n/d4)-(n/d3*10))*d4)/100;
    }while(hash[n]!=true);
    cout<<k<<endl;
    scanf("%d",&n);
}
}
