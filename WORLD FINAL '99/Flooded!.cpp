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
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a,m,n,l,tt=0;
double LOW;
int us[1000];
int cmp(const void* a, const void* b){
    return *((int*)a)-*((int*)b);
}
int main()
{
scanf("%d%d",&n,&m);
while(n){
    printf("Region %d\nWater level is ",++tt);
    l=0;
    LOOPB(i,0,n){
        LOOPB(j,0,m){
            scanf("%d",&us[l]);
            l++;
        }
    }
    qsort(us,l,sizeof(us[0]),cmp);
    LOW=us[0];
    scanf("%d",&k);
    if(k>0){
        LOOPB(i,0,l){
            while(i<l&&us[i]==us[i-1])i++;
            if(i==l||k<i*100*(us[i]-us[i-1]))break;
            k-=i*100*(us[i]-us[i-1]);
        }
        LOW=us[i-1];
    }
    if(k>0){
        while(i<l&&us[i]==us[i-1])i++;
        LOW+=(double)k*1.0/i/100;
    }
    printf("%.2lf meters.\n", LOW);
	printf("%.2lf percent of the region is under water.\n\n", i*100*1.0/l);
    scanf("%d%d",&n,&m);
}
}
