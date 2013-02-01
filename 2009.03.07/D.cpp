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
int i,j,k,a,m,n,s,t,l,fes[10000];
long double f1,f2;
struct fs{ int a,b;}temp;

struct fs yf(struct fs num){
    int a,b,t;
    do{
        a=MAX(num.a,num.b);
        b=MIN(num.a,num.b);
        while(b!=0){
        t=b;
        b=a%b;
        a=t;
        }
    if(a==1)break;
    num.a/=a;
    num.b/=a;
    }while(1);
    return num;
}

struct fs deal2(int a,struct fs b){
struct fs t;
t.a=a*b.b+b.a;
t.b=b.b;
return yf(t);
}

struct fs deal(long double num){
int t;
bool f;
struct fs tt,tt2;
t=(int)num;
fes[a++]=t;
while(ABS(num-floor(num))>=0.000001){
    num=1/(num-t);
    t=int(num);
    fes[a++]=t;
    if(a==10000)break;
}
a--;
//LOOP(i,0,a)
//    printf("!%d ",fes[i]);

RLOOP(i,a,0){
    f=true;
    tt.a=1;
    tt.b=fes[i];
    RLOOP(j,i-1,0){
        tt=deal2(fes[j],tt);
        t=tt.a;tt.a=tt.b;tt.b=t;
        if(tt.a>l||tt.b>l){f=false;break;}
    }
    if(f)break;
}

if(ABS((long double)(tt.a)/tt.b-num)>ABS(1/l-num)){
    tt.b=1;tt.a=l;
}

if(f)return tt;
}
int main()
{
#ifdef ONLINE_JUDGE
#else
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
cin>>f1>>l;
temp=deal(f1);
printf("%d %d\n",temp.b,temp.a);
}
