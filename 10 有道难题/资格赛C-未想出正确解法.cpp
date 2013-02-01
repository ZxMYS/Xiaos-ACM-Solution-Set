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
int i,j,k,c,m,n,s,t,l,tt,cas,bb,be;
typedef struct {
	int b,e,v;
	}node;
int a[1001000];
vector<node> wtf;

void dp1(){
	int r=0,max=0,s1=0,e1=0;
	int i;
	LOOPB(i,0,n<<1){
		r+=a[i];
		if(r>max){
			e1=i;
			max=r;
		}
		if(r<0){
			wtf.push_back((node){s1,e1,max});
			s1=i+1;
			r=0;
			max=0;
			e1=i+1;
			if(i>n)
				break;
		}
	}
	
			wtf.push_back((node){s1,e1,max});
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d",&cas);
	while(cas--){
		wtf.clear();
		scanf("%d",&n);
		l=0;
		LOOPB(i,0,n){
			scanf("%d",&a[i]);
			a[i+n]=a[i];
		}
		int maxb,maxe;
		int max;
		dp1();
		LOOPB(i,0,wtf.size()){
			printf("%d %d %d\n",wtf[i].b,wtf[i].e,wtf[i].v); 
		}
		puts("\n"); 
	} 
	return 0;
}
