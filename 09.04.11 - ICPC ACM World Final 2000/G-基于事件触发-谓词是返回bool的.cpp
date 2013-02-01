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
#define PI 3.1415926535898
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a,m,n,s,t,l,tt,ans;
typedef struct {int id;vector<int> cando;} people;
typedef struct {int id,st,bet,num,need;} work;
work w[21];
people p[5];

map<int,int> topic,person;
map<int,vector<pair<bool,int> > > event;
map<int,vector<pair<bool,int> > >::iterator iter1;
list<int> pool;
list<int> pava;
list<int>::iterator piter1,piter2;

bool ecmp(pair<bool,int> a,pair<bool,int> b){
    if(a.first!=b.first)
    return (a.first)<(b.first);
    return (p[a.second].id<p[b.second].id);
}

int pcmp(const void* a, const void* b){
    return (*(people*)a).id-(*(people*)b).id;
}

inline void findjob(int now){
    int k;
    piter1=pava.begin();
    while(piter1!=pava.end()){
        LOOPB(k,0,p[*piter1].cando.size()){
            piter2=pool.begin();
            while(piter2!=pool.end()){
                if(*piter2==p[*piter1].cando[k]){
                    event[w[*piter2].need+now].push_back(pair<bool,int>(1,*piter1));
                    piter2=pool.erase(piter2);
                    piter1=pava.erase(piter1);
                    goto L1;
                }
                piter2++;
            }
        }
        piter1++;
        L1:;
    }
}

inline void solve(){
iter1=event.begin();
while(iter1!=event.end()){
    //cout<<(int)iter1->first<<"----"<<endl;
    sort(iter1->second.begin(),iter1->second.end(),ecmp);
    //LOOPB(i,0,iter1->second.size()){
    //    cout<<iter1->second[i].first<<' '<<iter1->second[i].second<<' '<<p[iter1->second[i].second].id<<endl;
    //}
    LOOPB(i,0,iter1->second.size()){
        if(iter1->second[i].first==0){
            pool.push_back(iter1->second[i].second);
        }
        else
            pava.push_back(iter1->second[i].second);
    }
    findjob(iter1->first);
    ans=iter1->first;
    iter1++;
}
}

int main()
{
scanf("%d",&n);
l=0;
while(n!=0){
topic.clear();
event.clear();
pool.clear();
pava.clear();
person.clear();
LOOPB(i,0,n){
    scanf("%d",&w[i].id);
    topic[w[i].id]=i;
    scanf("%d%d%d%d",&w[i].num,&w[i].st,&w[i].need,&w[i].bet);
    while(w[i].num--){
        event[w[i].st].push_back(pair<bool,int>(0,i));
        w[i].st+=w[i].bet;
    }
}
scanf("%d",&m);
LOOPB(i,0,m){
    scanf("%d",&a);
    p[i].id=a;
    person[a]=i;
    p[i].cando.clear();
    scanf("%d",&tt);
    LOOPB(j,0,tt){
        scanf("%d",&a);
        p[i].cando.push_back(topic[a]);
    }
}
qsort(p,m,sizeof(p[0]),pcmp);
LOOPB(i,0,m)
    event[0].push_back(pair<bool,int>(1,i));
solve();

printf("Scenario %d: All requests are serviced within %d minutes.\n",++l,ans);
scanf("%d",&n);
}
}
