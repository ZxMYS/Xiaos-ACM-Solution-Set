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
int i,j,k,a,m,n,s,t,l,tt,cas,ans,T,K;
const int oo=1<<29;
char ch;
vector<int> st[110];
bool ga[110][110];
int count[110];
bool val;
vector<int> in[110];
inline bool cross(const vector<int>& a,const vector<int>& b){
    int i;
    LOOPB(i,0,a.size()){
        if(a[i]==b[i])return false;
        if(i==0)continue;
        if((a[i]<b[i])^(a[i-1]<b[i-1]))
            return false;
    }
    return true;
}

inline void delp(int p){
}

inline void del(int p){
    int i;
    LOOPB(i,0,in[i].size()){

    }
}

inline int find(){
    int min=oo;
    int i,h=-1;
    LOOPB(i,0,T){
        if(val[i]&&min>in.size()){
            min=in.size();
            h=i;
        }
    }
    return h;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d",&cas);
while(cas--){
    printf("Case #%d: ",++tt);
    scanf("%d %d\n",&T,&K);
    tmp.clear();
    LOOPB(i,0,T){
        count[i]=0;
        in[i].clear();
        st[i].clear();
        LOOPB(j,0,K){
            scanf("%d",&t);
            st[i].push_back(t);
        }
    }
    LOOPB(i,0,T)
        LOOPB(j,0,T){
            ga[i][j]=cross(i,j);
            if(ga[i][j]){
                count[i]++;
                count[j]++;
                in[i].push_back(j);
                in[j].push_back(i);
            }
        }
    ans=0;
    
    while((t=find())!=-1){
        del(t);
    }
}
}
