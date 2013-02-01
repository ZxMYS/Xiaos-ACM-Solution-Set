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
#define INF (1e28)
int i,j,k,a,m,n,c,s,t,l,tt,cas;
double g[1001][1001];
double d[1001];

int main(){
	double x;
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d",&k);
	cas=1;
	while(k--){
		
		scanf("%d%d%d%d",&l,&t,&n,&c);
		LOOPB(i,0,c){
			scanf("%lf",&d[i]);
			//printf("%d %lf\n",i,d[i]);
		}
		while(i<n){
			d[i]=d[i%c];
			//printf("%d %lf\n",i,d[i]);
			i++;
		}
		LOOPB(j,0,n+1)
			LOOPB(i,0,l+1)
				g[j][i]=INF;
		g[0][0]=0;
		
		LOOPB(i,1,n+1){
			LOOPB(j,0,l+1){
				g[i][j]=g[i-1][j]+d[i-1]/0.5;
				if(t<g[i][j]){
					if(j>0)
					x=max(t-g[i-1][j-1],0.0);
					if(x*0.5<d[i-1]&&j>0)
					g[i][j]=min(g[i][j],g[i-1][j-1]+x+(d[i-1]-x*0.5));
				}
				//printf("%d %d = %lf\n",i,j,g[i][j]);
			}
		}
		double ans=INF;
		LOOPB(j,0,l+1){
			ans=min(ans,g[n][j]);
			//printf("%lf ",g[n][j]);
		}
		
		printf("Case #%d: ",cas++);
		printf("%.0lf\n",ans);	
	}
	return 0;
}
