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
#define ABS(x) ((x)<0?-(x):(x))
#define PI 3.1415926535898
int i,j,k,a,m,n,s,t,l,tt,cas;
bool ga[13][13],x,y;
long long int f[13][13][1<<12];
int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d",&cas);
s=0;
while(cas--){
    scanf("%d%d",&n,&m);
    t=1<<m;
    tt=t<<1;
    LOOP(i,1,n)
        LOOP(j,1,m){
            scanf("%d",&ga[i][j]);
        }
    f[0][m][0]=1;
    LOOP(i,1,n){
        LOOPB(j,0,t){
            f[i][0][j<<1]=f[i-1][m][j];
        }
        LOOP(j,1,m){
            a=1<<j;
            l=a>>1;
            LOOPB(k,0,tt){
                x=k&a;
                y=k&l;
                if(ga[i][j]){
                    f[i][j][k]=f[i][j-1][k^a^l];
                    if(x^y){
                        f[i][j][k]+=f[i][j-1][k];
                    }
                }else{
                    if(!x&&!y){
                        f[i][j][k]=f[i][j-1][k];
                    }else{
                        f[i][j][k]=0;
                    }
                }
            }
        }
    }
    printf("Case %d: There are %I64d ways to eat the trees.\n",++s,f[n][m][0]);
}
}
