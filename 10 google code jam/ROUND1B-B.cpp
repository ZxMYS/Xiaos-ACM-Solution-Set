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
int i,j,k,a,m,n,s,b,t,l,tt,cas;
vector<int> x,v;
vector<double> ti;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("B-large.in","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d",&tt);
	LOOP(cas,1,tt){
		printf("Case #%d: ",cas);
		scanf("%d%d%d%d",&n,&k,&b,&t);
		x.clear();
		v.clear();
		ti.clear();
		a=0;
		
		LOOPB(i,0,n){
			scanf("%d",&l);
			x.push_back(l);
		}
		reverse(x.begin(),x.end());
		LOOPB(i,0,n){
			scanf("%d",&l);
			v.push_back(l);
			ti.push_back((b-x[n-i-1])/(double)l);
			//printf("ti:%lf ",ti[i]);
		}
		reverse(ti.begin(),ti.end());
		
		i=0,j=0;
		while(i<n&&k){
			if(ti[i]>t){
				j++;
			}else{
				a+=j;
				k--;
			}
			i++;
		}
		if(k)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n",a);
	}
	
	return 0;
}
