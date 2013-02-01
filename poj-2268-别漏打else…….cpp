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
int i,j,k,a,m,n,s,t,ttt,l,tt;
char tmp,str[500],str2[500],score[21],wt[21],bt[21],ga[21][21],team[21][500];
float f1,f2;
inline int ft(char t[]){
    int i;
    LOOPB(i,0,n)
        if(strcmp(t,team[i])==0)
            return i;
    return -1;
}

void dfs(int a,int b){
    if(b>=n){
        dfs(a+1,0);
        return;
    }
    if(a>=n){
	  int num_better;
	  int num_worse;
	  int i,k;
	  LOOPB(i,0,n){
            num_better=0;
            num_worse=0;
            LOOPB(k,0,n){
                if(score[k]>score[i])num_better++;
                else if(score[k]<score[i])num_worse++;
            }
	        bt[i] = MIN(bt[i],num_better+1);
	        wt[i] = MAX(wt[i],n-num_worse);
       }
       return;
    }
    if(a==b||ga[a][b]){
        dfs(a,b+1);
        return;
    }
    score[a]+=3;
    dfs(a,b+1);
    score[a]-=3;

    score[a]++;
    score[b]++;
    dfs(a,b+1);
    score[a]--;
    score[b]--;

    score[b]+=3;
    dfs(a,b+1);
    score[b]-=3;
}
int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d",&n);
t=0;
while(n!=0){
printf("Group #%d\n",++t);
LOOPB(i,0,n){
    scanf("%s",&team[i]);
    score[i]=0;
    bt[i]=n;
    wt[i]=1;
    LOOPB(j,0,n)
        ga[i][j]=0;
}
scanf("%d",&m);
LOOPB(i,0,m){
    scanf("%s%s%d%d",&str,&str2,&ttt,&l);
    k=ft(str);
    a=ft(str2);
    ga[k][a]=1;
    if(ttt>l)score[k]+=3;
    else if(ttt==l){score[k]++;score[a]++;}
    else score[a]+=3;
}
dfs(0,0);
LOOPB(i,0,n)
    printf("%s %d-%d\n",team[i],bt[i],wt[i]);
putchar('\n');
scanf("%d",&n);
}

}
