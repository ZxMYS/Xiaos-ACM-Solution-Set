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
int i,j,k,a,m,n,s,t,l,tt,cas,c,d;
typedef struct{
	int type;
	map<int,int> sn;
	} node;
node p[2000];
vector<int> left,right;
vector<int> le;
int f[1111][1111]; 

inline bool sat(map<int,int>& now,map<int,int>& need){
	map<int,int>::iterator iter,iter2;
	for(iter=need.begin();iter!=need.end();iter++){
		if((iter2=now.find(iter->first))==now.end()){
			return false;
			break;
		}if(iter2->second<iter->second){
			return false;
			break;
		}
	}
	return true;
}

int dp(int l,int pos){
	//printf("%d %d n e\n",l,pos);
	if(l==le.size()){
		return 1;
	}
	map<int,int> now;
	map<int,int>::iterator iter,iter2;
	//printf("%d %d n e leaderpos:%d\n",l,pos,le[l]);
	if(f[l][pos]!=-1)
		return f[l][pos];
	int i;
	LOOPB(i,pos,le[l]){
		for(iter=p[i].sn.begin();iter!=p[i].sn.end();iter++){
			if((iter2=now.find(iter->first))==now.end()){
				now.insert(make_pair(iter->first,1));
			}else
				iter2->second++;
		} 
	}
	int po=le[l]+1;
	
		//printf("%d %d n left end:\n",l,pos);
	for(iter=now.begin();iter!=now.end();iter++){
		//printf("%d %d n\n",iter->first,iter->second);
	}
	if(le[l]==n-1&&!sat(now,p[le[l]].sn))
		return 0;
	if(sat(now,p[le[l]].sn)){
		i=po;
		//printf("%d %d n left already\n",l,pos);
	}else		
		while(po<n&&p[po].type!=1){
			for(iter=p[po].sn.begin();iter!=p[po].sn.end();iter++){
				if((iter2=now.find(iter->first))==now.end()){
					now.insert(make_pair(iter->first,1));
				}else
					iter2->second++;
			} 
			po++;
			s=true;
			if(sat(now,p[le[l]].sn)){
				i=po;
				break;
			} 
		}
	if(p[po].type==1&&!sat(now,p[le[l]].sn))
		return 0;
	int ret=0;
	po=i; 
	//printf("%d %d n next start at:%d\n",l,pos,po);
	if(l==le.size()-1)
		ret=sat(now,p[le[l]].sn)?1:0;
	else{
		while(po<n&&p[po].type!=1){
			ret+=dp(l+1,po);
			while(ret>9997)
				ret-=9997;
			po++;
		}
		ret+=dp(l+1,po);
		while(ret>9997)
			ret-=9997;
	}
	//printf("%d %d n return:%d\n",l,pos,ret);
	return (f[l][pos]=ret);
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d",&n);
	LOOPB(j,0,n)
		LOOPB(k,0,n)
			f[j][k]=-1;
	LOOPB(i,0,n){
		scanf("%d",&(p[i].type));
		if(p[i].type){
			le.push_back(i);
			scanf("%d",&m);
			p[i].sn.clear();
			LOOPB(j,0,m){
				scanf("%d%d",&c,&d);
				p[i].sn.insert(make_pair(c,d));
			}
		}else{
			scanf("%d",&l);
			LOOPB(j,0,l){
				scanf("%d",&d);
				p[i].sn.insert(make_pair(d,-1));
			}
		}
	}
	if(le.size()==0)
	printf("0\n");
	 else
	printf("%d\n",dp(0,0));
	
	return 0;
}
