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
#define EPS 0.0000001
const int oo=1<<29;
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a,m,n,s,t,l,tt,cas,x,y,ans;
typedef struct {double l,r;} qtype;
list<qtype> qs;
list<qtype>::iterator iter1,iter2;
qtype tmp;
double xxx;
bool cmp(const qtype a,const qtype b){
    return a.r>b.r;
}

inline void out(){
    iter1=qs.begin();
    while(iter1!=qs.end()){
        printf("%lf %lf\n",iter1->l,iter1->r);
        iter1++;
    }
    cout<<endl;
}

inline void solve(){
    iter1=qs.begin();
    if(iter1!=qs.end()){
        xxx=iter1->l;
        ans++;
    }
    iter1++;
    while(iter1!=qs.end()){
        if(iter1->r+EPS>=xxx)
            iter1=qs.erase(iter1);
        else{
            ans++;
            xxx=iter1->l;
            iter1++;
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d%d",&n,&m);
l=0;
bool flag;
while(n){
    printf("Case %d: ",++l);
    flag=false;
    ans=0;
    qs.clear();
    LOOPB(i,0,n){
        scanf("%d%d",&x,&y);
        if(!flag){
        if(y>m)
            flag=true;
        xxx=sqrt(m*m-y*y);
        tmp.l=x-xxx;
        tmp.r=x+xxx;
        qs.push_back(tmp);
        }
    }
    if(flag){
        printf("-1\n");
        goto L2;
    }
    //out();
    iter1=qs.begin();
    while(iter1!=qs.end()){
        iter2=qs.begin();
        while(iter2!=qs.end()){
            if(iter2==iter1){
                iter2++;
                continue;
            }
            if(iter2->l+EPS>=iter1->l&&iter2->r<=iter1->r+EPS){
                iter1=qs.erase(iter1);
                goto L1;
            }else
                iter2++;
        }
        iter1++;
        L1:;
    }
    qs.sort(cmp);
    //out();
    solve();
    printf("%d\n",ans);
    L2:
    scanf("%d%d",&n,&m);
}
}
