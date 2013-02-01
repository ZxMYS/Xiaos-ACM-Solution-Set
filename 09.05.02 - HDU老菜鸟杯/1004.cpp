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
const int oo=1<<29;
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,a,m,n,s,t,l,tt,cas;
double k;
char tmp,str[500];
int pins[15];

inline int ishigh(double v){
    if(ABS(v-5)<=0.5)return 1;
    else return 0;
}

inline bool ef(int a,int b){
    if(b<7){
        if(pins[a]!=-1&&pins[b]!=-1&&pins[b+1]==-1)return true;
    }else{
        if(pins[a]!=-1&&pins[b]!=-1&&pins[b-2]==-1)return true;
    }return false;
}

inline void out(int a,int b){
    if(b<7){
        if(pins[a]==1&&pins[b]==1)
            {
                cout<<b+1<<" L"<<endl;
                return;
            }
        else if(pins[a]*pins[b]==0){
                cout<<b+1<<" H"<<endl;
                return;
            }}
    else{
        if(pins[a]==1&&pins[b]==1)
                {
                    cout<<b-2<<" L"<<endl;
                    return;
                }
            else if(pins[a]*pins[b]==0){
                    cout<<b-2<<" H"<<endl;
                    return;
                }}
}

inline void pa(int a,int b){
    if(ef(a,b)){
        out(a,b);
    }
}

inline void solve(){
    pa(1,2);
    pa(4,5);
    pa(9,10);
    pa(12,13);
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
while(scanf("%d",&n)!=EOF){
    memset(pins,-1,sizeof(pins));
    tmp=0;
    LOOPB(i,0,n){
        scanf("%d%lf",&a,&k);
        if(a==14&&k!=5)tmp=1;
        if(a==7&&k>0.8)tmp=1;
        if(a==3||a==6||a==8||a==11)tmp=1;
        s=ishigh(k);
        pins[a]=s;
    }
    if(tmp==1)goto NO;
    if(pins[14]!=1||pins[7]!=0)
        goto NO;
    cout<<"Yes"<<endl;
    solve();
    continue;
    NO:
        cout<<"No"<<endl;
}

}
