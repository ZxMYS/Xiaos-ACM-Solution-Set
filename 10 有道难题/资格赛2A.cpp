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
int i,j,p,k,a,m,n,s,t,l,tt,cas;
char ch[]={'a','o','d',' '};
char wtf[2000000];
char asd[8000000];
string tmp;
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d",&cas);
	while(cas--){
		tt=0;
		scanf("%s",&wtf);
		m=strlen(wtf);
		p=0;
		LOOPB(i,0,m){
			asd[p++]=ch[(wtf[i]>>6)&3];
			asd[p++]=ch[(wtf[i]>>4)&3];
			asd[p++]=ch[(wtf[i]>>2)&3];
			asd[p++]=ch[wtf[i]&3];
		}
		asd[p]=0;
		tmp=string(asd);
		k=0;
		while((k=tmp.find("dao",k))!=string::npos){
			k++;
			tt++;
		}
		printf("%d\n",tt);
	}
	return 0;
}
