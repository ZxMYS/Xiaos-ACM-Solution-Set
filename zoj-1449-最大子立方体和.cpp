/*
����Ӷκ���һ��o(n)��dp����ƽ��������ƽ���ʱ���ȼ�������Ϊһ�е�����ֶκͣ�Ȼ��ѵڶ��мӵ���һ��
�ϼ����һ�е�����ֶκͣ���ʵ�ʾ��Ǽ����˵�һ�к͵ڶ��������е������ƽ��͡����ο��Լ�������Ϊ���е������ƽ��͡�
Ȼ��������Ϊ3�е�����Ӷκ͡�������������������ƽ��͵ļ��㡣
����������������Ȼ�պ�«��ư���ȼ��㵥��ƽ������ͣ�Ȼ��ѵڶ���ƽ��ӵ���һ��ƽ���ϣ����ú��Ϊ2����������͡�
�������ơ�
�㷨���Ӷ�Ϊo(n^7)��
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
