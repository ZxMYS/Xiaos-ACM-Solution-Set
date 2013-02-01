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
int i,k,a,m,n,s,t,l,tt;
unsigned long long int j;
const unsigned long long  int ans[31]={0,1,2,5,10,21,42,85,170,341,682,1365,2730,5461,10922,21845,43690,87381,174762,349525,699050,1398101,2796202,5592405,11184810,22369621,44739242,89478485,178956970,357913941,715827882};
bool on[100];
unsigned long long  int geton(int);
unsigned long long  int getoff(int n){
    if(n==1){//printf("getoff:%d\n",n);
    on[1]=false;return 1;}
    if(!on[n])return 0;
    int i;unsigned long long  int j=0;
    if(!on[n-1])j+=geton(n-1);
    RLOOP(i,n-2,1){
        //if(on[i])
        j+=getoff(i);
    }
    //printf("getoff:%d\n",n);
    on[n]=false;
    return j+1;
}
unsigned long long  int geton(int n){
    if(n==1){//printf("geton:%d\n",n);
    on[1]=true;return 1;}
    int i;unsigned long long  int j=0;
    if(!on[n-1])j+=geton(n-1);
    RLOOP(i,n-2,1){
        //if(on[i])
        j+=getoff(i);
    }
    //printf("geton:%d\n",n);
    on[n]=true;
    return j+1;
}
int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d",&tt);
while(tt--){
    scanf("%d",&n);
/*LOOP(n,1,30){
    j=0;
    memset(on,0,sizeof(on));
    RLOOP(i,n,1)
        if(!on[i]){//printf("on%d\n",i);
        j+=geton(i);}
    printf("%llu\n",j);
}*/
    printf("%llu\n",ans[n]);
}
}
