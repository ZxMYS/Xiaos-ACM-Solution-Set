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
int i,j,k,a,m,n,s,t,l,tt,cas;
int p[200][200];
int p2[200][200];
int line[100];
inline void clear(){
	int i;
	int j;
	LOOPB(i,0,100)
		LOOPB(j,0,100)
			p[i][j]=0;
	LOOPB(i,0,200)
		LOOPB(j,0,200)
			p2[i][j]=-1;
}

inline void print(){
	int i;
	int j;
	LOOPB(i,25,75){
		LOOPB(j,25,75)
			printf("%2d ",p[i][j]);
		printf("\n");
	}
}
inline void print2(){
	int i;
	int j;
	LOOPB(i,25,75){
		LOOPB(j,25,75)
			printf("%2d ",p2[i][j]);
		printf("\n");
	}
}

inline bool check(int x1,int y1,int x,int y,int x2){
	int i,j;
	LOOP(i,x1,x2)
		LOOP(j,y1,y){
			if(p[i][j]!=p[x-i+x][y-j+y])
			return false;
		}
	return true;
}


inline bool check2(int x1,int y1,int x,int y,int x2){
	//printf("check2:%d %d %d %d\n",x1,y1,x,y);
	int i,j;
	LOOP(i,x1,x2)
		LOOP(j,y1,y){
			if(p[i][j]!=p[x-i+x+1][y-j+y+1])
			return false;
		}
	return true;
}

inline int getval2(int x,int y,int i,int j){
	double xx=ABS(i-(x+0.5));
	double yy=ABS(j-(y+0.5));
	if(i<=xx&&j<=yy||i>=xx&&j>=yy){
	if(p[(int)(x+0.5+xx)][(int)(y+0.5+yy)]!=-1)
		return p[(int)(x+0.5+xx)][(int)(y+0.5+yy)];
	if(p[(int)(x+0.5-xx)][(int)(y+0.5+yy)]!=-1)
		return p[(int)(x+0.5-xx)][(int)(y+0.5+yy)];
	}
	if(p[(int)(x+0.5+xx)][(int)(y+0.5-yy)]!=-1)
		return p[(int)(x+0.5+xx)][(int)(y+0.5-yy)];
	if(p[(int)(x+0.5-xx)][(int)(y+0.5-yy)]!=-1)
		return p[(int)(x+0.5-xx)][(int)(y+0.5-yy)];
}


inline int calc2(int x,int y){
	int i;
	int j;
	int xl,xr,yt,yb;
	xl=min(50,(x-50)+(x-50)-k+52);
	xr=max(50+k-1,((x-50)<<1)+51);
	yt=min(50,(y-50)+(y-50)-k+52);
	yb=max(50+k-1,((y-50)<<1)+51);
	printf("%d %d:%d %d,%d-%d,%d\n",k,x,y,xl,yt,xr,yb);
	int cost=0;
	//return 1<<29;
	LOOPB(i,0,200)
		memcpy(p[i],p2[i],sizeof(p2[i]));
	LOOP(i,xl,xr){
		LOOP(j,yt,yb){
			if(p[i][j]==-1){
				p[i][j]=getval2(x,y,i,j);
				cost+=p[i][j];
			}
		}
	}
	printf("cost:%d\n",check2(xl,yt,x,y,xr)?cost:1<<29);
	if(check2(xl,yt,x,y,xr)){
		print();
		return cost;
	}else
		return 1<<29;
}

inline int getval(int x,int y,int i,int j){
	int xx=ABS(i-x);
	int yy=ABS(j-y);
	if(i<=x&&j<=y||i>=x&&j>=y){
		if(p[x-xx][y-yy]!=-1)
			return p[x-xx][y-yy];
		if(p[x+xx][y+yy]!=-1)
			return p[x+xx][y+yy];
	}
	if(p[x-xx][y+yy]!=-1)
		return p[x-xx][y+yy];
	if(p[x+xx][y-yy]!=-1)
		return p[x+xx][y-yy];
}

inline int calc(int x,int y){
	int i;
	int j;
	int xl,xr,yt,yb;
	xl=min(50,(x-50)+(x-50)-k+51);
	xr=max(50+k-1,((x-50)<<1)+50);
	yt=min(50,(y-50)+(y-50)-k+51);
	yb=max(50+k-1,((y-50)<<1)+50);
	//printf("%d %d:%d %d,%d-%d,%d\n",k,x,y,xl,yt,xr,yb);
	int cost=0;
	//return 1<<29;
	LOOPB(i,0,200)
		memcpy(p[i],p2[i],sizeof(p2[i]));
	LOOP(i,xl,xr){
		LOOP(j,yt,yb){
			if(p[i][j]==-1){
				p[i][j]=getval(x,y,i,j);
				cost+=p[i][j];
			}
		}
	}
	//printf("cost:%d\n",check(xl,yt,x,y,xr)?cost:1<<29);
	if(check(xl,yt,x,y,xr)){
		//print();
		return cost;
	}else
		return 1<<29;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d",&cas);
	int ans;
	while(cas--){
		ans=1<<29;
		printf("Case #%d: ",++tt);
		//printf("\n");
		scanf("%d",&k);
		clear();
		LOOP(i,1,(k<<1)-1)
			LOOP(j,1,min(i,(k<<1)-i)){
				scanf("%d",&p[i][j]);
			}
		LOOPB(i,0,100){
			line[i]=1;
		}
		LOOPB(i,0,k)
			LOOPB(j,0,k){
				p2[50+j][50+i]=p[i+j+1][line[i+j+1]++];
			}
		//print2();
		LOOPB(i,0,k)
			LOOPB(j,0,k)
				ans=min(ans,calc(i+50,j+50));	
		LOOP(i,-1,k)
			LOOP(j,-1,k)
				ans=min(ans,calc2(i+50,j+50));	
		printf("%d\n",ans);
	}
	return 0;
}
