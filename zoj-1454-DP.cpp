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
int i,j,k,a,m,n,s,t,l,tt,cas,hirecost,firecost,wagecost,ans;
int f[13][500],need[13];

inline int cost(int a,int b){
    if(a==b)return a*wagecost;
    else if(a>b)return firecost*(a-b)+b*wagecost;
    else return hirecost*(b-a)+b*wagecost;
}


int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d",&n);
while(n){
    scanf("%d%d%d",&hirecost,&wagecost,&firecost);
    m=-oo;
    LOOP(i,1,n){
        scanf("%d",&need[i]);
        m=MAX(m,need[i]);
    }
    LOOP(i,2,n){
        LOOP(j,need[i],m){
            f[i][j]=oo;
        }
    }
        
    LOOP(i,need[1],m){
        f[1][i]=cost(0,i);
    }
    LOOP(i,2,n){
        LOOP(j,need[i],m){
            LOOP(k,need[i-1],m)
                f[i][j]=MIN(f[i][j],f[i-1][k]+cost(k,j));
        }
    }
    ans=oo;
    LOOP(i,need[n],m){
        ans=min(f[n][i],ans);
    }
    printf("%d\n",ans);
    scanf("%d",&n);
}
}
