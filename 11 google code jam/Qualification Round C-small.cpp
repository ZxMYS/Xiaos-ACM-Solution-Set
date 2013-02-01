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
vector<int> can;
int main(){
	int i,j,k,a,m,n,s,t,l,tt,cas,r,ll,rr;
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d",&k);
	cas=1;
	while(k--){
		tt=-1;;
		can.clear();
		scanf("%d",&n);
		t=(1<<n)-1;
		LOOPB(i,0,n){
			scanf("%d",&m);
			can.push_back(m);
		}
		LOOPB(i,1,t){
			l=r=0;ll=rr=0;
			LOOPB(j,0,n){
				s=can[j];
				if(i&(1<<j)){
					l=l^s;
					ll+=s;
				}else{
					r=r^s;
					rr+=s;
				}
			}	
			if(l==r){
				tt=max(tt,ll);
			}
		}
		printf("Case #%d: ",cas++);
		if(tt!=-1)
			printf("%d",tt);
		else
			printf("NO");
		printf("\n");
	}
	
	return 0;
}
