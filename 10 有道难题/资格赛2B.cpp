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
map<string,double> nv; 
map<string,double>::iterator iter;
vector<string> c;
char nam[100];

void add(char a[]){
	if(nv.find(a)!=nv.end())
		return;
	nv.insert(make_pair(a,0.0));
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d",&cas);
	while(cas--){
		nv.clear();
		scanf("%d",&m);
		scanf("%d",&n);
		LOOPB(i,0,n){
			c.clear();
			scanf("%d",&t);
			scanf("%d",&l);
			LOOPB(j,0,t){
				scanf("%s",&nam);
				add(nam);
				c.push_back(nam); 
			}
			scanf("%s",&nam);
			nv.find(nam)->second+=min(t*m,l);
			l-=t*m;
			if(l<0)continue;
			continue;
			LOOPB(j,0,t){
				if(c[j]!=nam){
					nv.find(c[j])->second-=l/(double)(t);
				}
			}
		}
		for(iter=nv.begin();iter!=nv.end();iter++){
			if(iter->second!=0)
				printf("%s %d\n",iter->first.c_str(),(int)iter->second); 
		}
		printf("\n");
	}
	return 0;
}
