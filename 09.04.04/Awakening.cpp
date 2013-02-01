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
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int i,j,k,a,m,n,s,t,l,tt;
typedef struct{string name;list<int> ass;} object;
map<string,int> namemap,assmap;
map<string,int>::iterator iter1,iter2;
list<int>::iterator assiter1,assiter2;
object ob[1001];
vector<string> ass,ass2;
list<int> asstocheck;
string str;
char cstr[500],cchar;
/*inline unsigned int SDBMHash(char * str)
{
     unsigned int hash = 0 ;
     while ( * str)
         hash = ( * str ++ ) + (hash << 6 ) + (hash << 16 ) - hash;
     return (hash & 0x7FFFFFFF );
}*/
  template<typename _InputIterator, typename _Tp>
    inline _InputIterator
    find2(_InputIterator __first, _InputIterator __last,
	 const _Tp& __val)
    {
      while (__first != __last && !(*__first == __val)){
            if(*__first > __val)return __last;
	       ++__first;
        }
      return __first;
    }
int main()
{
#ifndef ONLINE_JUDGE
freopen("in.txt","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d",&n);
namemap.clear();
assmap.clear();
LOOPB(i,0,n){
    scanf("%s",&cstr);
    cstr[strlen(cstr)-1]=0;
    //printf("%s\n",cstr);
    ob[i].name=cstr;
    ob[i].ass.clear();
    namemap.insert(pair<string,int>(ob[i].name,i));
    scanf("%c",&cchar);
    while(cchar==' '){
        cin>>str;
        iter1=assmap.find(str);
        if(iter1!=assmap.end()){
            ob[i].ass.push_back(iter1->second);
        }else{
            assmap.insert(pair<string,int>(str,ass.size()));
            ob[i].ass.push_back(ass.size());
            ass.push_back(str);
        }
        scanf("%c",&cchar);
    }
}
LOOPB(i,0,n)
    ob[i].ass.sort();
scanf("%d",&m);
LOOPB(i,0,m){
    cin>>str;
    scanf("%c",&cchar);
    iter1=namemap.find(str);
    if(iter1==namemap.end()){goto L1;}
    asstocheck.clear();
    assiter1=ob[iter1->second].ass.begin();
    while(assiter1!=ob[iter1->second].ass.end())
        asstocheck.push_back(*assiter1++);
    while(cchar==' '){
        cin>>str;
        iter1=namemap.find(str);
        if(iter1==namemap.end()){goto L1;}
        assiter1=asstocheck.begin();
        while(assiter1!=asstocheck.end()){
            if(find2(ob[iter1->second].ass.begin(),ob[iter1->second].ass.end(),*(assiter1))==ob[iter1->second].ass.end())
                {assiter1=asstocheck.erase(assiter1);continue;}
            assiter1++;
        }
        if(asstocheck.empty())goto L1;
        scanf("%c",&cchar);
    }
    
    assiter1=asstocheck.begin();
    assiter2=asstocheck.end();
    assiter2=unique(asstocheck.begin(),asstocheck.end());
    ass2.clear();
    while(assiter1!=assiter2){
        ass2.push_back(ass[*assiter1++]);
    }
    sort(ass2.begin(),ass2.end());
    cout<<ass2[0];
    LOOPB(k,1,ass2.size())
        cout<<' '<<ass2[k];
    cout<<endl;
    continue;
    L1:
        while(cchar!='\n')scanf("%c",&cchar);
        printf("No solution.\n");
}
}
