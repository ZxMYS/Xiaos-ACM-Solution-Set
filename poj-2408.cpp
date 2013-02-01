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
typedef struct {string f,t;} node;
node nodetmp;
vector<node> word[30];
vector<vector<string> > group[30010];
vector<string> grouptmp;
string tmp;

inline bool wcmp(const node& a,const node& b){
    return a.t<b.t;
}

inline bool cmp(const vector<string>& a,const vector<string>& b){
    return a[0]<b[0];
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
while(cin>>tmp){
    nodetmp.f=tmp;
    sort(tmp.begin(),tmp.end());
    nodetmp.t=tmp;
    word[tmp.length()].push_back(nodetmp);
}
LOOPB(l,1,30){
    sort(word[l].begin(),word[l].end(),wcmp);
    i=0;
    while(i<word[l].size()){
        grouptmp.clear();
        grouptmp.push_back(word[l][i].f);
        j=i+1;
        while(j<word[l].size()&&word[l][i].t==word[l][j].t){
            grouptmp.push_back(word[l][j].f);
            j++;
        }
        group[grouptmp.size()].push_back(grouptmp);
        i=j;
    }
}
j=0;
i=30000;
while(i>0&&j<5){
    if(!group[i].size())goto L1;
    LOOPB(k,0,group[i].size()){
        sort(group[i][k].begin(),group[i][k].end());
    }
    sort(group[i].begin(),group[i].end(),cmp);
    k=0;
    while(j<5&&k<group[i].size()){
        cout<<"Group of size "<<i<<": ";
        t=0;
        while(t<group[i][k].size()){
            cout<<group[i][k][t]<<" ";
            tt=t;
            t++;
            while(t<group[i][k].size()&&group[i][k][t]==group[i][k][tt])
                t++;
        }
        cout<<"."<<endl;
        k++;
        j++;
    }
    L1:
    i--;
}
}
