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
int i,j,k,a,m,n,s,t,l,tt,cas;
typedef struct {int s[3],root,left,right;} node;
node tree[500000*4+1];
typedef struct {int s[3];long long int id;} node2;
node2 g[500100],gtmp,*gtmp2;
int tmp[3];
char command[10],argv[10];
long long int id,id2;
bool cmp(const node2 a,const node2 b){
    return a.id<b.id;
}

void build(int root,int left,int right){
    tree[root].s[1]=tree[root].s[0]=tree[root].s[2]=0;
    tree[root].left=left;
    tree[root].right=right;
    if(left==right)
        return;
    int mid=(left+right)>>1;
    build(root<<1,left,mid);
    build((root<<1)+1,mid+1,right);
}

void add2(int root,int left,int right){
    tree[root].s[0]+=tmp[0];
    tree[root].s[1]+=tmp[1];
    tree[root].s[2]+=tmp[2];
    if(tree[root].left==left&&tree[root].right==right)
        return;
    int mid=(tree[root].left+tree[root].right)>>1;
    if(left>mid)
        add2((root<<1)+1,left,right);
    else if(right<=mid)
        add2(root<<1,left,right);
    else{
        add2(root<<1,left,mid);
        add2((root<<1)+1,mid+1,right);
    }
}

void add(int root,int left,int right){
    tree[root].s[t]+=l;
    if(tree[root].left==left&&tree[root].right==right)
        return;
    int mid=(tree[root].left+tree[root].right)>>1;
    if(left>mid)
        add((root<<1)+1,left,right);
    else if(right<=mid)
        add(root<<1,left,right);
    else{
        add(root<<1,left,mid);
        add((root<<1)+1,mid+1,right);
    }
}

int query(int root,int left,int right){
    if(tree[root].left==left&&tree[root].right==right){
        return tree[root].s[t];
    }
    int mid=(tree[root].left+tree[root].right)>>1;
    if(left>mid)
        return query((root<<1)+1,left,right);
    else if(right<=mid)
        return query(root<<1,left,right);
    else
        return query(root<<1,left,mid)+query((root<<1)+1,mid+1,right);
}

inline int findidlower(long long int id){
    gtmp.id=id;
    return lower_bound(g+1,g+n+1,gtmp,cmp)-g;
}

inline int findidupper(long long int id){
    gtmp.id=id;
    return upper_bound(g+1,g+n+1,gtmp,cmp)-g-1;
}


inline void sett(char argv[]){
    switch(argv[0]){
        case 'f':
            t=0;
            break;
        case 's':
            t=1;
            break;
        case 'c':
            t=2;
            break;
        case 'A':
            t=3;
            break;
    }
}

inline void cadd(){
    scanf("%I64d%d%s",&id,&l,&argv);
    sett(argv);
    tt=findidlower(id);
    add(1,tt,tt);
}

inline void cquery(){
    scanf("%I64d%I64d%s",&id,&id2,&argv);
    sett(argv);
    a=findidlower(id);
    k=findidupper(id2);
    if(a>k){
        if(t!=3)
            printf("0\n");
        else
            printf("0 0 0\n");
        return;
        }
    if(t!=3)
    printf("%d\n",query(1,a,k));
    else{
        t=0;
        printf("%d ",query(1,a,k));
        t=1;
        printf("%d ",query(1,a,k));
        t=2;
        printf("%d\n",query(1,a,k));
    }
}

inline void cmove(){
    scanf("%I64d%I64d%d%s",&id,&id2,&l,&argv);
    sett(argv);
    a=findidlower(id);
    k=findidupper(id2);
    //cout<<"move"<<a<<' '<<k<<' '<<t<<endl;
    tt=query(1,a,a);
    if(tt<l){
        printf("[ERROR] %I64d does not have enough %s! It needs %d more!\n",id,argv,l-tt);
        l=tt;
    }
    add(1,k,k);
    l=-l;
    add(1,a,a);
}

inline void cspend(){
//[ERROR] 3 does not have enough crab! It needs 4 more!
    scanf("%I64d%d%s",&id,&l,&argv);
    a=findidlower(id);
    sett(argv);
    tt=query(1,a,a);
    if(tt<l){
        printf("[ERROR] %I64d does not have enough %s! It needs %d more!\n",id,argv,l-tt);
        l=tt;
    }
    l=-l;
    add(1,a,a);
}


int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d",&n);
build(1,1,n);
LOOP(i,1,n)
    scanf("%I64d%d%d%d",&g[i].id,&g[i].s[0],&g[i].s[1],&g[i].s[2]);
sort(g+1,g+n+1,cmp);

//LOOP(i,1,n){
//    cout<<i<<' '<<findidlower(g[i].id)<<' '<<findidupper(g[i].id)<<':'<<g[i].id<<' '<<g[i].s[0]<<' '<<g[i].s[1]<<' '<<g[i].s[2]<<endl;
//}

LOOP(i,1,n){
    tmp[0]=g[i].s[0];
    tmp[1]=g[i].s[1];
    tmp[2]=g[i].s[2];
    add2(1,i,i);
}
scanf("%d",&m);
LOOPB(i,0,m){
    scanf("%s",&command);
    switch(command[1]){
        case 'A':
            cadd();
            break;
        case 'Q':
            cquery();
            break;
        case 'M':
            cmove();
            break;
        case 'S':
            cspend();
            break;
    }
}
}
