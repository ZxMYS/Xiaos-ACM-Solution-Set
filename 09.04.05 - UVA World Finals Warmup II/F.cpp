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
int i,j,k,a,m,n,s,t,l,tt;
typedef struct {int x1,y1,x2,y2;} tra;
unsigned long long int ans;
tra ttmp;
int ga[210][210];
bool check(){
int i,j;
if(ga[ttmp.x1][ttmp.y1]==1||ga[ttmp.x1][ttmp.y2]==1||ga[ttmp.x2][ttmp.y2]==1||ga[ttmp.x2][ttmp.y1]==1)
    return false;
LOOPB(i,ttmp.x1+1,ttmp.x2)
    LOOPB(j,ttmp.y1+1,ttmp.y2){
        if(ga[i][j]>=1)return false;
    }
LOOPB(i,ttmp.x1+1,ttmp.x2){
    if((ga[i][ttmp.y1]&8)||
    (ga[i][ttmp.y2]&2)||(ga[i][ttmp.y1]==1)||(ga[i][ttmp.y2]==1))return false;
}
LOOPB(i,ttmp.y1+1,ttmp.y2){
    if((ga[ttmp.x1][i]&4)||(ga[ttmp.x2][i]&16)||(ga[ttmp.x2][i]==1)||(ga[ttmp.x1][i]==1))return false;
}
if((ga[ttmp.x1][ttmp.y1]&128)||(ga[ttmp.x1][ttmp.y2]&64)||(ga[ttmp.x2][ttmp.y2]&512)||(ga[ttmp.x2][ttmp.y1]&256))
    return false;
return true;
}
                            //  2       32+:cross   64|128
                            //4 1 16                 -+-
                            //  8                  512|256
int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d",&tt);
m=0;
while(tt--){
    printf("Case %d: ",++m);
    ans=0;
    LOOPB(i,0,210)
        memset(ga[i],0,sizeof(ga[i]));
    scanf("%d",&n);
    LOOPB(i,0,n){
        scanf("%d%d%d%d",&ttmp.x1,&ttmp.y1,&ttmp.x2,&ttmp.y2);
        ttmp.x1+=100;
        ttmp.y1+=100;
        ttmp.x2+=100;
        ttmp.y2+=100;
        if(check()){
            ttmp.x1-100;
            /*cout<<(ttmp.x1-100)<<' ';
            cout<<(ttmp.y1-100)<<' ';
            cout<<(ttmp.x2-100)<<' ';
            cout<<(ttmp.y2-100)<<endl;*/
            ans+=(ttmp.y2-ttmp.y1)*(ttmp.x2-ttmp.x1);
            LOOPB(k,ttmp.x1+1,ttmp.x2)
                LOOPB(j,ttmp.y1+1,ttmp.y2){
                    ga[k][j]=1;
                }
            LOOP(k,ttmp.x1,ttmp.x2){
                ga[k][ttmp.y1]|=8;
                ga[k][ttmp.y2]|=2;
            }
            LOOP(k,ttmp.y1,ttmp.y2){
                ga[ttmp.x1][k]|=4;
                ga[ttmp.x2][k]|=16;
            }
            ga[ttmp.x1][ttmp.y1]|=32+128;
            ga[ttmp.x1][ttmp.y2]|=32+64;
            ga[ttmp.x2][ttmp.y1]|=32+256;
            ga[ttmp.x2][ttmp.y2]|=32+512;
        }
    }
    cout<<ans<<endl;
}
}
