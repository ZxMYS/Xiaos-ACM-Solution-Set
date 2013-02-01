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
typedef struct {int rank,id;} ranktype;
map<string,int> key;
map<string,int>::iterator iter;
vector<vector<int> > pages;
vector<int> query;
int i,j,k,t=0,keys;

bool cmp(const ranktype a,const ranktype b){
    return a.rank>b.rank;
}

inline int keytoint(string keyword){
    iter=key.find(keyword);
    if(iter==key.end()){
        key.insert(pair<string,int>(keyword,keys));
        return keys++;
    }
    else
        return iter->second;
}

inline vector<int> read(){
    vector<int> tmp;
    tmp.clear();
    string str;
    char ch=0;
    while(ch!='\n'){
        scanf("%c",&ch);
        str="";
        while(ch!='\n'&&ch!=' '){
            str+=toupper(ch);
            scanf("%c",&ch);
        }
        tmp.push_back(keytoint(str));
    }
    return tmp;
}

inline void solve(){
    vector<int> tmp;
    vector<ranktype> rank;
    ranktype rankt;
    rank.clear();
    tmp=read();
    LOOPB(j,0,pages.size()){
        rankt.rank=0;
        LOOPB(k,0,pages[j].size()){
            LOOPB(i,0,tmp.size()){
                if(pages[j][k]==tmp[i])
                    rankt.rank+=(8-k)*(8-i);
            }
        }
        rankt.id=j+1;
        rank.push_back(rankt);
    }
    stable_sort(rank.begin(),rank.end(),cmp);
    if(rank.size()>=5){
        LOOPB(i,0,5){
            if(!rank[i].rank)break;
            printf(" P%d",rank[i].id);
        }
    }else{
        LOOPB(i,0,rank.size()){
            if(!rank[i].rank)break;
            printf(" P%d",rank[i].id);
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
char ch;
pages.clear();
printf("Query Pages\n");
scanf("%c ",&ch);
while(ch!='E'){
    if(ch=='P')
        pages.push_back(read());
    else{
        printf("Q%d:",++t);
        solve();
        putchar('\n');
    }
    scanf("%c ",&ch);
}
}
