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
const int oo=1<<29;
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,m,n,s,t,l,tt,cas;
typedef struct {int left,right;long long int sum,add;} node;
long long int temp;
node aa[400000];
char c;

void build(int root,int left,int right){
    aa[root].sum=0;
    aa[root].left=left;
    aa[root].right=right;
    if(left==right){
        return;
    }
    int mid=(left+right)>>1;
    build(root<<1,left,mid);
    build((root<<1)+1,mid+1,right);
}

void update(int root,int pos,long long int l){
    if(aa[root].left==pos&&aa[root].right==pos){
        aa[root].sum=l;
        return;
    }
    else if(aa[(root<<1)].right>=pos){
        aa[root].sum+=l;
        update(root<<1,pos,l);
    }else{
        aa[root].sum+=l;
        update((root<<1)+1,pos,l);
    }
}

void add(int root,int left,int right,long long int l){
    aa[root].sum+=(right-left+1)*l;
    if(aa[root].left==left&&aa[root].right==right){
        aa[root].add+=l;
        return;
    }
    int mid=(aa[root].left+aa[root].right)>>1;
    if(left>mid)
        add((root<<1)+1,left,right,l);
    else if(right<=mid)
        add(root<<1,left,right,l);
    else{
        add(root<<1,left,mid,l);
        add((root<<1)+1,mid+1,right,l);
    }
}

void qu(int root,int left,int right){
    if(aa[root].left==left&&aa[root].right==right){
        temp+=aa[root].sum;
        return;
    }
    temp+=aa[root].add*(right-left+1);
    int mid=(aa[root].left+aa[root].right)>>1;
    if(left>mid)
        qu((root<<1)+1,left,right);
    else if(right<=mid)
        qu(root<<1,left,right);
    else{
        qu(root<<1,left,mid);
        qu((root<<1)+1,mid+1,right);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d%d",&n,&m);
build(1,1,n);
LOOP(i,1,n){
    scanf("%I64d",&temp);
    update(1,i,temp);
}
scanf("\n");
while(m--){
    scanf("%c",&c);
    if(c=='Q'){
        scanf("%d%d",&s,&t);
        temp=0;
        qu(1,s,t);
        printf("%I64d\n",temp);
    }else{
        scanf("%d%d%I64d",&s,&t,&temp);
        add(1,s,t,temp);
    }
    scanf("\n");
}
}
