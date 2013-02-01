//化为4个子矩形
//预处理所有2^i*2^j的矩形

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
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
#define ABS(x) ((x)<0?-(x):(x))
#define PI 3.1415926535898
#define oo (1<<29)
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a,m,n,s,t,l,tt,cas,N,x1,x2,y1,y2;
int ga[301][301];
int f[9][9][301][301];
const int b[10]={1,2,4,8,16,32,64,128,256,512};

inline int LOG2(int n){
    int k=0;
    while(b[k]<=n)k++;
    return k-1;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d",&cas);
while(cas--){
    scanf("%d",&n);
    LOOPB(i,0,n)
        LOOPB(j,0,n){
            scanf("%d",&ga[i][j]);
            f[0][0][i][j]=ga[i][j];
        }

    s=LOG2(n);
    
    //注意循环的顺序。
    LOOP(i,0,s)//W
        LOOP(j,0,s){//H
            if((!i)&(!j))continue;
            for(t=0;t+b[j]<=n;t++)//注意是<=
                for(l=0;l+b[i]<=n;l++)
                    if(!i)//W
                            f[i][j][t][l]=MIN(f[i][j-1][t][l],f[i][j-1][t+b[j-1]][l]);
                    else
                            f[i][j][t][l]=MIN(f[i-1][j][t][l],f[i-1][j][t][l+b[i-1]]);
                }
                
    
    scanf("%d",&N);
    LOOPB(i,0,N){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        x1--;x2--;y1--;y2--;
        s=LOG2(x2-x1+1);//注意+1,因为是元素的个数
        t=LOG2(y2-y1+1);
        printf("%d\n",MIN(MIN(f[t][s][x1][y1],f[t][s][x1][y2-b[t]+1]),MIN(f[t][s][x2-b[s]+1][y1],f[t][s][x2-b[s]+1][y2-b[t]+1])));
    }
}
}
