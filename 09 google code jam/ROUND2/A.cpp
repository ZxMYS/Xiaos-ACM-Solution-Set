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
int i,j,k,a,m,n,s,t,l,tt,cas,ans;
const int oo=1<<29;
char ch;

typedef struct{int r,id;} node;
node row[100];

inline int doswap(int s,int t){
    int c=0;
    while(t!=s){
        swap(row[t],row[t-1]);
        t--;
        c++;
    }
    return c;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d",&cas);
while(cas--){
    printf("Case #%d: ",++tt);
    scanf("%d\n",&n);
    LOOPB(i,0,n){
        row[i].r=0;
        LOOPB(j,0,n){
            scanf("%c",&ch);
            if(ch=='1'){
                row[i].r=j;
            }
        }
        scanf("\n");
    }
    bool flag=true;
    LOOPB(i,0,n){
        if(row[i].r>i)flag=false;
    }
    if(flag){printf("0\n");continue;}
    ans=0;
    LOOPB(i,0,n){
        LOOPB(j,i+1,n){
            if(row[i].r>i&&row[j].r<=i){
                ans+=doswap(i,j);
                goto L1;
            }
        }
        L1:;
    }
    printf("%d\n",ans);
}
}
