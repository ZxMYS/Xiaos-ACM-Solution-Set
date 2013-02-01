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
typedef struct {int s,l,e,id;} brick;
typedef struct {int id,e;} line;
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a=0,m,n,s,t,tt;
brick b[100100];
vector<int> l[100100];
list<line> li;
line lt;
list<line>::iterator iter;
int cmp(const void* a, const void* b){
    int i=(*(brick *)a).s-(*(brick *)b).s;
    if(i)return i;
    return (*(brick *)a).e-(*(brick *)b).e;
}

int main()
{
/*#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif*/
scanf("%d",&n);
LOOPB(i,0,n){
    scanf("%d%d",&b[i].l,&b[i].s);
    b[i].e=b[i].s+b[i].l;
    b[i].id=i;
}
qsort(b,n,sizeof(b[0]),cmp);
//LOOPB(i,0,n)
//    printf("%d %d\n",b[i].s,b[i].e);
m=0;
LOOPB(i,0,n){
    iter=li.begin();
    while(iter!=li.end()&&iter->e>b[i].s)
        iter++;
    if(iter!=li.end()){
        iter->e=b[i].e;
        l[iter->id].push_back(b[i].id);
    }else{
        m++;
        lt.e=b[i].e;
        lt.id=m;
        li.push_back(lt);
        l[m].clear();
        l[m].push_back(b[i].id);
    }
}

printf("%d\n",m);
LOOP(i,1,m){
    a=l[i].size();
    LOOPB(j,0,a)
        printf("%d\n",l[i][j]+1);
}
}
