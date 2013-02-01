#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cassert>
#include<cmath>
#include<cstring>
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
#define ABS(x) ((x)<0?-(x):(x))
#define PI 3.1415926535898
int i,j,k,a,m,n,s,t,l,tt,cas;
const int oo=1<<29;
set<string> attr;
string in,tmp;
istringstream ssin;
typedef struct{bool leaf;double val;string name;int l,r;} node;
node tree[10000];
int tot;
char ch;
inline void buildtree(int p){
/*tree ::= (weight [feature tree tree])
weight is a real number between 0 and 1, inclusive
feature is a string of 1 or more lower case English letters*/
    tree[p].leaf=true;
    ssin>>tree[p].val>>tmp;
    if(tmp[0]!=')'){
        tree[p].leaf=false;
        tree[p].name=tmp;
        ch=0;
        while(ch!='(')
            ssin>>ch;
        tree[p].l=tot;
        buildtree(tot++);
        ch=0;
        while(ch!='(')
            ssin>>ch;
        tree[p].r=tot;
        buildtree(tot++);
        ch=0;
        while(ch!=')')
            ssin>>ch;
    }
}

inline double calc(){
    double ret=tree[1].val;
    int p=1;
    while(!tree[p].leaf){
        if(attr.find(tree[p].name)!=attr.end()){
            p=tree[p].l;
        }else{
            p=tree[p].r;
        }
        ret*=tree[p].val;
    }
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d\n",&cas);
tt=0;
while(cas--){
    printf("Case #%d:\n",++tt);
    scanf("%d\n",&l);
    in="";
    tot=2;
    i=0;
    while(i<l){
        scanf("%c",&ch);
        if(ch=='\n'){
            i++;
        }else if(ch=='('){
            in+=" ( ";
        }else if(ch==')'){
            in+=" ) ";
        }else
            in+=ch;
    }
    ssin.clear();
    ssin.str(in);
    ch=0;
    while(ch!='(')
        ssin>>ch;
    buildtree(1);
    scanf("%d\n",&n);
    LOOPB(i,0,n){
        cin>>tmp;
        scanf("%d",&m);
        attr.clear();
        LOOPB(j,0,m){
            cin>>tmp;
            attr.insert(tmp);
        }
        printf("%.7lf\n",calc());
    }
}
}
