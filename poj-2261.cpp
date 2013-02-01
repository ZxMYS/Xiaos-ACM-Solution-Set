#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<sstream>
#include<assert.h>
#include<list>
#include<iostream>
using namespace std;
#define LOOP(x,y,z) for((x)=(y);(x)<=(z);(x)++)
#define LOOPB(x,y,z) for((x)=(y);(x)<(z);(x)++)
#define RLOOP(x,y,z) for((x)=(y);(x)>=(z);(x)--)
#define RLOOPB(x,y,z) for((x)=(y);(x)>(z);(x)--)
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a,m,n,s,t,tt;
double stages[6][16],l[16][16];
string teams[16];
int main()
{
#ifdef ONLINE_JUDGE
#else
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
LOOP(i,0,15){
    cin>>teams[i];
    stages[0][i]=1;
}
LOOP(i,0,15)
LOOP(j,0,15){
    cin>>l[i][j];
    l[i][j]*=0.01;
    printf("%lf\n",l[i][j]);
}
LOOP(i,1,4)
LOOP(j,0,15)
    stages[i][j]=0;
t=1;
LOOP(k,1,4){
LOOP(i,0,15)
LOOP(j,0,15){
    if((abs(int(i/t) - int(j/t))==1)&&(int(j/(t<<1))==int(i/(t<<1))))
    stages[k][i]+=stages[k-1][i]*l[i][j];
}
t<<=1;
}
LOOP(i,0,15)
    printf("%lf\n",stages[4][i]);
}
