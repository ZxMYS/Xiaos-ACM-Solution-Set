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
int i,j,k,a,m,n,s,t,l,tt,cas;
int p[111][111];
int ga[111][111];
char id[30];
bool labeled[30];
//North, West, East, South.
const int move[4][2]={{-1,0},{0,-1},{0,1},{1,0}};

inline char conv(int p){
    if(id[p]==-1)
        id[p]=s++;
    return id[p];
}

inline int flow(int x,int y){
    if(p[x][y]!=-1)
        return p[x][y];
    int xx,yy,i,h=ga[x][y],dir=-1;
    LOOPB(i,0,4){
        xx=x+move[i][0];
        yy=y+move[i][1];
        if(xx>=0&&yy>=0&&xx<m&&yy<n){
            if(ga[xx][yy]<h){
                dir=i;
                h=ga[xx][yy];
            }
        }
    }
    if(dir!=-1){
        p[x][y]=flow(x+move[dir][0],y+move[dir][1]);
    }else{
        p[x][y]=s++;
    }
    return p[x][y];
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("B-large.in","r",stdin);
freopen("out","w",stdout);
#endif
t=1;
scanf("%d",&cas);
while(cas--){
    printf("Case #%d:\n",t++);
    s=0;
    scanf("%d%d",&m,&n);
    LOOPB(i,0,m)
        LOOPB(j,0,n){
            scanf("%d",&ga[i][j]);
            p[i][j]=-1;
        }
                
    LOOPB(i,0,m)
        LOOPB(j,0,n){
            if(p[i][j]==-1)
                flow(i,j);
        }
    memset(id,-1,sizeof(id));
    s='a';
    LOOPB(i,0,m){
        cout<<conv(p[i][0]);
        LOOPB(j,1,n)
            cout<<' '<<conv(p[i][j]);
        cout<<endl;
    }
}
}
