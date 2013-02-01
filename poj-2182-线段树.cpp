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
typedef struct {int l,r,v;} nodetype;
nodetype tree[16382]; //注意不能开成8001*2，虽然N只有8000，但是用到的最大节点经实验是16381；
                        //(=(2^13-8000)*2=192*2)
int orz[8001];

void build_tree(int root,int l,int r){
    tree[root].l=l;tree[root].r=r;tree[root].v=r-l+1;
    if(l==r)return;
    build_tree(root<<1,l,(l+r)>>1);
    build_tree((root<<1)+1,((l+r)>>1)+1,r);
}

int query(int root,int v){
    tree[root].v--;
    if(tree[root].l==tree[root].r)
        return tree[root].l;
    if(tree[root<<1].v>=v)
        return query(root<<1,v);
    else
        return query((root<<1)+1,v-tree[root<<1].v);
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d",&n);
LOOP(i,1,n-1)
    scanf("%d",&orz[i]);
build_tree(1,1,n);
RLOOP(i,n-1,1){
    orz[i]=query(1,orz[i]+1);
}
orz[0]=query(1,1);
LOOPB(i,0,n)
    printf("%d\n",orz[i]);
}
