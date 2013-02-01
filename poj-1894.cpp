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
int i,j,k,a,b,m,n,s,t,l,tt,wok[500],wok2[500];
char str[500];

inline int moddiv(){
    int i,j=0;
    RLOOP(i,wok[0],1){
        wok[i]+=j*10;
        j=wok[i]%b;
        wok[i]/=b;
    }
    while(wok[wok[0]]==0&&wok[0]!=1)wok[0]--;
    return j;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d",&b);
scanf("%s",&str);
if(!strcmp(str,"0")){printf("\n");return 0;}
wok[0]=strlen(str);
j=wok[0]-1;
l=1;
RLOOP(i,j,0){
 wok[l++]=str[i]-'0';
}
j=moddiv();
l=0;
while(!(wok[wok[0]]==0&&wok[0]==1)){
    wok2[l++]=j;
    j=moddiv();
}
wok2[l++]=j;
//LOOPB(i,0,l)
//printf("%d",wok2[i]);
//printf("\n");

LOOPB(i,0,l){
    if(wok2[i]==0&&i!=l-1){
        wok2[i]+=b;
        j=i+1;
        wok2[j]--;
        while(wok2[j]<0){
            wok2[j]+=b;
            j++;
            wok2[j]--;
        }
    }
}
while(wok2[l-1]==0)l--;
RLOOP(i,l-1,0)
    printf("%d",wok2[i]);
printf("\n");
}
