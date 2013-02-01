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
#define oo (1e8)
#define eps 1e-5
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
typedef struct {double  x,y;} ptype;
ptype ants[101];
int i,j,k,a,m,n,s,t,tt,cas,match[101];
double w[101][101],l[101],r[101],slack[101],dx,x,y;
bool chkx[101],chky[101];
inline double dis(int a,double x,double y){
    return sqrt((ants[a].x-x)*(ants[a].x-x)+(ants[a].y-y)*(ants[a].y-y)); //KAO,别写错符号
}

bool find(int u){       //邻接矩阵就不要传个n进来了。。。。
    chkx[u]=true;
    int i;
    LOOPB(i,0,n){
        if(!chky[i]){
            if(fabs(l[u]+r[i]-w[u][i])<eps){
                chky[i]=true;
                if(match[i]==-1||find(match[i])){
                    match[i]=u;
                    return true;
                }
            }else if(l[u]+r[i]-w[u][i]<slack[i])
                  slack[i]=l[u]+r[i]-w[u][i];
        }
    }
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d",&n);
LOOPB(i,0,n){
    scanf("%lf%lf",&ants[i].x,&ants[i].y);
    l[i]=-oo;
}
LOOPB(i,0,n){
    scanf("%lf%lf",&x,&y);
    r[i]=0;
    match[i]=-1;
    LOOPB(j,0,n){
        w[j][i]=-dis(j,x,y);
        l[j]=MAX(l[j],w[j][i]);
    }
}

LOOPB(k,0,n){
    LOOPB(i,0,n)
        slack[i]=oo;    //注意slack的初始化在这里。
    while(1){
        memset(chkx,0,sizeof(chkx));
        memset(chky,0,sizeof(chky));
        
        if(find(k))
            break;
            
        dx=oo;
        LOOPB(i,0,n)
            if(!chky[i]&&slack[i]<dx)
                    dx=slack[i];
        LOOPB(i,0,n){
            if(!chky[i])
                slack[i]-=dx;
            else
                r[i]+=dx;
            if(chkx[i])
                l[i]-=dx;
       }
    }
}
LOOPB(i,0,n)
    l[match[i]]=i;
LOOPB(i,0,n)
    printf("%.0lf\n",l[i]+1);
}
