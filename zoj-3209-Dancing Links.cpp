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
int i,j,k,a,m,n,s,t,l,tt,cas,ans,_n,_m;
const int CC=900,RR=501;
int mem[RR],cnt[CC];
int all_t;
struct node{
int r,c;
node *up,*down,*left,*right;
} all[CC*RR+10],row[RR],col[CC],root;
typedef struct {int x,y,xx,yy;}rect;
set<int> xset,yset;
vector<rect> rec;
int _x[31];
int _y[31];
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
scanf("%d",&cas);
while(cas--){
    all_t=0;
    rec.clear();
    xset.clear();
    yset.clear();
    root.r=RR;
    root.c=CC;
    root.down=root.up=root.right=root.left=&root;
    ans=oo;
    scanf("%d%d%d",&n,&m,&t);
    rect rectmp;
    LOOPB(i,0,t){
        int x,y,xx,yy;
        scanf("%d%d%d%d",&x,&y,&xx,&yy);
        xset.insert(x);
        yset.insert(y);
        xset.insert(xx);
        yset.insert(yy);
        rectmp.x=x;
        rectmp.y=y;
        rectmp.xx=xx;
        rectmp.yy=yy;
        rec.push_back(rectmp);
    }
    set<int>::iterator iter;
    i=0;
    for(iter=xset.begin();iter!=xset.end();iter++){
        _x[*iter]=i++;
    }
    _n=i-1;
    i=0;
    for(iter=yset.begin();iter!=yset.end();iter++){
        _y[*iter]=i++;
    }
    _m=i-1;
    s=_m*_n;
    LOOPB(i,0,s){
        cnt[i]=0;
        col[i].c=i;
        col[i].r=RR;
        col[i].left=&root;
        col[i].right=col[i].left->right;
        col[i].left->right=&col[i];
        col[i].right->left=&col[i];
        col[i].up=col[i].down=&col[i];
    }
    LOOPB(i,0,t){
        row[i].r=i;
        row[i].c=CC;
        row[i].right=row[i].left=&row[i];
        row[i].up=&root;
        row[i].down=root.down;
        row[i].up->down=&row[i];
        row[i].down->up=&row[i];
    }

    t=0;
    LOOPB(i,0,rec.size()){
        //cout<<rec[i].x<<' '<<rec[i].y<<' '<<rec[i].xx<<' '<<rec[i].yy<<endl;
        //cout<<_x[rec[i].x]<<' '<<_y[rec[i].y]<<' '<<_x[rec[i].xx]<<' '<<_y[rec[i].yy]<<endl;
        LOOPB(j,_x[rec[i].x],_x[rec[i].xx])
                LOOPB(k,_y[rec[i].y],_y[rec[i].yy]){
                        link(i,j*_m+k);
                }
    }

    LOOPB(i,0,t){
        row[i].left->right=row[i].right;
        row[i].right->left=row[i].left;
    }
    solve(0);
    if(ans==oo)
        ans=-2;
    printf("%d\n",ans+1);
}
}
