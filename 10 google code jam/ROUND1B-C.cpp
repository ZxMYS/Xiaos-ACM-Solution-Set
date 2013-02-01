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
int ans[100];
int ans_c[]={1,2,3,5,8,14,24,43,77,140,256,472,874,1628,3045,5719,10780,20388,38674,73562,40265,68060,13335,84884};
inline int before(int mask,int n){
	int i,ret=0,ma=1;
	LOOPB(i,0,n-1){
		if(ma&mask){
			ret++;
		}
		ma<<=1;
	}
	return ret+1;
}

inline int check(int mask,int n){
	int ret=0,j;
	if(!((1<<n-1)&mask))
		return 0;
	//printf("%d:\n",mask);
	while((j=before(mask,n))>1){
		if((1<<(j-1))&mask)
			n=j;
		else
			return 0;
		//printf("!%d ",n);
		//printf("?%d ",before(mask,n));
	}
	//puts("\n");
	return n<1?0:1;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d",&tt);
	
	//	printf("%d %d %d: ",before(7,3),before(26,4),before(26,5));
	
	//return 0;
		//fprintf(stderr,"%d\n",i);
	//use this to calc answers
	/*LOOP(j,2,25){
		LOOP(i,2,(1<<j)-1){
		//fprintf(stderr,"%d\n",j);
			ans[j]+=check(i,j);
			if(ans[j]>100003)
				ans[j]%=100003;
			i++;
		}
	}
	LOOP(i,2,25){
		printf("%d,",ans[i]);
	}*/
	
	LOOP(cas,1,tt){
		scanf("%d",&t);
		printf("Case #%d: %d\n",cas,ans_c[t-2]);
		
	}
	
	return 0;
}
