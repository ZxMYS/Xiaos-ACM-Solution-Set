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
int i,j,k,m,n,s,t,l,tt,cas,maxflow;
typedef struct _node{int t,c;_node *r;} edgetype;
vector<edgetype> edge[210];
edgetype etmp;
edgetype *ptmp,*pre[210];
int d[210],cnt[210],cur[210],a[210];

inline int sap(){
    int i,j,k,v,flow=0;
    LOOPB(i,0,n)
        d[i]=a[i]=cnt[i]=cur[i]=0;
    cnt[0]=n;
    a[s]=oo;
    k=s;
    while(d[s]<n){
        v=0;
        LOOPB(i,cur[k],edge[k].size()){
            if(edge[k][i].c&&d[edge[k][i].t]+1==d[k]){
                v=edge[k][i].t;
                break;
            }
        }
        cur[k]=i;
        if(cur[k]!=edge[k].size()){
            pre[v]=&edge[k][i];
            assert(edge[k][i].r->t==k);
            a[v]=MIN(a[k],edge[k][i].c);
            if((k=v)==t){
                do{
                    pre[k]->c-=a[t];
                    pre[k]->r->c+=a[t];
                    k=pre[k]->r->t;
                }while(k!=s);
                flow+=a[t];
                LOOPB(i,0,n)
                    a[i]=0;
                a[s]=oo;
            }
        }else{
            if(--cnt[d[k]]==0)break;
            d[k]=n;
            cur[k]=0;
            LOOPB(i,cur[k],edge[k].size())
                if(edge[k][i].c&&d[edge[k][i].t]+1<d[k])
                    d[k]=d[edge[k][i].t]+1;
            cnt[d[k]]++;
            if(k!=s)k=pre[k]->r->t;
        }
    }
    return flow;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
//freopen("out","w",stdout);
#endif
scanf("%d%d%d",&n,&s,&t);
s--;t--;
LOOPB(i,0,n){
    LOOP(j,0,i)scanf("%*d");
    LOOPB(j,i+1,n){
        scanf("%d",&l);
        if(l){
            if((i==s&&j==t)||(i==t&&j==s)) goto NOANS;
            etmp.t=j;
            if(i!=s&&i!=t&&j!=s&&j!=t)
                etmp.c=1;
            else
                etmp.c=oo;
            edge[i].push_back(etmp);
            etmp.t=i;
            etmp.c=0;
            etmp.r=&edge[i][edge[i].size()-1];
            edge[j].push_back(etmp);
            etmp.r->r=&edge[j][edge[j].size()-1];
        }
    }
}
LOOPB(i,0,n){
    LOOPB(j,0,edge[i].size()){
        printf("%d %d\n",edge[i][j].t,edge[i][j].c);
        printf("%d %d\n",edge[i][j].r->t,edge[i][j].r->c);
        assert(edge[i][j].r->t==i);
    }
}
maxflow=sap();
printf("%d\n",maxflow);
return 0;
NOANS:
    printf("NO ANSWER!\n");
}
