#include<stdio.h>
#include<algorithm>
#include<iostream>
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
int i,j,k,m,n,s,t,l,tt,cas,ans,ans2,f[1001];
typedef struct {int a,b;} doudous;
doudous a[1001];

bool cmp(const doudous a,const doudous b){
    return a.a!=b.a?a.a<b.a:a.b<b.b;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d",&n);
LOOPB(i,0,n){
    scanf("%d%d",&a[i].a,&a[i].b);
    f[i]=1;
}
sort(a,a+n,cmp);
/*LOOPB(i,0,n)
    cout<<a[i].a<<' '<<a[i].b<<endl;*/
ans=1;
LOOPB(i,0,n){
    LOOPB(j,i+1,n)
        if(a[j].a>a[i].a&&a[j].b>a[i].b){
            f[j]=MAX(f[i]+1,f[j]);
            ans=MAX(ans,f[j]);
        }
}
printf("%d\n",ans);
return 0;
}
