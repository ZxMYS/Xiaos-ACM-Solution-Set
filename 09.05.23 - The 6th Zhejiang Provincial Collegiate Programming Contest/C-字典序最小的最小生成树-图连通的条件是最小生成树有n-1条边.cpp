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
const int oo=1<<29;
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a,m,n,s,t,l,tt,cas,ans,cur,tmp2;
typedef struct {int a,b,c;} edgetype;
vector<edgetype> edge,edge2,answer;
edgetype tmp;
int ga[110][110],father[110];

bool cmp(const edgetype a,const edgetype b){
    if(a.c==b.c){
        return (a.a!=b.a)?a.a<b.a:a.b<b.b;
    }else
        return a.c<b.c;
}

bool cmp2(const edgetype a,const edgetype b){
    return (a.a!=b.a)?a.a<b.a:a.b<b.b;
}


void unionit(int x,int y){
    father[x]=y;
}

int find(int x){
    if(father[x]==x)
        return x;
    else
        father[x]=find(father[x]);
    return father[x];
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d",&cas);
while(cas--){
    edge2.clear();
    edge.clear();
    scanf("%d",&n);
    LOOPB(i,0,n){
        father[i]=i;
        LOOPB(j,0,n){
            scanf("%d",&tt);
            if(tt&&i<j){
                tmp.a=i;
                tmp.b=j;
                tmp.c=tt;
                edge.push_back(tmp);
            }
        }
    }
    sort(edge.begin(),edge.end(),cmp);
    answer.clear();
    ans=0;
    LOOPB(i,0,edge.size()){
        if(find(edge[i].a)==find(edge[i].b))
            continue;
        unionit(find(edge[i].a),find(edge[i].b));
        ans+=edge[i].c;
        answer.push_back(edge[i]);
    }
    if(answer.size()!=n-1){
        cout<<"-1"<<endl;
        continue;
    }
    sort(answer.begin(),answer.end(),cmp2);
    LOOPB(i,0,answer.size()-1){
        cout<<answer[i].a+1<<' '<<answer[i].b+1<<' ';
    }
    cout<<answer[i].a+1<<' '<<answer[i].b+1;
    cout<<endl;
}
}
