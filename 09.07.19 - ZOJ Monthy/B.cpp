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
const int oo=1<<30;
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a,m,n,b,s,t,l,T,tt,cas;
typedef struct {int a,b;} node;
typedef struct {int t,v;} edge;
edge tmp;
node ntmp,now;
vector<edge> ga[110];
vector<edge> shortcut[110];
int h[110][5000];
bool queued[110][5000];
queue<node> qu;

inline void spfa(){
    while(!qu.empty())
        qu.pop();
    int i,j;
    LOOPB(i,0,n){
        LOOP(j,0,k+1){
            h[i][j]=oo;
            queued[i][j]=false;
        }
    }
    h[s][0]=0;
    queued[s][0]=true;
    ntmp.a=s;
    ntmp.b=0;
    qu.push(ntmp);
    while(!qu.empty()){
        now=qu.front();
        //cout<<"here!:"<<now.a<<' '<<now.b<<endl;
        queued[now.a][now.b]=false;
        qu.pop();
        LOOPB(i,0,ga[now.a].size()){
            if(h[ga[now.a][i].t][now.b]>h[now.a][now.b]+ga[now.a][i].v){
                h[ga[now.a][i].t][now.b]=h[now.a][now.b]+ga[now.a][i].v;
                if(!queued[ga[now.a][i].t][now.b]&&h[ga[now.a][i].t][now.b]<=T){
                    ntmp.a=ga[now.a][i].t;
                    ntmp.b=now.b;
                    queued[ntmp.a][ntmp.b]=true;
                    qu.push(ntmp);
                }
            }
        }
        LOOPB(i,0,shortcut[now.a].size()){
            if(h[shortcut[now.a][i].t][now.b+1]>h[now.a][now.b]+shortcut[now.a][i].v){
                h[shortcut[now.a][i].t][now.b+1]=h[now.a][now.b]+shortcut[now.a][i].v;
                if(!queued[shortcut[now.a][i].t][now.b+1]&&h[shortcut[now.a][i].t][now.b+1]<=T){
                    ntmp.a=shortcut[now.a][i].t;
                    ntmp.b=now.b+1;
                    queued[ntmp.a][ntmp.b]=true;
                    qu.push(ntmp);
                }
            }
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
while(scanf("%d",&n)!=EOF){
    LOOPB(i,0,n){
        ga[i].clear();shortcut[i].clear();
    }
    scanf("%d",&k);
    LOOPB(i,0,k){
        scanf("%d%d%d",&a,&b,&l);
        tmp.v=l;
        a--;b--;
        tmp.t=b;
        ga[a].push_back(tmp);
        tmp.t=a;
        ga[b].push_back(tmp);
    }
    scanf("%d",&k);
    LOOPB(i,0,k){
        scanf("%d%d%d",&a,&b,&l);
        tmp.v=l;
        a--;b--;
        tmp.t=b;
        shortcut[a].push_back(tmp);
        tmp.t=a;
        shortcut[b].push_back(tmp);
    }
    scanf("%d%d%d",&s,&t,&T);
    s--;t--;
    spfa();
    LOOP(i,0,k){
        if(h[t][i]<=T)break;
    }
    if(i==k+1)
        cout<<"Impossible\n";
    else
        cout<<i<<endl;
}
}
