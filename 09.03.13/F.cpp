#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<memory.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<sstream>
#include<list>
using namespace std;
#define LOOP(x,y,z) for((x)=(y);(x)<=(z);(x)++)
#define LOOPB(x,y,z) for((x)=(y);(x)<(z);(x)++)
#define RLOOP(x,y,z) for((x)=(y);(x)>=(z);(x)--)
#define RLOOPB(x,y,z) for((x)=(y);(x)>(z);(x)--)
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define CHECK(x) (stat[i][(x)]==st[(x)])
#define PI 3.1415926535898
#define INF 1<<20
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
typedef struct {int x,y,s,st,orz;} s;
char ga[30][30],li[7];
queue<s> qu;
s tmp,tmp2;
int i,j,k,a,m,n,t,l,tt,sx,sy,now,f[30][30][24][6];
const int step[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
const char color[7]={'X','r','c','g','m','y','b'};
int o[128];
const int stat[24][6]={
    {1,2,3,4,5,6},
    {1,2,6,5,3,4},
    {1,2,4,3,6,5},
    {1,2,5,6,4,3},
    {2,1,4,3,5,6},
    {2,1,6,5,4,3},
    {2,1,3,4,6,5},
    {2,1,5,6,3,4},
    {3,4,2,1,5,6},
    {3,4,6,5,2,1},
    {3,4,1,2,6,5},
    {3,4,5,6,1,2},
    {4,3,1,2,5,6},
    {4,3,6,5,1,2},
    {4,3,2,1,6,5},
    {4,3,5,6,2,1},
    {5,6,2,1,4,3},
    {5,6,3,4,2,1},
    {5,6,1,2,3,4},
    {5,6,4,3,1,2},
    {6,5,1,2,4,3},
    {6,5,3,4,1,2},
    {6,5,2,1,3,4},
    {6,5,4,3,2,1},
};

const int turn[24][4]={
    {8,12,21,17},
    {22,18,13,9},
    {14,10,19,23},
    {16,20,11,15},
    {12,8,23,19},
    {20,16,9,13},
    {10,14,17,21},
    {18,22,15,11},
    {4,0,22,16},
    {23,17,1,5},
    {2,6,18,20},
    {19,21,7,3},
    {0,4,20,18},
    {21,19,5,1},
    {6,2,16,22},
    {17,23,3,7},
    {5,3,8,14},
    {9,15,0,6},
    {1,7,12,10},
    {13,11,4,2},
    {3,5,10,12},
    {11,13,6,0},
    {7,1,14,8},
    {15,9,2,4},
};

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d%d\n",&m,&n);
while(n!=0){
    while(!qu.empty())
        qu.pop();
    LOOPB(i,0,n){
        LOOPB(j,0,m){
            scanf("%c",&ga[i][j]);
            if(ga[i][j]=='#'){sx=i;sy=j;ga[i][j]='w';}
            LOOPB(k,0,24)
                LOOPB(a,0,6)
                    f[i][j][k][a]=INF;
            }
        scanf("\n");
    }
    scanf("%s",&li);
    LOOP(i,0,5)
        o[li[i]]=i;
    tmp.s=0;
    tmp.x=sx;
    tmp.y=sy;
    tmp.st=0;
    tmp.orz=0;
    tmp2.st=0;
    now=INF;
    qu.push(tmp);
    while(qu.size()>0){
        tmp=qu.front();
        qu.pop();
        if(now<=tmp.st)continue;
        LOOP(i,0,3){
            tmp2.x=tmp.x+step[i][0];
            tmp2.y=tmp.y+step[i][1];
            if(!(tmp2.x>=0&&tmp2.y>=0&&tmp2.x<n&&tmp2.y<m))continue;
            tmp2.st=tmp.st;
            tmp2.s=turn[tmp.s][i];
            if(ga[tmp2.x][tmp2.y]!='w'&&ga[tmp2.x][tmp2.y]!=color[stat[tmp2.s][0]])continue;
            if(ga[tmp2.x][tmp2.y]!='w'&&o[ga[tmp2.x][tmp2.y]]!=tmp.st)continue;
           tmp2.orz=tmp.orz+1;
            if(f[tmp2.x][tmp2.y][tmp2.s][tmp2.st]<=tmp2.orz)continue;
            if(ga[tmp2.x][tmp2.y]==li[tmp2.st]) {tmp2.st++;}
            if(tmp2.st==6){now=MIN(now,tmp2.orz);}
            f[tmp2.x][tmp2.y][tmp2.s][tmp2.st]=tmp2.orz;
            qu.push(tmp2);
        }
    }
    if(now<INF){printf("%d\n",now);goto L1;}
    printf("unreachable\n");
    L1:
    scanf("%d%d\n",&m,&n);
}
}
