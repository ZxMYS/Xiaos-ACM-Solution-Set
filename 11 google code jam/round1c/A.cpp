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

int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d",&k);
	cas=1;
	while(k--){
		scanf("%d %d\n",&n,&m);
		LOOPB(i,0,n){
			LOOPB(j,0,m)
				scanf("%c",&g[i][j]);
			scanf("\n");
		}
		LOOPB(i,0,n){
			LOOPB(j,0,m){
				if(g[i][j]=='#'){
					if(g[i][j+1]!='#'||g[i+1][j]!='#'||g[i+1][j+1]!='#')
						goto impos;
					g[i][j]=g[i+1][j+1]='/';
					g[i][j+1]=g[i+1][j]='\\';
				}
			}
		}
		printf("Case #%d:\n",cas++);
		LOOPB(i,0,n){
			LOOPB(j,0,m){
				printf("%c",g[i][j]);
			}
			printf("\n");
		}
		continue;
		impos:
		printf("Case #%d:\n",cas++);	
			printf("Impossible\n");
	}
	return 0;
}
