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
#define PI 3.1415926535898
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,m,n,s,a,t,l,tt;
char str[30000],str1[30000];
int istr[30000],istr1[30000];
int rstr[30000],key[30000];

inline int ONEHEX(char a){
    return (a>='0'&&a<='9')?int(a-'0'):int(a-'A'+10);
}

int HextoDec(char a,char b){
    return ONEHEX(a)*16+ONEHEX(b);
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%s%s",&str,&str1);
n=strlen(str);
a=strlen(str1);
for(i=0;i<n;i+=2){
    istr[i>>1]=HextoDec(str[i],str[i+1]);
}
for(i=0;i<a;i+=2){
    istr1[i>>1]=HextoDec(str1[i],str1[i+1]);
}
n>>=1;
key[0]=istr1[0]^32;
rstr[0]=istr[0]^key[0];
LOOPB(i,1,n+1){
key[i]=rstr[i-1]^istr1[i];
if(i!=n+1)rstr[i]=istr[i]^key[i];
}
LOOPB(i,0,n+1){
    printf("%02X",key[i]);
}
printf("\n");
}
