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
vector<int> bot;
vector<int> pos;

inline int lookfornext(int s,int b){
	int i;
	LOOPB(i,s,bot.size()){
		if(bot[i]==b) return i;
	}
	return -1;
}

int main(){
	int i,j,k,a,m,n,s,t,l,tt,cas;
	int op,bp,ot,bt,ott,btt,last;
	#ifndef ONLINE_JUDGE
	freopen("A-large.in","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d",&k);
	cas=1;
	while(k--){
		bot.clear();
		pos.clear();
		l=0;
		scanf("%d ",&n);
		t=0;
		op=bp=1;
		last='x';
		LOOPB(i,0,n){
			scanf("%c %d",&a,&s);
			if(i!=n-1)
				scanf(" ");
			//printf("%c %d\n",a,s);
			bot.push_back(a);
			pos.push_back(s);
		}
		m=0;
		bool pushed;
		while(m!=n){
			pushed=false;
			ot=lookfornext(m,'O');
			bt=lookfornext(m,'B');
			if(ot!=-1){
				if(op==pos[ot]&&ot==m){
					m++;
					pushed=true;
				}else{
					if(op>pos[ot])
						op--;
					else if(op<pos[ot])
						op++;
				}
			}
			if(bt!=-1){
				if(bp==pos[bt]&&bt==m&&(!pushed)){
					m++;
				}else{
					if(bp>pos[bt])
						bp--;
					else if(bp<pos[bt])
						bp++;
				}
			}
			t++;
			//printf("%d %d:bt=%d , ot=%d op%d bp%d\n",t,m,bt,ot,op,bp);
		}
		printf("Case #%d: %d\n",cas++,t);
	}
	
	return 0;
}
