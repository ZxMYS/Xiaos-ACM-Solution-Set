#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cassert>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<sstream>
using namespace std;
#define LOOP(x,y,z) for((x)=(y);(x)<=(z);(x)++)
#define LOOPB(x,y,z) for((x)=(y);(x)<(z);(x)++)
#define RLOOP(x,y,z) for((x)=(y);(x)>=(z);(x)--)
#define RLOOPB(x,y,z) for((x)=(y);(x)>(z);(x)--)
#define ABS(x) ((x)<0?-(x):(x))
#define PI 3.1415926535898
#undef x
#undef y
int i,j,k,a,m,n,s,t,l,tt,cas,sx,sy,ex,ey,xleft,xright,ytop,ybottom,_xleft,_xright,_ytop,_ybottom;
typedef struct {int a,b,c;} line;
typedef struct {double x,y;} point;
line tmp,tmp2;

inline bool orz(int x1,int x2,int x3,int x4){
    if(x1>=x3&&x2<=x4)return true;
    if(x1<=x3&&x2>=x3)return true;
    if(x1<=x4&&x2>=x4)return true;
    if(x3>=x1&&x4<=x2)return true;
    return false;
}

inline bool cross(int x1,int x2,int y1,int y2,int x3,int x4,int y3,int y4){
    if(tmp.a*tmp2.b==tmp2.a*tmp.b){
        if(tmp.a*tmp2.c==tmp2.a*tmp.c)
            return orz(min(y1,y2),max(y1,y2),min(y3,y4),max(y3,y4))&&orz(min(x1,x2),max(x1,x2),min(x3,x4),max(x3,x4));
        return false;
    }
    point ptmp;
    ptmp.y=double(tmp.a*tmp2.c-tmp2.a*tmp.c)/(tmp2.a*tmp.b-tmp.a*tmp2.b);
    if(tmp.a==0){
        if(tmp.b*ptmp.y+tmp.c)
            return false;
        return orz(min(y1,y2),max(y1,y2),min(y3,y4),max(y3,y4))&&orz(min(x1,x2),max(x1,x2),min(x3,x4),max(x3,x4));
    }
    ptmp.x=double(tmp.b*ptmp.y+tmp.c)/-tmp.a;
    if(ptmp.x>=min(x1,x2)&&ptmp.x<=max(x1,x2)&&ptmp.y>=min(y1,y2)&&ptmp.y<=max(y1,y2))
        if(ptmp.x>=min(x3,x4)&&ptmp.x<=max(x3,x4)&&ptmp.y>=min(y3,y4)&&ptmp.y<=max(y3,y4))
            return true;
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d",&cas);
while(cas--){
    scanf("%d%d%d%d%d%d%d%d",&sx,&sy,&ex,&ey,&_xleft,&_ytop,&_xright,&_ybottom);
    xleft=min(_xleft,_xright);
    ytop=max(_ytop,_ybottom);
    xright=max(_xleft,_xright);
    ybottom=min(_ytop,_ybottom);
    if(sx>=xleft&&sx<=xright&&ex>=xleft&&ex<=xright&&sy>=ybottom&&sy<=ytop&&ey>=ybottom&&ey<=ytop)
        goto L1;
    if(sy==ey){
        tmp.a=0;
        tmp.b=1;
        tmp.c=-sy;
    }else if(sx==ex){
        tmp.a=1;
        tmp.b=0;
        tmp.c=-sx;
    }else{
        tmp.a=ey-sy;
        tmp.b=sx-ex;
        tmp.c=(ex-sx)*sy-(ey-sy)*sx;
    }

    tmp2.a=1;
    tmp2.b=0;
    tmp2.c=-xleft;
    if(cross(sx,ex,sy,ey,xleft,xleft,ybottom,ytop))
        goto L1;
    tmp2.a=1;
    tmp2.b=0;
    tmp2.c=-xright;
    if(cross(sx,ex,sy,ey,xright,xright,ybottom,ytop))
        goto L1;

    tmp2.a=0;
    tmp2.b=1;
    tmp2.c=-ybottom;
    if(cross(sx,ex,sy,ey,xleft,xright,ybottom,ybottom))
        goto L1;

    tmp2.a=0;
    tmp2.b=1;
    tmp2.c=-ytop;
    if(cross(sx,ex,sy,ey,xleft,xright,ytop,ytop))
        goto L1;
    printf("F\n");
    continue;
    L1:
        printf("T\n");
}
}
