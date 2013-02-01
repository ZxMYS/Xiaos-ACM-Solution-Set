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
int i,j,k,a,b,m,n,s,t,l,tt,cas;
int ga[210][210];
typedef struct {
	int x,y,d;
	int p;
} wtf;

typedef struct {
	int x,y;
} point;
vector<wtf> res;
const int W=15<<1;
const int H=28<<1;
const int MIN=min(W,H)<<1;
bool cmp(const wtf& a,const wtf& b){
	return a.p<b.p;	
}

inline void getp(const wtf& a,vector<point>& p){
	if(a.d==0){
		p.push_back((point){a.x,a.y});
		p.push_back((point){a.x+W,a.y});
		p.push_back((point){a.x,a.y+H});
		p.push_back((point){a.x+W,a.y+H});
	}else{
		p.push_back((point){a.x,a.y});
		p.push_back((point){a.x+H,a.y});
		p.push_back((point){a.x,a.y+W});
		p.push_back((point){a.x+H,a.y+W});
	}
}

inline bool isin(const vector<point>& a,const point& b){
	return b.x>=a[0].x&&b.x<=a[1].x&&b.y>=a[0].y&&b.y<=a[2].y;
}

inline bool cross(const vector<point>& a,const vector<point>& b){
	return a[0].x<=b[0].x&&a[1].x>=b[0].x&&a[0].y<=b[1].y&&a[0].y>=b[2].y;
}

inline bool overlap(const wtf& a,const wtf& b){
	vector<point> p1,p2;
	getp(a,p1);
	getp(b,p2);
	int i;
	LOOPB(i,0,p2.size()){
		if(isin(p1,p2[i])||cross(p1,p2)||cross(p2,p1))return true;
	}
	return false;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out","w",stdout);
	#endif
	while(true){
		scanf("%d%d",&a,&b);
		if(a==0)break;
		memset(ga,0,sizeof(ga));
		res.clear();
		a<<=1;
		b<<=1;
		scanf("%d",&n);
		LOOPB(i,0,n){
			scanf("%d%d",&s,&t);
			s<<=1;
			t<<=1;
			ga[s][t]=1;
		}
		//28*15
		LOOPB(i,0,a-W){
				LOOP(j,0,b-H){
					k=0;
					LOOPB(s,i+1,i+W-1)
						LOOPB(t,j+1,j+H-1){
							if(ga[s][t])
								k++;
						}
					res.push_back((wtf){i,j,0,k});
				}
		}
		
		LOOPB(i,0,a-H){
				LOOP(j,0,b-W){
					k=0;
					LOOPB(s,i+1,i+H-1)
						LOOPB(t,j+1,j+W-1){
							if(ga[s][t])
								k++;
						}
					res.push_back((wtf){i,j,1,k});
				}
		}	
	
		sort(res.begin(),res.end(),cmp);
		
		//printf("%d\n",res.size());
		LOOPB(i,0,res.size()){
			printf("%d\t%d %d %d:%d\n",i,res[i].x,res[i].y,res[i].d,res[i].p);
		}
		tt=100000;
		LOOPB(i,0,res.size())
			LOOPB(j,i+1,res.size()){
				if(res[i].p+res[j].p>=tt)
					continue;
				if(!overlap(res[i],res[j])){
					printf("%d %d %d\n",tt,i,j);
					tt=min(tt,res[i].p+res[j].p);
				}
			}
		printf("%d\n",tt);
		
		vector<point> p1,p2;
		getp(res[0],p1);
		getp(res[974],p2);
		
		LOOPB(i,0,p1.size()){
			printf("(%d,%d) ",p1[i].x,p1[i].y);
		}
		printf("\n");
		LOOPB(i,0,p2.size()){
			printf("(%d,%d) ",p2[i].x,p2[i].y);
		}
		//15*28
	}

	return 0;
}
