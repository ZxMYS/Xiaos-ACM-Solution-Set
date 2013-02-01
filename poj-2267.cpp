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
int i,j,k,a,m,n,s,t,l,tt,dis[101],min,mini;
typedef struct {int f,t,time,st;} route;
char cities[101][500],str[500],str2[500];
vector<route> r;
route tmp;

inline int fc(char cit[]){
    int i;
    LOOPB(i,0,m)
        if(strcmp(cit,cities[i])==0)return i;
    return -1;
}

inline int fora(char cit[]){
    int i=fc(cit);
    if(i==-1){
        strcpy(cities[m],cit);
        return m++;
    }else
        return i;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d",&tt);
LOOP(t,1,tt){
    printf("Test Case %d.\n",t);
    r.clear();
    m=0;
    scanf("%d",&n);
    LOOPB(i,0,n){
        scanf("%s%s%d%d",&str,&str2,&tmp.st,&tmp.time);
        if(tmp.time>12)continue;
        if(tmp.st>6&&tmp.st<18)continue;
        s=tmp.st+tmp.time;
        s%=24;
        if(s>6&&s<18)continue;
        tmp.st-=18;
        if(tmp.st<0)tmp.st+=24;
        a=fora(str);
        k=fora(str2);
        tmp.f=a;
        tmp.t=k;
        r.push_back(tmp);
        s=r.size()-1;
    }
    scanf("%s%s",&str,&str2);
    a=fora(str);
    s=fora(str2);
    if(a==-1||s==-1){
        goto L1;
    }
    LOOPB(i,0,m)
        dis[i]=(int)1e7;
    dis[a]=0;
    k=r.size();
    LOOPB(i,0,m)
        LOOPB(j,0,k){
            if(r[j].st<dis[r[j].f]%24)
                dis[r[j].t]=MIN(dis[r[j].t],(dis[r[j].f]/24+1)*24+r[j].st+r[j].time);
            else if(r[j].st>=dis[r[j].f]%24)
                dis[r[j].t]=MIN(dis[r[j].t],dis[r[j].f]+r[j].st+r[j].time);
        }
    if(dis[s]>=1e7)
L1:
        printf("There is no route Vladimir can take.\n");
    else
        printf("Vladimir needs %d litre(s) of blood.\n",dis[s]/24);
}
}
