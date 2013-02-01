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
int i,j,k,a,d,m,n,s,t,l,tt;
unsigned long long int matrix[500],matrix3[500],matrix4[500];

inline void mul(unsigned long long int a[],unsigned long long int b[]){
    int i,j;
    LOOPB(i,0,n){
        matrix4[i]=0;
        LOOPB(j,0,n)
            matrix4[i]+=a[j]*b[i>=j?i-j:n+i-j];
    }
    LOOPB(i,0,n)
        b[i]=matrix4[i]%m;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d%d%d%d",&n,&m,&d,&k);
LOOPB(i,0,n)scanf("%llu",&matrix[i]);
LOOP(i,0,d)matrix3[i]=1;
LOOP(i,d+1,n-d)matrix3[i]=0;
LOOPB(i,n-d,n)matrix3[i]=1;

while(k){
    if(k&1)
        mul(matrix3,matrix);
    mul(matrix3,matrix3);
    k>>=1;
}

printf("%llu",matrix[0]);
LOOPB(i,1,n)printf(" %llu",matrix[i]);
printf("\n");
}
