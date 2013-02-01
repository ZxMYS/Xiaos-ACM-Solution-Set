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
typedef struct {
    int l,r,size,key;
} node;
node t[100101];
int tot=0,root=0;
int i,j,k,a,m,n,s,l,tt,cas;
typedef struct {int x,y,k,index;} querytype;
querytype query[50101];
int dog[100101];
int ans[50101];
inline void left_rotate(int& root){
    int k=t[root].r;
    t[root].r=t[k].l;
    t[k].l=root;
    t[k].size=t[root].size;
    t[root].size=t[t[root].l].size+t[t[root].r].size+1;
    root=k;
}

inline void right_rotate(int& root){
    int k=t[root].l;
    t[root].l=t[k].r;
    t[k].r=root;
    t[k].size=t[root].size;
    t[root].size=t[t[root].l].size+t[t[root].r].size+1;
    root=k;
}

inline void maintain(int& root,bool flag){
    if(flag){
        if(t[t[root].l].size<t[t[t[root].r].r].size){
            left_rotate(root);
        }else if(t[t[root].l].size<t[t[t[root].r].l].size){
            right_rotate(t[root].r);
            left_rotate(root);
        }else
            return;
    }else{
        if(t[t[root].r].size<t[t[t[root].l].l].size){
            right_rotate(root);
        }else if(t[t[root].l].size<t[t[t[root].l].r].size){
            left_rotate(t[root].l);
            right_rotate(root);
        }else
            return;
    }
    maintain(t[root].l,false);
    maintain(t[root].r,true);
    maintain(root,false);
    maintain(root,true);
}

inline void insert(int& root,const int& key){
    if(!root){
        root=++tot;
        t[root].l=t[root].r=0;
        t[root].key=key;
        t[root].size=1;
        return;
    }
    t[root].size++;
    if(t[root].key>key)
        insert(t[root].l,key);
    else
        insert(t[root].r,key);
    maintain(root,key>=t[root].key);
}

inline int del(int& root,const int& key){
    t[root].size--;
    if(t[root].key==key||(!t[root].l&&key<t[root].key)||(!t[root].r&&key>=t[root].key)){
        if(!t[root].l||!t[root].r){
            int ret=t[root].key;
            root=t[root].l?t[root].l:t[root].r;
            return ret;
        }else{
            int x=key;
            x++;
            t[root].key=del(t[root].l,x);
            return t[root].key;
        }
    }
    if(t[root].key>key)
        return del(t[root].l,key);
    else
        return del(t[root].r,key);
}

inline int kth_min(const int& root,const int k){
    if(k==1+t[t[root].l].size)
        return t[root].key;
    if(t[root].l&&k<=t[t[root].l].size)
        return kth_min(t[root].l,k);
    else
        return kth_min(t[root].r,k-(t[root].l?t[t[root].l].size:0)-1);
}


inline bool querycmp(const querytype& a,const querytype& b){
    return a.x!=b.x?a.x<b.x:a.y<b.y;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d%d",&n,&m);
LOOP(i,1,n){
    scanf("%d",&dog[i]);
}
LOOPB(i,0,m){
    scanf("%d%d%d",&query[i].x,&query[i].y,&query[i].k);
    query[i].index=i;
}
sort(query,query+m,querycmp);

LOOP(i,query[0].x,query[0].y){
    insert(root,dog[i]);
}
ans[query[0].index]=kth_min(root,query[0].k);
LOOPB(i,1,m){
    if(query[i].x<query[i-1].y){
        LOOPB(j,query[i-1].x,query[i].x)
            del(root,dog[j]);
        LOOP(j,query[i-1].y+1,query[i].y)
            insert(root,dog[j]);
    }else{
        LOOP(j,query[i-1].x,query[i-1].y)
            del(root,dog[j]);
        LOOP(j,query[i].x,query[i].y)
            insert(root,dog[j]);
    }
    ans[query[i].index]=kth_min(root,query[i].k);
}
LOOPB(i,0,m)
    printf("%d\n",ans[i]);
}
