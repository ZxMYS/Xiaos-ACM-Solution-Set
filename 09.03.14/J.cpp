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
#define INF 1<<28
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a,b,c,d,e,f,m,n,t,sx,sy,ey,ex,tt;
char tmp[10001];
int orz=0;
vector<vector<bool> > ga;
vector<bool> tmp2;
vector<vector<int> > dis;
vector<vector<int> > al;
inline void link(int a,int b){
    assert(a!=b);
    dis[a][b]=dis[b][a]=1;
}

void f0(int x,int y){
    int sx=x,ex=x,t=orz;
    while(sx>=0&&ga[sx][y]){
            al[sx][y]+=t;
            //if(al[sx][y].second!=-1){
            ///   link(al[sx][y].first,al[sx][y].second);
            //}
            sx--;
        }
    sx++;
    while(ex<n&&ga[ex][y]){
            al[ex][y]+=t;
            //if(al[ex][y].second!=-1){
            //    link(al[ex][y].first,al[ex][y].second);
            //}
            ex++;
        }
    ex--;
    if((sx!=ex)){
        //printf("L0:%d %d - %d %d\n",l.sx,l.ex,l.sy,l.ey);
        orz++;
    }
    else al[x][y]=al[x][y]|0x0000FFFF;
}

void f1(int x,int y){
    int sy=y,ey=y,t=orz;
    while(sy>=0&&ga[x][sy]){
        al[x][sy]&=0x0000FFFF;
        al[x][sy]+=(t<<16);
        sy--;
        }
    sy++;
    while(ey<m&&ga[x][ey]){
        al[x][ey]&=0x0000FFFF;
        al[x][ey]+=(t<<16);
        ey++;
    }
    ey--;
    if((sy!=ey)){
        orz++;
    }else
        al[x][y]=al[x][y]|0xFFFF0000;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d%d\n",&n,&m);
ga.clear();
al.resize(n);
LOOPB(i,0,n){
    scanf("%s",&tmp);
    printf("%s!\n",tmp);
    tmp2.clear();
    LOOPB(j,0,m)
        if(tmp[j]=='.')tmp2.push_back(0); else tmp2.push_back(1);
    ga.push_back(tmp2);
    al[i].clear();
    LOOPB(j,0,m){
        al[i].push_back(0xFFFFFFFF);
    }
    scanf("\n");
}

LOOPB(i,0,n){
    LOOPB(j,0,m){
        if(ga[i][j]=='.')continue;
        if((al[i][j]&0xFFFF0000)==0xFFFF0000)
            {
                f0(i,j);
            }
        if((al[i][j]&0x0000FFFF)==0x0000FFFF)
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
    LOOPB(j,0,m)
        if(((al[i][j]&0x0000FFFF)!=0x0000FFFF)&&((al[i][j]&0xFFFF0000)!=0xFFFF0000))
        {
            link(al[i][j]&0x0000FFFF,(al[i][j]&0xFFFF0000)>>16);
        }
    }
ga.clear();
LOOPB(k,0,tt){
    dis[k][k]=0;
LOOPB(i,0,tt){
    if(i==k)continue;
LOOPB(j,0,tt){
    if(k==j||k==i)continue;
    dis[j][i]=dis[i][j]=MIN(dis[i][j],dis[i][k]+dis[k][j]);
}
}
}

LOOPB(i,0,n){
    LOOPB(j,0,m)
        printf("%d:%d ",al[a][b]&0x0000FFFF,(al[a][b]&0xFFFF0000)>>16);
    printf("\n");
}

scanf("%d",&t);
LOOPB(i,0,t){
scanf("%d%d%d%d",&a,&b,&c,&d);
a--;b--;c--;d--;
e=al[a][b]&0x0000FFFF;
f=al[c][d]&0x0000FFFF;
tt=INF;
if(e!=0x0000FFFF&&f!=0x0000FFFF)tt=MIN(tt,dis[e][f]);
e=(al[a][b]&0xFFFF0000)>>16;
f=al[c][d]&0x0000FFFF;
if(e!=0x0000FFFF&&f!=0x0000FFFF)tt=MIN(tt,dis[e][f]);
e=al[a][b]&0x0000FFFF;
f=(al[c][d]&0xFFFF0000)>>16;
if(e!=0x0000FFFF&&f!=0x0000FFFF)tt=MIN(tt,dis[e][f]);
e=(al[a][b]&0xFFFF0000)>>16;
f=(al[c][d]&0xFFFF0000)>>16;
if(e!=0x0000FFFF&&f!=0x0000FFFF)tt=MIN(tt,dis[e][f]);
if(tt==INF)tt=0;
printf("%d\n",tt);
}
}

