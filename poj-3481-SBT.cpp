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
const int oo=1<<29;
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a,m,n,s,l,tt,cas;
typedef struct {
    int l,r,key,id,size;
}node;
node tmp;
node t[1000010];
int tot=0,root=0;

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
    t[root].size=t[t[root].r].size+t[t[root].l].size+1;
    root=k;
}

inline void maintain(int& root,bool flag){
    if(flag){
        if(t[t[t[root].r].r].size>t[t[root].l].size)
            left_rotate(root);
        else if(t[t[t[root].r].l].size>t[t[root].l].size){
            right_rotate(t[root].r);
            left_rotate(root);
        }else
            return;
    }else{
        if(t[t[t[root].l].l].size>t[t[root].r].size)
            right_rotate(root);
        else if(t[t[t[root].l].r].size>t[t[root].r].size){
            left_rotate(t[root].l);
            right_rotate(root);
        }else
            return;
    }
    maintain(t[root].l,false);
    maintain(t[root].r,true);
    maintain(root,true);
    maintain(root,false);
}

inline void sbt_insert(int& root,const node& v){
    if(root==0){
        root=++tot;
        t[root]=v;
        t[root].size=1;
        return;
    }
    t[root].size++;
    if(t[root].key>v.key)
        sbt_insert(t[root].l,v);
    else
        sbt_insert(t[root].r,v);
    maintain(root,v.key>=t[root].key);
}

inline int sbt_delete(int& root,int key){
    t[root].size--;
    if(t[root].key==key||(!t[root].l&&t[root].key>key)||(!t[root].r&&t[root].key<=key)){
        int ret;
        if(!t[root].l||!t[root].r){
            ret=t[root].key;
            root=t[root].l?t[root].l:t[root].r;
        }else{
            int x=key;
            x++;
            ret=sbt_delete(t[root].l,x);
            t[root].key=ret;
        }
        return ret;
    }
    if(t[root].key>key)
        return sbt_delete(t[root].l,key);
    else
        return sbt_delete(t[root].r,key);
}

inline void outmin(){
    int k=root;
    if(k==0){
        printf("0\n");
        return;
    }
    while(t[k].l){
        k=t[k].l;
    }
    printf("%d\n",t[k].id);
    sbt_delete(root,t[k].key);
}

inline void outmax(){
    int k=root;
    if(k==0){
        printf("0\n");
        return;
    }
    while(t[k].r){
        k=t[k].r;
    }
    printf("%d\n",t[k].id);
    sbt_delete(root,t[k].key);
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
tmp.size=1;
scanf("%d",&n);
while(n){
    switch(n){
        case 1:
            scanf("%d%d",&k,&a);
            tmp.id=k;
            tmp.key=a;
            sbt_insert(root,tmp);
            break;
        case 2:
            outmax();
            break;
        case 3:
            outmin();
    }
    scanf("%d",&n);
}
}
