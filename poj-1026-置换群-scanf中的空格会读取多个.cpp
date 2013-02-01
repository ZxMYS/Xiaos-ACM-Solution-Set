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
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define ABS(x) ((x)<0?-(x):(x))
#define PI 3.1415926535898
int i,j,k,a,m,n,s,t,l,tt,cas;
int num[211];
char str[211],ans[211];
bool chked[211];
int move[211],mt;
inline void do_move(int offset){
    if(mt<=1||!offset)return;
    int i,j=offset;
    LOOPB(i,0,mt){
        ans[move[j]]=str[move[i]];
        j++;
        if(j>=mt)j-=mt;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
while(scanf("%d",&n)!=EOF&&n){
    LOOPB(i,0,n){
        scanf("%d",&num[i]);
        num[i]--;
    }
    scanf("%d",&m);
    getchar();
    while(m){
        memset(chked,0,sizeof(chked));
        gets(str);
        
        if(strlen(str)<n){
            LOOPB(i,strlen(str),n)
                str[i]=' ';
            str[n]=0;
        }
        strcpy(ans,str);
        LOOPB(i,0,n){
            if(!chked[i]){
                mt=0;
                move[mt++]=i;
                chked[i]=true;
                j=num[i];
                while(j!=i){
                    move[mt++]=j;
                    chked[j]=true;
                    j=num[j];
                }
                do_move(m%mt);
            }
        }
        ans[n]=0;
        printf("%s\n",ans);
        scanf("%d",&m);
        getchar();
    }
    printf("\n");
}
}
