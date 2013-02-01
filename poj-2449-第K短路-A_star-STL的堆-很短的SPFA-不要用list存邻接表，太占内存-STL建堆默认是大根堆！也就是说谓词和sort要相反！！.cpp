#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<assert.h>
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
const int oo=1<<29;
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a,m,n,s,t,l,tt,cas;
typedef struct {int v,w;} edge;
edge tmp,tmp2;
vector<edge> ga1[1001],ga[1001];
vector<edge>::iterator gaiter;
queue<int> qu;
vector<edge> heap;
int h[1001],c[1001];

bool cmp(const edge& a,const edge& b){
    return a.w+h[a.v]<b.w+h[b.v]?0:1; //注意这里的0和1；
}

inline int a_star(){
    if(h[s]>=oo)return -1;
    heap.clear();
    heap.reserve(1000000);
    tmp.v=s;
    tmp.w=0;
    heap.push_back(tmp);
    while(!heap.empty()){
        pop_heap(heap.begin(),heap.end(),cmp);
        tmp=heap.back();
        heap.pop_back();
        c[tmp.v]++;
        if(c[t]==k)return tmp.w;
        if(c[tmp.v]>k)continue;
        gaiter=ga[tmp.v].begin();
        while(gaiter!=ga[tmp.v].end()){
            tmp2.v=gaiter->v;
            tmp2.w=tmp.w+gaiter->w;
            heap.push_back(tmp2);
            push_heap(heap.begin(),heap.end(),cmp);
            gaiter++;
        }
    }
    return -1;
}
//SPFA倒过来求t的最短路
inline void calh(){
    while(!qu.empty())
        qu.pop();
    h[t]=0; //别忘了
    qu.push(t);
    while(!qu.empty()){
        tt=qu.front();
        qu.pop();
        gaiter=ga1[tt].begin();
        while(gaiter!=ga1[tt].end()){
            if(h[gaiter->v]>h[tt]+gaiter->w){
                qu.push(gaiter->v);
                h[gaiter->v]=h[tt]+gaiter->w;
            }
            gaiter++;
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
    LOOPB(i,0,m){
        scanf("%d%d%d",&a,&k,&s);
        tmp.v=a;
        tmp.w=s;
        ga1[k].push_back(tmp);
    }
    scanf("%d%d%d",&s,&t,&k);
    if(s==t)k++; //阴险的题目……
    LOOP(i,1,n){
        h[i]=oo;
        c[i]=0;
    }
    calh();
    //比起读入时同时完成两个邻接表只省了一点点内存……但是速度却会快一些？这是为什么？？？
    LOOP(i,1,n){
        gaiter=ga1[i].begin();
        tmp.v=i;
        while(gaiter!=ga1[i].end()){
            tmp.w=gaiter->w;
            ga[gaiter->v].push_back(tmp);
            gaiter++;
        }
        ga1[i].clear();
    }
    printf("%d",a_star());
}
