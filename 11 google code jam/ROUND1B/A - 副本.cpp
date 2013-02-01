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
int ggcd,lcm;
int GCD(int m,int n) 
{
int r;
if(m<n)
{
r=m;
m=n;
n=r;
}
while(n != 0) {
r = m % n;
m = n;
n = r;
}
return m;
} 
int main(){
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out","w",stdout);
	#endif
	scanf("%d",&k);
	cas=1;
	while(k--){
		scanf("%d %d %d\n",&n,&s,&t);
		LOOPB(i,0,n){
			scanf("%d",&g[0][i]);
		}
		ggcd=g[0][0];
		lcm=g[0][0];
		LOOPB(i,1,n){
			ggcd=(ggcd,g[0][i]);
			lcm*=g[0][i];
		}
		printf("Case #%d: ",cas++);	
		if(ggcd>=s&&ggcd<=l)
			printf("%d\n",ggcd);
		else if(lcm/ggcd>=s&&lcm/ggcd<=l)
			printf("%d\n",lcm/ggcd);
		else
			printf("NO");
			
	}
	return 0;
}
