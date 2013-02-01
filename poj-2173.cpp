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
int i,j,k,a,m,n,s,t=0,l,w,h,tt,P,Q,L;
typedef struct {int x,y;} point;
point p[102];

inline int check(int x,int y){
    int orz,l=MIN(w-x,h-y);
    LOOPB(orz,0,n){
        if(x+l>p[orz].x&&y+l>p[orz].y&&x<p[orz].x&&y<p[orz].y){
            l=MAX(p[orz].x-x,p[orz].y-y);
        }
    }
    //cout<<x<<' '<<y<<' '<<l<<endl;
    return l;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d%d%d",&n,&w,&h);
LOOPB(i,0,n){
    scanf("%d%d",&p[i].x,&p[i].y);
}
p[n].x=0;
p[n].y=0;
LOOP(i,0,n)
    LOOP(j,0,n){
        s=check(p[i].x,p[j].y);
        if(s>t){
            P=p[i].x;
            Q=p[j].y;
            t=s;
        }
    }
cout<<P<<' '<<Q<<' '<<t<<endl;
}
