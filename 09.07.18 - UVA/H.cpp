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
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define ABS(x) ((x)<0?-(x):(x))
#define PI 3.1415926535898
const int oo=1<<29;
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a,m,n,s,t,l,tt,cas,ID;
typedef struct {int t,v;} edge;
vector<edge> ga[10101];
vector<edge>::iterator gaiter;
edge tmp;
int g2[110][110];
int h[10101];
bool isHotel[10101];
bool queued[10101];
int HotelID[10101];
queue<int> qu;

inline void spfa(int s){
    int i;
    LOOPB(i,0,n){
        h[i]=oo;
        queued[i]=false;
    }
    while(!qu.empty())
        qu.pop();
    h[s]=0;
    qu.push(s);
    queued[s]=true;
    while(!qu.empty()){
        tt=qu.front();
        queued[tt]=false;
        qu.pop();
        gaiter=ga[tt].begin();
        while(gaiter!=ga[tt].end()){
            if(h[gaiter->t]>h[tt]+gaiter->v){
                queued[gaiter->t]=true;
                qu.push(gaiter->t);
                h[gaiter->t]=h[tt]+gaiter->v;
            }
            gaiter++;
        }
    }
    LOOPB(i,0,n){
        if(h[i]<=600&&isHotel[i])
            g2[HotelID[s]][HotelID[i]]=(i==n-1)?0:1;
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
    ID=0;
    tt=0;
    LOOPB(i,0,n){
        ga[i].clear();
        isHotel[i]=false;
    }
    LOOPB(i,0,103){
        LOOPB(j,0,103)
            g2[i][j]=oo;
    }
    scanf("%d",&t);
    LOOPB(i,0,t){
        scanf("%d",&a);
        a--;
        if(a==0||a==n-1)tt++;
        isHotel[a]=true;
        HotelID[a]=++ID;
    }
    isHotel[0]=isHotel[n-1]=true;
    HotelID[0]=0;HotelID[n-1]=++ID;
    scanf("%d",&m);
    LOOPB(i,0,m){
        scanf("%d%d%d",&a,&k,&l);
        a--;k--;
        tmp.t=k;
        tmp.v=l;
        ga[a].push_back(tmp);
        tmp.t=a;
        ga[k].push_back(tmp);
    }
    LOOPB(i,0,n){
        if(isHotel[i])
            spfa(i);
    }

    LOOP(k,0,ID)
        LOOP(i,0,ID){
            if(i==k)continue;
            LOOP(j,0,ID){
                if(i==j||j==k)continue;
                g2[i][j]=MIN(g2[i][k]+g2[k][j],g2[i][j]);
            }
    }
    printf("%d\n",g2[0][ID]<=600?g2[0][ID]:-1);
    scanf("%d",&n);
}
}
