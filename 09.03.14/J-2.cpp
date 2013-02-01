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
typedef struct {
    int x,y;
} point;
bool operator < ( const point lhs, const point rhs){
  return ( lhs.x < rhs.x || lhs.y < rhs.y );
}
point tmpp,tp,NUL;
int i,j,k,a,b,c,d,e,f,m,n,t,tt,up=0,orz=0;
string tmp;
const int INF=1<<28;
vector<string> ga;
vector<vector<int> > dis;
map<point,point> _map;
map<point,point>::iterator iter,iter2;

inline void link(int a,int b){
    assert(a!=b);
    dis[a][b]=dis[b][a]=1;
}

void f0(int x,int y){
    int sx=x,ex=x,t=orz;
    tp.y=y;
    while(sx>=0&&ga[sx][y]=='#'){
            tp.x=sx;
            (*_map.find(tp)).second.x=t;
            sx--;
        }
    while(ex<n&&ga[ex][y]=='#'){
            tp.x=ex;
            (*_map.find(tp)).second.x=t;
            ex++;
        }
    if((sx!=ex)){
        orz++;
    }
    else (*_map.find(tp)).second.x=-1;

}

void f1(int x,int y){
    int sy=y,ey=y,t=orz;
    tp.x=x;
    while(sy>=0&&ga[x][sy]=='#'){
        tp.y=sy;
        (*_map.find(tp)).second.y=t;
        sy--;
        }
    while(ey<m&&ga[x][ey]=='#'){
        tp.y=ey;
        (*_map.find(tp)).second.y=t;
        ey++;
    }
    if((sy!=ey)){
        orz++;
    }else
        (*_map.find(tp)).second.y=-1;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
//freopen("out","w",stdout);
#endif
scanf("%d%d\n",&n,&m);
NUL.x=-1;NUL.y=-1;
_map.clear();
ga.clear();

LOOPB(i,0,n){
    cin>>tmp;
    ga.push_back(tmp);
    LOOPB(j,0,tmp.length())
        if(tmp[j]=='#'){
            tmpp.x=i;tmpp.y=j;
            printf("insert:%d %d\n",tmpp.x,tmpp.y);
            _map.insert(make_pair(tmpp,NUL));
        }
    scanf("\n");
}

LOOPB(i,0,n){
    LOOPB(j,0,m){
        if(ga[i][j]=='.')continue;
        tmpp.x=i;tmpp.y=j;
        if((*_map.find(tmpp)).second.x==-1)
            {
                f0(i,j);
            }
        if((*_map.find(tmpp)).second.y==-1)
            {
                f1(i,j);
            }
    }
}


tt=orz;

dis.resize(tt);
LOOPB(i,0,tt){
    dis[i].clear();
    LOOPB(j,0,tt){
                dis[i].push_back(0x0FFFFFFF);
            }
}

LOOPB(i,0,n){
    LOOPB(j,0,m){
        tmpp.x=i;tmpp.y=j;
        iter=_map.find(tmpp);
        if((*iter).second.x!=-1&&(*iter).second.y!=-1)
        {
            link((*iter).second.x,(*iter).second.y);
        }
        }
    }

LOOPB(k,0,tt)
LOOPB(i,0,tt){
LOOPB(j,0,tt){
    if(i==j){dis[i][j]=0;continue;}
    if(k==j||k==i)continue;
    dis[j][i]=dis[i][j]=MIN(dis[i][j],dis[i][k]+dis[k][j]);
}
}

scanf("%d",&t);
LOOPB(i,0,t){
scanf("%d%d%d%d",&a,&b,&c,&d);
a--;b--;c--;d--;
printf("Q: %d %d - %d %d\n",a,b,c,d);
tmpp.x=a;tmpp.y=b;
iter=_map.find(tmpp);
tmpp.x=c;tmpp.y=d;
iter2=_map.find(tmpp);
assert(iter2!=_map.end()&&iter!=_map.end());
e=(*iter).second.x;
f=(*iter2).second.x;
tt=INF;
if(e!=-1&&f!=-1)tt=MIN(tt,dis[e][f]);
e=(*iter).second.y;
f=(*iter2).second.x;
if(e!=-1&&f!=-1)tt=MIN(tt,dis[e][f]);
e=(*iter).second.x;
f=(*iter2).second.y;
if(e!=-1&&f!=-1)tt=MIN(tt,dis[e][f]);
e=(*iter).second.y;
f=(*iter2).second.y;
if(e!=-1&&f!=-1)tt=MIN(tt,dis[e][f]);
if(tt==INF)tt=0;
printf("%d\n",tt);
}
/*
LOOPB(i,0,lines.size()){
    LOOPB(j,0,lines.size()){
        printf("%12d ",dis[i][j]);
    }
    printf("\n");
}

LOOPB(i,0,n){
    LOOPB(j,0,m){
        printf("%2d:%2d ",al[i][j].first,al[i][j].second);
    }
    printf("\n");
}*/


//LOOPB(i,0,lines.size())



}

