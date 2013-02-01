#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<assert.h>
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
#define oo (1<<29)
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a,m,n,s,t,tt,cas,dx;
typedef struct {int x,y;} ptype;
ptype ptmp;
vector<ptype> house,man;
char ch;
bool chkx[101],chky[101];
int l[101],r[101],w[101][101],match[101];

bool find(int n){
    chkx[n]=true;
    int i;
    LOOPB(i,0,house.size()){
        if(!chky[i]&&l[n]+r[i]==w[n][i]){
            chky[i]=true;
            if(match[i]==-1||find(match[i])){
                match[i]=n;
                return true;
            }
        }
    }
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d%d\n",&n,&m);
while(n){
    man.clear();
    house.clear();
    LOOPB(i,0,n){
        LOOPB(j,0,m){
            scanf("%c",&ch);
            switch(ch){
                case 'm':
                    ptmp.x=i;
                    ptmp.y=j;
                    man.push_back(ptmp);
                    break;
                case 'H':
                    ptmp.x=i;
                    ptmp.y=j;
                    r[house.size()]=0;
                    match[house.size()]=-1;
                    house.push_back(ptmp);
            }
        }
        scanf("\n");
    }
    LOOPB(i,0,man.size()){
        l[i]=-oo;
        LOOPB(j,0,house.size()){
            w[i][j]=-(ABS(man[i].x-house[j].x)+ABS(man[i].y-house[j].y));
            l[i]=MAX(l[i],w[i][j]);
        }
    }
    LOOPB(k,0,man.size()){
        while(1){
            memset(chkx,0,sizeof(chkx));
            memset(chky,0,sizeof(chky));
            
            if(find(k))
                break;
                
            dx=oo;
            LOOPB(i,0,house.size()){
                if(chkx[i]){
                    LOOPB(j,0,house.size()){
                        if(!chky[j])
                            dx=MIN(l[i]+r[j]-w[i][j],dx);
                    }
                }
            }
            LOOPB(i,0,house.size()){
                if(chkx[i])
                    l[i]-=dx;
                if(chky[i])
                    r[i]+=dx;
            }
        }
    }
    a=0;
    LOOPB(i,0,house.size())
        a+=w[match[i]][i];
    printf("%d\n",-a);
    scanf("%d%d\n",&n,&m);
}
}
