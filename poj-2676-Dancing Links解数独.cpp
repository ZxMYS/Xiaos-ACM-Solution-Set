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

#define RR 729
#define CC 324
const int oo=1<<29;
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a,m,n,s,t,l,tt,cas;
int mem[RR+9];
int ans[RR+9];
char ch[RR+9];
int cnt[CC+9];
struct node{
    int r,c;
    node *up,*down,*left,*right,*root;
}root,all[RR*CC+99],row[RR],col[CC];
int all_t;

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
    col[c].right->left=col[c].left;
    col[c].left->right=col[c].right;
    for(t=col[c].down;t!=&col[c];t=t->down){
        for(tt=t->right;tt!=t;tt=tt->right){
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
        t->right->left=t;
        t->left->right=t;
        for(tt=t->left;tt!=t;tt=tt->left){
            cnt[tt->c]++;
            tt->down->up=tt;
            tt->up->down=tt;
        }
    }
    col[c].left->right=&col[c];
    col[c].right->left=&col[c];
}

bool solve(int k){
    if(root.right==&root)
        return true;
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
        if(solve(k+1))
            return true;
        t->right->left=t;
        for(tt=t->left;tt!=t;tt=tt->left){
            resume(tt->c);
        }
        t->right->left=t->left;
    }
    resume(tc);
    return false;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out","w",stdout);
    #endif
    scanf("%d",&cas);
    double ss=0;
    string ch,ctmp;
    while(cas--)
    {
        ch="";
        LOOPB(i,0,9){
            cin>>ctmp;
            ch+=ctmp;
        }
        all_t=1;
        memset(cnt,0,sizeof(cnt));
        root.left=&root;
        root.right=&root;
        root.up=&root;
        root.down=&root;
        root.r=RR;
        root.c=CC;
        for(i=0;i<CC;i++)
        {
            col[i].c=i;
            col[i].r=RR;
            col[i].up=&col[i];
            col[i].down=&col[i];
            col[i].left=&root;
            col[i].right=root.right;
            col[i].left->right=&col[i];
            col[i].right->left=&col[i];
        }
        for(i=0;i<RR;i++)
        {
            row[i].r=i;
            row[i].c=CC;
            row[i].left=&row[i];
            row[i].right=&row[i];
            row[i].up=&root;
            row[i].down=root.down;
            row[i].up->down=&row[i];
            row[i].down->up=&row[i];
        }
        for(i=0;i<RR;i++)
        {
            int r=i/9/9%9;
            int c=i/9%9;
            int val=i%9+1;
            if(ch[r*9+c]=='0'||ch[r*9+c]==val+'0')
            {
                link(i,r*9+val-1);
                link(i,81+c*9+val-1);
                int tr=r/3;
                int tc=c/3;
                link(i,162+(tr*3+tc)*9+val-1);
                link(i,243+r*9+c);
            }
        }
        for(i=0;i<RR;i++)
        {
            row[i].left->right=row[i].right;
            row[i].right->left=row[i].left;
        }
        solve(1);
        for(i=1;i<=81;i++)
        {
            int t=mem[i]/9%81;
            int val=mem[i]%9+1;
            ans[t]=val;
        }
        j=0;
        for(i=0;i<81;i++){
            printf("%d",ans[i]);
            j++;
            if(j==9){
                cout<<endl;
                j=0;
            }
        }
    }
}
