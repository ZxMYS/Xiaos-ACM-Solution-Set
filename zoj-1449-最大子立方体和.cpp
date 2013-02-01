/*
求最长子段和是一个o(n)的dp。求平面的最大子平面和时，先计算行数为一行的最大字段和，然后把第二行加到第一行
上计算第一行的最大字段和，其实质就是计算了第一行和第二行这两行的最大子平面和。依次可以计算所有为两行的最大子平面和。
然后是行数为3行的最大子段和。。这样就完成了最大子平面和的计算。
至于最大子立体和依然照葫芦画瓢，先计算单个平面的最大和，然后把第二个平面加到第一个平面上，即得厚度为2得立体得最大和。
依次类推。
算法复杂度为o(n^7)。
*/

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
int i,j,k,a,m,n,s,t,l,tt,cas,ans,max;
int ga[21][21][21],f[21][21];

int max1(int *a,int n){
    int sum=-oo,b=-oo,i;
    LOOPB(i,0,n){
        if(b>0) b+=a[i];
        else b=a[i];
        sum=MAX(b,sum);
    }
    return sum;
}


int max2(int a[][21],int n){
    int max,sum=-oo,b[21],i,j,k;
    
    LOOPB(i,0,n){
        LOOPB(k,0,n)
            b[k]=0;
        LOOPB(j,i,n){
            LOOPB(k,0,n)
                b[k]+=a[j][k];
            max=max1(b,n);
            sum=MAX(max,sum);
        }
        if(j==1)
            sum=b[0];
    }
    return sum;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d",&n);
while(n){
    LOOPB(i,0,n)
        LOOPB(j,0,n)
            LOOPB(k,0,n)
                scanf("%d",&ga[i][j][k]);
    if(n==1){
        printf("%d\n",ga[0][0][0]);
        goto L1;
    }
    ans=0;
    LOOPB(i,0,n){
        LOOPB(j,0,n)
            LOOPB(k,0,n)
                f[j][k]=0;
        LOOPB(s,i,n){
            LOOPB(j,0,n)
                LOOPB(k,0,n)
                    f[j][k]+=ga[s][j][k];
            tt=max2(f,n);
            ans=MAX(tt,ans);
        }
    }
    printf("%d\n",ans);
    L1:
    scanf("%d",&n);
}
}
