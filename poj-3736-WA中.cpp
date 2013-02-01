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
const int oo=1<<29;
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a,m,n,s,t,l,tt,cas,x,y;
typedef struct {double x,y,s,t,d;} enemytype;
double HP,HP2;
double dist,dist2;
list<enemytype> en;
list<enemytype>::iterator iter,iter2;
enemytype tmp;

inline double dis(double x,double y,int x2){
    return (x-x2)*(x-x2)+y*y;
}


inline void move(){

}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
while(scanf("%d",&n)!=EOF){
    en.clear();
    HP2=0;
    tt=0;
    x=0;
    
    LOOPB(i,0,n){
        scanf("%lf%lf%lf%lf%lf",&tmp.x,&tmp.y,&tmp.t,&tmp.d,&tmp.s);
        tmp.d*=tmp.d;
        if(dis(tmp.x,tmp.y,0)<=tmp.d){
            HP2-=tmp.s;
            tt+=tmp.t;
        }
        else
            en.push_back(tmp);
    }
/*    iter=en.begin();
    while(iter!=en.end()){
        cout<<tmp.x<<' '<<tmp.y<<' '<<tmp.t<<' '<<tmp.d<<' '<<tmp.s<<endl;
        iter++;
    }*/
    scanf("%lf",&HP);
    HP+=HP2;
    if(HP<=0)
        goto L2;
    
    if(tt){
        L3:
        iter=en.begin();
        while(iter!=en.end()){
            move();
            if(dis(iter->x,iter->y,x)<=iter->d){
                HP-=iter->s;
                tt+=iter->t;
                if(HP<=0)
                    goto L2;
                iter=en.erase(iter);
            }else
                iter++;
        }
        tt--;
        if(tt)
            goto L3;
    }
    if(HP<=0)
        goto L2;
    while(x<=100&&HP>0&&!en.empty()){
        x++;
        t=1;
        L1:
        iter=en.begin();
        while(iter!=en.end()){
            move();
            if(dis(iter->x,iter->y,x)<=iter->d){
                HP-=iter->s;
                t+=iter->t;
                if(HP<=0)
                    goto L2;
                iter=en.erase(iter);
            }else
                iter++;
        }
        t--;
        if(t)
            goto L1;
        if(HP<=0)
            goto L2;
    }
    printf("Safe!\n");
    continue;
    L2:
        printf("Danger!\n");
}
}
