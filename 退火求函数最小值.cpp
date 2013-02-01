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
#include<set>
#include<map>
#include<queue>
#include<list>
#include<sstream>
#include<iomanip>
using namespace std;
#define LOOP(x,y,z) for((x)=(y);(x)<=(z);(x)++)
#define LOOPB(x,y,z) for((x)=(y);(x)<(z);(x)++)
#define RLOOP(x,y,z) for((x)=(y);(x)>=(z);(x)--)
#define RLOOPB(x,y,z) for((x)=(y);(x)>(z);(x)--)
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define ABS(x) ((x)<0?-(x):(x))
#define PI 3.1415926535898
#define EPS 0.000001
const int oo=1<<29;
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a,m,n,s,t,l,tt,cas;
int countt,times;
double temperature,best,cur,bestx,curx,prebest,ans,ansx;
inline double f(double x){
    return x-sqrt(x)-log(x)+sin(x)+sin(x)-log10(x);
}

inline bool ac(double cur){
    if(best>cur)return true;
    double p=(rand())/double(RAND_MAX);
    double q=exp((best-cur)/temperature);       //求最小值
    if(p<q)
        return true;
    return false;
}

int main()
{
tt=1000;
cout<<setprecision(13);
while(tt--){    //多次运行观察
    best=100;
    s=10;
    while(s--){
        srand((unsigned)time(NULL));
        times=20;   //times有重要影响
        temperature=300;
        countt=0;
        while(1){
            temperature*=0.95;
            LOOPB(i,0,times){
                prebest=best;
                curx=bestx;
                curx+=0.1*(rand())/double(RAND_MAX);
                cur=f(curx);
                if(ac(cur)){
                    bestx=curx;
                    best=cur;
                }

                curx=bestx;
                curx-=0.1*(rand())/double(RAND_MAX);   //0.1处对结果影响巨大
                while(curx<0)
                    curx+=0.08*(rand())/double(RAND_MAX);

                cur=f(curx);
                if(ac(cur)){
                    bestx=curx;
                    best=cur;
                }
                if(fabs(prebest-best)<EPS){
                    countt++;
                    if(countt>5)
                        goto L1;
                }else
                    countt=0;
            }
        }
    L1:
    if(best<ans){
        ans=best;
        ansx=bestx;
    }
    }
    cout<<ans<<' '<<ansx<<endl;
}
system("pause");
}
