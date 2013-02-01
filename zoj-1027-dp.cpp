#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cassert>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<sstream>
using namespace std;
#define LOOP(x,y,z) for((x)=(y);(x)<=(z);(x)++)
#define LOOPB(x,y,z) for((x)=(y);(x)<(z);(x)++)
#define RLOOP(x,y,z) for((x)=(y);(x)>=(z);(x)--)
#define RLOOPB(x,y,z) for((x)=(y);(x)>(z);(x)--)
#define ABS(x) ((x)<0?-(x):(x))
#define PI 3.1415926535898
int i,j,k,a,m,n,s,t,l,tt,cas;
const int oo=1<<29;
int score[5][5]={
{5,-1,-2,-1,-3},
{-1,5,-3,-2,-4},
{-2,-3,5,-2,-2},
{-1,-2,-2,5,-1},
{-3,-4,-2,-1,-oo}};
char str[200],str1[200];
int f[200][200];
inline void char2int(char& ch){
    //ACGT
    switch(ch){
        case 'A':
            ch=0;
            return;
        case 'C':
            ch=1;
            return;
        case 'G':
            ch=2;
            return;
        default:
            ch=3;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d",&cas);
f[0][0]=0;
while(cas--){
    scanf("%d ",&n);
    LOOP(i,1,n){
        scanf("%c",&str[i]);
        char2int(str[i]);
    }
    scanf("%d ",&m);
    LOOP(i,1,m){
        scanf("%c",&str1[i]);
        char2int(str1[i]);
    }
    LOOP(i,1,n)
        f[i][0]=f[i-1][0]+score[str[i]][4];
    LOOP(i,1,m)
        f[0][i]=f[0][i-1]+score[4][str1[i]];
    LOOP(i,1,n)
        LOOP(j,1,m){
            f[i][j]=f[i-1][j-1]+score[str[i]][str1[j]];
            f[i][j]=max(f[i][j],f[i-1][j]+score[str[i]][4]);
            f[i][j]=max(f[i][j],f[i][j-1]+score[4][str1[j]]);
        }
    printf("%d\n",f[n][m]);
}

}
