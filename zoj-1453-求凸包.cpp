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
int i,j,k,a,b,m,n,s,t,tt;
int nn, num, stop;
short stack[101];
double tmp;
typedef struct {short x,y;} pointtype;
pointtype p[101];

inline int det(int x0,int y0,int x1,int y1,int x2,int y2){
    return (x1-x0)*(y2-y0)-(x2-x0)*(y1-y0);
}

inline int det(int x1,int y1,int x2,int y2){
    return x1*y2-x2*y1;
}

bool pcmp(const pointtype a, const pointtype b){
    int a1=a.x-p[0].x,b1=a.y-p[0].y;
    int a2=b.x-p[0].x,b2=b.y-p[0].y;
    int p=det(a1,b1,a2,b2);
    return (p>0||p==0&&a1*a1+b1*b1>a2*a2+b2*b2);
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
    sort(p+1,p+nn,pcmp);
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

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d",&n);
while(n){
    LOOPB(i,0,n)
        scanf("%d%d",&p[i].x,&p[i].y);
    if(n==1){
        printf("0.00\n");
        goto L1;
    }
    if(n==2){
        printf("%.2lf\n",2*dist(p[0].x,p[0].y,p[1].x,p[1].y));
        goto L1;
    }
    nn=n;
    findconvex();
    stack[stop]=stack[0]; //NOTICE!
    tmp=0;
    LOOPB(i,0,stop){
        tmp+=dist(p[stack[i]].x,p[stack[i]].y,p[stack[i+1]].x,p[stack[i+1]].y);
    }
    printf("%.2lf\n",tmp);
    L1:
        scanf("%d",&n);
}
}
