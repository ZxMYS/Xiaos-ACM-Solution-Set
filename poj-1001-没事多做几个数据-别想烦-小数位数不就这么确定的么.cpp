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
int i,j,k,a,n,s,mm,t,l;
int tt[1000],tt2[1000],m;
bool f;
char str[1000];
inline void mul(int a[],int b[]){
    static int c[1000];
    memset(c,0,sizeof(c));
    LOOP(i,1,a[0])
        LOOP(j,1,b[0]){
            c[i+j-1]+=a[i]*b[j];
    }
    c[0]=a[0]+b[0];
    LOOP(i,1,c[0]){
            c[i+1]+=c[i]/10;
            c[i]%=10;
    }
    while(c[c[0]]==0&&c[0]>1)c[0]--;
    LOOP(i,0,c[0])
        b[i]=c[i];
}
int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
while(scanf("%s%d",&str,&n)!=EOF){
    f=false;
    tt[0]=0;
    mm=i=0;
    while(str[i]&&str[i]!='.'){i++;}
    m=6-i-1;
    i++;
    while(str[i]&&str[i]=='0'){mm++;i++;}
    if(m==-1)tt[0]=6;
    else tt[0]=5;
    i=0;j=1;
    while(str[i]){
        if(str[i]!='.')tt[tt[0]-j+++1]=str[i]-'0';
        i++;
    }
    while(tt[tt[0]]==0&&tt[0]>1)tt[0]--;
    if(tt[0]==1&&tt[1]==0)m=-1;
    tt2[0]=1;
    tt2[1]=1;
    LOOPB(k,0,n){
        mul(tt,tt2);
    }
    l=m*n;i=0;
    if(l>tt2[0]){
        str[i++]='.';
        f=true;
        t=l-tt2[0];
        LOOPB(k,0,t)
            str[i++]='0';
        l=5001;
        }
    RLOOP(k,tt2[0],1){
        if(k==l){str[i++]='.';f=true;}
        str[i++]=(int)tt2[k]+'0';
    }
    str[i]=0;
    i--;
    if(f)
    while(str[i]=='0'&&i>0)
        str[i--]=0;
    if(str[i]=='.')
        str[i]=0;
    printf("%s",str);
    putchar('\n');
}
}
