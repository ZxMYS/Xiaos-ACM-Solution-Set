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

struct node{
	map<string,int> c;	
};
int root;
int top;
node dir[100000];
char str[110];
vector<string> strv;

int deal(vector<string>& p){
	int now=0,i=0,j;
	int ret=0;
	map<string,int>::iterator iter;
	while(i<p.size()&&(iter=dir[now].c.find(p[i]))!=dir[now].c.end()){
		i++;
		now=iter->second;
	}
	LOOPB(j,i,p.size()){
		dir[now].c.insert(make_pair<string,int>(p[j],top));
		now=top;
		top++;
		dir[now].c.clear();
		ret++;
	}
	return ret;
}

void split(string str,vector<string>& ret){
     int nend=0;   
     int nbegin=1;   
     while(nend != -1)   
     {   
         nend = str.find('/', nbegin);   
         if(nend == -1)   
             ret.push_back(str.substr(nbegin, str.length()-nbegin));   
         else  
            ret.push_back(str.substr(nbegin, nend-nbegin));   
         nbegin = nend + 1;   
     }   
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("A-large.in","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d",&tt);
	LOOP(cas,1,tt){
		printf("Case #%d: ",cas);
		a=0;
		root=0;
		top=1;
		dir[root].c.clear();
		scanf("%d%d",&n,&m);
		
		strv.clear();
		LOOPB(i,0,n){
			scanf("%s",&str);
			strv.push_back(str);
		}
		sort(strv.begin(),strv.end());
		
		LOOPB(i,0,n){
			vector<string> tmp;
			split(strv[i],tmp);	
			deal(tmp);
		}
		
		strv.clear();
		LOOPB(i,0,m){
			scanf("%s",&str);
			strv.push_back(str);
		}
		
		LOOPB(i,0,m){
			vector<string> tmp;
			split(strv[i],tmp);	
			a+=deal(tmp);
		}
		printf("%d\n",a);
	}
	
	return 0;
	
}
