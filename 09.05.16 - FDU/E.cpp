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
#define digit=10000000000;
const int oo=1<<29;
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a,m,n,s,l,cas;
unsigned long long int fn[51][51],cn[51][51],t;
double wtf[51][51][10],tt;



inline void c(int n,int m){
    if(cn[n][m]!=0)
        return;
    if(n==1){
        if(m>=1){
            cn[n][m][0]=1;
            cn[n][m][1]=3;
        }else{
            cn[n][m][0]=1;
            cn[n][m][1]=2;
        }
    }
    if(m>=1)
        cn[n][m]=2*c(n-1,m)+c(n-1,m-1);
    else
    cn[n][m]=2*c(n-1,m);
}


inline void f(int n,int m){
    if(fn[n][m]!=0)
        return;
    if(m==0)
        return 0;
    if(n==1)
        return m>1?3:2;
    fn[n][m]=2*f(n-1,m)+f(n-1,m-1);
    return fn[n][m]%1e10;
}
int main()
{
freopen("e.in","r",stdin);
freopen("out","w",stdout);
LOOP(i,0,50){
        memset(fn[i],0,sizeof(fn[i]));
        memset(cn[i],0,sizeof(cn[i]));
        LOOP(j,0,50)
            wtf[i][j]=0;
}


/*    cout<<c(3,1)<<endl;

LOOPB(i,0,10)
    cout<<c(i,1)<<endl;
*/

//while(scanf("%d%d",&n,&m)!=EOF){
    LOOPB(n,14,50){
    cout<<n<<' '<<m<<' '<<endl;
    tt=c(n,14);
    t=f(n,14);
    //cout<<tt<<' '<<t<<endl;
    printf("%.5lf\n",t*100.0/tt);
    }
//}
}
