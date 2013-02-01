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
char str2[500],str[500];
int ans[500],num1[500],num2[500];
int tmp;

inline void pr(int* num,int l){
    int i;
    while(num[l-1]==0&&l>1)
        l--;
    RLOOP(i,l-1,0)
        printf("%d",num[i]);
}

inline void st2nu(char* str,int* num){
    int i,j=strlen(str)-1,p=0;
    RLOOP(i,j,0){
        if(str[i]=='1')
            num[p++]=1;
        else
            num[p++]=0;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d",&cas);
tt=0;
while(cas--){
    memset(num1,0,sizeof(num1));
    memset(num2,0,sizeof(num2));
    printf("%d ",++tt);
    scanf("%s %s",&str,&str2);
    n=max(strlen(str),strlen(str2));
    st2nu(str,num1);
    st2nu(str2,num2);
    tmp=0;
    LOOPB(i,0,n){
        ans[i]=num1[i]+num2[i]+tmp;
        tmp=0;
        if(ans[i]>=2){
            tmp=1;
            ans[i]-=2;
        }
    }
    if(tmp){
        ans[n]=1;
        n++;
    }
    pr(ans,n);
    printf("\n");
}
}
