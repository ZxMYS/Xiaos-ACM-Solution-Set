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
int i,j,k,a,m,n,s,t,l,l1,tt,cas;
char str1[81],str[81];
int f[81][81];
int d[81][81];

void out(int n,int i,int j){ //notice
    if(!n)return;
     switch(d[i][j])
     {
         case 0:
                out(n,i-1,j-1);
                break;
         case 1:
                out(n-1,i,j-1);
                printf("%d Insert %d,%c\n",n,j,str1[j-1]);
                break;
         case 2:
                out(n-1,i-1,j);
                printf("%d Delete %d\n",n,j+1);
                break;
         case 3:
                out(n-1,i-1,j-1);
                printf("%d Replace %d,%c\n",n,j,str1[j-1]);
                break;
     }
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
while(scanf("%s%s",&str,&str1)!=EOF){
    l=strlen(str);
    l1=strlen(str1);
        
    LOOP(j,0,l1){
        f[0][j]=j;
        d[0][j]=1;  //notice
    }
    LOOP(j,0,l){
        f[j][0]=j;
        d[j][0]=2;  //notice
    }
    LOOP(i,1,l)
        LOOP(j,1,l1){
            if(str[i-1]==str1[j-1]){
                f[i][j]=f[i-1][j-1];
                d[i][j]=0;
            }else{
                f[i][j]=f[i][j-1]+1;
                d[i][j]=1;
                if(f[i][j]>f[i-1][j]+1){
                    f[i][j]=f[i-1][j]+1;
                    d[i][j]=2;
                }
                if(f[i][j]>f[i-1][j-1]+1){
                    f[i][j]=f[i-1][j-1]+1;
                    d[i][j]=3;
                }
            }
        }

    printf("%d\n",f[l][l1]);
    out(f[l][l1],l,l1);
}
}
