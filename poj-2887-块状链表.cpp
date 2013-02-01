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
int i,j,k,a,m,n,s,t,l,tt,cas;
char str[1000101],ch;
int bt;
typedef struct _node{
    int n;
    char el[2010];
    _node *pre,*nxt;
} node;
node *first=new(node);

inline void link(node *a,node *b){
    b->nxt=a->nxt;
    a->nxt=b;
    b->nxt->pre=b;
    b->pre=a;
}

inline void del(node *a,node *b){
    a->nxt=b->nxt;
    a->nxt->pre=a;
    delete(b);
}

inline void merge(node *a,node *b){
    memcpy(a->el+a->n,b->el,b->n);
    a->n+=b->n;
    del(a,b);
}

inline void split(node *a,int size){
    node *tmp=new(node);
    memcpy(tmp->el,a->el+a->n-size,size);
    a->n-=size;
    tmp->n=size;
    link(a,tmp);
}

inline void balance(){
    node *tmp=first->nxt,*pre=first;
    while(tmp!=first){
        if(tmp->n>bt<<1)
            split(tmp,tmp->n-bt);
        else if(tmp->n+pre->n<bt)
            merge(pre,tmp);
        tmp=tmp->nxt;
    }
}

inline void build(){
    int p=0,i=MIN(bt,l);
    node *tmp,*pre;
    int j(i);
    first->n=i;
    LOOPB(i,0,j){
        first->el[i]=str[i];
    }
    first->pre=first->nxt=first;
    p+=j;
    pre=first;
    while(p<l){
        tmp=new(node);
        j=MIN(bt,l-p);
        tmp->n=j;
        LOOPB(i,0,j){
            tmp->el[i]=str[i+p];
        }
        p+=j;
        link(pre,tmp);
        pre=tmp;
    }
}

inline int findpos(int pos,node* &a){
    int sum=0;
    node *tmp=first,*pre;
    while(sum<pos){
        sum+=tmp->n;
        pre=tmp;
        tmp=tmp->nxt;
    }
    a=pre;
    return pos-sum+pre->n-1;
}

inline void query(int pos){
    int j;
    node *tmp;
    j=findpos(pos,tmp);
    printf("%c\n",tmp->el[j]);
}

inline void insert(char ch,int pos){
    if(pos!=l+1){
        int j;
        node *tmp;
        j=findpos(pos,tmp);
        tmp->n++;
        memcpy(tmp->el+j+1,tmp->el+j,tmp->n-j);
        *(tmp->el+j)=ch;
    }else{
        node *tmp=first->nxt,*pre=first;
        while(tmp!=first){
            pre=tmp;
            tmp=tmp->nxt;
        }
        *(pre->el+pre->n)=ch;
        pre->n++;
    }
    balance();
}

inline void print(){
    node *tmp;
    int i,j=first->n;
    LOOPB(i,0,j){
        printf("%c",first->el[i]);
    }
    tmp=first->nxt;
    while(tmp!=first){
        j=tmp->n;
        LOOPB(i,0,j){
            printf("%c",tmp->el[i]);
        }
        tmp=tmp->nxt;
    }
    putchar('\n');
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%s",&str);
l=strlen(str);
bt=(int)sqrt((double)l);
build();
scanf("%d\n",&n);
LOOPB(i,0,n){
    scanf("%c",&ch);
    if(ch=='Q'){
        scanf("%d\n",&a);
        query(a);
    }else{
        scanf("%*c%c",&ch);
        scanf("%d\n",&a);
        if(a>l)a=l+1;
        insert(ch,a);
        l++;
        //print();
    }
}
}
