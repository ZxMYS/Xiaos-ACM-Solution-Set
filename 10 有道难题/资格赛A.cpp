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
int i,j,k,a,b,c,m,n,s,t,l,tt,cas;
char tmp[1010];
int aa[40],bb[40],cc[40];

void v1(int a,int b[40]){
	int i;
	LOOPB(i,0,40){
		b[i]=a%n;
		a/=n;
	}
}

void v2(int& a,int b[40]){
	int i;
	a=0;
	RLOOP(i,39,0){
		a*=n;
		a+=b[i];
	}
}

void add(){
	int i;
	LOOPB(i,0,40){
		cc[i]=aa[i]+bb[i];
		cc[i]%=n;
	}
}

void out(int x[40]){
	int i;
	LOOPB(i,0,40)
		printf("%d ",x[i]);
	printf("\n");
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d",&cas);
	while(cas--){
		memset(aa,0,sizeof(aa));
		memset(bb,0,sizeof(bb));
		memset(cc,0,sizeof(cc));
		scanf("%d%s%d",&a,&tmp,&b);
		n=strlen(tmp)+1;
		v1(a,aa);
		v1(b,bb);
		//out(aa);
		//out(bb);
		
		add();
		v2(c,cc);
		printf("%d\n",c);
	}
	return 0;
}
