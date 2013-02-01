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
int i,j,k,a,m,n,s,t,l,tt,cas,w,h,N,M,H,W;
int ga[500][500],sum[500][500],ans[500][500];
int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
while(scanf("%d%d%d%d",&N,&M,&H,&W)!=EOF){
    n=N,m=M;
    N+=H<<1;
    M+=W<<1;
    LOOPB(i,0,N)
        LOOPB(j,0,M)
            ga[i][j]=0;
    LOOPB(i,0,n)
        LOOPB(j,0,m)
            scanf("%d",&ga[i+H][j+W]);

    
    LOOPB(i,0,M)
        sum[0][i]=ga[0][i];
    LOOPB(i,0,N)
        LOOPB(j,0,M){
            if(!j)
                sum[i][0]=ga[i][0];
            else{
                sum[i][j]=sum[i][j-1]+(sum[i-1][j]-sum[i-1][j-1]+ga[i][j]);
            }
    }
    
    LOOP(h,0,H)
        LOOP(w,0,W)
            ans[w][h]=-oo;

    w=W;
    LOOPB(h,1,H){
        LOOPB(i,0,N-H){
            LOOPB(j,0,M-W){
                if(i&&j)
                    ans[w][h]=MAX(ans[w][h],sum[i+h-1][j+w-1]-sum[i-1][j+w-1]-sum[i+h-1][j-1]+sum[i-1][j-1]);
                else if(i)
                    ans[w][h]=MAX(ans[w][h],sum[i+h-1][j+w-1]-sum[i-1][j+w-1]);
                else if(j)
                    ans[w][h]=MAX(ans[w][h],sum[i+h-1][j+w-1]-sum[i+h-1][j-1]);
            }
        }
    }
    

    h=H;
    LOOPB(w,1,W){
        LOOPB(i,0,N-H){
            LOOPB(j,0,M-W){
                if(i&&j)
                    ans[w][h]=MAX(ans[w][h],sum[i+h-1][j+w-1]-sum[i-1][j+w-1]-sum[i+h-1][j-1]+sum[i-1][j-1]);
                else if(i)
                    ans[w][h]=MAX(ans[w][h],sum[i+h-1][j+w-1]-sum[i-1][j+w-1]);
                else if(j)
                    ans[w][h]=MAX(ans[w][h],sum[i+h-1][j+w-1]-sum[i+h-1][j-1]);
            }
        }
    }
    tt=-oo;
    h=H;
    LOOPB(w,1,W){
            tt=MAX(tt,ans[w][h]+ans[W-w][h]);
    }
    w=W;
    LOOPB(h,1,H){
            tt=MAX(tt,ans[w][h]+ans[w][H-h]);
    }
    cout<<tt<<endl;
}
}
