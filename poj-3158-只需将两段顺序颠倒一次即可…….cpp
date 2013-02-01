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
int i,j,k,a,m,n,s,t,l,tt;
bool wk1[200],wk2[200],wk3;
char tmp;

inline bool check(int p){
    if(p+m>=tt)return false;
    int i,j=MIN(p+m,n);
    LOOP(i,p,j){
        if(wk1[i]&&wk2[i-p])return false;
    }
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
tt=1<<29;
memset(wk1,0,sizeof(wk1));
memset(wk2,0,sizeof(wk2));
n=-1;
scanf("%c",&tmp);
while(tmp!='\n'){
    wk1[++n]=tmp-'1';
    scanf("%c",&tmp);
}

m=-1;
scanf("%c",&tmp);
while(tmp!='\n'){
    wk2[++m]=tmp-'1';
    scanf("%c",&tmp);
}

LOOP(i,0,n+1){
if(i+m>=tt)break;
if(check(i)){
    tt=MIN(tt,MAX(m,MAX(n,(i<=0?-i+n:i+m))));
}
}
LOOP(i,0,m){
    wk3=wk2[i];
    wk2[i]=wk1[i];
    wk1[i]=wk3;
}
t=m;
m=n;
n=t;
LOOP(i,0,n+1){
if(i+m>=tt)break;
if(check(i)){
    tt=MIN(tt,MAX(m,MAX(n,i+m)));
}
}
printf("%d\n",tt+1);
}
