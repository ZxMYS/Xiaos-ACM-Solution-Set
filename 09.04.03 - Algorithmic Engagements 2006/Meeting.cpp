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
int i,j,k,a,b,c,m,s,t,l,tt,wtf[20][2];
char tmp,str[500];
int ans[12]={4,7,1,8,9,7,6,3,9,2,1,3};
unsigned long long int n;
int main()
{
//#ifndef ONLINE_JUDGE
//freopen("in.txt","r",stdin);
//freopen("out","w",stdout);
//#endif

scanf("%llu",&n);
printf("%d\n",ans[(n-3)%12]);
/*b=0;
c=1;
wtf[0][0]=1;
wtf[0][1]=0;
LOOPB(i,2,n){
    wtf[c][0]=(wtf[b][1]+wtf[b][0])%10;
    wtf[c][1]=wtf[b][0]%10;
    //printf("%d %d %d\n",i,wtf[c][0],wtf[c][1]);
    b=c++;
    c&=1;
}
//printf("%d %d %d %d\n",wtf[b][0],wtf[b][1],wtf[c][1],wtf[c][0]);
printf("%d\n",(wtf[b][0]+wtf[b][1]+2*(wtf[c][1]+wtf[c][0]))%10);
}*/
}

