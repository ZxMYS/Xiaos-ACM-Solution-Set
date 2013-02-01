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
int i,j,a,m,n,s,t,tt;
unsigned long long int k,l;
char str[500];
bool flag[7];
int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d",&tt);
while(tt--){
    scanf("%d%d",&a,&m);
    memset(flag,0,sizeof(flag));
    l=0;
    s=100000;
    k=((unsigned long long int)(a+m))*(m-a+1)/2;
    scanf("%s",&str);
    LOOPB(i,0,6){
        if(str[i]=='|')l+=5*s;
        s/=10;
    }
    scanf("%s",&str);scanf("%s",&str);
    LOOPB(j,0,5){
    scanf("%s",&str);
    s=100000;
        LOOPB(i,0,6){
            if(str[i]=='o'&&!flag[i])l+=s;
            else flag[i]=true;
            s/=10;
        }
    }
    scanf("\n");
    //printf("%llu %llu\n",k,l);
    if(k==l)printf("No mistake\n");else printf("Mistake\n");
}
}
