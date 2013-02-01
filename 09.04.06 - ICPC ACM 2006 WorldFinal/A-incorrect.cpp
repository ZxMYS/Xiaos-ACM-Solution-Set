#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
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
#define PI 3.1415926535898
#define oo 1<<28
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a,m,n,s,t,l,tt,ans,caseid=0,travel;
typedef struct {int cost,at,tat,t,rat;vector<int> ticketused;} st;
vector<int> tickets[200],tc[220],ti;
bool checked[21][21][21];
// 旅行阶段 使用机票 机票阶段
int cost[200];
map<int,int> cities;
map<int,int>::iterator iter;
vector<int> routine;
queue<st> qu;
st qtmp,qtmp2,anst;

inline int findoradd(int name){
    int j;
    iter=cities.find(name);
    if(iter==cities.end()){
        j=cities.size();
        cities.insert(make_pair(name,j));
        tickets[j].clear();
        return j;
    }else return iter->second;
}

inline int justfind(int name){
    iter=cities.find(name);
    if(iter==cities.end()){
        return -1;
    }else return iter->second;
}


inline st bfs(){
ti.clear();
int i,j,k;
while(!qu.empty())
      qu.pop();
LOOPB(i,0,routine.size())
    memset(checked[i],0,sizeof(checked[1]));
qtmp.cost=0;//花费
qtmp.at=routine[0];//所在点
qtmp.tat=-1;//目前在用的机票所在地
qtmp.t=-1;//目前在用机票
qtmp.rat=0;
qtmp.ticketused.clear();
qu.push(qtmp);
while(!qu.empty()){
    qtmp=qu.front();
    qu.pop();
    if(qtmp.cost>ans)continue;
    //继续使用当前机票
    if(qtmp.t!=-1&&qtmp.tat!=tickets[qtmp.t].size()-1&&
    !checked[qtmp.rat][qtmp.t][qtmp.tat+1]){
        qtmp2=qtmp;
        qtmp2.tat=qtmp.tat+1;
        qtmp2.at=tickets[qtmp.t][qtmp2.tat];
        checked[qtmp.rat][qtmp.t][qtmp2.tat]=true;
        if(qtmp2.at==routine[qtmp.rat+1]){
            cout<<"arrive1 "<<qtmp2.at<<endl;
            qtmp2.rat++;
            checked[qtmp.rat][qtmp.t][qtmp2.tat]=true;
        }
        if(qtmp2.rat==routine.size()-1){
            ans=qtmp2.cost;
            anst=qtmp2;
        }
        else{
            cout<<qtmp2.cost<<' '<<qtmp2.at<<' '<<qtmp2.tat<<' '<<qtmp2.t<<' '<<qtmp2.rat<<' '<<endl;
            qu.push(qtmp2);
        }
    }
    //换机票
    LOOPB(k,0,tc[qtmp.at].size()){
        qtmp2=qtmp;
        qtmp2.at=tickets[tc[qtmp.at][k]][1];
        qtmp2.tat=0;
        qtmp2.cost+=cost[tc[qtmp.at][k]];
        qtmp2.t=tc[qtmp.at][k];
        qtmp.ticketused.push_back(tc[qtmp.at][k]);
        if(!checked[qtmp2.rat][qtmp2.t][qtmp2.tat]){
            checked[qtmp2.rat][qtmp2.t][qtmp2.tat]=true;
            if(qtmp2.at==routine[qtmp.rat+1]){
                cout<<"arrive2 "<<qtmp2.at<<endl;
                qtmp2.rat++;
                checked[qtmp.rat][qtmp.t][qtmp2.tat]=true;
            }
            if(qtmp2.rat==routine.size()-1){
                ans=qtmp2.cost;
                anst=qtmp2;
            }
            else{
            cout<<qtmp2.cost<<' '<<qtmp2.at<<' '<<qtmp2.tat<<' '<<qtmp2.t<<' '<<qtmp2.rat<<' '<<endl;
            qu.push(qtmp2);
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
scanf("%d",&n);
while(n){
    ++caseid;
    travel=0;
    
    cities.clear();
    LOOPB(i,0,n){
        scanf("%d%d",&cost[i],&m);
        tickets[i].clear();
        scanf("%d",&tt);
        a=findoradd(tt);
        tt=a;
        tickets[i].push_back(tt);
        tc[a].push_back(i);
        LOOPB(k,1,m){
            scanf("%d",&tt);
            a=findoradd(tt);
            tt=a;
            tickets[i].push_back(tt);
        }
    }
    scanf("%d",&m);
    LOOPB(i,0,m){
        printf("Case %d, Trip %d: Cost = ",caseid,++travel);
        routine.clear();
        scanf("%d",&l);
        LOOPB(k,0,l){
            scanf("%d",&tt);
            a=findoradd(tt);
            tt=a;
            routine.push_back(tt);
        }
        ans=oo;
        bfs();
        printf("%d\n  Tickets used: %d",ans,anst.ticketused[0]+1);
        LOOPB(k,1,anst.ticketused.size())
            printf(" %d",anst.ticketused[k]+1);
        putchar('\n');
    }
    scanf("%d",&n);
    
}
}
