/*所以首先把区间从小到大排序，这样可以保证每个
元素只插入一次，删除也只有一次。
如样例。 首先把 1-5  区间元素插入，
到第二个区间 2-7 时，把 1-2 删除， 5-7 插入
（题目已说明没有一个区间包含另一个区间的情况）
*/

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
#define lowbit(x) ((x)&-(x))
int i,j,k,a,m,n,s,t,l,tt,cas;
typedef struct {int index,v;} _dogtype;
_dogtype _dog[100101];
typedef struct {int x,y,k,index;} querytype;
querytype query[50101];
int dog[100101];
int c[100101];
int ans[50101];

inline bool _dogcmp(const _dogtype& a,const _dogtype& b){
    return a.v<b.v;
}
inline bool querycmp(const querytype& a,const querytype& b){
    return a.x!=b.x?a.x<b.x:a.y<b.y;
}

inline void add(int pos,const int v){
    while(pos<=n){
        c[pos]+=v;
        pos+=lowbit(pos);
    }
}
inline int sum(int pos){
    int s=0;
    while(pos>0){
        s+=c[pos];
        pos-=lowbit(pos);
    }
    return s;
}

inline int kth_min(const int& k){
    int L=1,R=n+1,mid;
    while(L+1<R){
        mid=(L+R)>>1;
        if(sum(mid)>=k)
            R=mid;
        else
            L=mid;
    }
    if(sum(L)==k)return L;
    return L+1;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d%d",&n,&m);
LOOP(i,1,n){
    scanf("%d",&_dog[i].v);
    _dog[i].index=i;
}
sort(_dog+1,_dog+n+1,_dogcmp);
LOOP(i,1,n){
    dog[_dog[i].index]=i;
}
LOOPB(i,0,m){
    scanf("%d%d%d",&query[i].x,&query[i].y,&query[i].k);
    query[i].index=i;
}
sort(query,query+m,querycmp);
LOOP(i,query[0].x,query[0].y){
    add(dog[i],1);
}
ans[query[0].index]=_dog[kth_min(query[0].k)].v;
LOOPB(i,1,m){
    if(query[i].x<query[i-1].y){
        LOOPB(j,query[i-1].x,query[i].x)
            add(dog[j],-1);
        LOOP(j,query[i-1].y+1,query[i].y)
            add(dog[j],1);
    }else{
        LOOP(j,query[i-1].x,query[i-1].y)
            add(dog[j],-1);
        LOOP(j,query[i].x,query[i].y)
            add(dog[j],1);
    }
    ans[query[i].index]=_dog[kth_min(query[i].k)].v;
}
LOOPB(i,0,m)
    printf("%d\n",ans[i]);
}
