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
int i,j,k,a,m,n,s,t,l,d,tt,cas;
string str;
typedef struct _node{
    _node* c[26];
}node;
node *root;

inline void dict_insert(const string& str){
    int i;
    node *now=root;
    node *tmp;
    LOOPB(i,0,str.length()){
        if(now->c[str[i]-'a']==NULL){
            tmp=new(node);
            memset(tmp->c,0,sizeof(tmp->c));
            now=now->c[str[i]-'a']=tmp;
        }else
            now=now->c[str[i]-'a'];
    }
}

inline void get_char_set(vector<char>& char_set,const string& str,int& p){
    if(str[p]!='('){
        char_set.push_back(str[p++]);
        return;
    }
    p++;
    while(str[p]!=')'){
        char_set.push_back(str[p++]);
    }
    p++;
}

int solve(const string& str,int p,node* dict){
    if(p==str.length()){
        return 1;
    }
    vector<char> char_set;
    get_char_set(char_set,str,p);
    int i,ret=0;
    LOOPB(i,0,char_set.size()){
        if(dict->c[char_set[i]-'a']!=NULL){
            ret+=solve(str,p,dict->c[char_set[i]-'a']);
        }
    }
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("A-large.in","r",stdin);
freopen("out","w",stdout);
#endif
scanf("%d%d%d",&l,&d,&n);
root=new(node);
memset(root->c,0,sizeof(root->c));
LOOPB(i,0,d){
    cin>>str;
    dict_insert(str);
}
cas=1;
LOOPB(i,0,n){
    printf("Case #%d: ",cas++);
    cin>>str;
    printf("%d\n",solve(str,0,root));
}
}
