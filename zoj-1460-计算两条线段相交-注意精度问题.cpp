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
#define EPS 0.00000001
int i,j,n,l,t,tt,ans;
double x,y,xx,yy;
typedef struct {bool f;double k,b,x;} linetype;
typedef struct {double x,y;} pointtype;
linetype line[8];
pointtype jiaodian[9];
int jiaodiansize;

inline bool valid(double x){
    return x>EPS&&x+EPS<1000;
}

inline void jiao(int a,int b){
    int i;
    if(!line[a].f&&!line[b].f){
        x=(line[a].b-line[b].b)/(line[b].k-line[a].k);
        y=line[b].k*x+line[b].b;

    }else if(line[a].f&&line[b].f)
        return;
    else{
        if(!line[a].f){
            swap(a,b);
        }
        x=line[a].x;
        y=line[b].k*x+line[b].b;
    }
    if(valid(x)&&valid(y)){
            LOOPB(i,0,jiaodiansize){
                if(
                ABS((jiaodian[i]).x-x)<=EPS&&
                ABS((jiaodian[i]).y-y)<=EPS)
                    return;
            }
            //cout<<"***"<<x<<' '<<y<<endl;
            jiaodian[jiaodiansize].x=x;
            jiaodian[jiaodiansize].y=y;
            jiaodiansize++;
        }
}

inline int countpoint(int n){
    jiaodiansize=0;
    int i;
    LOOPB(i,0,n){
        jiao(i,n);
    }
    return jiaodiansize;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d",&n);
while(n){
    ans=1;
    jiaodiansize=0;
    l=0;
    LOOPB(t,0,n){
        scanf("%lf%lf%lf%lf",&x,&y,&xx,&yy);
        /*if(x>xx){
            swap(x,xx);
            swap(y,yy);
        }*/
        line[l].f=(x==xx);
        
        if(!line[l].f){
            line[l].k=(yy-y)/(xx-x);
            line[l].b=yy-line[l].k*xx;
        }else{
            line[l].x=x;
            if(line[l].x==0)
                goto L1;
        }
            
        LOOPB(j,0,l){
            if(line[j].f||line[l].f){
                if(line[j].f&&line[l].f){
                    if(line[l].x==line[j].x)
                        goto L1;
                }else
                    continue;
            }else
            if(ABS(line[j].k-line[l].k)<EPS&&ABS(line[l].b-line[j].b)<EPS)
                goto L1;
        }
        
        if(!line[l].f){
            if(ABS(line[l].k)<=EPS&&(ABS(line[l].b-1000)<=EPS||ABS(line[l].b)<=EPS))
                goto L1;
        }else
            if(ABS(line[l].x-1000)<=EPS||ABS(line[l].x)<=EPS)
                goto L1;
        
        tt=ans;
        ans+=countpoint(l)+1;
        //cout<<l<<':'<<x<<' '<<y<<' '<<xx<<' '<<yy<<' '<<ans-tt<<endl;
        l++;
        L1:;
    }
    printf("%d\n",ans);
    scanf("%d",&n);
}
}
