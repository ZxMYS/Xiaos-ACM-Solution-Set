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
#include<set>
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
int i,j,k,a,m,n,s,t,l,tt,cas,ans;
const int CC=500,RR=100;
int mem[RR],cnt[CC];
int all_t;
struct node{
int r,c;
node *up,*down,*left,*right;
} all[CC*RR],row[RR],col[CC],root;
inline void link(int r,int c){
    cnt[c]++;
    node *tmp=&all[all_t++];
    tmp->r=r;
    tmp->c=c;
    tmp->left=&row[r];
    tmp->right=row[r].right;
    tmp->left->right=tmp;
    tmp->right->left=tmp;
    tmp->up=&col[c];
    tmp->down=col[c].down;
    tmp->up->down=tmp;
    tmp->down->up=tmp;
}

inline void remove(int c){
    node *t,*tt;
    col[c].left->right=col[c].right;
    col[c].right->left=col[c].left;
    for(t=col[c].down;t!=&col[c];t=t->down){
        for(tt=t->left;tt!=t;tt=tt->left){
            cnt[tt->c]--;
            tt->up->down=tt->down;
            tt->down->up=tt->up;
        }
        t->left->right=t->right;
        t->right->left=t->left;
    }
}

inline void resume(int c){
    node *t,*tt;
    for(t=col[c].down;t!=&col[c];t=t->down){
        t->left->right=t;
        t->right->left=t;
        for(tt=t->left;tt!=t;tt=tt->left){
            cnt[tt->c]++;
            tt->up->down=tt;
            tt->down->up=tt;
        }
    }
    col[c].left->right=&col[c];
    col[c].right->left=&col[c];
}

bool solve(int k){
    if(k>=ans)return false;
    if(root.right==&root){
        ans=MIN(ans,k-1);
        return true;
    }
    int min=oo;
    node *t,*tt;
    int tc;
    for(t=root.right;t!=&root;t=t->right){
        if(cnt[t->c]<min){
            min=cnt[t->c];
            tc=t->c;
            if(min<=1)break;
        }
    }
    remove(tc);
    for(t=col[tc].down;t!=&col[tc];t=t->down){
        mem[k]=t->r;
        t->left->right=t;
        for(tt=t->right;tt!=t;tt=tt->right){
            remove(tt->c);
        }
        t->left->right=t->right;
        solve(k+1);
        t->left->right=t;
        for(tt=t->right;tt!=t;tt=tt->right){
            resume(tt->c);
        }
        t->left->right=t->right;
    }
    resume(tc);
    return false;
}


int main(){
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
while(scanf("%d%d",&m,&n)!=EOF){
    memset(mem,0,sizeof(mem));
    memset(cnt,0,sizeof(cnt));
    all_t=0;
    root.r=RR;
    root.c=CC;
    root.down=root.up=root.right=root.left=&root;
    ans=oo;

    LOOPB(i,0,n){
        cnt[i]=0;
        col[i].c=i;
        col[i].r=RR;
        col[i].left=&root;
        col[i].right=col[i].left->right;
        col[i].left->right=&col[i];
        col[i].right->left=&col[i];
        col[i].up=col[i].down=&col[i];
    }
    LOOPB(i,0,m){
        row[i].r=i;
        row[i].c=CC;
        row[i].right=row[i].left=&row[i];
        row[i].up=&root;
        row[i].down=root.down;
        row[i].up->down=&row[i];
        row[i].down->up=&row[i];
    }
    LOOPB(i,0,m){
         LOOPB(j,0,n){
            scanf("%d",&t);
            if(t)
                link(i,j);
            }
    }

    LOOPB(i,0,m){
        row[i].left->right=row[i].right;
        row[i].right->left=row[i].left;
    }
    solve(0);
    if(ans==oo)
        cout<<"It is impossible"<<endl;
    else
        cout<<"Yes, I found it"<<endl;
}
}
