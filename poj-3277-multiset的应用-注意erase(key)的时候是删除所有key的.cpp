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
typedef struct {int x,h;bool f;} node;
long long int ans;
node tmp;
inline bool nodecmp(const node& a,const node& b){
    return a.x==b.x?a.f>b.f:a.x<b.x;
}
multiset<int> h;
vector<node> p;
int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
ans=0;
scanf("%d",&n);
LOOPB(i,0,n){
    scanf("%d%d%d",&a,&k,&l);
    tmp.f=true;
    tmp.x=a;
    tmp.h=l;
    p.push_back(tmp);
    tmp.f=false;
    tmp.x=k;
    p.push_back(tmp);
}
sort(p.begin(),p.end(),nodecmp);
LOOPB(i,0,p.size()){
    if(p[i].f)
        h.insert(p[i].h);
    else
        h.erase(h.find(p[i].h));
    if(h.size()==0)
        continue;
    ans+=(long long int)(*h.rbegin())*(p[i+1].x-p[i].x);
}
cout<<ans<<endl;
}
