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
int i,j,k,a,m,n,s,t,l,tt,cas;
char tmp,str[500];
int tr[200][200];
int ga[200][200];
int tax[200];

void out(int f,int t){
    while(f!=t){
        printf("-->%d",tr[f][t]+1);
        f=tr[f][t];
    }
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d",&n);
while(n){
    LOOPB(i,0,n){
        LOOPB(j,0,n){
            scanf("%d",&t);
            if(t==-1)
                ga[i][j]=oo;
            else
                ga[i][j]=t;
            tr[i][j]=j;
        }
    }
    LOOPB(i,0,n)
        scanf("%d",&tax[i]);
    LOOPB(k,0,n)
        LOOPB(i,0,n){
            if(i==k)continue;
            LOOPB(j,0,n){
                if(j==k||j==i)continue;
                s=ga[i][k]+ga[k][j]+tax[k];
                if(ga[i][j]>s){
                    tr[i][j]=tr[i][k];
                    ga[i][j]=s;
                }else if(ga[i][j]==s){
                    if(tr[i][j]>tr[i][k])
                        tr[i][j]=tr[i][k];
                }
            }
        }
    scanf("%d%d",&s,&t);
    /*
    From 2 to 4 :
    Path: 2-->1-->5-->4
    Total cost : 17
    */
    while(s!=-1){
        printf("From %d to %d :\nPath: ",s,t);
        s--;t--;
        printf("%d",s+1);
        out(s,t);
        printf("\n");
        printf("Total cost : %d\n\n",ga[s][t]);
        scanf("%d%d",&s,&t);
    }
    scanf("%d",&n);
}
}
