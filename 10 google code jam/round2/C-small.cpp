#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cassert>
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
int i,j,k,a,m,n,s,t,l,tt,cas,r,x1,y1,x2,y2;
bool p[201][201];
bool p2[201][201];


inline void clear(){
	int i;
	int j;
	LOOPB(i,0,201)
		LOOPB(j,0,201)
			p[i][j]=0;
}

inline void fill(int x1,int y1,int x2,int y2){
	int i,j;
	LOOP(i,x1,x2){
		LOOP(j,y1,y2){
			p[i][j]=1;
		}
	}
}

inline void print(){
	int i;
	int j;
	LOOPB(i,0,201){
		LOOPB(j,0,201)
			printf("%d",p[i][j]);
		printf("\n");
	}
}

inline bool run(){
	int flag=false;
	int i,j;
	LOOPB(i,0,201)
		memcpy(p2[i],p[i],sizeof(p[i]));
	LOOPB(i,0,201)
		LOOPB(j,0,201){
			if(i!=0&&j!=0){
				if((p2[i-1][j]||p2[i][j-1])&&p2[i][j]){
					flag=true;
					p[i][j]=true;
				}else if(p2[i][j])
					p[i][j]=false;
				if((p2[i-1][j]&&p2[i][j-1])){
					flag=true;
					p[i][j]=true;
				}
			}else if(i!=0){
				if(p2[i-1][j]&&p2[i][j]){
					flag=true;
					p[i][j]=true;
				}else if(p2[i][j])
					p[i][j]=false;
			}else if(j!=0){
				if(p2[i][j-1]&&p2[i][j]){
					flag=true;
					p[i][j]=true;
				}else if(p2[i][j])
					p[i][j]=false;
			}
		}
	//print();
	//printf("\n\n");
	return flag;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d",&cas);
	int ans;
	while(cas--){
		ans=1;
		printf("Case #%d: ",++tt);
		scanf("%d",&r);
		clear();
		if(r==0){
			printf("0\n");
			continue;
		}
		LOOPB(i,0,r){
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			fill(x1,y1,x2,y2);
		}
		//print();
		while(run()){
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
