#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<list>
using namespace std;
#define LOOP(x,y,z) for((x)=(y);(x)<=(z);(x)++)
#define LOOPB(x,y,z) for((x)=(y);(x)<(z);(x)++)
#define RLOOP(x,y,z) for((x)=(y);(x)>=(z);(x)--)
#define RLOOPB(x,y,z) for((x)=(y);(x)>(z);(x)--)
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define PI 3.1415926535898
#define oo 10000000
int i,j,k,a,m,n,s,t,l,tt,ttt,q,parent[3001],ans[1001];
typedef struct {int s,t,v;} ee;
list<ee> qu;
list<ee>::iterator quiter;
vector<ee> edge;
ee tmp;

int find(int n){
    if(parent[n]==n)return n;
    parent[n]=find(parent[n]);
    return parent[n];
}
inline void un(int a,int b){
    parent[find(a)]=parent[find(b)];
}
bool cmp(ee a,ee b){
    return a.v<b.v;
}

int main()
{
//#ifndef ONLINE_JUDGE
//freopen("in.txt","r",stdin);
//freopen("out","w",stdout);
//#endif
scanf("%d",&tt);
while(tt--){
    printf("Case %d\n",++ttt);
    scanf("%d%d",&n,&m);
    edge.clear();
    LOOPB(i,0,n)
            parent[i]=i;
    LOOPB(i,0,m){
            scanf("%d%d%d",&a,&k,&s);
            k--;a--;
            tmp.s=k;
            tmp.t=a;
            tmp.v=s;
            edge.push_back(tmp);
        }
    sort(edge.begin(),edge.end(),cmp);
    /*LOOPB(i,0,m){
        printf("%d %d %d\n",edge[i].s,edge[i].t,edge[i].v);
    }*/
    scanf("%d",&q);
    l=q;
    i=0;
    while(q--){
        scanf("%d%d",&a,&k);
        a--;k--;
        tmp.s=a;
        tmp.t=k;
        tmp.v=i++;
        qu.push_back(tmp);
    }
    quiter=qu.begin();
    i=0;
    while(quiter!=qu.end()){
        un(edge[i].s,edge[i].t);
        while(quiter!=qu.end()){
            if(find(quiter->s)==find(quiter->t)){
                ans[quiter->v]=edge[i].v;
                quiter=qu.erase(quiter);
                goto L1;
            }
            quiter++;
            L1:;
        }
        i++;
        quiter=qu.begin();
    }
    i=0;
    while(l--)
        printf("%d\n",ans[i++]);
    putchar('\n');
}
}
