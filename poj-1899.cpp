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
int i,j,k,a,m,n,s,t,l,tt,r[110],x[110],y[110],f[110],ch[110];
struct shap{
    int l,r,t,b;
}rec[110];
/*inline unsigned long long int dis(int i,int j){
    return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
}*/

inline bool jiao(int i,int j){
    if(x[i]>x[j]){
        int t=i;
        i=j;
        j=t;
    }
    if(y[i]<=y[j])
        if(y[i]+r[i]>=y[j]-r[j]&&x[i]+r[i]>=x[j]-r[j])
            return true;
    else
        if(y[i]-r[i]>=y[j]+r[j]&&x[i]+r[i]>=x[j]-r[j])
            return true;
    return false;
}

int findp(int tar){
    if(f[tar]==tar)return tar;
    int i;
    i=findp(f[tar]);
    f[tar]=i;
    return i;
}

void update(int tar,int s){
    if(f[tar]==tar){
        f[tar]=s;return;
    }
    int i;
    i=f[tar];
    f[tar]=s;
    update(i,s);
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d %d",&n,&m);
s=n*m;
scanf("%d",&n);
LOOPB(i,0,n){
    scanf("%d%d%d",&x[i],&y[i],&r[i]);
    f[i]=i;
    ch[i]=false;
    rec[i].l=1<<29;
    rec[i].r=-(1<<29);
    rec[i].t=-(1<<29);
    rec[i].b=(1<<29);
}
LOOPB(i,0,n){
LOOPB(j,i+1,n){
    if(jiao(i,j)){
        update(j,findp(i));
    }
}
}
LOOPB(i,0,n){
    j=findp(i);
    //printf("C:%d %d %d\n",x[i],y[i],r[i]);
    rec[j].l=MIN(rec[j].l,x[i]-r[i]);
    rec[j].r=MAX(rec[j].r,x[i]+r[i]);
    rec[j].t=MAX(rec[j].t,y[i]+r[i]);
    rec[j].b=MIN(rec[j].b,y[i]-r[i]);
}
LOOPB(i,0,n){
    j=findp(i);
    if(!ch[j]){
        //printf("F!%d %d %d %d\n",rec[j].l,rec[j].r,rec[j].t,rec[j].b);
        s-=(rec[j].r-rec[j].l)*(rec[j].t-rec[j].b);
        ch[j]=true;
    }
}
printf("%d\n",s);
}
