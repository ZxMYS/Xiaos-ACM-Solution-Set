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
const int oo=1<<29;
int used;
int ans[17];
int ans2[17];
const int p2[]={2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536};

inline int count1(int k){
    int ret=0;
    while(k){
        ret+=k&1;
        k>>=1;
    }
    return ret;
}

inline bool vali(int k){
    int i;
    int j;
    LOOP(i,0,l){
        LOOP(j,0,l){
            if(i==j)continue;
            if((i+1)%(j+1))continue;
            if(((k>>i)&1)&&((k>>j)&1))return false;
        }
    }
    return true;
}

inline void getans2(){
    int i;
    LOOPB(i,0,l)
        if((used>>i)&1){
            ans2[l]=i;
            return;
        }
    ans2[l]=-1;
}


int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
memset(ans,0,sizeof(ans));
a=1<<17;
used=s=1;
t=l=0;
LOOP(i,0,a){
    if(i==p2[l]){
        getans2();
        ans[l++]=s;
    }
    j=count1(i);
    if(j>=s){
        if(vali(i)){
            if(j>s){
                used=i;
                s=j;
            }else
                used|=i;
        }
    }
}
LOOPB(i,0,17)
    cout<<ans[i]<<' '<<ans2[i]<<endl;
}
