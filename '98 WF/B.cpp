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
#define PI 3.1415926535898
const int VCRUISE=400,AOPT=30,GPHOPT=2000,GPHEXTRA=10,CLIMBCOST=50;
int n,k,i,j,l,n2;
double t,data[11][60];
int data3[11],data2[11][60];
double gets(double r){
    return r>0?r:0;
}
double getgallon(int n,int m,int l){
    return CLIMBCOST*gets(m-l)+(fabs(m-AOPT)*GPHEXTRA+GPHOPT)*(data[n][1]/(((m-20)*data[n][3]+(40-m)*data[n][2])/20+VCRUISE));
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out","w",stdout);
    #endif
    scanf("%d",&n);
    while(n2<n){
        scanf("%d",&k);
        LOOP(i,1,k)
            scanf("%lf%lf%lf",&data[i][1],&data[i][2],&data[i][3]);
        LOOP(j,20,40)
            data[1][j]=getgallon(1,j,0);
        LOOP(i,2,k)
            LOOP(j,20,40){
                data[i][j]=1<<29;
                LOOP(l,20,40){
                    t=getgallon(i,j,l)+data[i-1][l];
                    if(t<data[i][j]){
                        data[i][j]=t;
                        data2[i][j]=l;
                    }
                }
            }
        t=1<<29;
        LOOP(j,20,40)
            if(data[k][j]<t){
                t=data[k][j];
                data3[k]=j;
            }
        RLOOP(i,k,2)
            data3[i-1]=data2[i][data3[i]];
        printf("Flight %d:",++n2);
        LOOP(i,1,k)printf("%3d",data3[i]);
        printf(" %.0lf\n",data[k][data3[k]]);
    }
}
