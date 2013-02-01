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
int i,j,k,a,m,n,ss,t,l,tt,cas,p,s;
const int oo=1<<29;
template<class T> string i2s(T x){ostringstream o; o<<x;return o.str();}
int tmp,str[500],ch;
float f1,f2;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d\n",&tt);
	ss=0;
	while(++ss,tt--){
		t=0;
		printf("Case #%d: ", ss);
		scanf("%d%d%d",&n,&s,&p);
		int m=3*p-2;
		int k=3*p-4;
		if(p==0){
			printf("%d\n",n);
			LOOPB(i,0,n)
				scanf("%*d");
			continue;
		}
		if(p==1){
			k=1;
		}
		
		LOOPB(i,0,n){
			scanf("%d",&l);
			if(l>=m)
				t++;
			else if(s>0&&l>=k){
				s--;t++;
			}
		}
		printf("%d\n",t);
	}
	
	return 0;
}
