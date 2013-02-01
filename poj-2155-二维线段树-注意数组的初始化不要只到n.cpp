#include<stdio.h>
#include<stdlib.h>
#include<time.h>
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
int i,j,k,a,m,n,s,t,l,tt,cas,x1,x2,y1,y2;
char op;
bool tree[3001][3001]; //记录的不是状态，而是以i,j为根的数的翻转次数。

void change_y(int rootx,int rooty,int begin,int end,int y1,int y2){
    if(begin==y1&&end==y2){
        tree[rootx][rooty]=!tree[rootx][rooty];
        return;
    }
    int mid=(begin+end)>>1;
    if(y2<=mid)change_y(rootx,(rooty<<1)+1,begin,mid,y1,y2);
    else if(y1>mid)change_y(rootx,(rooty<<1)+2,mid+1,end,y1,y2);
    else{
        change_y(rootx,(rooty<<1)+1,begin,mid,y1,mid);
        change_y(rootx,(rooty<<1)+2,mid+1,end,mid+1,y2);
    }
}

void change_x(int root,int begin,int end,int x1,int x2,int y1,int y2){
    if(begin==x1&&end==x2){
        change_y(root,0,1,n,y1,y2);
        return;
    }
    int mid=(begin+end)>>1;
    if(x2<=mid)change_x((root<<1)+1,begin,mid,x1,x2,y1,y2);
    else if(x1>mid)change_x((root<<1)+2,mid+1,end,x1,x2,y1,y2);
    else{
        change_x((root<<1)+1,begin,mid,x1,mid,y1,y2);
        change_x((root<<1)+2,mid+1,end,mid+1,x2,y1,y2);
    }
}

void query_y(int rootx, int rooty, int begin, int end, int y)
{
 tt ^=tree[rootx][rooty];
 if (begin != end)
 {
  int mid = (begin+end)>>1;
  if (y <= mid) query_y(rootx, (rooty<<1)+1, begin, mid, y);
  else query_y(rootx, (rooty<<1)+2, mid+1, end, y);
 }
}

void query_x(int root, int begin, int end, int x, int y)
{
 query_y(root, 0, 1, n, y);
 if (begin != end)
 {
  int mid = (begin+end)>>1;
  if (x <=mid) query_x((root<<1)+1, begin, mid, x, y);
  else query_x((root<<1)+2, mid+1, end, x, y);
 }
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d",&cas);
while(cas--){
    scanf("%d%d\n",&n,&t);
    /*LOOP(i,0,n)
        LOOP(j,i,n)
            tree[j][i]=tree[i][j]=0;*/
    //这样初始化是错误的……这个是树的数组
    memset(tree,0,sizeof(tree));
    LOOPB(k,0,t){
        scanf("%c",&op);
        if(op=='C'){
            scanf("%d%d%d%d\n",&x1,&y1,&x2,&y2);
            change_x(0,1,n,x1,x2,y1,y2);
        }else{
            scanf("%d%d\n",&x1,&y1);
            tt=0;
            query_x(0,1,n,x1,y1);
            printf("%d\n",tt);
        }
    }
    if(cas)putchar('\n');
}
}
