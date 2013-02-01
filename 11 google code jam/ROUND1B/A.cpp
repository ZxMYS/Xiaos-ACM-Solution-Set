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
int g[100][100];
double wp[100];
double owp[100];
double oowp[100];
double dt;
double rpi[100];
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d",&k);
	cas=1;
	while(k--){
		scanf("%d\n",&n);
		LOOPB(i,0,n){
			wp[i]=0;
			a=0;
			m=0;
			LOOPB(j,0,n){
				scanf("%c",&g[i][j]);
				if(g[i][j]!='.')
					m++;
				if(g[i][j]=='1')
					a++;
			}
			wp[i]=((double)a)/m;
			scanf("\n");
		}
		LOOPB(i,0,n){
			owp[i]=0;
			t=0;
			dt=0;
			LOOPB(j,0,n){
				if(g[i][j]=='.')continue;
				a=m=0;
				t++;
				LOOPB(s,0,n){
					if(g[j][s]=='.')continue;
					if(s==i)continue;
					m++;
					if(g[j][s]=='1')
					a++;
				}
				dt+=((double)a)/m;
			}
			owp[i]=dt/t;
		}
		LOOPB(i,0,n){
			dt=m=0;
			LOOPB(j,0,n){
				if(g[i][j]=='.')continue;
				m++;
				dt+=owp[j];
			}
			oowp[i]=dt/m;
		}
		
		printf("Case #%d:\n",cas++);
		LOOPB(i,0,n)
			printf("%.13lf\n", 0.25 * wp[i] + 0.50 * owp[i] + 0.25 * oowp[i]);
	}
	return 0;
}
