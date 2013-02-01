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
int i,j,k,a,m,n,s,t,p,l,tt,cas;
typedef struct {int a,b;} pro;
deque<pro> prob,can_solve;
pro temp;
deque<pro>::iterator iter,iter1;

inline bool proba(const pro & a,const pro & b){
    return a.a<b.a;
}

inline bool probb(const pro & a,const pro & b){
    return a.b<b.b;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
while(scanf("%d%d%d",&n,&m,&p)!=EOF){
    prob.clear();
    can_solve.clear();
    LOOPB(i,0,n){
        scanf("%d%d",&t,&l);
        temp.a=t;
        temp.b=l;
        prob.push_back(temp);
    }
    sort(prob.begin(),prob.end(),proba);
    while(prob.begin()!=prob.end()&&prob.begin()->a<=p){
        can_solve.push_back(*prob.begin());
        prob.pop_front();
    }
    make_heap(can_solve.begin(),can_solve.end(),probb);
    k=0;
    while(k<m&&can_solve.begin()!=can_solve.end()){
        k++;
        pop_heap(can_solve.begin(),can_solve.end(),probb);
        p+=can_solve.rbegin()->b;
        can_solve.pop_back();
        while(prob.begin()!=prob.end()&&prob.begin()->a<=p){
            can_solve.push_back(*prob.begin());
            push_heap(can_solve.begin(),can_solve.end(),probb);
            prob.pop_front();
        }
    }
    cout<<p<<endl;
}

}
