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
int i,j,k,a,m,n,t,tt;
int f[10010],l[10010],r[10010],son[10010],fp[10010];
char str[10010];
void build(int po){
    if(m<0)return;
    if(str[m]=='a'){
        l[po]=1;r[po]=0;son[po]=0;m--;
        return;
    }
    son[po]=(int)(str[m]-'0');
    l[po]=t+1;
    r[po]=t+son[po];
    t=r[po];
    m--;
    int i;
    RLOOP(i,r[po],l[po])
        build(i);
}

void s(int po){
    if(son[po]==0){
        f[po]=1;return;
    }
    int i;
    LOOPB(i,0,son[po])
        s(l[po]+i);
    int j,k=0,ansp,ans=1<<29;
    LOOPB(i,0,son[po]){
        k=0;
        LOOPB(j,0,son[po]){
            k=MAX(k,j+f[l[po]+(i+j)%son[po]]);
        }
        if(k<ans){
            ans=k;
            ansp=i;
        }
    }
    f[po]=ans;
    fp[po]=ansp;
}

void p(int po){
    if(son[po]){
        int i,j;
        i=fp[po];
        LOOPB(j,0,son[po])
            p(l[po]+(i+j)%son[po]);
        printf("%d",son[po]);
    }else
    printf("a");
}
int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%s",&str);
m=strlen(str)-1;
t=0;
build(0);
s(0);
printf("%d\n",f[0]);
p(0);
printf("\n");
}
