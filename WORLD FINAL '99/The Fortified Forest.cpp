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
#define PI 3.1415926535898
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
typedef struct {int x,y;} pointtype;
pointtype points[20],p[20];
int i,j,k,a,b,m,n,s,t,tt;
int nn, num, stop, ans0, v0, best, len;
int stack[20], ans[20], l[20], v[20];
bool flag[20];
double tmp,extra;

inline int det(int x0,int y0,int x1,int y1,int x2,int y2){
    return (x1-x0)*(y2-y0)-(x2-x0)*(y1-y0);
}

inline int det(int x1,int y1,int x2,int y2){
    return x1*y2-x2*y1;
}

int pcmp(const void* a, const void* b){
    int a1=(*(pointtype*)a).x-p[0].x,b1=(*(pointtype*)a).y-p[0].y;
    int a2=(*(pointtype*)b).x-p[0].x,b2=(*(pointtype*)b).y-p[0].y;
    int p=det(a1,b1,a2,b2);
    return (p>0||p==0&&a1*a1+b1*b1>a2*a2+b2*b2)?-1:1;
}

inline double dist(int x1,int y1,int x2,int y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

inline void findconvex(){
    t=0;
    LOOPB(i,0,nn)
        if(p[i].y<p[t].y||p[i].y==p[t].y&&p[i].x<p[t].x){
            t=i;
        }
    swap(p[0],p[t]);
    qsort(p+1,nn-1,sizeof(p[0]),pcmp);
    t=2;
    LOOPB(i,2,nn){
        if(det(p[0].x,p[0].y,p[i-1].x,
            p[i-1].y,p[i].x,p[i].y)!=0)
            p[t++]=p[i];
    }

    stop=3;
    stack[0]=0;
    stack[1]=1;
    stack[2]=2;
    
    LOOPB(i,3,t){
        for(a=stack[stop-2],b=stack[stop-1];
            det(p[a].x,p[a].y,p[b].x,
            p[b].y,p[i].x,p[i].y)<=0;
            a=stack[stop-2],b=stack[stop-1]){
                stop--;
            }
        stack[stop++]=i;
    }

}

inline void solve(){
    nn=0;tmp=0;len=0;
    LOOPB(i,0,n)
        if(flag[i]){
            len+=l[i];
        }else{
            p[nn++]=points[i];
        }
    stop=0;
    if(nn>2)
        findconvex();
    else{
        stop=nn;
        LOOPB(i,0,nn)
            stack[i]=i;
    }
    stack[stop]=stack[0];
    LOOPB(i,0,stop){
        tmp+=dist(p[stack[i]].x,p[stack[i]].y,p[stack[i+1]].x,p[stack[i+1]].y);
    }
    if(tmp<=len+1e-7){
        if(v0<best||v0==best&&n-nn<ans0){
            best=v0;
            ans0=0;
            LOOPB(i,0,n){
                if(flag[i])
                    ans[ans0++]=i;
            }
            extra=len-tmp;
        }
    }
}

void dfs(int x){
    if(x==n){
        solve();
        return;
    }
    dfs(x+1);
    flag[x]=1;
    v0+=v[x];
    dfs(x+1);
    flag[x]=0;
    v0-=v[x];
}

int main()
{
scanf("%d",&n);
while(n){
    t=0;
    LOOPB(i,0,n){
        scanf("%d%d%d%d",&points[i].x,&points[i].y,&v[i],&l[i]);
    }
    best=1<<29;
    memset(flag,0,sizeof(flag));
    v0=0;
    dfs(0);
    printf("Forest %d\nCut these trees:", ++tt);
    LOOPB(i,0,ans0)
        printf(" %d",ans[i]+1);
    printf("\nExtra wood: %.2f\n\n",extra);
    scanf("%d",&n);
}
}
