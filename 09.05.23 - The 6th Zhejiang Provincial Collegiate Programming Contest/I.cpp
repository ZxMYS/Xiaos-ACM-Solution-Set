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
int i,j,k,a,m,n,s,t,l,tt,cas;
int aa[200],bb[200];
bool flag1,flag2;
int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d",&cas);
while(cas--){
    flag1=flag2=true;
    scanf("%d",&n);
    LOOPB(i,0,n){
        scanf("%d",&aa[i]);
    }
    LOOPB(i,0,n){
        scanf("%d",&bb[i]);
    }
    LOOPB(i,0,n){
        if(aa[i]!=bb[i]){
            flag1=false;
            break;
        }
    }
    LOOPB(i,0,n){
        if(aa[i]!=bb[n-i-1]){
            flag2=false;
            break;
        }
    }
    if(flag1&&flag2){
        cout<<"both"<<endl;
    }
    else if(flag1){
        cout<<"queue"<<endl;
    }
    else if(flag2)
        cout<<"stack"<<endl;
    else
        cout<<"neither"<<endl;
}
}
