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
int i,j,k,a,b,m,n,s,t,l,tt,cas;
set<int> res;
typedef struct {
	int a,b;
} wtf;
vector<wtf> wep;
vector<int> tmp;
bool cmp(const wtf& a,const wtf& b){
	return a.a+a.b*t<b.a+b.b*t;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d%d",&n,&k);
		res.insert(0);
	LOOPB(i,0,n){
		scanf("%d%d",&t,&l);
		wep.push_back((wtf){t,l});
	}
	t=0;
	while(res.size()<k*1000){
		t++;
		//sort(wep.begin(),wep.end(),cmp);
		tmp.clear();
		LOOPB(i,0,wep.size()){
			for(set<int>::iterator iter=res.begin();iter!=res.end();iter++){
				tmp.push_back(*iter+wep[i].a+wep[i].b*t);
			}
		}
		LOOPB(i,0,tmp.size())
			res.insert(tmp[i]);
	}
	j=0;
	//printf("\n");
	set<int>::iterator iter;
	for(iter=res.begin();j<k;iter++,j++){
		//printf("%d\n",*iter);
	}
	printf("%d\n",*iter);
	return 0;
}
