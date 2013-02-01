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
#define ABS(x) ((x)<0?-(x):(x))
#define PI 3.1415926535898
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a,m,n,s,t,l,tt,x[1010],y[1010],z[1010],orz[1010],un[1010];
typedef struct {unsigned long long int d;int s,t;} link;
link links[1000010];
double ansr=0;
inline unsigned long long int dis(int i,int j){
return ((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])+(z[i]-z[j])*(z[i]-z[j]));
}

int cmp(const void* a, const void* b){
    return (*(link *)a).d>(*(link *)b).d?1:-1;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d",&n);
LOOPB(i,0,n){
    scanf("%d%d%d%d",&x[i],&y[i],&z[i],&orz[i]);
    un[i]=1;
}
l=-1;
LOOPB(i,0,n)
    LOOPB(j,i+1,n)
        //if(orz[i]!=orz[j])
        {
            //if(i==j)continue;
            links[++l].d=dis(i,j);
            links[l].s=i;
            links[l].t=j;
        }
        
qsort(links,l+1,sizeof(links[0]),cmp);

//LOOP(i,0,l)
//    printf("%llu %d %d\n",links[i].d,links[i].s,links[i].t);
s=0;ansr=0;m=0;i=0;
while(i<=l){
    j=i;
    while(j<=l&&links[j].d==links[i].d){
        //printf("%d %d\n",i,j);
        if(orz[links[j].s]!=orz[links[j].t]){
            un[links[j].t]--;
            un[links[j].s]--;
            if(un[links[j].t]==-1)m++;
            if(un[links[j].s]==-1)m++;
        }else{
            un[links[j].t]++;
            un[links[j].s]++;
            if(un[links[j].t]==0)m--;
            if(un[links[j].s]==0)m--;
        }
        j++;
    }
    if(m>s){
        s=m;
        ansr=links[i].d;
    }
    i=j;
}
printf("%d\n%.4lf\n",s,sqrt(double(ansr))+1e-8);
}
