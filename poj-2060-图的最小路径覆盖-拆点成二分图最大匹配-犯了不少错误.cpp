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
#define PI 3.1415926535898
#define ABS(x) ((x)<0?-(x):(x))
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
typedef struct {int ex,ey,sx,sy,st,et;} books;
books book[501];
bool chk[1010];
vector<int> ga[1010];
int i,j,k,a,n,cas,match[1010];

bool find(int n){
    int i;
    //chk[n]=true; ！！！这句不能要！！！SB了！！！！！
    LOOPB(i,0,ga[n].size()){
        if(!chk[ga[n][i]]){
            chk[ga[n][i]]=true;
            if(match[ga[n][i]]==-1||find(match[ga[n][i]])){
                match[ga[n][i]]=n;   //NOTICE!不是match[n]!!!
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
scanf("%d",&cas);
while(cas--){
    scanf("%d",&n);
    LOOPB(i,0,n){
        scanf("%d:%d%d%d%d%d",&a,&k,&book[i].sx,&book[i].sy,&book[i].ex,&book[i].ey);
        book[i].st=a*60+k;
        book[i].et=book[i].st+ABS(book[i].ex-book[i].sx)+ABS(book[i].ey-book[i].sy);
        ga[i].clear();
        match[i]=-1;
    }
    LOOPB(i,0,n){
        LOOPB(j,i+1,n){
            if(i==j)continue;
            if(book[i].et+ABS(book[i].ex-book[j].sx)+ABS(book[i].ey-book[j].sy)+1<=book[j].st)
                ga[i].push_back(j);
        }
    }
    a=0;
    LOOPB(i,0,n){
        LOOPB(j,0,n)
            chk[j]=false;
        if(find(i))
            a++;
    }
    printf("%d\n",n-a);
}
}
