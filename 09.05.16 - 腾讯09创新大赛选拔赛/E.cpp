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
int i,j,k,a,m,n,s,t,l,tt,ts,cas,total,lastday;
typedef struct {int ld,lds,ts;} qquser;
typedef unsigned long long int ULL;
ULL qq;
qquser tmp;
map<ULL,qquser> qqmap;
list<pair<int,int> > sclist;
map<ULL,qquser>::iterator qqiter;
list<pair<int,int> >::iterator sciter;
inline void query(ULL qq){
    qqiter=qqmap.find(qq);
    if(qqiter==qqmap.end()){
        printf("%d\n",total+1);
        return;
    }
    l=0;
    sciter=sclist.begin();
    while(sciter->first>qqiter->second.ts){
        l+=sciter->second;
        sciter++;
    }
    printf("%d\n",l+1);
}

inline void update(ULL qq){
    scanf("%d",&n);
    if(n<=9)return;
    if(n<=199)n=10;
    else if(n<=999)n=20;
    else n=30;
    qqiter=qqmap.find(qq);
    if(qqiter==qqmap.end()){
        tmp.ld=-1;
        tmp.lds=0;
        tmp.ts=0;
        qqmap.insert(pair<ULL,qquser>(qq,tmp));
        total++;
        qqiter=qqmap.find(qq);
        s=0;
    }else
        s=qqiter->second.ts;
    if(qqiter->second.ld!=tt){
        qqiter->second.ld=tt;
        qqiter->second.ts+=n;
        qqiter->second.lds=n;
    }
    else{
        if(qqiter->second.lds+n>100){
            qqiter->second.ts+=100-qqiter->second.lds;
            qqiter->second.lds=100;
        }
        else{
            qqiter->second.ts+=n;
            qqiter->second.lds+=n;
        }
    }
    if(s){
        sciter=sclist.begin();
        while(sciter->first>s){
            sciter++;
        }
        sciter->second--;
        if(!sciter->second)
            sclist.erase(sciter);
    }
    sciter=sclist.begin();
    while(sciter!=sclist.end()&&sciter->first>qqiter->second.ts){
            sciter++;
        }
    if(sciter->first!=qqiter->second.ts)
        sclist.insert(sciter,pair<int,int>(qqiter->second.ts,1));
    else
        sciter->second++;
}

inline void out(){
    sciter=sclist.begin();
    while(sciter!=sclist.end()){
        cout<<sciter->first<<':'<<sciter->second<<" | ";
        sciter++;
    }
    cout<<endl;
    qqiter=qqmap.begin();
    while(qqiter!=qqmap.end()){
        cout<<qqiter->first<<':'<<qqiter->second.ts<<" | "<<endl;
        qqiter++;
    }
    cout<<endl;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
total=0;
ts=tt=-1;
while(scanf("%I64u%d",&qq,&m)!=EOF){
    //out();
    if(m==-1){
        query(qq);
        continue;
    }
    else{
        if(tt!=m){
            ts=tt;
            tt=m;
        }
        update(qq);
    }
}
}
