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
int i,j,a,m,n,s,tt,p,g,cas;
int k,t,l;
map<string,int> party;
map<string,int>::iterator iter;
string tmp;
char ch;
#define EPS 0.00001
inline void yes(){
    cout<<"Guess #"<<i+1<<" was correct."<<endl;
}

inline void no(){
    cout<<"Guess #"<<i+1<<" was incorrect."<<endl;
}

inline void deal(int k,char ch){
    char ch2;
    switch(ch){
        case '>':
            scanf("%c",&ch2);
            if(ch2=='='){
                scanf("%d",&l);
                l*=10;
                if(k-l>=0)
                    yes();
                else
                    no();
            }else{
                scanf("%d",&l);
                l*=10;
                if(k-l>0)
                    yes();
                else
                    no();
            }
            break;
        case '<':
            scanf("%c",&ch2);
            if(ch2=='='){
                scanf("%d",&l);
                l*=10;
                if(k-l<=0)
                    yes();
                else
                    no();
            }else{
                scanf("%d",&l);
                l*=10;
                if(k-l<0)
                    yes();
                else
                    no();
            }
            break;
        case '=':
            scanf("%d",&l);
            l*=10;
            if(k-l==0)
                yes();
            else
                no();
            break;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out","w",stdout);
    #endif
    scanf("%d%d\n",&p,&g);
    LOOPB(i,0,p){
        cin>>tmp;
        scanf("%d.%d",&t,&k);
        party.insert(make_pair(tmp,t*10+k));
    }
    LOOPB(i,0,g){
        k=0;
        while(1){
            cin>>tmp;
            iter=party.find(tmp);
            if(iter!=party.end()){
                k+=iter->second;
            }
            scanf("%c",&ch);
            if(ch==' ')scanf("%c",&ch);
            if(ch!='+'){
                break;
            }
        }
        deal(k,ch);
    }
}
