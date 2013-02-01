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
#define ABS(x) ((x)<0?-(x):(x))
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a,m,n,s,t,l,tt;
long double f1,f2;
struct fs{ int a,b;}temp;
int main()
{
#ifdef ONLINE_JUDGE
#else
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
cin>>f1>>l;
f2=1e9;
LOOP(i,1,l){
    if(f2<1e-14)f2=0;
    t=f1*i;
    if(t==0)t=1;
    if(t>l)t=l;
    if(f2>ABS(f1-(long double)t/i)){
        temp.a=t;
        temp.b=i;
        f2=ABS(f1-(long double)t/i);
    }
    if(t<l)t++;
    if(f2>ABS(f1-(long double)t/i)){
        temp.a=t;
        temp.b=i;
        f2=ABS(f1-(long double)t/i);
    }
}
cout<<temp.a<<" "<<temp.b<<endl;
}
