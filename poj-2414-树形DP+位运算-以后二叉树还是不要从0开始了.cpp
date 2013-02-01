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
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
char seqs[1030][1100];
int stat[5000][1100];
int cost[5000];

inline void outchar(int stat){
    int i;
    RLOOP(i,25,0)
        if(stat&(1<<i)){
            printf("%c",'A'+i);
            return;
        }
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
while(scanf("%d%d",&n,&l)&&n&&l){
    memset(cost,0,sizeof(cost));
    LOOPB(i,0,n)
        scanf("%s",&seqs[i]);
    LOOPB(i,0,n){
        LOOPB(j,0,l)
            stat[n+i-1][j]=1<<(seqs[i][j]-'A');
    }
    for(;n>1;n>>=1){
        LOOPB(i,(n>>1)-1,n){
            cost[i]=cost[(i<<1)+2]+cost[(i<<1)+1];
            LOOPB(j,0,l){
                if(!(stat[i][j]=stat[(i<<1)+2][j]&stat[(i<<1)+1][j])){
                    cost[i]++;
                    stat[i][j]=stat[(i<<1)+2][j]|stat[(i<<1)+1][j];
                }
            }
        }
    }
    LOOPB(i,0,l){
        outchar(stat[0][i]);
    }
    cout<<' '<<cost[0]<<endl;
}
}
